#include "offerwindow.h"
#include "ui_offerwindow.h"

OfferWindow::OfferWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OfferWindow)
{
    ui->setupUi(this);}

OfferWindow::~OfferWindow()
{
    delete ui;
}
