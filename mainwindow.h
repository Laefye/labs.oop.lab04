#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "engine/facade.h"
#include "qtscenedrawer.h"
#include <QDoubleSpinBox>
#include "normalizationdialog.h"

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
    NormalizationDialog::Result normalization;

    void selectFile();
    void loadFile();
    void showError(QString message);
    void updateUi();
    void updateEnabled();
    void setPoint(QDoubleSpinBox* x, QDoubleSpinBox* y, QDoubleSpinBox* z, const Point& point);
    Point getPoint(QDoubleSpinBox* x, QDoubleSpinBox* y, QDoubleSpinBox* z);
    void openNormilizationDialog();
private slots:
    void setProjection();
    void setTransform();
};
#endif // MAINWINDOW_H
