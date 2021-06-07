#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Log(std::string, short int);

    void on_pushButton_clicked();

    void on_BPoint_Generate_Btn_clicked();

    void on_Keys_Generate_Btn_clicked();

    void on_Alice_SendMsg_Btn_clicked();

    void on_Bob_SendMsg_Btn_clicked();

    void on_setBasePoint_clicked();

    void on_Signature_Create_clicked();

    void on_Submit_Signature_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
