#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "offerslist.h"
#include "offerwindow.h"

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
    currOffersView = offerslist->stringList;
    // offers list (also temp StringList for boundaries)
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

void MainWindow::applyFilter()
{
    currOffersView.clear();
    currCarsList.clear();
    QString brand = ui->BrandFilter->currentText();
    QString model = ui->ModelFilter->currentText();
    // QString country = ui->CountryFilter->currentText();

    for (auto i = offerslist->carsList.begin(); i != offerslist->carsList.end(); ++i)
    {
        car currCar = *i;

        if (brand != "All" && model != "All" && model != "")
        {
            if (currCar.brand == brand && currCar.model == model
                && minPrice <= currCar.price && currCar.price <= maxPrice
                && minMileage <= currCar.mileage && currCar.mileage <= maxMileage
                && minAge <= currCar.age && currCar.age <= maxAge)
            {
                currOffersView.append(currCar.getCarString());
                currCarsList.append(currCar);
            }
        }
        else if (brand != "All")
        {
            if (currCar.brand == brand
                && minPrice <= currCar.price && currCar.price <= maxPrice
                && minMileage <= currCar.mileage && currCar.mileage <= maxMileage
                && minAge <= currCar.age && currCar.age <= maxAge)
            {
                currOffersView.append(currCar.getCarString());
                currCarsList.append(currCar);
            }
        }
        else
        {
            if (minPrice <= currCar.price && currCar.price <= maxPrice
                && minMileage <= currCar.mileage && currCar.mileage <= maxMileage
                && minAge <= currCar.age && currCar.age <= maxAge)
            {
                currOffersView.append(currCar.getCarString());
                currCarsList.append(currCar);
            }
        }

    }
    if (searchInput != "")
        currOffersView = currOffersView.filter(searchInput, Qt::CaseInsensitive);
    offersView->setStringList(currOffersView);
    ui->OffersList->setModel(offersView);
}

void MainWindow::on_BrandFilter_textActivated(const QString &currBrand)
{
    QList<QString> modelsList = {"All"};
    for (const car& i: offerslist->getModel(currBrand))
        modelsList.append(i.model);
    modelsList.removeDuplicates();
    modelModel->setStringList(modelsList);
    ui->ModelFilter->setModel(modelModel);
    if (currBrand == "All")
        ui->ModelFilter->clear();

    applyFilter();
}

void MainWindow::on_ModelFilter_textActivated(const QString &currModel)
{
    applyFilter();
}

void MainWindow::on_CountryFilter_textActivated(const QString &currCountry)
{
//     QString currBrand = ui->BrandFilter->currentText();
//     if (currCountry != "All")
//     {
//         // making set of all brands of given country
//         QSet<QString> carsBrands = {"All"};
//         for (const auto &i: offerslist->getModel(currCountry))
//             carsBrands.insert(i.brand);

//         // changing BrandFilter by made set
//         brandModel->setStringList(carsBrands.values());
//         ui->BrandFilter->setModel(brandModel);

//         if (currBrand.size() == 2)
//             on_BrandFilter_textActivated(carsBrands.values().first());
//         else
//             ui->BrandFilter->setCurrentText("All");
//             on_BrandFilter_textActivated("All");

//         offersView->setStringList(currOffersView.filter(currCountry + ' '));
//         ui->OffersList->setModel(offersView);
//     }

//     // returns BrandFilter to initial state
//     else {
//         brandModel->setStringList(offerslist->brand);
//         ui->BrandFilter->setModel(brandModel);
//         ui->BrandFilter->setCurrentText(currBrand);
//     }
}

void MainWindow::on_PriceMin_textEdited(const QString &arg1)
{
    qint64 currMinPrice;
    if (arg1 == "")
        currMinPrice = 0;
    else
        currMinPrice = arg1.toUInt();

    this->minPrice = currMinPrice;

    applyFilter();
}

void MainWindow::on_PriceMax_textEdited(const QString &arg1)
{
    qint64 currMaxPrice;
    if (arg1 == "")
        currMaxPrice = 1000000000;
    else
        currMaxPrice = arg1.toUInt();

    this->maxPrice = currMaxPrice;

    applyFilter();
}

void MainWindow::on_MileageMin_textEdited(const QString &arg1)
{
    int currMinMileage;
    if (arg1 == "")
        currMinMileage = 0;
    else
        currMinMileage = arg1.toInt();

    this->minMileage = currMinMileage;

    applyFilter();
}

void MainWindow::on_MileageMax_textEdited(const QString &arg1)
{
    int currMaxMileage;
    if (arg1 == "")
        currMaxMileage = 1000000000;
    else
        currMaxMileage = arg1.toInt();

    this->maxMileage = currMaxMileage;

    applyFilter();
}

void MainWindow::on_AgeMin_textEdited(const QString &arg1)
{
    int currMinAge;
    if (arg1 == "")
        currMinAge = 0;
    else
        currMinAge = arg1.toInt();

    this->minAge = currMinAge;

    applyFilter();
}

void MainWindow::on_AgeMax_textEdited(const QString &arg1)
{
    int currMaxAge;
    if (arg1 == "")
        currMaxAge = 1000000000;
    else
        currMaxAge = arg1.toInt();

    this->maxAge = currMaxAge;

    applyFilter();
}

void MainWindow::on_SearchButton_clicked()
{
    searchInput = ui->SearchBar->text();
    applyFilter();
}

void MainWindow::on_pushButton_clicked()
{
    on_CountryFilter_textActivated("All");
    ui->CountryFilter->setCurrentText("All");

    ui->BrandFilter->setCurrentText("All");
    on_BrandFilter_textActivated("All");

    ui->ModelFilter->clear();

    offersView->setStringList(offerslist->stringList);
    ui->OffersList->setModel(offersView);

    ui->PriceMin->clear();
    ui->PriceMax->clear();
    ui->MileageMin->clear();
    ui->MileageMax->clear();
    ui->AgeMin->clear();
    ui->AgeMax->clear();

    ui->SearchBar->clear();
}

void MainWindow::on_OffersList_doubleClicked(const QModelIndex &index)
{
    currOffer = currCarsList[index.row()];
    OfferWindow *w2 = new OfferWindow(currOffer);
    w2->show();
}
