/********************************************************************************
** Form generated from reading UI file 'knowledge.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KNOWLEDGE_H
#define UI_KNOWLEDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KnowledgeClass
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QLineEdit *questionNumberLineEdit;
    QLineEdit *questionNumberOutOfLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *questionTitleLineEdit;
    QLabel *label_6;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *testCustomQuickSortPushButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QTextEdit *quesitonTextEdit;
    QGroupBox *groupBox_4;
    QTextEdit *answerTextEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QLabel *label_4;
    QListView *batchListView;
    QLineEdit *batchSearchLineEdit;
    QLineEdit *batchBSearchLineEdit;
    QLabel *label_7;
    QGroupBox *groupBox_5;
    QListView *questionListView;
    QLabel *label_5;
    QLineEdit *questionSearchLineEdit;
    QLineEdit *questionBSearchLineEdit;
    QLabel *label_8;
    QGroupBox *groupBox_6;
    QLabel *label;
    QLineEdit *batchTitleLineEdit;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KnowledgeClass)
    {
        if (KnowledgeClass->objectName().isEmpty())
            KnowledgeClass->setObjectName(QStringLiteral("KnowledgeClass"));
        KnowledgeClass->resize(561, 622);
        KnowledgeClass->setMinimumSize(QSize(561, 622));
        KnowledgeClass->setMaximumSize(QSize(561, 622));
        actionExit = new QAction(KnowledgeClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(KnowledgeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(230, 70, 321, 81));
        questionNumberLineEdit = new QLineEdit(groupBox_2);
        questionNumberLineEdit->setObjectName(QStringLiteral("questionNumberLineEdit"));
        questionNumberLineEdit->setEnabled(true);
        questionNumberLineEdit->setGeometry(QRect(110, 50, 71, 20));
        questionNumberLineEdit->setFrame(true);
        questionNumberLineEdit->setReadOnly(true);
        questionNumberOutOfLineEdit = new QLineEdit(groupBox_2);
        questionNumberOutOfLineEdit->setObjectName(QStringLiteral("questionNumberOutOfLineEdit"));
        questionNumberOutOfLineEdit->setEnabled(true);
        questionNumberOutOfLineEdit->setGeometry(QRect(240, 50, 71, 20));
        questionNumberOutOfLineEdit->setReadOnly(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 91, 21));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 50, 41, 21));
        questionTitleLineEdit = new QLineEdit(groupBox_2);
        questionTitleLineEdit->setObjectName(QStringLiteral("questionTitleLineEdit"));
        questionTitleLineEdit->setEnabled(true);
        questionTitleLineEdit->setGeometry(QRect(110, 20, 201, 20));
        questionTitleLineEdit->setReadOnly(true);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 91, 21));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 520, 542, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        testCustomQuickSortPushButton = new QPushButton(layoutWidget);
        testCustomQuickSortPushButton->setObjectName(QStringLiteral("testCustomQuickSortPushButton"));

        horizontalLayout->addWidget(testCustomQuickSortPushButton);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(230, 160, 321, 351));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(layoutWidget1);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        quesitonTextEdit = new QTextEdit(groupBox_3);
        quesitonTextEdit->setObjectName(QStringLiteral("quesitonTextEdit"));
        quesitonTextEdit->setGeometry(QRect(10, 20, 301, 141));
        quesitonTextEdit->setFrameShape(QFrame::Box);
        quesitonTextEdit->setReadOnly(true);

        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(layoutWidget1);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        answerTextEdit = new QTextEdit(groupBox_4);
        answerTextEdit->setObjectName(QStringLiteral("answerTextEdit"));
        answerTextEdit->setGeometry(QRect(10, 20, 301, 141));
        answerTextEdit->setFrameShape(QFrame::Box);
        answerTextEdit->setReadOnly(true);

        verticalLayout->addWidget(groupBox_4);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 211, 501));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 81, 21));
        batchListView = new QListView(groupBox);
        batchListView->setObjectName(QStringLiteral("batchListView"));
        batchListView->setGeometry(QRect(10, 80, 191, 161));
        batchListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        batchListView->setSelectionMode(QAbstractItemView::SingleSelection);
        batchListView->setSelectionBehavior(QAbstractItemView::SelectRows);
        batchSearchLineEdit = new QLineEdit(groupBox);
        batchSearchLineEdit->setObjectName(QStringLiteral("batchSearchLineEdit"));
        batchSearchLineEdit->setGeometry(QRect(100, 20, 101, 20));
        batchBSearchLineEdit = new QLineEdit(groupBox);
        batchBSearchLineEdit->setObjectName(QStringLiteral("batchBSearchLineEdit"));
        batchBSearchLineEdit->setGeometry(QRect(100, 50, 101, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 50, 81, 21));

        verticalLayout_2->addWidget(groupBox);

        groupBox_5 = new QGroupBox(layoutWidget2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        questionListView = new QListView(groupBox_5);
        questionListView->setObjectName(QStringLiteral("questionListView"));
        questionListView->setGeometry(QRect(10, 80, 191, 161));
        questionListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        questionListView->setSelectionBehavior(QAbstractItemView::SelectRows);
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 81, 21));
        questionSearchLineEdit = new QLineEdit(groupBox_5);
        questionSearchLineEdit->setObjectName(QStringLiteral("questionSearchLineEdit"));
        questionSearchLineEdit->setGeometry(QRect(100, 20, 101, 20));
        questionBSearchLineEdit = new QLineEdit(groupBox_5);
        questionBSearchLineEdit->setObjectName(QStringLiteral("questionBSearchLineEdit"));
        questionBSearchLineEdit->setGeometry(QRect(100, 50, 101, 20));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 50, 81, 21));

        verticalLayout_2->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(230, 10, 321, 51));
        label = new QLabel(groupBox_6);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 91, 21));
        batchTitleLineEdit = new QLineEdit(groupBox_6);
        batchTitleLineEdit->setObjectName(QStringLiteral("batchTitleLineEdit"));
        batchTitleLineEdit->setEnabled(true);
        batchTitleLineEdit->setGeometry(QRect(110, 20, 201, 20));
        batchTitleLineEdit->setReadOnly(true);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 550, 541, 23));
        KnowledgeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KnowledgeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 561, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        KnowledgeClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(KnowledgeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setContextMenuPolicy(Qt::CustomContextMenu);
        KnowledgeClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(KnowledgeClass);
        QObject::connect(actionExit, SIGNAL(triggered()), KnowledgeClass, SLOT(on_actionExit_Triggered()));
        QObject::connect(batchSearchLineEdit, SIGNAL(textChanged(QString)), KnowledgeClass, SLOT(on_batchSearchLineEdit_TextChanged(QString)));
        QObject::connect(questionSearchLineEdit, SIGNAL(textChanged(QString)), KnowledgeClass, SLOT(on_quesitonSearchLineEdit_TextChanged(QString)));
        QObject::connect(batchBSearchLineEdit, SIGNAL(textChanged(QString)), KnowledgeClass, SLOT(on_batchBSearchLineEdit_TextChanged(QString)));
        QObject::connect(questionBSearchLineEdit, SIGNAL(textChanged(QString)), KnowledgeClass, SLOT(on_quesitonBSearchLineEdit_TextChanged(QString)));
        QObject::connect(testCustomQuickSortPushButton, SIGNAL(clicked()), KnowledgeClass, SLOT(on_testCustomQuickSortPushButton_Clicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), KnowledgeClass, SLOT(on_testCustomBinarySearchPushButton_Clicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), KnowledgeClass, SLOT(on_manipulate2DArray_Clicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), KnowledgeClass, SLOT(on_writeReadBinaryFile_Clicked()));

        QMetaObject::connectSlotsByName(KnowledgeClass);
    } // setupUi

    void retranslateUi(QMainWindow *KnowledgeClass)
    {
        KnowledgeClass->setWindowTitle(QApplication::translate("KnowledgeClass", "Knowledge", Q_NULLPTR));
        actionExit->setText(QApplication::translate("KnowledgeClass", "Exit", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("KnowledgeClass", "Question information ", Q_NULLPTR));
        label_2->setText(QApplication::translate("KnowledgeClass", "Question Number:", Q_NULLPTR));
        label_3->setText(QApplication::translate("KnowledgeClass", "Out of:", Q_NULLPTR));
        label_6->setText(QApplication::translate("KnowledgeClass", "Question title:", Q_NULLPTR));
        testCustomQuickSortPushButton->setText(QApplication::translate("KnowledgeClass", "Test Custom Quick Sort", Q_NULLPTR));
        pushButton->setText(QApplication::translate("KnowledgeClass", "Test Custom Binary Search", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("KnowledgeClass", "Manipulate 2D Array ", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("KnowledgeClass", "Question", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("KnowledgeClass", "Answer", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("KnowledgeClass", "Quesiton Batch Selection", Q_NULLPTR));
        label_4->setText(QApplication::translate("KnowledgeClass", "Search:", Q_NULLPTR));
        label_7->setText(QApplication::translate("KnowledgeClass", "Binary Search:", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("KnowledgeClass", "Question Selection", Q_NULLPTR));
        label_5->setText(QApplication::translate("KnowledgeClass", "Search:", Q_NULLPTR));
        label_8->setText(QApplication::translate("KnowledgeClass", "Binary Search:", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("KnowledgeClass", "Quesiton Batch", Q_NULLPTR));
        label->setText(QApplication::translate("KnowledgeClass", "Batch title:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("KnowledgeClass", "Write Read from binary file using random-access algorithms", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("KnowledgeClass", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KnowledgeClass: public Ui_KnowledgeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNOWLEDGE_H
