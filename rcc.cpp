#include "rcc.h"
#include "ui_RCCantileverForm.h"
#include "concreteDrawer.h"
#include <QDebug>

rcc::rcc(Ui::RCCantileverForm *form)
{
    mForm = form;
    view = form->graphicsView;
    scene = new QGraphicsScene;
    view->setScene(scene);

    height = new float(0);
    width = new float(0);
    thickness = new float(0);
    extensionFront = new float(0);
    extensionBack = new float(0);
    depth = new float(0);
    embedment = new float(0);
    angle = new float(0);

    connect(mForm->heightSpin, SIGNAL(valueChanged(double)), this, SLOT(set_height()));
    connect(mForm->widthSpin, SIGNAL(valueChanged(double)), this, SLOT(set_width()));
    connect(mForm->thicknessSpin, SIGNAL(valueChanged(double)), this, SLOT(set_thickness()));
    connect(mForm->extensionSpin, SIGNAL(valueChanged(double)), this, SLOT(set_extension()));
    connect(mForm->depthSpin, SIGNAL(valueChanged(double)), this, SLOT(set_depth()));
    connect(mForm->embedmentSpin, SIGNAL(valueChanged(double)), this, SLOT(set_embedment()));
    connect(mForm->angleSpin, SIGNAL(valueChanged(double)), this, SLOT(set_angle()));

    view->scale(1,-1);
}

rcc::~rcc()
{
    delete mForm;
    delete view;
    delete scene;
    delete height;
    delete width;
    delete thickness;
    delete extensionFront;
    delete extensionBack;
    delete depth;
    delete embedment;
}

void rcc::update_drawing()
{
    std::vector<float> xpoints;
    std::vector<float> ypoints;

    xpoints.push_back(0);
    ypoints.push_back(0);

    xpoints.push_back(0);
    ypoints.push_back(*depth/12);

    xpoints.push_back(*extensionFront);
    ypoints.push_back(ypoints[1]);

    xpoints.push_back(xpoints[2]);
    ypoints.push_back(*height);

    xpoints.push_back(xpoints[3]+(*thickness/12));
    ypoints.push_back(*height);

    xpoints.push_back(xpoints[4]);
    ypoints.push_back(ypoints[1]);

    xpoints.push_back(*width);
    ypoints.push_back(ypoints[1]);

    xpoints.push_back(*width);
    ypoints.push_back(0);

    for (int i{0}; i < xpoints.size(); i++)
    {
        xpoints[i] *= 50;
        ypoints[i] *= 50;
    }

    DrawLines(scene, xpoints, ypoints, *embedment, *angle);

    //view->fitInView((-(*height)*.1), (-(*width)*.1), *height * 1.1, *width * 1.1);
    scene->setSceneRect(QRectF((-(*width)*10), (-(*height)*10), *width * 70, *height * 70));
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void rcc::set_height()
{
    *height = mForm->heightSpin->value();
    update_drawing();
}

void rcc::set_width()
{
    *width = mForm->widthSpin->value();
    update_drawing();
}

void rcc::set_thickness()
{
    *thickness = mForm->thicknessSpin->value();
    set_extension();
    update_drawing();
}

void rcc::set_extension()
{
    *extensionFront = mForm->extensionSpin->value();
    *extensionBack = *width - *thickness - *extensionFront;
    update_drawing();
}

void rcc::set_depth()
{
    *depth = mForm->depthSpin->value();
    update_drawing();
}

void rcc::set_embedment()
{
    *embedment = mForm->embedmentSpin->value();
    update_drawing();
}

void rcc::set_angle()
{
    *angle = mForm->angleSpin->value();
    update_drawing();
}
