#include "offerwindow.h"
#include "ui_offerwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include "mainwindow.h"



OfferWindow::OfferWindow(std::shared_ptr<Profile> profile, car currCar, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OfferWindow)
    , profile (profile)
    , currCar(currCar)
    , carInfoModel(new QStringListModel)
    , carName(new QStringListModel)
{
    ui->setupUi(this);
    carInfoModel->setStringList({currCar.getCarInfo()});
    carName->setStringList({currCar.getCarName()});
    ui->CarInfo->setModel(carInfoModel);
    ui->CarName->setModel(carName);
    // profile->connector.prepare("setFavourite", "INSERT INTO _favourites (email,car_id) Values ($1,$2) On Conflict do nothing returning email");
}


OfferWindow::~OfferWindow()
{
    delete ui;
}

void OfferWindow::on_FavoriteButton_clicked()
{
    if (profile->getEmail() == ""){
        QMessageBox::critical(this, "Not logged in", "Please log in into account");
        // QMessageBox box;
        // box.setText("Please log in into account");
        // box.setIcon(QMessageBox::Critical);
        // box.exec();
    }
    else {
        if (profile->getFavourites().contains(currCar.id))
        {
            QMessageBox::critical(this, "Duplicate data", "This car is already in your favourites");
            // QMessageBox box;
            // box.setText("This car is already in your _favourites");
            // box.setIcon(QMessageBox::Critical);
            // box.exec();
        }
        else
        {
            profile->addFavourite(currCar.id);
            QSqlQuery query(profile->db);
            if (profile->db.isOpen())
            {
                if (query.prepare("INSERT INTO favourites (email, car_id) VALUES (:email, :car_id)"))
                {
                    query.bindValue(":email", profile->getEmail());
                    query.bindValue(":car_id", currCar.id);
                    if (query.exec())
                        QMessageBox::information(this, "Success", "Car added to favourites successfully");
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
        }

        /*pqxx::work cursor(profile->connector);
        pqxx::result res = cursor.exec_prepared("setFavourite",profile->getEmail().toStdString(),currCar.id);
        cursor.commit();*/
    }
}

//definetly not copied from happy
void OfferWindow::on_pushButton_clicked()
{
    if (profile->getEmail() == ""){
        QMessageBox::critical(this, "Not logged in", "Please log in into account");

    }
    else {
        if (not(profile->getFavourites().contains(currCar.id)))
        {
            QMessageBox::critical(this, "Duplicate data", "This car is not in your favourites");

        }
        else
        {
            profile->removeFavourite(currCar.id);
            QSqlQuery query(profile->db);
            if (profile->db.isOpen())
            {
                if (query.prepare("DELETE FROM favourites WHERE email = :email AND car_id = :car_id "))
                    //SELECT car_id FROM favourites WHERE email = :email"
                {
                    query.bindValue(":email", profile->getEmail());
                    query.bindValue(":car_id", currCar.id);

                    if (query.exec()){
                        QMessageBox::information(this, "Success", "Car removed from favourites successfully");
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
        }
    }
}

