/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *A_Param_LineEdit;
    QLabel *label_2;
    QLineEdit *B_Param_LineEdit;
    QLabel *label_3;
    QLineEdit *Modulus_LineEdit;
    QLabel *label_4;
    QLineEdit *Cofactor_LineEdit;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLineEdit *X_BPoint_LineEdit;
    QPushButton *BPoint_Generate_Btn;
    QFrame *line;
    QLabel *label_6;
    QLineEdit *PublicKey_LineEdit;
    QLabel *label_7;
    QLineEdit *PrivateKey_LineEdit;
    QPushButton *Keys_Generate_Btn;
    QLineEdit *Y_BPoint_LineEdit;
    QLineEdit *C_BPoint_LineEdit;
    QLineEdit *Bob_Public_Key_LineEdit;
    QLineEdit *lineEdit_3;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *setBasePoint;
    QLineEdit *Shared_Key;
    QLabel *label_14;
    QGroupBox *groupBox_5;
    QTextBrowser *Alice_TextBrowser;
    QLineEdit *Alice_LineEdit;
    QPushButton *Alice_SendMsg_Btn;
    QGroupBox *groupBox_6;
    QTextBrowser *Bob_TextBrowser;
    QLineEdit *Bob_LineEdit;
    QPushButton *Bob_SendMsg_Btn;
    QGroupBox *groupBox_7;
    QTextBrowser *Ops_TextBrowser;
    QGroupBox *groupBox_4;
    QPushButton *Signature_Create;
    QPushButton *Submit_Signature;
    QLabel *label_8;
    QLineEdit *Signature_R;
    QLineEdit *Signature_S;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(749, 598);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(2000, 1500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 731, 221));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 241, 191));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 81, 21));
        A_Param_LineEdit = new QLineEdit(groupBox_2);
        A_Param_LineEdit->setObjectName(QString::fromUtf8("A_Param_LineEdit"));
        A_Param_LineEdit->setGeometry(QRect(140, 30, 91, 22));
        A_Param_LineEdit->setMaxLength(32767);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 81, 21));
        B_Param_LineEdit = new QLineEdit(groupBox_2);
        B_Param_LineEdit->setObjectName(QString::fromUtf8("B_Param_LineEdit"));
        B_Param_LineEdit->setGeometry(QRect(140, 60, 91, 22));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 55, 21));
        Modulus_LineEdit = new QLineEdit(groupBox_2);
        Modulus_LineEdit->setObjectName(QString::fromUtf8("Modulus_LineEdit"));
        Modulus_LineEdit->setGeometry(QRect(140, 90, 91, 22));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 120, 111, 21));
        Cofactor_LineEdit = new QLineEdit(groupBox_2);
        Cofactor_LineEdit->setObjectName(QString::fromUtf8("Cofactor_LineEdit"));
        Cofactor_LineEdit->setGeometry(QRect(140, 120, 91, 22));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 150, 93, 21));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(260, 20, 461, 191));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 30, 61, 21));
        X_BPoint_LineEdit = new QLineEdit(groupBox_3);
        X_BPoint_LineEdit->setObjectName(QString::fromUtf8("X_BPoint_LineEdit"));
        X_BPoint_LineEdit->setGeometry(QRect(100, 30, 51, 22));
        BPoint_Generate_Btn = new QPushButton(groupBox_3);
        BPoint_Generate_Btn->setObjectName(QString::fromUtf8("BPoint_Generate_Btn"));
        BPoint_Generate_Btn->setGeometry(QRect(290, 30, 71, 21));
        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 60, 441, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 100, 80, 20));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        PublicKey_LineEdit = new QLineEdit(groupBox_3);
        PublicKey_LineEdit->setObjectName(QString::fromUtf8("PublicKey_LineEdit"));
        PublicKey_LineEdit->setGeometry(QRect(100, 100, 81, 22));
        PublicKey_LineEdit->setReadOnly(true);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 130, 81, 21));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        PrivateKey_LineEdit = new QLineEdit(groupBox_3);
        PrivateKey_LineEdit->setObjectName(QString::fromUtf8("PrivateKey_LineEdit"));
        PrivateKey_LineEdit->setGeometry(QRect(100, 130, 81, 22));
        PrivateKey_LineEdit->setReadOnly(true);
        Keys_Generate_Btn = new QPushButton(groupBox_3);
        Keys_Generate_Btn->setObjectName(QString::fromUtf8("Keys_Generate_Btn"));
        Keys_Generate_Btn->setGeometry(QRect(350, 120, 71, 21));
        Y_BPoint_LineEdit = new QLineEdit(groupBox_3);
        Y_BPoint_LineEdit->setObjectName(QString::fromUtf8("Y_BPoint_LineEdit"));
        Y_BPoint_LineEdit->setGeometry(QRect(160, 30, 51, 22));
        C_BPoint_LineEdit = new QLineEdit(groupBox_3);
        C_BPoint_LineEdit->setObjectName(QString::fromUtf8("C_BPoint_LineEdit"));
        C_BPoint_LineEdit->setGeometry(QRect(220, 30, 51, 22));
        Bob_Public_Key_LineEdit = new QLineEdit(groupBox_3);
        Bob_Public_Key_LineEdit->setObjectName(QString::fromUtf8("Bob_Public_Key_LineEdit"));
        Bob_Public_Key_LineEdit->setGeometry(QRect(220, 100, 81, 22));
        Bob_Public_Key_LineEdit->setReadOnly(true);
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(220, 130, 81, 22));
        lineEdit_3->setReadOnly(true);
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(130, 80, 31, 16));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(250, 80, 21, 16));
        label_13->setAlignment(Qt::AlignCenter);
        setBasePoint = new QPushButton(groupBox_3);
        setBasePoint->setObjectName(QString::fromUtf8("setBasePoint"));
        setBasePoint->setGeometry(QRect(380, 30, 75, 23));
        Shared_Key = new QLineEdit(groupBox_3);
        Shared_Key->setObjectName(QString::fromUtf8("Shared_Key"));
        Shared_Key->setGeometry(QRect(160, 160, 81, 22));
        Shared_Key->setReadOnly(true);
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 160, 81, 20));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 240, 381, 151));
        Alice_TextBrowser = new QTextBrowser(groupBox_5);
        Alice_TextBrowser->setObjectName(QString::fromUtf8("Alice_TextBrowser"));
        Alice_TextBrowser->setGeometry(QRect(10, 50, 360, 91));
        Alice_TextBrowser->setReadOnly(true);
        Alice_LineEdit = new QLineEdit(groupBox_5);
        Alice_LineEdit->setObjectName(QString::fromUtf8("Alice_LineEdit"));
        Alice_LineEdit->setGeometry(QRect(10, 20, 300, 22));
        Alice_SendMsg_Btn = new QPushButton(groupBox_5);
        Alice_SendMsg_Btn->setObjectName(QString::fromUtf8("Alice_SendMsg_Btn"));
        Alice_SendMsg_Btn->setGeometry(QRect(320, 20, 51, 21));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 400, 381, 150));
        Bob_TextBrowser = new QTextBrowser(groupBox_6);
        Bob_TextBrowser->setObjectName(QString::fromUtf8("Bob_TextBrowser"));
        Bob_TextBrowser->setGeometry(QRect(10, 50, 360, 91));
        Bob_LineEdit = new QLineEdit(groupBox_6);
        Bob_LineEdit->setObjectName(QString::fromUtf8("Bob_LineEdit"));
        Bob_LineEdit->setGeometry(QRect(10, 20, 300, 22));
        Bob_SendMsg_Btn = new QPushButton(groupBox_6);
        Bob_SendMsg_Btn->setObjectName(QString::fromUtf8("Bob_SendMsg_Btn"));
        Bob_SendMsg_Btn->setGeometry(QRect(320, 20, 51, 21));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(400, 360, 341, 191));
        Ops_TextBrowser = new QTextBrowser(groupBox_7);
        Ops_TextBrowser->setObjectName(QString::fromUtf8("Ops_TextBrowser"));
        Ops_TextBrowser->setEnabled(true);
        Ops_TextBrowser->setGeometry(QRect(10, 20, 321, 161));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(400, 240, 341, 111));
        Signature_Create = new QPushButton(groupBox_4);
        Signature_Create->setObjectName(QString::fromUtf8("Signature_Create"));
        Signature_Create->setGeometry(QRect(140, 70, 75, 23));
        Submit_Signature = new QPushButton(groupBox_4);
        Submit_Signature->setObjectName(QString::fromUtf8("Submit_Signature"));
        Submit_Signature->setGeometry(QRect(260, 40, 50, 23));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 40, 60, 20));
        Signature_R = new QLineEdit(groupBox_4);
        Signature_R->setObjectName(QString::fromUtf8("Signature_R"));
        Signature_R->setGeometry(QRect(110, 40, 60, 20));
        Signature_S = new QLineEdit(groupBox_4);
        Signature_S->setObjectName(QString::fromUtf8("Signature_S"));
        Signature_S->setGeometry(QRect(180, 40, 60, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 749, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Elliptic Curve and Field", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Parameter 'a':", nullptr));
        A_Param_LineEdit->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Parameter 'b':", nullptr));
        B_Param_LineEdit->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Modulus:", nullptr));
        Modulus_LineEdit->setText(QCoreApplication::translate("MainWindow", "997", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Maximum cofactor:", nullptr));
        Cofactor_LineEdit->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "ECDH", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Base Point:", nullptr));
        X_BPoint_LineEdit->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        X_BPoint_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "X coordinate", nullptr));
        BPoint_Generate_Btn->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Public keys:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Private keys:", nullptr));
        Keys_Generate_Btn->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        Y_BPoint_LineEdit->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Y_BPoint_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Y coordinate", nullptr));
        C_BPoint_LineEdit->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        C_BPoint_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Cofactor", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Alice", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Bob", nullptr));
        setBasePoint->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Shared Key:", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Alice Textbox", nullptr));
        Alice_SendMsg_Btn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Bob Textbox", nullptr));
        Bob_SendMsg_Btn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Operations", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "ECDSA", nullptr));
        Signature_Create->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        Submit_Signature->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Signature:", nullptr));
        Signature_R->setInputMask(QString());
        Signature_S->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
