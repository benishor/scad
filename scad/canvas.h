#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget {
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
signals:

public slots:
};

#endif // CANVAS_H
