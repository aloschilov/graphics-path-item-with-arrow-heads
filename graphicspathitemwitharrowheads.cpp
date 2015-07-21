//
// Created by Alexander Loshchilov on 7/20/15.
//

#include <QtCore>
#include <QtGui>
#include <QtDebug>
#include <math.h>
#include "graphicspathitemwitharrowheads.h"

GraphicsPathItemWithArrowHeads::GraphicsPathItemWithArrowHeads(QGraphicsItem *parent) :
        QGraphicsPathItem(parent)
{
    initializeArrowHeads();
}

GraphicsPathItemWithArrowHeads::GraphicsPathItemWithArrowHeads(const QPainterPath &path, QGraphicsItem *parent):
        QGraphicsPathItem(path, parent)
{
    initializeArrowHeads();
}

void GraphicsPathItemWithArrowHeads::paint(QPainter * painter,
                                           const QStyleOptionGraphicsItem * option,
                                           QWidget * widget) {
    QGraphicsPathItem::paint(painter, option, widget);

    QPainterPath currentPath = path();

    QPolygonF polygon = currentPath.toFillPolygon();

    QPointF thePointBefore = polygon.at(polygon.count() - 3);
    QPointF theLastPoint = polygon.at(polygon.count() - 2);
    QPointF endVector = theLastPoint - thePointBefore;

    qDebug() << thePointBefore << theLastPoint << endVector << atan2(endVector.x(), endVector.y());

    painter->translate(theLastPoint);
    painter->rotate(atan2(endVector.x(), endVector.y()) * 180.0 / M_PI);

    qreal arrowLength = 5.0;

    static const QPointF points[3] = {
            QPointF(-arrowLength, tan(10.0 * M_PI / 180.0) * arrowLength),
            QPointF(0.0, 0.0),
            QPointF(-arrowLength, -tan(10.0 * M_PI / 180.0) * arrowLength)
    };

    painter->drawPolygon(points, 3);
}

void GraphicsPathItemWithArrowHeads::initializeArrowHeads()
{
    isHeadArrowVisible = false;
    isTailArrowVisible = false;
}
