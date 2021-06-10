#include "figure.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent) : QObject(parent), QGraphicsItem() {
    // Устанавливаем начальную координату для отрисовки фигуры
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    // Подключаем сигнал изменения координат к слоту запуска обновления содержимого объекта
    connect(this, &Figure::pointChanged, this, &Figure::updateFigure);
}

Figure::~Figure(){}

QRectF Figure::boundingRect() const {
    // Возвращаем область, в которой лежит фигура. Обновляемая область зависит от начальной и конечной точки
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateFigure() {
    // Вызываем обновление области, в которой лежит фигура
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point) {
    my_startPoint = mapFromScene(point);
    pointChanged();
}

void Figure::setEndPoint(const QPointF point) {
    my_endPoint = mapFromScene(point);
    pointChanged();
}

QPointF Figure::startPoint() const {
    return my_startPoint;
}

QPointF Figure::endPoint() const {
    return my_endPoint;
}
