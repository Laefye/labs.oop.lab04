#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QFileDialog>
#include <exception>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , drawer(this)
    , facade(&drawer)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->setFile, &QPushButton::clicked, this, &MainWindow::selectFile);
    connect(ui->load, &QPushButton::clicked, this, &MainWindow::loadFile);

    QGridLayout* layout = (QGridLayout*) this->centralWidget()->layout();
    layout->addWidget(&this->drawer, 1, 0, 2, 2);
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
    } catch (std::exception& e) {
        showError(e.what());
    }
}
