#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "filereader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    NormalizationParameters params;
    FileReader reader;
    reader.read("/home/laefye/Downloads/meow.csv", params);
}

MainWindow::~MainWindow()
{
    delete ui;
}
