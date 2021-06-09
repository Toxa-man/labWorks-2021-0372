#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classes.h"
#include "additions.h"

Domain domain;
User Alice {
    "Alice", &domain
};
User Bob {
    "Bob", &domain
};
AES Alice_aes, Bob_aes;
std::string signedText = "";
bool sign = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Alice_LineEdit, SIGNAL(returnPressed()), ui->Alice_SendMsg_Btn, SIGNAL(clicked()));
    connect(ui->Bob_LineEdit, SIGNAL(returnPressed()), ui->Bob_SendMsg_Btn, SIGNAL(clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int a = ui->A_Param_LineEdit->text().toInt();
    int b = ui->B_Param_LineEdit->text().toInt();
    int p = ui->Modulus_LineEdit->text().toInt();
    int c = ui->Cofactor_LineEdit->text().toInt();

    if (4 * pow(a, 3) + 27 * pow(b, 2)==0){
        Log("The elliptic curve is singular. It can't be used in cryptography!", 0);
    } else if (!isPrime(p)){
        Log("Modulus isn't prime!", 0);
    } else if (c < 3){
        Log("Maximum Cofactor can't be less than 3", 0);
    } else {
        domain.SetParams(a, b, p, c);
        Log("Domain was set!\n-----", 1);
    }
}

void MainWindow::on_BPoint_Generate_Btn_clicked()
{
    if (domain.cardinality != 0) {
        Log("Generating base point...", 2);
        if (domain.generate_basepoint()) {
            ui->C_BPoint_LineEdit->setText(QString::number(domain.cofactor));
            ui->X_BPoint_LineEdit->setText(QString::number(domain.base_point[0]));
            ui->Y_BPoint_LineEdit->setText(QString::number(domain.base_point[1]));
            Log("Base point was generated!\n-----", 1);
        } else {
            Log("Base point cannot be found. Try another curve or change max cofactor.", 2);
        }
    } else {
        Log("Domain parameters are not set!", 2);
    }
}

void MainWindow::on_Keys_Generate_Btn_clicked()
{
    if (!domain.base_point.is_inf()) {
        Log("Creating Users's keys...", 2);
        Alice.generate_keys();
        Bob.generate_keys();
        Alice.create_shared_key(Bob.public_key);
        Bob.create_shared_key(Alice.public_key);
        Log("Users's keys were created!\n-----", 1);

        Alice_aes.SetParams(std::to_string(Alice.get_sharedkey()[0]), 16);
        Bob_aes.SetParams(std::to_string(Bob.get_sharedkey()[0]), 16);

        std::string Alice_PK = "(" + std::to_string(Alice.public_key[0]) + "; " + std::to_string(Alice.public_key[1])+")";
        ui->PublicKey_LineEdit->setText(QString::fromStdString(Alice_PK));

        std::string Bob_PK = "(" + std::to_string(Bob.public_key[0]) + "; " + std::to_string(Bob.public_key[1])+")";
        ui->Bob_Public_Key_LineEdit->setText(QString::fromStdString(Bob_PK));

        ui->PrivateKey_LineEdit->setText(QString::number(Alice.get_privatekey()));
        ui->lineEdit_3->setText(QString::number(Bob.get_privatekey()));

        std::string Shared_Key = "(" + std::to_string(Alice.get_sharedkey()[0]) + "; " + std::to_string(Alice.get_sharedkey()[1])+")";
        ui->Shared_Key->setText(QString::fromStdString(Shared_Key));

    } else {
        Log("Create a base point first!", 2);
    }
}

void MainWindow::on_Alice_SendMsg_Btn_clicked()
{
    std::string plain = ui->Alice_LineEdit->text().toStdString();

    if (plain == "") {
        return;
    }

    std::string cipheredPlain, decipheredPlain, recoveredPlain;
    ui->Alice_TextBrowser->append("Alice: " + QString::fromStdString(plain));

    if (!Alice.get_sharedkey().is_inf()) {
        if (signedText == "") {
            signedText = plain;
        }
        Alice_aes.encrypt(signedText, cipheredPlain);
        Log("The message was encrypted: " + Alice_aes.decode_cipher(cipheredPlain) + "\n---", 2);

        Bob_aes.decrypt(cipheredPlain, decipheredPlain);
        if (sign) {
            if (Bob.check_signature(Alice.public_key, decipheredPlain, recoveredPlain)) {
                Log("Signature is correct!\n-----", 1);
                ui->Bob_TextBrowser->append(QString::fromStdString("Alice: " + recoveredPlain));
            } else {
                Log("Signature is incorrect!\n-----", 0);
            }
        } else {
            ui->Bob_TextBrowser->append(QString::fromStdString("Alice: " + decipheredPlain));
        }
    } else {
        ui->Bob_TextBrowser->append("Alice: " + QString::fromStdString(plain));
    }

    ui->Alice_LineEdit->clear();
    signedText = "";
    sign = 0;
}

void MainWindow::on_Bob_SendMsg_Btn_clicked()
{
    std::string plain = ui->Bob_LineEdit->text().toStdString();

    if (plain == "") {
        return;
    }

    std::string cipheredPlain, decipheredPlain, recoveredPlain;
    ui->Bob_TextBrowser->append("Bob: " + QString::fromStdString(plain));

    if (!Bob.get_sharedkey().is_inf()) {
        if (signedText == "") {
            signedText = plain;
        }
        Bob_aes.encrypt(signedText, cipheredPlain);
        Log("The message was encrypted: " + Bob_aes.decode_cipher(cipheredPlain) + "\n---", 2);

        Alice_aes.decrypt(cipheredPlain, decipheredPlain);
        if (sign) {
            if (Alice.check_signature(Bob.public_key, decipheredPlain, recoveredPlain)) {
                Log("Signature is correct!\n-----", 1);
                ui->Alice_TextBrowser->append(QString::fromStdString("Bob: " + recoveredPlain));
            } else {
                Log("Signature is incorrect!\n-----", 0);
            }
        } else {
            ui->Alice_TextBrowser->append(QString::fromStdString("Bob: " + decipheredPlain));
        }
    } else {
        ui->Alice_TextBrowser->append("Bob: " + QString::fromStdString(plain));
    }

    ui->Bob_LineEdit->clear();
    signedText = "";
    sign = 0;
}

void MainWindow::on_setBasePoint_clicked()
{
    if (domain.cardinality != 0) {
        if (domain.set_basepoint(ui->X_BPoint_LineEdit->text().toInt(),ui->Y_BPoint_LineEdit->text().toInt(), ui->C_BPoint_LineEdit->text().toInt())) {
            Log("The base point was set!\n-----", 1);
        } else {
            Log("The base point is invalid!", 0);
        }
    } else {
        Log("Domain parameters is not set!", 2);
    }
}

void MainWindow::on_Signature_Create_clicked()
{
   int r, s;
   std::string plain;
   if (ui->Alice_LineEdit->text() != "") {
       plain = ui->Alice_LineEdit->text().toStdString();
       Alice.create_signature(plain);
       Alice.get_signature(r, s);
       Log("The signature was created: (" + std::to_string(r) + "; " + std::to_string(s) + ")", 2);
       ui->Signature_R->setText(QString::number(r));
       ui->Signature_S->setText(QString::number(s));
   } else if (ui->Bob_LineEdit->text() != "") {
       plain = ui->Bob_LineEdit->text().toStdString();
       Bob.create_signature(plain);
       Bob.get_signature(r, s);
       Log("The signature was created: (" + std::to_string(r) + "; " + std::to_string(s) + ")", 2);
       ui->Signature_R->setText(QString::number(r));
       ui->Signature_S->setText(QString::number(s));
   }
}

void MainWindow::on_Submit_Signature_clicked()
{
    int r, s;
    std::string plain;
    r = ui->Signature_R->text().toInt();
    s = ui->Signature_S->text().toInt();
    if (ui->Alice_LineEdit->text() != "") {
        plain = ui->Alice_LineEdit->text().toStdString();
        Alice.sign_message(plain, signedText, r, s);
        Log("The message was signed with (" + std::to_string(r) + "; " + std::to_string(s) + ")", 2);
        sign = 1;
    } else if (ui->Bob_LineEdit->text() != "") {
        plain = ui->Bob_LineEdit->text().toStdString();
        Bob.sign_message(plain, signedText, r, s);
        Log("The message was signed with (" + std::to_string(r) + "; " + std::to_string(s) + ")", 2);
        sign = 1;
    }
    ui->Signature_R->clear();
    ui->Signature_S->clear();
}

void MainWindow::Log(std::string msg, short int code) {
    if (code == 0) {
        msg = "ERROR: " + msg;
    } else if (code == 1) {
        msg = "SUCCESS: " + msg;
    } else if (code == 2) {
        msg = "INFO: " + msg;
    }
    ui->Ops_TextBrowser->append(QString::fromStdString(msg));
}
