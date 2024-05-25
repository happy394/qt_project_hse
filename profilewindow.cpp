#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QDebug>
#include <QMessageBox>



ProfileWindow::ProfileWindow(std::shared_ptr<Profile> db,QWidget *parent)
    : QDialog(parent)
    , profile(db)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);
    profile->connector.prepare("getData","SELECT email,client_password FROM profiles where email = $1 AND client_password = $2");
    profile->connector.prepare("setData", "INSERT INTO profiles (email,client_password) Values ($1,$2) On Conflict do nothing returning email");
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}



void ProfileWindow::on_RegistereButton_clicked()
{   QMessageBox box;
    profile ->setEmail(ui->EmailEdit->text());
    profile ->setPassword(ui->PasswordEdit->text());
    if (profile->getEmail() != "" and profile->getPassword() != ""){
        pqxx::work cursor(profile->connector);
        pqxx::result res = cursor.exec_prepared("setData",profile->getEmail().toStdString(),profile->getPassword().toStdString());
        cursor.commit();

        if (res.empty()){
            box.setText("User already exist");
            box.exec();
        }
        else{
            box.setText("Registred successfully");
            this->close();
            box.exec();
        }
    }
    else{
        box.setText("Don't use empty login or password");
        box.setIcon(QMessageBox::Critical);
        box.exec();
    }
}

bool ProfileWindow::logIn(QString email, QString password)
{
    profile ->setEmail(email);
    profile ->setPassword(password);
    pqxx::work cursor(profile->connector);
    pqxx::result data = cursor.exec_prepared("getData",profile->getEmail().toStdString(),profile->getPassword().toStdString());
    return not(data.empty());
}


void ProfileWindow::on_Login_Button_clicked()
{
    bool suc = logIn(ui->EmailEdit->text(),ui->PasswordEdit->text());
    QMessageBox box;
    if (suc){
        box.setText("Logged in successfully");
        box.setIcon(QMessageBox::Information);
        box.exec();
        this->close();
    }
    else{
        box.setText("Invalid email or password");
        box.setIcon(QMessageBox::Critical);
        box.exec();
    }

}


