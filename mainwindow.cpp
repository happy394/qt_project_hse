#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "offerslist.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , offerslist(new offersList)
    , list(new QStringListModel)
    , brand(new QStringListModel)
    , model(new QStringListModel)
    , country(new QStringListModel)
    , stringlist(new QStringList)
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
    delete brand;
    delete country;
    delete model;
}

void MainWindow::on_BrandFilter_textActivated(const QString &currBrand)
{
    if (currBrand != "")
    {
        // making list of models
        QSet<QString> carsModelsSet;
        for (const auto &i : offerslist->getModel(currBrand))
            carsModelsSet.insert(i.model);

        // sorting list of models
        // "" is an empty element. I think it is needed to show that nothing was chosen
        QStringList carsModels = {""};
        carsModels += carsModelsSet.values();
        std::sort(carsModels.begin()+1, carsModels.end());

        // placing models in filter
        model->setStringList(carsModels);
        ui->ModelFilter->setModel(model);

        // changing offers list
        list->setStringList(stringlist->filter(currBrand));
        ui->OffersList->setModel(list);
    }
    else
        ui->ModelFilter->clear();
}

void MainWindow::on_ModelFilter_textActivated(const QString &currModel)
{
    QString currBrand = ui->BrandFilter->currentText();
    if (currModel != "")
    {
        // filtering OffersList by brand and model
        list->setStringList(stringlist->filter(currBrand + ' ' + currModel));
        ui->OffersList->setModel(list);
    }
    else
        // trigger choosing brand in BrandFilter to move ModelFilter to initial state
        on_BrandFilter_textActivated(currBrand);
}

// problems with this filter (bugs and OffersList should be filtered)
void MainWindow::on_CountryFilter_textActivated(const QString &currCountry)
{
    QString currBrand = ui->BrandFilter->currentText();
    if (currCountry != "")
    {
        // making set of all brands of given country
        QSet<QString> carsBrands;
        for (const auto &i: offerslist->getModel(currCountry))
            carsBrands.insert(i.brand);

        // changing BrandFilter by made set
        brand->setStringList(carsBrands.values());
        ui->BrandFilter->setModel(brand);

        if (currBrand == "")
            on_BrandFilter_textActivated(carsBrands.values().first());
        else
            on_BrandFilter_textActivated(currBrand);

        list->setStringList(stringlist->filter(currCountry + ' '));
        ui->OffersList->setModel(list);
    }

    // returns BrandFilter to initial state
    else {
        brand->setStringList(offerslist->brand);
        ui->BrandFilter->setModel(brand);
        ui->BrandFilter->setCurrentText(currBrand);
    }
}

void MainWindow::on_pushButton_clicked()
{
    on_CountryFilter_textActivated("");
    ui->CountryFilter->setCurrentText("");

    ui->BrandFilter->setCurrentText("");
    on_BrandFilter_textActivated("");

    ui->ModelFilter->clear();

    list->setStringList(*stringlist);
    ui->OffersList->setModel(list);
}

