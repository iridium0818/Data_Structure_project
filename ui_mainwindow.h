/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QListView *listView;
    QFrame *frame_2;
    QLineEdit *inputx;
    QLineEdit *inputy;
    QPushButton *nearpt;
    QLabel *label;
    QFrame *frame_3;
    QFrame *frame_4;
    QLineEdit *inputx_2;
    QFrame *frame_6;
    QFrame *frame_5;
    QLineEdit *inputy_2;
    QFrame *frame_7;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QToolButton *toolButton;
    QToolButton *toolButton_5;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QPushButton *shortpt;
    QPushButton *pushButton;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1002, 909);
        MainWindow->setMaximumSize(QSize(1024, 1024));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(239, 235, 229, 1);"));
        MainWindow->setIconSize(QSize(1024, 1024));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(690, -20, 311, 921));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        listView = new QListView(frame);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        listView->setGeometry(QRect(10, 120, 281, 781));
        listView->setMaximumSize(QSize(300, 900));
        listView->setStyleSheet(QString::fromUtf8("background-color: rgba(235, 235, 235, 1);\n"
"border-radius: 13px;"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setSpacing(0);
        listView->setModelColumn(0);
        listView->setWordWrap(false);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 30, 281, 61));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgba(217, 217, 217, 1);\n"
"border-radius: 13px;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        inputx = new QLineEdit(frame_2);
        inputx->setObjectName(QString::fromUtf8("inputx"));
        inputx->setGeometry(QRect(10, 10, 150, 20));
        inputx->setMinimumSize(QSize(100, 20));
        inputx->setMaximumSize(QSize(150, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        inputx->setFont(font);
        inputy = new QLineEdit(frame_2);
        inputy->setObjectName(QString::fromUtf8("inputy"));
        inputy->setGeometry(QRect(10, 30, 150, 20));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputy->sizePolicy().hasHeightForWidth());
        inputy->setSizePolicy(sizePolicy);
        inputy->setMinimumSize(QSize(150, 20));
        inputy->setMaximumSize(QSize(100, 20));
        inputy->setFont(font);
        nearpt = new QPushButton(frame_2);
        nearpt->setObjectName(QString::fromUtf8("nearpt"));
        nearpt->setGeometry(QRect(180, 10, 90, 41));
        nearpt->setMinimumSize(QSize(90, 20));
        nearpt->setMaximumSize(QSize(93, 52));
        nearpt->setFont(font);
        nearpt->setStyleSheet(QString::fromUtf8("background-color: rgba(119, 94, 207, 0.73);"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 100, 111, 16));
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 10, 651, 81));
        frame_3->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"background-color: rgb(255, 255, 255);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(20, 15, 251, 50));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgba(217, 217, 217, 1);\n"
"border-radius: 13px;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        inputx_2 = new QLineEdit(frame_4);
        inputx_2->setObjectName(QString::fromUtf8("inputx_2"));
        inputx_2->setGeometry(QRect(20, 10, 161, 29));
        inputx_2->setMinimumSize(QSize(102, 29));
        inputx_2->setMaximumSize(QSize(164, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        inputx_2->setFont(font1);
        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(300, 37, 51, 5));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: rgba(217, 217, 217, 1);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(380, 15, 251, 50));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgba(217, 217, 217, 1);\n"
