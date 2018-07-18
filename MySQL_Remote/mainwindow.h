#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString Text, int interval, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_OpenWorkbench_clicked();
    void on_pushButton_CloseWorkbench_clicked();
    void status();
    void PrintInterval();

private:
    QString password;
    int interval, currentInterval;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
