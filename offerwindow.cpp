#include "offerwindow.h"
#include "ui_offerwindow.h"
#include "mainwindow.h"

OfferWindow::OfferWindow(car currCar, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OfferWindow)
    , currCar(currCar)
    , carOfferModel(new QStringListModel)
{
    ui->setupUi(this);
    carOfferModel->setStringList({currCar.getCarString()});
    ui->CarInfo->setModel(carOfferModel);
}

OfferWindow::~OfferWindow()
{
    delete ui;
}
