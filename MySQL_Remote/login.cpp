#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString str = "echo ";
    str += ui->password->text();
    str += " | sudo -S su";
    QByteArray ba = str.toLatin1();
    int check = system(ba.data());
    if (check == 0)
    {
    openMainWindow();
    this->close();
    }
    else
    {
        ui->password->clear();
        ui->error->setText("Error: incorrect password");
        ui->error->setStyleSheet("QLabel { color : red }");
    }
}
void Login::openMainWindow()
{
    NewMainWindow = new MainWindow(ui->password->text(), ui->interval->value());
    NewMainWindow->show();
}

void Login::on_password_returnPressed()
{
    Login::on_pushButton_clicked();
}
