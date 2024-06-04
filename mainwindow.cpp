#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , drawer(this)
    , facade(&drawer)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    facade.loadScene("/home/laefye/Downloads/meow.csv");
    QGridLayout* layout = (QGridLayout*) this->centralWidget()->layout();
    layout->addWidget(&this->drawer, 1, 0, 2, 1);
    facade.draw();
}

MainWindow::~MainWindow()
{
    delete ui;
}
