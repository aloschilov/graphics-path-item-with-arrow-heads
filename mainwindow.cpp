//
// Created by Alexander Loshchilov on 7/20/15.
//

#include <QtWidgets>
#include "mainwindow.h"
#include "graphicspathitemwitharrowheads.h"

MainWindow::MainWindow()
{
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);
    setCentralWidget(view);

    QPainterPath path;
    path.moveTo(0, 0);
    path.cubicTo(99, 0,  50, 50,  99, 99);

    QTransform transform;
    transform.translate(150, 150);

    scene->addItem(new GraphicsPathItemWithArrowHeads(path));
    scene->addItem(new QGraphicsPolygonItem(path.toFillPolygon(transform)));
}
