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
    model->setStringList(offerslist->model);
    country->setStringList(offerslist->country);
    ui->BrandFilter->setModel(brand);
    ui->ModelFilter->setModel(model);
    ui->CountryFilter->setModel(country);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete list;
}
