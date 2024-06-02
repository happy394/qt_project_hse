#include "offerwindow.h"
#include "ui_offerwindow.h"
#include <QMessageBox>


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
    // profile->connector.prepare("setFavourite", "INSERT INTO favourites (email,car_id) Values ($1,$2) On Conflict do nothing returning email");

}


OfferWindow::~OfferWindow()
{
    delete ui;
}

void OfferWindow::on_FavoriteButton_clicked()
{
    if (profile->getEmail() == ""){
        QMessageBox box;
        box.setText("Please log in into account");
        box.setIcon(QMessageBox::Critical);
        box.exec();
    }
    else {
    profile->addFavourite(currCar.id);
    QSqlQuery query;
    query.prepare("INSERT INTO favourites (email,car_id) Values (:email, :car_id)");
    query.bindValue(":email", profile->getEmail());
    query.bindValue(":car_id", currCar.id);
    query.exec();
    profile->db.commit();
    /*pqxx::work cursor(profile->connector);
    pqxx::result res = cursor.exec_prepared("setFavourite",profile->getEmail().toStdString(),currCar.id);
    cursor.commit();*/
    }
}

