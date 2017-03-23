#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void writePositionSettings();
    void readPositionSettings();

protected:
    void moveEvent(QMoveEvent*);
    void resizeEvent(QResizeEvent*);
    void closeEvent(QCloseEvent*);

private slots:
    void on_action_Quit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
