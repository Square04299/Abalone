#include "hexcell.h"

#include <cmath>

#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

HexCell::HexCell(double x, double y,
                     std::string value,Color c,
                     QGraphicsPolygonItem * parent)
    : QGraphicsPolygonItem (parent),
      _x { x }, _y { y },
      _value { value },
      _c{c}
{
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
    QPen pen(Qt::black, 1);
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


void HexCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    event->accept();
    qDebug() << "receive mouse event, emit signal Hexagon";
    emit sendValue(_value);

}

