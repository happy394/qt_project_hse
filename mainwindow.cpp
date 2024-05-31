#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "aboutdialog.h"
#include <QMenuBar>
#include "car.h"
#include "guidelinedialog.h"
#include "offerwindow.h"
#include <QMenuBar>
#include <qmessagebox.h>
#include "profilewindow.h"
#include <memory>
#include "profile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , brandModel(new QStringListModel)
    , modelModel(new QStringListModel)
    , offersModel(new offersmodel)
    , proxyModel(new ProxyModel)
{
    // main window set up
    ui->setupUi(this);

    // offers table using proxy model
    proxyModel->setSourceModel(offersModel);
    proxyModel->sort(0);
    ui->tableView->setModel(proxyModel);

    // dropdown filters
    brandModel->setStringList(offersModel->brand);
    ui->BrandFilter->setModel(brandModel);

    // Profile pointers Please don't delte without telling me!(confier)
    profile = std::make_shared<Profile>();
    profileWindow = std::make_shared<ProfileWindow>(profile);

    // Add "Help" menu item
    QMenu *helpMenu = menuBar()->addMenu(tr("Help"));
    QAction *helpAction = new QAction(tr("Open Guideline"), this);
    helpMenu->addAction(helpAction);
    connect(helpAction, &QAction::triggered, this, &MainWindow::showGuideline);

    // Add "About" menu item
    QMenu *moreMenu = menuBar()->addMenu(tr("More"));
    QAction *aboutAction = new QAction(tr("About"), this);
    moreMenu->addAction(aboutAction);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete offerModel;
    delete brandModel;
    delete modelModel;
    delete sortModel;
    delete proxyModel;
}

void MainWindow::on_BrandFilter_textActivated(const QString &currBrand)
{
    proxyModel->setBrand(currBrand);

    // make models list according to brand
    QStringList modelList = {"All"};
    modelList += offersModel->getModel(currBrand);
    modelList.removeDuplicates();

    // fill model dropdown filter
    modelModel->setStringList(modelList);
    ui->ModelFilter->setModel(modelModel);

    // check if we need to clear model dropdown filter
    if (currBrand == "All")
        ui->ModelFilter->clear();
}

void MainWindow::on_ModelFilter_textActivated(const QString &currModel)
{
    proxyModel->setModel(currModel);
}

void MainWindow::on_PriceMin_textEdited(const QString &arg1)
{
    if (arg1 == "")
        proxyModel->setMinPrice(0);
    else
        proxyModel->setMinPrice(arg1.toInt());
}

void MainWindow::on_PriceMax_textEdited(const QString &arg1)
{
    if (arg1 == "")
        proxyModel->setMaxPrice(1000000000);
    else
        proxyModel->setMaxPrice(arg1.toUInt());
}

void MainWindow::on_MileageMin_textEdited(const QString &arg1)
{
    if (arg1 == "")
        proxyModel->setMinMileage(0);
    else
        proxyModel->setMinMileage(arg1.toInt());
}

void MainWindow::on_MileageMax_textEdited(const QString &arg1)
{
    if (arg1 == "")
        proxyModel->setMaxMileage(1000000000);
    else
        proxyModel->setMaxMileage(arg1.toUInt());
}

void MainWindow::on_AgeMin_textEdited(const QString &arg1)
{
    if (arg1 == "")
        proxyModel->setMinAge(0);
    else
        proxyModel->setMinAge(arg1.toInt());
}

void MainWindow::on_AgeMax_textEdited(const QString &arg1)
{
    if (arg1 == "")
        proxyModel->setMaxAge(1000000000);
    else
        proxyModel->setMaxAge(arg1.toUInt());
}

void MainWindow::on_SearchButton_clicked()
{
    proxyModel->setSearch(ui->SearchBar->text());
}

void MainWindow::on_pushButton_clicked()
{
    // self-made func to reset all filters in proxy model
    proxyModel->reset();

    // reset dropdown filters
    ui->BrandFilter->setCurrentText("All");
    ui->ModelFilter->clear();

    // reset search bar
    ui->SearchBar->clear();
}

void MainWindow::showGuideline()
{
    GuidelineDialog guidelineDialog(this);
    guidelineDialog.exec();
}

void MainWindow::showAboutDialog()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}

// void MainWindow::on_OffersList_cellDoubleClicked(int row, int column)
// {
//     QStringList chosenCarInfo;
//     for (int i = 0; i < 13; ++i)
//     {
//         chosenCarInfo.push_back(ui->OffersList->item(row, i)->text());

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QStringList chosenCarInfo;
    QList<QModelIndex> indexes = ui->tableView->selectionModel()->selectedIndexes();
    for (QModelIndex j: indexes)
    {
        chosenCarInfo.push_back(j.data().toString());
    }

    car chosenCar(chosenCarInfo[0], chosenCarInfo[1], chosenCarInfo[2].toInt(), chosenCarInfo[3], chosenCarInfo[4], chosenCarInfo[5],
chosenCarInfo[6], chosenCarInfo[7].toInt(), chosenCarInfo[8], chosenCarInfo[9].toDouble(), chosenCarInfo[10].toInt(), chosenCarInfo[11].toInt(),chosenCarInfo[12].toInt());


    OfferWindow *w2 = new OfferWindow(profile,chosenCar);
    w2->show();
}

//Profile window Please don't delte without telling me!(confier)
void MainWindow::on_FavoriteButton_clicked()
{
    profileWindow ->show();

}
//QSettings setting("drumdrum");
//settings.setValue("id", id);
//settings.value("id");

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    onlyFavourites = (arg1!=0);
    // applyFilter();
}
