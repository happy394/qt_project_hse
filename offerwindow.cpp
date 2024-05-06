#include "offerwindow.h"
#include "ui_offerwindow.h"

OfferWindow::OfferWindow(car currCar, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OfferWindow)
    , currCar(currCar)
    , carInfoModel(new QStringListModel)
    , carName(new QStringListModel)
{
    ui->setupUi(this);
    carInfoModel->setStringList({currCar.getCarInfo()});
    carName->setStringList({currCar.getCarName()});
    ui->CarInfo->setModel(carInfoModel);
    ui->CarName->setModel(carName);
}

OfferWindow::~OfferWindow()
{
    delete ui;
}
