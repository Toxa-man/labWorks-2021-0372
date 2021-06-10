#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>

#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PaintScene *scene;  // Объявляем наше поле для рисования
    QTimer *timer;      // Определяем таймер для подготовки актуальных размеров графической сцены

private:
    // Переопределяем событие изменения размера окна для пересчёта размеров графической сцены
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotTimer();
    void on_Romb_clicked();
    void on_Square_clicked();
    void on_Triagle_clicked();
};

#endif // MAINWINDOW_H
