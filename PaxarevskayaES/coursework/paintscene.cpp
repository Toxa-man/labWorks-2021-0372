#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}

PaintScene::~PaintScene() {}

int PaintScene::typeFigure() const {
    return my_typeFigure;
}

void PaintScene::setTypeFigure(const int type) {
    my_typeFigure = type;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    // Устанавливаем конечную координату положения мыши в текущую отрисовываемую фигуру
    tempFigure->setEndPoint(event->scenePos());
    // Обновляем содержимое сцены, необходимо для устранения артефактов при отрисовке фигур
    this->update(QRectF(0,0,this->width(), this->height()));
}

// После нажатия кнопку мыши, создаём одну из 3 фигур и помещаем её на наше поле, сохранив указатель на неё в переменной *tempFigure
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    switch (my_typeFigure) {
    case SquareType: {
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    default:{
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    }
    this->addItem(tempFigure);
}
