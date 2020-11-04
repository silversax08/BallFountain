#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
class MainWindowForm;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void on_actionExit_triggered();
private slots:
    void on_LaunchButton_clicked();
    void on_VelocitySlider_sliderMoved(int position);
    void on_AngleSlider_sliderMoved(int position);
    void on_VelocitySlider_valueChanged(int value);
    void on_AngleSlider_valueChanged(int value);
private:
    Ui::MainWindowForm *mMainWindowUI;
    int velocity{7};
    int angle{0};
};

#endif // MAINWINDOW_H
