#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include "ui_knowledge.h"
#include "utils.h"

#include <QtWidgets/QMainWindow>

#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringListModel>
#include <QJsonArray>
#include <QVector>
#include <QModelIndex>
#include <QCloseEvent>

class Knowledge : public QMainWindow
{
	Q_OBJECT

public:
	Knowledge(QWidget *parent = 0);
	~Knowledge();

private:
	Ui::KnowledgeClass ui;

	/// <summary>
	/// Dynamic String List Model of batches connected to batchListView.
	/// </summary>
	QStringListModel *batchModel;

	/// <summary>
	/// Dynamic String List Model of questions connected to questionListView.
	/// </summary>
	QStringListModel *questionModel;

	/// <summary>
	/// Vector of QuestionBatch object batches.
	/// </summary>
	QVector<utils::QuestionBatch> batches;

	/// <summary>
	/// Vector of vectors of quesiton QJsonObjects.
	/// </summary>
	QVector<QVector<QJsonObject>> questions;
	
	/// <summary>
	/// Vector of pointers to current questions.
	/// </summary>
	QVector<QJsonObject*> currentQuestions;

	/// <summary>
	/// Vector of pointers to current batchs.
	/// </summary>
	QVector<utils::QuestionBatch*> currentBatches;
	
	/// <summary>
	/// Change question method.
	/// </summary>
	/// <param name="bIndex"></param>
	/// <param name="qIndex"></param>
	void changeQuestion(const size_t &bIndex, const size_t &qIndex);	

	/// <summary>
	/// Clear question views method.
	/// </summary>
	void clearQuestionViews();

protected slots:
	/// <summary>
	/// Action exit triggered event method.
	/// </summary>
	void on_actionExit_Triggered();

	/// <summary>
	///	Batch search line edit text changed event method.
	/// </summary>
	/// <param name="value"></param>
	void on_batchSearchLineEdit_TextChanged(const QString& value);

	/// <summary>
	///	Question search line edit text changed event method.
	/// </summary>
	/// <param name="value"></param>
	void on_quesitonSearchLineEdit_TextChanged(const QString& value);

	/// <summary>
	/// Batch binary search line edit text changed event method.
	/// </summary>
	/// <param name="value"></param>
	void on_batchBSearchLineEdit_TextChanged(const QString& value);

	/// <summary>
	/// Question binary search line edit text changed event method.
	/// </summary>
	/// <param name="value"></param>
	void on_quesitonBSearchLineEdit_TextChanged(const QString& value);

	/// <summary>
	/// Test custom quick sort push button clicked event method.
	/// </summary>
	void on_testCustomQuickSortPushButton_Clicked();

	/// <summary>
	/// Test custom binary search push button clicked event method.
	/// </summary>
	void on_testCustomBinarySearchPushButton_Clicked();

	/// <summary>
	/// Manipulate 2D array push button clicked event method.
	/// </summary>
	void on_manipulate2DArray_Clicked();

	/// <summary>
	/// Write read binary file push button clicked event method.
	/// </summary>
	void on_writeReadBinaryFile_Clicked();

	/// <summary>
	/// Close event method.
	/// </summary>
	/// <param name="event"></param>
	void closeEvent(QCloseEvent* event);

private slots:
	/// <summary>
	/// batch list view selection changed event method.
	/// </summary>
	/// <param name="selection"></param>
	void on_batchListView_SelectionChanged(const QItemSelection& selection);

	/// <summary>
	/// Question list view selection changed event method.
	/// </summary>
	/// <param name="selection"></param>
	void on_questionListView_SelectionChanged(const QItemSelection& selection);
};

#endif // KNOWLEDGE_H
