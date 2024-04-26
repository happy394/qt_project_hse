#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "offerslist.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), offerslist(new offersList), list(new QStringListModel), brand(new QStringListModel),
    model(new QStringListModel), country(new QStringListModel)
{
    ui->setupUi(this);
    list->setStringList(offerslist->stringList);
    ui->OffersList->setModel(list);

    // dropdown filters
    brand->setStringList(offerslist->brand);
    country->setStringList(offerslist->country);
    ui->BrandFilter->setModel(brand);
    ui->CountryFilter->setModel(country);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete list;
}

void MainWindow::on_BrandFilter_textActivated(const QString &arg1)
{
    model->setStringList(offerslist->getModel(arg1));
    ui->ModelFilter->setModel(model);
}

void MainWindow::on_CountryFilter_textActivated(const QString &arg1)
{
    QStringList car = offerslist->getModel(arg1);
    brand->setStringList(car);
    ui->BrandFilter->setModel(brand);
    if (car.length() == 1)
    {
        model->setStringList(offerslist->getModel(car[0]));
        ui->ModelFilter->setModel(model);
    }
    else
        ui->ModelFilter->clear();
}

