#include "mainwindow.h"
#include "ui_mainwindowform.h"
#include "OSGWidget.h"
#include "sphereupdatecallback.h"
#include "UpdateBallPhysics.hpp"

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

}

void MainWindow::on_LaunchButton_clicked()
{
    mMainWindowUI->OSGOutput->sphere_setup(velocity, angle);
}

void MainWindow::on_VelocitySlider_sliderMoved(int position)
{
    velocity = position;
}

void MainWindow::on_AngleSlider_sliderMoved(int position)
{
    angle  = position;
}

void MainWindow::on_VelocitySlider_valueChanged(int value)
{
    velocity = value;
}

void MainWindow::on_AngleSlider_valueChanged(int value)
{
    angle  = value;
}
