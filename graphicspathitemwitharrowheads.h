//
// Created by Alexander Loshchilov on 7/20/15.
//

#ifndef GRAPHICS_PATH_ITEM_WITH_ARROWS_GRAPHICSPATHITEMWITHARROWHEADS_H
#define GRAPHICS_PATH_ITEM_WITH_ARROWS_GRAPHICSPATHITEMWITHARROWHEADS_H


#include <QtWidgets/qgraphicsitem.h>

class GraphicsPathItemWithArrowHeads : public QGraphicsPathItem
{
public:
    GraphicsPathItemWithArrowHeads(QGraphicsItem *parent=0);
    GraphicsPathItemWithArrowHeads(const QPainterPath &path, QGraphicsItem * parent = 0);

    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
protected:
    void initializeArrowHeads();
    bool isHeadArrowVisible;
    bool isTailArrowVisible;
};


#endif //GRAPHICS_PATH_ITEM_WITH_ARROWS_GRAPHICSPATHITEMWITHARROWHEADS_H
