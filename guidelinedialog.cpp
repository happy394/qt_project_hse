#include "guidelinedialog.h"
#include "ui_guidelinedialog.h"

GuidelineDialog::GuidelineDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GuidelineDialog)
{
    ui->setupUi(this);

    QString guidelineText = "This is your guideline on how to use the app:\n\n"
                            "1. Use the Brand filter to select the car brand.\n"
                            "2. Use the Model filter to select the car model.\n"
                            "3. Set the price, mileage, and age range to filter the cars.\n"
                            "4. Use the search bar to find specific cars.\n"
                            "5. Double-click on a car in the list to view more details.\n"
                            "6. Press the reset button to clear all filters and search input.";

    ui->guidelineTextEdit->setPlainText(guidelineText);
}

GuidelineDialog::~GuidelineDialog()
{
    delete ui;
}
