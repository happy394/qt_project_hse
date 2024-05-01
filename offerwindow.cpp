#include "offerwindow.h"
#include "ui_offerwindow.h"

OfferWindow::OfferWindow(car currCar, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OfferWindow)
    , currCar(currCar)
    , carInfoModel(new QStringListModel)
{
    ui->setupUi(this);
    carInfoModel->setStringList({currCar.getCarString()});
    ui->CarInfo->setModel(carInfoModel);
}

OfferWindow::~OfferWindow()
{
    delete ui;
}
