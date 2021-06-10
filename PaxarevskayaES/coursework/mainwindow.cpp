#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new PaintScene();   // Инициализируем наше поле
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Чтобы линии фигур не были пиксельными, установим сглаживание

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::slotTimer() {
    // Переопределяем размеры графической сцены в зависимости от размеров окна
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_Romb_clicked() {
    scene->setTypeFigure(PaintScene::RombType);
}

void MainWindow::on_Square_clicked() {
    scene->setTypeFigure(PaintScene::SquareType);
}

void MainWindow::on_Triagle_clicked() {
    scene->setTypeFigure(PaintScene::TriangleType);
}
