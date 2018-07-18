#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QString data, int interval, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTimer *timer_interval = new QTimer(this);
    connect(timer_interval, SIGNAL(timeout()), this, SLOT(PrintInterval()));
    timer_interval->start(1000);
    ui->setupUi(this);

    MainWindow::password = data;
    MainWindow::interval = interval;
    MainWindow::currentInterval = interval/1000;
    MainWindow::status();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_start_clicked()
{
    QApplication::setOverrideCursor(Qt::BusyCursor);
    QString str = "echo ";
    str += MainWindow::password;
    str += " | sudo -S /usr/local/mysql/support-files/mysql.server start";
    QByteArray ba = str.toLatin1();
    system(ba.data());
    MainWindow::status();
}

void MainWindow::on_pushButton_stop_clicked()
{
    QApplication::setOverrideCursor(Qt::BusyCursor);
    QString str = "echo ";
    str += MainWindow::password;
    str += " | sudo -S /usr/local/mysql/support-files/mysql.server stop";
    QByteArray ba = str.toLatin1();
    system(ba.data());
    MainWindow::status();
}

void MainWindow::on_pushButton_OpenWorkbench_clicked()
{
    system("open -Fna /Applications/MySQLWorkbench.app/Contents/MacOS/MySQLWorkbench");
}

void MainWindow::on_pushButton_CloseWorkbench_clicked()
{
    system("osascript -e 'quit app \"MySQLWorkbench\"'");
}

void MainWindow::status()
{
    ui->status->clear();
    QString str = "echo ";
    str += MainWindow::password;
    str += " | sudo -S /usr/local/mysql/support-files/mysql.server status";
    QByteArray ba = str.toLatin1();
    int check = system(ba.data());
    if (check == 0)
    {
        ui->status->setText("Running");
        ui->status->setStyleSheet("QLabel { font-size:20pt; font-weight:600; color : green }");
        ui->status->adjustSize();
    }
    else
    {
        ui->status->setText("Stopped");
        ui->status->setStyleSheet("QLabel { font-size:20pt; font-weight:600; color : red }");
        ui->status->adjustSize();
    }
    QApplication::setOverrideCursor(Qt::ArrowCursor);
}
void MainWindow::PrintInterval()
{
    ui->update->clear();
    MainWindow::currentInterval -= 1;
    if (MainWindow::currentInterval == 0)
    {
        ui->update->setText("updated");
        status();
    }
    else if (MainWindow::currentInterval < 0)
    {
        MainWindow::currentInterval = MainWindow::interval/1000;
    }
}


