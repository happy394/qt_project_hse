#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "offerslist.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , offerslist(new offersList)
    , offersView(new QStringListModel)
    , brandModel(new QStringListModel)
    , modelModel(new QStringListModel)
    , countryModel(new QStringListModel)
{
    ui->setupUi(this);

    // offers list (also temp StringList for boundaries)
    currOffersView = offerslist->stringList;
    offersView->setStringList(offerslist->stringList);
    ui->OffersList->setModel(offersView);

    // dropdown filters
    brandModel->setStringList(offerslist->brand);
    countryModel->setStringList(offerslist->country);
    ui->BrandFilter->setModel(brandModel);
    ui->CountryFilter->setModel(countryModel);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete offersView;
    delete brandModel;
    delete countryModel;
    delete modelModel;
}

void MainWindow::on_BrandFilter_textActivated(const QString &currBrand)
{
    // if nothing was chosen
    if (currBrand == "")
    {
        ui->ModelFilter->clear();
        countryModel->setStringList(offerslist->country);
        ui->CountryFilter->setModel(countryModel);
        offersView->setStringList(currOffersView);
        ui->OffersList->setModel(offersView);
    }
    else
    {
        // making list of models
        QSet<QString> carsModelsSet;
        for (const auto &i : offerslist->getModel(currBrand))
            carsModelsSet.insert(i.model);

        // sorting list of models
        // "" is an empty element. It is needed to show that nothing was chosen
        QStringList carsModels = {""};
        carsModels += carsModelsSet.values();
        std::sort(carsModels.begin()+1, carsModels.end()); // sorting in alphabetic order

        // placing models in filter
        modelModel->setStringList(carsModels);
        ui->ModelFilter->setModel(modelModel);

        // changing offers list
        offersView->setStringList(currOffersView.filter(currBrand));
        ui->OffersList->setModel(offersView);
    }

}

void MainWindow::on_ModelFilter_textActivated(const QString &currModel)
{
    QString currBrand = ui->BrandFilter->currentText();
    if (currModel != "")
    {
        // filtering OffersList by brand and model
        offersView->setStringList(currOffersView.filter(currBrand + ' ' + currModel));
        ui->OffersList->setModel(offersView);
    }
    else
        // trigger choosing brand in BrandFilter to move ModelFilter to initial state
        on_BrandFilter_textActivated(currBrand);
}

void MainWindow::on_CountryFilter_textActivated(const QString &currCountry)
{
    QString currBrand = ui->BrandFilter->currentText();
    if (currCountry != "")
    {
        // making set of all brands of given country
        QSet<QString> carsBrands = {""};
        for (const auto &i: offerslist->getModel(currCountry))
            carsBrands.insert(i.brand);

        // changing BrandFilter by made set
        brandModel->setStringList(carsBrands.values());
        ui->BrandFilter->setModel(brandModel);

        if (currBrand.size() == 2)
            on_BrandFilter_textActivated(carsBrands.values().first());
        else
            ui->BrandFilter->setCurrentText("");
            on_BrandFilter_textActivated("");

        offersView->setStringList(currOffersView.filter(currCountry + ' '));
        ui->OffersList->setModel(offersView);
    }

    // returns BrandFilter to initial state
    else {
        brandModel->setStringList(offerslist->brand);
        ui->BrandFilter->setModel(brandModel);
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

    offersView->setStringList(offerslist->stringList);
    currOffersView = offerslist->stringList;
    ui->OffersList->setModel(offersView);

    ui->PriceMin->clear();
    ui->PriceMax->clear();
}

void MainWindow::on_PriceMin_textEdited(const QString &currMinPrice)
{
    // as currOffersView will be smaller due to bigger minPrice, we need to check if user
    // makes as input smaller price so we can restore deleted offers and filter them again.
    if (this->minPrice > currMinPrice.toInt())
        currOffersView = offerslist->stringList;

    // making offers, satisfying minPrice, in new StringList
    QStringList newStringlist;
    this->minPrice = currMinPrice.toInt();

    for (const auto& i: currOffersView)
    {
        int checkPrice = (*(i.split(' ').end()-3)).toInt();

        if (checkPrice >= minPrice && maxPrice >= checkPrice)
        {
            newStringlist.append(i);
        }
    }

    currOffersView = newStringlist;

    // filtering offers again if they were filtered by brand or model
    if (ui->BrandFilter->currentText() != "")
    {
        QString currModel = ui->ModelFilter->currentText();
        on_BrandFilter_textActivated(ui->BrandFilter->currentText());
        on_ModelFilter_textActivated(currModel);
        ui->ModelFilter->setCurrentText(currModel);
    }
    else
    {
        offersView->setStringList(currOffersView);
        ui->OffersList->setModel(offersView);
    }
}


void MainWindow::on_PriceMax_textEdited(const QString &currMaxPrice)
{
    // as currOffersView will be smaller due to smaller maxPrice, we need to check if user
    // makes as input bigger price so we can restore deleted offers and filter them again.
    if (this->maxPrice < currMaxPrice.toInt())
        currOffersView = offerslist->stringList;

    QStringList newStringlist;
    this->maxPrice = currMaxPrice.toInt();

    // making offers, satisfying maxPrice, in new StringList
    for (const auto& i: currOffersView)
    {
        int checkPrice = (*(i.split(' ').end()-3)).toInt();

        if (checkPrice >= minPrice && maxPrice >= checkPrice)
        {
            newStringlist.append(i);
        }
    }

    currOffersView = newStringlist;

    // filtering offers again if they were filtered by brand or model
    if (ui->BrandFilter->currentText() != "")
    {
        QString currModel = ui->ModelFilter->currentText();
        on_BrandFilter_textActivated(ui->BrandFilter->currentText());
        on_ModelFilter_textActivated(currModel);
        ui->ModelFilter->setCurrentText(currModel);
    }
    else
    {
        offersView->setStringList(currOffersView);
        ui->OffersList->setModel(offersView);
    }
}
