#include "knowledge.h"
#include "utils.h"

#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringListModel>
#include <QJsonArray>
#include <QVector>
#include <QtAlgorithms>
#include <QCloseEvent>
#include <QListWidget>
#include <fstream>

Knowledge::Knowledge(QWidget *parent)
	: QMainWindow(parent)
{
	// TODO: Fix all this.
	
	const QString val = utils::readFile("Q&A.json");
	const QJsonArray arr = QJsonDocument::fromJson(val.toUtf8()).array();

	for (size_t index = 0; index < arr.count(); index++)
	{
		utils::QuestionBatch tempBatch;
		QVector<QJsonObject> tempQuestions;
		auto var = arr[index].toObject();

		tempBatch.title = var["title"].toString();
		tempBatch.description = var["description"].toString();
		tempBatch.bIndex = index;

		for each (auto var in var["questions"].toArray())
		{
			tempQuestions.push_back(var.toObject());
		}

		this->questions.push_back(tempQuestions);
		this->batches.push_back(tempBatch);
	}

	// Sort batch array.
	qSort(batches.begin(), batches.end(), utils::CompQuestionBatchByTitle());

	// Sort questions 2D array.
	for (size_t index = 0; index < questions.count(); index++)
		qSort(questions[index].begin(), questions[index].end(), utils::compareQJsonObjectBy("title"));

	ui.setupUi(this);

	// Create model
	batchModel = new QStringListModel(this);
	questionModel = new QStringListModel(this);
	
	currentBatches.clear();
	for (size_t index = 0; index < batches.count(); index++)
		currentBatches.push_back(&batches[index]);

	// StringList to populate batchModel.
	QStringList batchList;
	for each (auto var in batches)
		batchList << var.title;

	// Populate our model
	batchModel->setStringList(batchList);

	// Assign list view to models.
	ui.batchListView->setModel(batchModel);
	ui.questionListView->setModel(questionModel);

	// Custom slot.
	connect(ui.batchListView->selectionModel(),
		SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
		this, SLOT(on_batchListView_SelectionChanged(QItemSelection)));

	// Custom slot.
	connect(ui.questionListView->selectionModel(),
		SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
		this, SLOT(on_questionListView_SelectionChanged(QItemSelection)));

	// Creating and deleting dynamic char array,
	// just incase.
	char* dynCharArr = new char[10];
	dynCharArr[9] = '\0';
	delete[] dynCharArr;
}

void Knowledge::on_batchListView_SelectionChanged(const QItemSelection& selection)
{
	const size_t bIndex = currentBatches[ui.batchListView->currentIndex().row()][0].bIndex;

	// Error checking
	if (questions[bIndex].empty())
		return;

	// Clearing question views
	clearQuestionViews();

	currentQuestions.clear();
	currentQuestions.resize(questions[bIndex].length());
	utils::copyOverReference(questions[bIndex].begin(), questions[bIndex].end(), currentQuestions);

	QStringList List;
	for (size_t index = 0; index < questions[bIndex].count(); index++)
		List << questions[bIndex][index]["title"].toString();
	questionModel->setStringList(List);

	// Getting index 0 of question model and setting it in question list view.
	ui.questionListView->selectionModel()->select(questionModel->index(0, 0), QItemSelectionModel::Select);

	// Display question information.
	changeQuestion(bIndex, 0);
}

void Knowledge::on_questionListView_SelectionChanged(const QItemSelection & selection)
{
	if (!ui.questionListView->currentIndex().isValid())
		return;
	if (ui.batchListView->currentIndex().row() == SIZE_MAX)
		return;

	const size_t qIndex = ui.questionListView->currentIndex().row();

	if (qIndex == SIZE_MAX)
		return;

	changeQuestion(ui.batchListView->currentIndex().row(), qIndex);
}

Knowledge::~Knowledge()
{
	delete batchModel;
	delete questionModel;
}

void Knowledge::on_actionExit_Triggered()
{
	this->close();
}

void Knowledge::on_batchSearchLineEdit_TextChanged(const QString& value)
{
	currentBatches.clear();
	
	QStringList List;
	for (size_t index = 0; index < batches.count(); index++)
	{
		if (value.isEmpty()) // If binary search line edit is empty.
		{
			List << batches[index].title;
			currentBatches.push_back(&batches[index]);
		}
		else if (batches[index].title.contains(value))
		{
			List << batches[index].title;
			currentBatches.push_back(&batches[index]);
			clearQuestionViews();
		}
	}

	batchModel->setStringList(List);
}

void Knowledge::on_quesitonSearchLineEdit_TextChanged(const QString& value)
{
	// Error checking.
	if (!ui.batchListView->currentIndex().isValid())
		return;

	const size_t bIndex = currentBatches[0][ui.batchListView->currentIndex().row()].bIndex;

	// Error checking.
	if (bIndex == SIZE_MAX)
		return;

	currentQuestions.clear();

	QStringList List;
	for (size_t index = 0; index < questions[bIndex].count(); index++)
	{
		if (value.isEmpty()) // If question search line edit is empty.
		{
			List << questions[bIndex][index]["title"].toString();
			currentQuestions.push_back(&questions[bIndex][index]);
		}
		else if (questions[bIndex][index]["title"].toString().contains(value))
		{
			List << questions[bIndex][index]["title"].toString();
			currentQuestions.push_back(&questions[bIndex][index]);
		}
	}
	questionModel->setStringList(List);
}

