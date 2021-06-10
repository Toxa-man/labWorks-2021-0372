#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    QPointF my_startPoint;    // Стартовая точка
    QPointF my_endPoint;    // Конечная точка
    QRectF boundingRect() const;    // Место, где находится фигура

public:
    explicit Figure(QPointF point, QObject *parent = nullptr);
    ~Figure();

    QPointF startPoint() const;    // Начальная точка
    QPointF endPoint() const;    // Конечная точка

    void setStartPoint(const QPointF point);    // Установка начальной точки
    void setEndPoint(const QPointF point);    // Установка конечной точки

public slots:
    void updateFigure();    // Слот обновления области, в которой находится фигура

signals:
    void pointChanged();    // Сигнал об изменении точки
};

#endif // FIGURE_H
