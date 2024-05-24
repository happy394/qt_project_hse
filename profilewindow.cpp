#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QDebug>


ProfileWindow::ProfileWindow(std::shared_ptr<Profile> db,QWidget *parent)
    : QDialog(parent)
    , profile(db)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}


void ProfileWindow::on_pushButton_clicked()
{
    profile ->setEmail(ui->EmailEdit->text());
    profile ->setPassword(ui->PasswordEdit->text());
    //qInfo(qUtf8Printable(profile->getEmail()));
    pqxx::work cursor(profile->connector);
    QString query = "INSERT INTO \"Profiles\" (email,Client_password) Values (\'' + profile->getEmail() + '\', \'' +  profile->getPassword() + '\')";
    cursor.exec(query.toStdString());
}