"border-radius: 13px;"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        inputy_2 = new QLineEdit(frame_5);
        inputy_2->setObjectName(QString::fromUtf8("inputy_2"));
        inputy_2->setGeometry(QRect(20, 10, 161, 29));
        inputy_2->setMinimumSize(QSize(102, 29));
        inputy_2->setMaximumSize(QSize(164, 20));
        inputy_2->setFont(font1);
        frame_7 = new QFrame(centralwidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(0, 690, 691, 211));
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
" border-radius: 13px;"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_7);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(510, 10, 171, 181));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(150, 15));
        label_2->setMaximumSize(QSize(16777215, 10));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_6->addWidget(label_2);

        toolButton = new QToolButton(layoutWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(8);
        toolButton->setFont(font2);

        verticalLayout_6->addWidget(toolButton);

        toolButton_5 = new QToolButton(layoutWidget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        sizePolicy1.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy1);
        toolButton_5->setFont(font2);

        verticalLayout_6->addWidget(toolButton_5);

        toolButton_4 = new QToolButton(layoutWidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        sizePolicy1.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy1);
        toolButton_4->setFont(font2);

        verticalLayout_6->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(layoutWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy1.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy1);
        toolButton_3->setFont(font2);

        verticalLayout_6->addWidget(toolButton_3);

        toolButton_2 = new QToolButton(layoutWidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy1.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy1);
        toolButton_2->setFont(font2);

        verticalLayout_6->addWidget(toolButton_2);

        shortpt = new QPushButton(frame_7);
        shortpt->setObjectName(QString::fromUtf8("shortpt"));
        shortpt->setGeometry(QRect(10, 120, 220, 60));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(shortpt->sizePolicy().hasHeightForWidth());
        shortpt->setSizePolicy(sizePolicy2);
        shortpt->setMinimumSize(QSize(150, 30));
        shortpt->setMaximumSize(QSize(250, 60));
        shortpt->setBaseSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        shortpt->setFont(font3);
        shortpt->setTabletTracking(false);
        shortpt->setAcceptDrops(false);
        shortpt->setAutoFillBackground(false);
        shortpt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	background-color:rgba(119, 94, 207, 0.73);\n"
"    border-radius: 13px; \n"
"    color: white;\n"
"    letter-spacing: 5px;\n"
"}\n"
""));
        pushButton = new QPushButton(frame_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 120, 220, 60));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(220, 60));
        pushButton->setMaximumSize(QSize(250, 60));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton->setFont(font4);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	background-color:rgba(119, 94, 207, 0.73);\n"
"    border-radius: 13px; \n"
"    color: white;\n"
"    letter-spacing: 5px;\n"
"}"));
        toolButton_6 = new QToolButton(frame_7);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(20, 70, 150, 30));
        sizePolicy1.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy1);
        toolButton_6->setMinimumSize(QSize(100, 20));
        toolButton_6->setMaximumSize(QSize(160, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(12);
        toolButton_6->setFont(font5);
        toolButton_7 = new QToolButton(frame_7);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setGeometry(QRect(20, 20, 150, 30));
        sizePolicy1.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy1);
        toolButton_7->setMinimumSize(QSize(100, 20));
        toolButton_7->setMaximumSize(QSize(160, 30));
        toolButton_7->setFont(font5);
        toolButton_7->setLayoutDirection(Qt::LeftToRight);
        toolButton_7->setStyleSheet(QString::fromUtf8("text - align: left;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1002, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\257\274\350\210\252\347\263\273\347\273\237", nullptr));
        inputx->setPlaceholderText(QCoreApplication::translate("MainWindow", "x\345\235\220\346\240\207(0-32767)", nullptr));
        inputy->setPlaceholderText(QCoreApplication::translate("MainWindow", "y\345\235\220\346\240\207(0-32767)", nullptr));
        nearpt->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242(\345\217\263\351\224\256\345\217\214\345\207\273)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221100\344\270\252\347\202\271\346\240\207\345\217\267", nullptr));
        inputx_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\254\254\344\270\200\344\270\252\347\202\271\346\240\207\345\217\267(1-10000)", nullptr));
        inputy_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\254\254\344\272\214\344\270\252\347\202\271\346\240\207\345\217\267(1-10000)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\201\223\350\267\257\347\212\266\345\206\265", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", ">150%", nullptr));
        toolButton_5->setText(QCoreApplication::translate("MainWindow", "100%-150%", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindow", "80%-100%", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "50%-80%", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "<50%", nullptr));
        shortpt->setText(QCoreApplication::translate("MainWindow", "\350\267\235\347\246\273\346\234\200\347\237\255", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\234\200\347\237\255", nullptr));
        toolButton_6->setText(QCoreApplication::translate("MainWindow", "\350\267\235\347\246\273\357\274\232", nullptr));
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
