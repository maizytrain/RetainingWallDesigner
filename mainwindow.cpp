#include "mainwindow.h"
#include "ui_mainwindowform.h"
#include "ui_RCCantileverForm.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow{parent},
    mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);

    //connect(mMainWindowUI->action, SIGNAL(triggered()), this, SLOT(actionExit_triggered()));
    connect(mMainWindowUI->actionNew_File, SIGNAL(triggered()), this, SLOT(create_new_wall()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::create_new_wall()
{
    create_rcc_wall();
}


void MainWindow::create_rcc_wall()
{
    mRccFormUI = new Ui::RCCantileverForm;
    mRccFormUI->setupUi(mMainWindowUI->dummyWidget);
}
