#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "offerslist.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), offerslist(new offersList), list(new QStringListModel)
{
    ui->setupUi(this);
    list->setStringList(offerslist->stringList);
    ui->OffersList->setModel(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}
