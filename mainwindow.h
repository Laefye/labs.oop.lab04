#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"
#include "qtscenedrawer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QtSceneDrawer drawer;
    Facade facade;
    Ui::MainWindow *ui;

    void selectFile();
    void loadFile();
    void showError(QString message);
};
#endif // MAINWINDOW_H
