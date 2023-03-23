#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

#include <QGuiApplication>
#include <QTreeWidgetItem>

namespace Ui {class MainWindowForm;}
namespace Ui {class RCCantileverForm;}

class rcc;

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void create_rcc_wall();

public slots:
    //void actionExit_triggered();
    void create_new_wall();

private:
    Ui::MainWindowForm *mMainWindowUI;
    Ui::RCCantileverForm *mRccFormUI;
    rcc *mRcc;
};

#endif // MAINWINDOW_H
