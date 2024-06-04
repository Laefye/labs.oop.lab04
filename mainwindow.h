#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"
#include "qtscenedrawer.h"
#include <QDoubleSpinBox>

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
    void updateUi();
    void setPoint(QDoubleSpinBox* x, QDoubleSpinBox* y, QDoubleSpinBox* z, const Point& point, bool enabled);
    Point getPoint(QDoubleSpinBox* x, QDoubleSpinBox* y, QDoubleSpinBox* z);
private slots:
    void setTransform();
};
#endif // MAINWINDOW_H
