#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "offerslist.h"
#include "offerwindow.h"
#include "guidelinedialog.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , offerslist(new offersList)
    , offerModel(new QStringListModel)
    , brandModel(new QStringListModel)
    , modelModel(new QStringListModel)
{
    // main window set up
    ui->setupUi(this);

    // initial offers list
    offerModel->setStringList(offerslist->stringList);
    ui->OffersList->setModel(offerModel);

    // dropdown filters
    brandModel->setStringList(offerslist->brand);
    ui->BrandFilter->setModel(brandModel);

    // changable containers for this window
    currOfferStringList = offerslist->stringList;
    currCarList = offerslist->carsList;

    // Add "Help" menu item
    QMenu *helpMenu = menuBar()->addMenu(tr("Help"));
    QAction *helpAction = new QAction(tr("Open Guideline"), this);
    helpMenu->addAction(helpAction);
    connect(helpAction, &QAction::triggered, this, &MainWindow::showGuideline);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete offerslist;
    delete offerModel;
    delete brandModel;
    delete modelModel;
}

void MainWindow::applyFilter()
{
    // clear containers to fill them with filtered data
    currOfferStringList.clear();
    currCarList.clear();

    // get current filters text
    QString brand = ui->BrandFilter->currentText();
    QString model = ui->ModelFilter->currentText();
    searchInput = ui->SearchBar->text();

    // iterate through all cars. find those which are ok with filters
    for (auto i = offerslist->carsList.begin(); i != offerslist->carsList.end(); ++i)
    {
        car currCar = *i;

        if (minPrice <= currCar.price && currCar.price <= maxPrice
            && minMileage <= currCar.mileage && currCar.mileage <= maxMileage
            && minAge <= currCar.age && currCar.age <= maxAge)
        {
            if (brand != "All" && model != "All" && model != "")
            {
                if (currCar.brand == brand && currCar.model == model)
                {
                    currOfferStringList.append(currCar.getCarString());
                    currCarList.append(currCar);
                }
            }
            else if (brand != "All")
            {
                if (currCar.brand == brand)
                {
                    currOfferStringList.append(currCar.getCarString());
                    currCarList.append(currCar);
                }
            }
            else
            {
                currOfferStringList.append(currCar.getCarString());
                currCarList.append(currCar);
            }
        }
    }

    // extra filter by search text
    if (searchInput != "")
    {
        QList<car> tempCarList;
        currOfferStringList = currOfferStringList.filter(searchInput, Qt::CaseInsensitive);
        for (auto &k: currCarList)
        {
            if (currOfferStringList.contains(k.getCarString()))
                tempCarList.append(k);
        }
        currCarList = tempCarList;
    }

    // finally add filtered data to OffersList
    offerModel->setStringList(currOfferStringList);
    ui->OffersList->setModel(offerModel);
}

void MainWindow::on_BrandFilter_textActivated(const QString &currBrand)
{
    // make models list according to brand
    QStringList modelList = {"All"};
    modelList += offerslist->getModel(currBrand);
    modelList.removeDuplicates();

    // fill model dropdown filter
    modelModel->setStringList(modelList);
    ui->ModelFilter->setModel(modelModel);

    // check if we need to clear model dropdown filter
    if (currBrand == "All")
        ui->ModelFilter->clear();

    // filter OffersList
    applyFilter();
}

void MainWindow::on_ModelFilter_textActivated(const QString &currModel)
{
    applyFilter();
}

void MainWindow::on_PriceMin_textEdited(const QString &arg1)
{
    if (arg1 == "")
        minPrice = 0;
    else
        minPrice = arg1.toUInt();

    applyFilter();
}

void MainWindow::on_PriceMax_textEdited(const QString &arg1)
{
    if (arg1 == "")
        maxPrice = 1000000000;
    else
        maxPrice = arg1.toUInt();

    applyFilter();
}

void MainWindow::on_MileageMin_textEdited(const QString &arg1)
{
    if (arg1 == "")
        minMileage = 0;
    else
        minMileage = arg1.toInt();

    applyFilter();
}

void MainWindow::on_MileageMax_textEdited(const QString &arg1)
{
    if (arg1 == "")
        maxMileage = 1000000000;
    else
        maxMileage = arg1.toInt();

    applyFilter();
}

void MainWindow::on_AgeMin_textEdited(const QString &arg1)
{
    if (arg1 == "")
        minAge = 0;
    else
        minAge = arg1.toInt();

    applyFilter();
}

void MainWindow::on_AgeMax_textEdited(const QString &arg1)
{
    if (arg1 == "")
        maxAge = 1000000000;
    else
        maxAge = arg1.toInt();

    applyFilter();
}

void MainWindow::on_SearchButton_clicked()
{
    applyFilter();
}

void MainWindow::on_pushButton_clicked()
{
    // reset dropdown filters
    ui->BrandFilter->setCurrentText("All");
    ui->ModelFilter->clear();

    // reset boundaries
    ui->PriceMin->clear();
    minPrice = 0;
    ui->PriceMax->clear();
    maxPrice = 100000000;
    ui->MileageMin->clear();
    minMileage = 0;
    ui->MileageMax->clear();
    maxMileage = 100000000;
    ui->AgeMin->clear();
    minAge = 0;
    ui->AgeMax->clear();
    maxAge = 100000000;

    // reset search bar
    ui->SearchBar->clear();

    applyFilter();
}

void MainWindow::on_OffersList_doubleClicked(const QModelIndex &index)
{
    OfferWindow *w2 = new OfferWindow(currCarList[index.row()]);
    w2->show();
}

void MainWindow::showGuideline()
{
    GuidelineDialog guidelineDialog(this);
    guidelineDialog.exec();
}
