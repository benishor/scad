#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_action_Quit_triggered() {
    if (QMessageBox::question(this, "Quit", "Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
        close();
        qApp->quit();
    }
}

void MainWindow::writePositionSettings() {
    QSettings settings("benishor", "scad");

    settings.beginGroup("mainwindow");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("savestate", saveState());
    settings.setValue("maximized", isMaximized());
    if (!isMaximized()) {
        settings.setValue("pos", pos());
        settings.setValue("size", size());
    }

    settings.endGroup();
}

void MainWindow::readPositionSettings() {
    QSettings settings("benishor", "scad");

    settings.beginGroup("mainwindow");

    restoreGeometry(settings.value("geometry", saveGeometry()).toByteArray());
    restoreState(settings.value("savestate", saveState()).toByteArray());
    move(settings.value("pos", pos()).toPoint());
    resize(settings.value("size", size()).toSize());
    if (settings.value("maximized", isMaximized()).toBool())
        showMaximized();

    settings.endGroup();
}

void MainWindow::moveEvent(QMoveEvent*) {
    writePositionSettings();
}

void MainWindow::resizeEvent(QResizeEvent*) {
    writePositionSettings();
}

void MainWindow::closeEvent(QCloseEvent*) {
    writePositionSettings();
}
