#include "hexcell.h"

#include <cmath>


HexCell::HexCell(double x, double y,
                     std::string value,Board b, int vX, int vY,
                     QGraphicsPolygonItem * parent)
    : QGraphicsPolygonItem (parent),
      _x { x }, _y { y },
      _value { value },
      _vX{vX}, _vY{vY},
      _b{b},
      _c{}
{
    _c = _b.getColor(_vX,_vY);
    static const double pi_over_6 = atan(1) * 4 / 6;
    static const double r = 35;

    QPolygonF polygon;
    polygon << QPointF(r * cos(pi_over_6), r * sin(pi_over_6));
    polygon << QPointF(0, r);
    polygon << QPointF(-r * cos(pi_over_6), r * sin(pi_over_6));
    polygon << QPointF(-r * cos(pi_over_6), -r * sin(pi_over_6));
    polygon << QPointF(0, -r);
    polygon << QPointF(r * cos(pi_over_6), -r * sin(pi_over_6));
    setPolygon(polygon);
}


void HexCell::paint(QPainter * painter,
                      [[maybe_unused]] const QStyleOptionGraphicsItem * option,
                      [[maybe_unused]] QWidget * widget)
{
    QPen pen(QColor(128, 96, 68), 2);
    painter->setPen(pen);
    QBrush brush;
    switch (_c) {
    case WHITE:
        brush.setColor(Qt::white);
        break;
    case BLACK:
        brush.setColor(Qt::black);
        break;
    default:
        brush.setColor(QColor(195,155,119));
        break;
    }
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPolygon(polygon());
}

void HexCell::updateColor(){
    _c = _b.getColor(_vX,_vY);
    update();
}

void HexCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    event->accept();
    qDebug() << "receive mouse event, emit signal Hexagon";
    emit sendValue(_value);

}
















