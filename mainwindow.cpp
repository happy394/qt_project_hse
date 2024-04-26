#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "offerslist.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), offerslist(new offersList), list(new QStringListModel), brand(new QStringListModel),
    model(new QStringListModel), country(new QStringListModel), stringlist(new QStringList)
{
    ui->setupUi(this);
    stringlist = &offerslist->stringList;
    list->setStringList(*stringlist);
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
    QList <car> cars = offerslist->getModel(arg1);
    QStringList carsModels = {"None"};
    QString carsBrand = cars[0].brand;
    for (const auto& i: cars)
    {
        if (!carsModels.contains(i.model))
            carsModels.append(i.model);
    }
    model->setStringList(carsModels);
    ui->ModelFilter->setModel(model);
    list->setStringList(stringlist->filter(carsBrand));
    ui->OffersList->setModel(list);
}

void MainWindow::on_CountryFilter_textActivated(const QString &arg1)
{
    if (arg1 != "None")
    {
        QList <car> cars = offerslist->getModel(arg1);
        QStringList carsBrands;
        for (const auto& i: cars)
        {
            carsBrands.append(i.brand);
        }

        brand->setStringList(carsBrands);
        ui->BrandFilter->setModel(brand);
        if (carsBrands.length() == 1)
        {
            model->setStringList({cars[0].brand});
            ui->ModelFilter->setModel(model);
        }
        else
            ui->ModelFilter->clear();
    }

    // returns BrandFilter to initial state
    else
    {
        brand->setStringList(offerslist->brand);
        ui->BrandFilter->setModel(brand);
    }
}


void MainWindow::on_ModelFilter_textActivated(const QString &arg1)
{
    QList <car> cars = offerslist->getModel(arg1);
    if (arg1 != "None")
    {
        QStringList stringList = this->stringlist->filter(cars[0].model);
        list->setStringList(stringList);
        ui->OffersList->setModel(list);
    }
    // somehow code below throws error that [] operator is out of range :)
    // else
    // {
    //     QStringList stringList = this->stringlist->filter(cars[0].brand);
    //     list->setStringList(stringList);
    //     ui->OffersList->setModel(list);
    // }

}

