#include "qtscenedrawer.h"
#include <qpainter.h>

QtSceneDrawer::QtSceneDrawer(QWidget* parent) : QWidget(parent) {
    this->scene = 0;
}

void QtSceneDrawer::draw(const Scene& scene) {
    this->scene = &scene;
    repaint();
}

void QtSceneDrawer::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, width() - 1, height() - 1);
    if (this->scene == 0) {
        return;
    }
    painter.setPen(Qt::white);
    for (std::shared_ptr<Figure> figure : this->scene->figures()) {
        for (Edge edge : figure->edges()) {
            Point begin = figure->transform(edge.begin().position());
            Point end = figure->transform(edge.end().position());
            painter.drawLine(begin.X() + width() / 2, height() / 2 - begin.Z(), end.X() + width() / 2, height() / 2 - end.Z());
        }
    }
}
