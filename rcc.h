#ifndef RCC_H
#define RCC_H

#include <QMainWindow>
#include "qgraphicsview.h"
#include <QtCore>

#include <QGuiApplication>

namespace Ui {class RCCantileverForm;}

class rcc : public QMainWindow
{
    Q_OBJECT

public:
    rcc(Ui::RCCantileverForm *form);
    ~rcc();

public slots:
    void update_drawing();
    void set_height();
    void set_width();
    void set_thickness();
    void set_extension();
    void set_depth();
    void set_embedment();

private:
    Ui::RCCantileverForm *mForm;
    QGraphicsView *view;
    QGraphicsScene *scene;

    float *height;
    float *width;
    float *thickness;
    float *extensionFront;
    float *extensionBack;
    float *depth;
    float *embedment;
};

#endif // RCC_H
