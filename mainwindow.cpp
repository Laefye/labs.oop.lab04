#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QFileDialog>
#include <exception>
#include <QMessageBox>
#include "engine/point.h"
#include "engine/exceptions/scenenotloadedexception.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , drawer(this)
    , facade(&drawer)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->setFile, &QPushButton::clicked, this, &MainWindow::selectFile);
    connect(ui->load, &QPushButton::clicked, this, &MainWindow::loadFile);
    connect(ui->positionX, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->positionY, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->positionZ, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->rotationX, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->rotationY, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->rotationZ, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->scaleX, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->scaleY, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->scaleZ, SIGNAL(valueChanged(double)), SLOT(setTransform()));
    connect(ui->scaleByAllAxis, SIGNAL(stateChanged(int)), SLOT(setTransform()));

    QGridLayout* layout = (QGridLayout*) this->centralWidget()->layout();
    layout->addWidget(&this->drawer, 1, 0, 1, 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showError(QString message) {
    QMessageBox box(this);
    box.setText(message);
    box.exec();
}

void MainWindow::setPoint(QDoubleSpinBox* x, QDoubleSpinBox* y, QDoubleSpinBox* z, const Point& point) {
    x->setValue(point.X());
    y->setValue(point.Y());
    z->setValue(point.Z());
}

Point MainWindow::getPoint(QDoubleSpinBox* x, QDoubleSpinBox* y, QDoubleSpinBox* z) {
    return Point(x->value(), y->value(),  z->value());
}

void MainWindow::setTransform() {
    updateEnabled();
    try {
        facade.setTransform(
            getPoint(ui->positionX, ui->positionY, ui->positionZ),
            getPoint(ui->rotationX, ui->rotationY, ui->rotationZ),
            getPoint(ui->scaleX, ui->scaleByAllAxis->isChecked() ? ui->scaleX : ui->scaleY, ui->scaleByAllAxis->isChecked() ? ui->scaleX : ui->scaleZ)
        );
    } catch (SceneNotLoadedException& e) {

    }
}

void MainWindow::updateUi() {
    Point position, rotation, scale;
    facade.getTransform(position, rotation, scale);
    setPoint(ui->positionX, ui->positionY, ui->positionZ, position);
    setPoint(ui->rotationX, ui->rotationY, ui->rotationZ, rotation);
    setPoint(ui->scaleX, ui->scaleY, ui->scaleZ, scale);
    updateEnabled();
}

void MainWindow::updateEnabled() {
    ui->positionX->setEnabled(facade.isLoaded());
    ui->positionY->setEnabled(facade.isLoaded());
    ui->positionZ->setEnabled(facade.isLoaded());
    ui->rotationX->setEnabled(facade.isLoaded());
    ui->rotationY->setEnabled(facade.isLoaded());
    ui->rotationZ->setEnabled(facade.isLoaded());
    ui->scaleX->setEnabled(facade.isLoaded());
    ui->scaleY->setEnabled(facade.isLoaded() && !ui->scaleByAllAxis->isChecked());
    ui->scaleZ->setEnabled(facade.isLoaded() && !ui->scaleByAllAxis->isChecked());
    ui->scaleByAllAxis->setEnabled(facade.isLoaded());
}

void MainWindow::selectFile() {
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("CSV (*.csv)");
    if (dialog.exec()) {
        QStringList selectedFiles = dialog.selectedFiles();
        ui->filename->setText(selectedFiles.first());
    }
}

void MainWindow::loadFile() {
    try {
        facade.loadScene(ui->filename->text().toStdString());
        updateUi();
    } catch (std::exception& e) {
        showError(e.what());
    }
}
