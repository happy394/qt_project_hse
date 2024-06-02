#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>

ProfileWindow::ProfileWindow(std::shared_ptr<Profile> db,QWidget *parent)
    : QDialog(parent)
    , profile(db)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);
    // profile->connector.prepare("getData","SELECT email,client_password FROM profiles where email = $1 AND client_password = $2");
    // profile->connector.prepare("setData", "INSERT INTO profiles (email,client_password) Values ($1,$2) On Conflict do nothing returning email");
    // profile->connector.prepare("getFavourites", "SELECT car_id FROM _favourites WHERE email = $1");
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}

void ProfileWindow::on_RegistereButton_clicked()
{
    // QMessageBox box;
    profile ->setEmail(ui->EmailEdit->text());
    profile ->setPassword(ui->PasswordEdit->text());
    if (profile->getEmail() != "" and profile->getPassword() != ""){
        QSqlQuery query(profile->db);
        if (profile->db.isOpen())
        {
            if (query.prepare("INSERT INTO profiles (email, password) Values (:email, :password)"))
            {
                query.bindValue(":email", profile->getEmail());
                query.bindValue(":password", profile->getPassword());
                if (query.exec())
                {

                    QMessageBox::information(this, "Success", "Registred successfully");
                    this->close();
                }
                else
                {
                    qDebug() << "Query did not execute due to: " << query.lastError().text();
                    QMessageBox::critical(this, "Duplicate data", "User already exist");
                }
            }
            else
            {
                qDebug() << "Query not prepared due to the following error: " << query.lastError().text();
            }
        }
        else
        {
            qDebug() << "Database not opened due to: " << profile->db.lastError().text();
            QMessageBox::information(this, "Database not open", "Not opened successfully");
        }



        // pqxx::work cursor(profile->connector);
        // pqxx::result res = cursor.exec_prepared("setData",profile->getEmail().toStdString(),profile->getPassword().toStdString());
        // cursor.commit();

        // if (res.empty()){
        // {
        //     box.setText("User already exist");
        //     box.exec();
        // }
        // else{
        //     ;
        //     ox.setText("Registred successfully");
        //     this->close();
        //     box.exec();
        // }
    }
    else{
        QMessageBox::critical(this, "Invalid input", "Don't use empty login or password");
        // box.setText("Don't use empty login or password");
        // box.setIcon(QMessageBox::Critical);
        // box.exec();
    }
}

bool ProfileWindow::logIn(QString email, QString password)
{
    profile ->setEmail(email);
    profile ->setPassword(password);
    QSqlQuery query(profile->db);
    if (profile->db.isOpen())
    {
        if (query.prepare("SELECT email, password FROM profiles WHERE (email = :email AND password = :password)"))
        {
            query.bindValue(":email", profile->getEmail());
            query.bindValue(":password", profile->getPassword());
            if (query.exec())
            {
                query.next();
                bool l = !query.value(0).isNull();
                return l;
            }
            else
            {
                qDebug() << "Query did not execute due to: " << query.lastError().text();
                QMessageBox::information(this, "Query did not execute", "Not successful executing the query");
            }
        }
        else
        {
            qDebug() << "Query not prepared due to the following error: " << query.lastError().text();
        }
    }
    else
    {
        qDebug() << "Database not opened due to: " << profile->db.lastError().text();
        QMessageBox::information(this, "Database not open", "Not opened successfully");
    }

    return false;

    // pqxx::work cursor(profile->connector);
    // pqxx::result data = cursor.exec_prepared("getData",profile->getEmail().toStdString(),profile->getPassword().toStdString());
    // return not(data.empty());
}


void ProfileWindow::on_Login_Button_clicked()
{
    bool suc = logIn(ui->EmailEdit->text(),ui->PasswordEdit->text());
    // QMessageBox box;
    if (suc){
        QMessageBox::information(this, "Logged in", "Logged in successfully");
        // box.setText("Logged in successfully");
        // box.setIcon(QMessageBox::Information);
        // box.exec();
        QSqlQuery query(profile->db);
        if (profile->db.isOpen())
        {
            if (query.prepare("SELECT car_id FROM favourites WHERE email = :email"))
            {
                query.bindValue(":email", profile->getEmail());
                if (query.exec())
                {
                    QSettings settings("drumdrum");
                    settings.setValue("id", profile->getEmail());
                    qInfo() << settings.value("id");
                    // pqxx::work cursor(profile->connector);
                    // pqxx::result _favourites = cursor.exec_prepared("getFavourites",profile->getEmail().toStdString());
                    // for (const auto &car : _favourites){
                    while(query.next())
                    {
                        profile->addFavourite(query.value(0).toInt()); // 0 because of only car_id column was executed
                    }
                }
                else
                {
                    qDebug() << "Query did not execute due to: " << query.lastError().text();
                    QMessageBox::information(this, "Query did not execute", "Not successful executing the query");
                }
            }
            else
            {
                qDebug() << "Query not prepared due to the following error: " << query.lastError().text();
            }
        }
        else
        {
            qDebug() << "Database not opened due to: " << profile->db.lastError().text();
            QMessageBox::information(this, "Database not open", "Not opened successfully");
        }
        this->close();
    }
    else{
        QMessageBox::critical(this, "Wrong input", "Invalid email or password");
        // box.setText("Invalid email or password");
        // box.setIcon(QMessageBox::Critical);
        // box.exec();
    }
}


