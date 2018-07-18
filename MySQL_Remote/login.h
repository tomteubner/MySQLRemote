#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    void openMainWindow();
    ~Login();
    MainWindow *NewMainWindow;

private slots:
    void on_pushButton_clicked();

    void on_password_returnPressed();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
