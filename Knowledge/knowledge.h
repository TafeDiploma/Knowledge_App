#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include <QtWidgets/QMainWindow>
#include "ui_knowledge.h"
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

	void changeQuestion(const size_t &bIndex, const size_t &qIndex);	

protected slots:
	void on_actionExit_Triggered();
	void on_batchSearchLineEdit_TextChanged(const QString& value);
	void on_quesitonSearchLineEdit_TextChanged(const QString& value);
	void on_batchBSearchLineEdit_TextChanged(const QString& value);
	void on_quesitonBSearchLineEdit_TextChanged(const QString& value);
	void on_testCustomQuickSortPushButton_Clicked();
	void on_testCustomBinarySearchPushButton_Clicked();
	void on_manipulate2DArray_Clicked();
	void on_writeReadBinaryFile_Clicked();
	void on_randomAccessHandling_Clicked();
	void closeEvent(QCloseEvent* event);

private slots:
	void on_batchListView_SelectionChanged(const QItemSelection& selection);
	void on_questionListView_SelectionChanged(const QItemSelection& selection);
};

#endif // KNOWLEDGE_H