void Knowledge::on_batchBSearchLineEdit_TextChanged(const QString& value)
{
	currentBatches.clear();

	QStringList List;
	size_t bSize = 0;

	// Binary searching batches and output results.
	std::pair<utils::QuestionBatch*, utils::QuestionBatch*> p = std::equal_range(batches.begin(), batches.end(), value, utils::CompQuestionBatchByTitleBSearch());
	for (auto i = p.first; i != p.second; ++i)
	{
		List << i->title;
		bSize++;
	}

	if (!List.empty()) // If anything found after binary search.
	{
		currentBatches.resize(bSize);
		utils::copyOverReference(p.first, p.second, currentBatches);
		batchModel->setStringList(List);
		clearQuestionViews();
	}
	else // If nothing found after binary search.
	{
		for (size_t index = 0; index < batches.count(); index++)
		{
			List << batches[index].title;
			currentBatches.push_back(&batches[index]);
		}
		batchModel->setStringList(List);
	}
}

void Knowledge::on_quesitonBSearchLineEdit_TextChanged(const QString& value)
{
	// Error checking
	if (!ui.batchListView->currentIndex().isValid())
		return;

	const size_t bIndex = currentBatches[ui.batchListView->currentIndex().row()][0].bIndex;

	// Error checking
	if (bIndex == SIZE_MAX)
		return;

	currentQuestions.clear();

	QStringList List;
	size_t qSize = 0;

	// Binary searching questions and output results.
	std::pair<QJsonObject*, QJsonObject*> p = std::equal_range(questions[bIndex].begin(),
		questions[bIndex].end(), value, utils::CompQJsonObjectToStringByTitle());
	for (auto i = p.first; i != p.second; ++i)
	{
		List << i->value("title").toString();
		qSize++;
	}

	if (!List.empty()) // If anything found after binary search.
	{
		currentQuestions.resize(qSize);
		utils::copyOverReference(p.first, p.second, currentQuestions);
		questionModel->setStringList(List);
	}
	else // If nothing found after binary search.
	{
		for (size_t index = 0; index < questions[bIndex].count(); index++)
		{
			List << questions[bIndex][index]["title"].toString();
			currentQuestions.push_back(&questions[bIndex][index]);
		}
		questionModel->setStringList(List);
	}
	
}

void Knowledge::on_testCustomQuickSortPushButton_Clicked()
{
	int numberArray[] =
	{
		4532,
		54654,
		987,
		9879,
		34543,
		12312,
		324,
		564,
		888,
		555
	};
	
	QString stringArray[] =
	{
		"unfasten",
		"shivering",
		"pocket",
		"excite",
		"rescue",
		"coil",
		"kindly",
		"uneven",
		"enjoy",
		"foregoing",
		"brainy",
		"change"
	};

	// Pushing unsorted all elements of int array into string.
	QString output = "<b>Unsorted int array:</b><br>";
	for each (int var in numberArray)
		output.push_back((QString::number(var)) + ", ");

	// Sorting int array and pushing it into string.
	utils::quickSort(std::begin(numberArray), std::end(numberArray));
	output.push_back("<br><b>Sorted int array:</b><br>");
	for each (int var in numberArray)
		output.push_back((QString::number(var)) + ", ");

	output.push_back("<br>");

	// Pushing unsorted all elements of string array into string.
	output.push_back("<br><b>Unsorted QString array:</b><br>");
	for each (QString var in stringArray)
		output.push_back((var) + ", ");

	// Sorting string array and pushing it into string.
	utils::quickSort(std::begin(stringArray), std::end(stringArray));
	output.push_back("<br><b>Sorted QString array:</b><br>");
	for each (QString var in stringArray)
		output.push_back((var)+", ");

	// Output into message box.
	QMessageBox msgBox("Sorting Arrays",
		"<p>" + output + "</p>",
		QMessageBox::Question,
		QMessageBox::Ok | QMessageBox::Default,
		QMessageBox::NoButton,
		QMessageBox::NoButton);
	msgBox.exec();
}

