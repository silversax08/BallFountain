#include "mainwindow.h"
#include "ui_mainwindowform.h"
#include "OSGWidget.h"
#include "sphereupdatecallback.h"
#include "BallMotion.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);
//    mMainwindowUI->pushButton;
}

MainWindow::~MainWindow()
{
    delete mMainWindowUI;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    mMainWindowUI->OSGOutput->sphere_setup();
}
