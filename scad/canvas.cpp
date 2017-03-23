#include "canvas.h"
#include <QMouseEvent>
#include <QPainter>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    // otherwise we do not get MouseMove events without pressing a mouse button
    setMouseTracking(true);
}


static bool isPanning = false;
static QPoint initialMousePos;
static QPoint currentMousePos;
static QPoint panOffset;

void Canvas::mousePressEvent(QMouseEvent *event) {
    isPanning = true;
    initialMousePos = event->pos();
    this->setCursor(QCursor(Qt::CrossCursor));
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));
    if (isPanning) {
        isPanning = false;
        panOffset += event->pos() - initialMousePos;
        currentMousePos = initialMousePos = QPoint(0, 0);
        repaint();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if (isPanning) {
        currentMousePos = event->pos();
        repaint();
    }
}


void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // draw background
    QBrush backgroundBrush;
    backgroundBrush.setStyle(Qt::SolidPattern);
    backgroundBrush.setColor(QColor(25, 50, 75, 255));
    painter.fillRect(QRectF(0, 0, this->width(), this->height()), backgroundBrush);

    // draw grid
    painter.setPen(QPen(QColor(205, 205, 255, 35), 1, Qt::DashLine));

    int cellWidth = 40;
    int cellHeight = 40;

    int x = 0;
    int y = 0;

    QPoint currentOffset = isPanning ?
                           panOffset + (currentMousePos - initialMousePos) :
                           panOffset;

    if (currentOffset.x() < 0) {
        x = 0 - (abs(currentOffset.x()) % cellWidth);
    } else {
        x = 0 - (cellWidth - (currentOffset.x() % cellWidth));
    }

    if (currentOffset.y() < 0) {
        y = 0 - (abs(currentOffset.y()) % cellHeight);
    } else {
        y = 0 - (cellHeight - (currentOffset.y() % cellHeight));
    }


    for (; x < this->width(); x+=cellWidth) {
        painter.drawLine(QLineF(QPoint(x, 0),
                                QPoint(x, this->height())));
    }
    for (; y < this->height(); y+=cellHeight) {
        painter.drawLine(QLineF(QPoint(0, y),
                                QPoint(this->width(), y)));
    }


    painter.end();
}
