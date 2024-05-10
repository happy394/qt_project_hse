#include "loginwindow.h"
#include "ui_loginwindow.h"
// #include "database.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginBar_textChanged(const QString &arg1)
{
    login = arg1;
}


void LoginWindow::on_PasswordBar_textChanged(const QString &arg1)
{
    password = arg1;
}


void LoginWindow::on_CheckUser_clicked()
{
    // user currUser
    // checkUser()
}