void Knowledge::on_testCustomBinarySearchPushButton_Clicked()
{
	int numberArray[] =
	{
		4532,
		54654,
		987,
		9879,
		34543,
		12312,
		324,
		564,
		888,
		555
	};

	QString stringArray[] =
	{
		"unfasten",
		"shivering",
		"pocket",
		"excite",
		"rescue",
		"coil",
		"kindly",
		"uneven",
		"enjoy",
		"foregoing",
		"brainy",
		"change"
	};
	
	// Sorting number and string arrays.
	utils::quickSort(std::begin(numberArray), std::end(numberArray));
	utils::quickSort(std::begin(stringArray), std::end(stringArray));

	// Binary searching number and string arrays.
	int* returnNumber = utils::binarySearch(std::begin(numberArray), std::end(numberArray), 555);
	QString* returnString = utils::binarySearch(std::begin(stringArray), std::end(stringArray), "brainy");

	// Pushing the results of the binary search for int array into QString.
	QString output = "<b>Binary Search Int Array:</b><br>";
	for each (int var in numberArray)
		output.push_back((QString::number(var)) + ", ");
	output.push_back("<br><b>Searched Value: </b><br>" + QString::number(*returnNumber));

	// Pushing the results of the binary search for string array into QString.
	output.push_back("<br><br><b>Binary Search QString Array:</b><br>");
	for each (auto var in stringArray)
		output.push_back((var) + ", ");
	output.push_back("<br><b>Searched Value: </b><br>" + (*returnString));

	// Output into message box.
	QMessageBox msgBox("Binary Searching Arrays",
		"<p>" + output + "</p>",
		QMessageBox::Question,
		QMessageBox::Ok | QMessageBox::Default,
		QMessageBox::NoButton,
		QMessageBox::NoButton);
	msgBox.exec();
}

void Knowledge::on_manipulate2DArray_Clicked()
{
	QString output;

	// Creating and maniplulating 2D standard C-Style array.
	const size_t x = 10, y = 10;
	QString arr[y][x];
	for (size_t yIndex = 0; yIndex < (sizeof(arr) / sizeof(arr[0])); yIndex++)
	{
		output.push_back("<b>Row: </b>");
		for (size_t xIndex = 0; xIndex < (sizeof(arr[yIndex]) / sizeof(arr[yIndex][0])); xIndex++)
		{
			arr[yIndex][xIndex] = "Y: " + QString::number(yIndex) + " X: " + QString::number(xIndex);
			output.push_back((arr[yIndex][xIndex]) + " | ");
		}
		output.push_back("<br>");
	}

	// Output into message box.
	QMessageBox msgBox("Manipulated 2D Array",
		"<p>" + output + "</p>",
		QMessageBox::Question,
		QMessageBox::Ok | QMessageBox::Default,
		QMessageBox::NoButton,
		QMessageBox::NoButton);
	msgBox.exec();
}

void Knowledge::on_writeReadBinaryFile_Clicked()
{
	QString output;
	
	// Reading from precreated file.
	QString readFile = utils::readBinaryFile("binaryFile.bin");
	output.push_back("<b>Reading binary file</b><br>");
	output.push_back(readFile);

	// Creating/Overriding and writing and reading from file.
	utils::writeBinaryFile("binaryWriteFile.bin", readFile);
	output.push_back("<br><b>Reading binary file writen</b><br>");
	output.push_back(utils::readBinaryFile("binaryWriteFile.bin"));

	// Accessing binaryFile.bin using random algorithms.
	output.push_back("<br><b>Reading binary file using random algorithms</b><br>");
	output.push_back("<b>from 21 bytes from beg: </b>" + utils::accessFileRandomly("binaryFile.bin", 21));
	output.push_back("<br><b>from -3 bytes from end: </b>" + utils::accessFileRandomly("binaryFile.bin", -3, std::ifstream::end));

	// Output into message box.
	QMessageBox msgBox("Read/Writeing binary File",
		"<p>" + output + "</p>",
		QMessageBox::Question,
		QMessageBox::Ok | QMessageBox::Default,
		QMessageBox::NoButton,
		QMessageBox::NoButton);
	msgBox.exec();
}

void Knowledge::changeQuestion(const size_t& bIndex, const size_t& qIndex)
{
	// Display batch information.
	ui.batchTitleLineEdit->setText(currentBatches[ui.batchListView->currentIndex().row()][0].title);
	ui.questionNumberOutOfLineEdit->setText(QString::number(currentQuestions.length()));

	// Display question information.
	ui.questionTitleLineEdit->setText(currentQuestions[qIndex][0]["title"].toString());
	ui.questionNumberLineEdit->setText(QString::number(qIndex + 1));
	ui.quesitonTextEdit->setText(currentQuestions[qIndex][0]["question"].toString());

	// Display answer information
	ui.answerTextEdit->setText(currentQuestions[qIndex][0]["answer"].toString());
}

void Knowledge::clearQuestionViews()
{
	this->questionModel->setStringList(QStringList());
	ui.questionSearchLineEdit->clear();
	ui.questionBSearchLineEdit->clear();
	ui.questionNumberLineEdit->clear();
	ui.questionNumberOutOfLineEdit->clear();
	ui.quesitonTextEdit->clear();
	ui.answerTextEdit->clear();
}

void Knowledge::closeEvent(QCloseEvent* event)
{
	// Show conformation message box.
	QMessageBox msgBox("Warning",
		"Are you sure?",
		QMessageBox::Warning,
		QMessageBox::No | QMessageBox::Default,
		QMessageBox::Yes,
		QMessageBox::NoButton);

	if (msgBox.exec() == QMessageBox::Yes)
		event->accept();
	else
		event->ignore();
}