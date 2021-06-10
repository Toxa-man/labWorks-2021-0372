#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

    int typeFigure() const;    // Возвращение текщего типа
    void setTypeFigure(const int type);    // Установка текущего типа

    // Перечисление типов используемых фигур
    enum FigureTypes {SquareType, RombType, TriangleType};

signals:
    void typeFigureChanged();    // Сигнал об изменении типа текущей фигуры

private:
    // Объект для временного хранения рисуемой фигуры
    Figure *tempFigure;
    int my_typeFigure;   // Текущий тип фигуры

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
