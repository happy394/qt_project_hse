#include "aboutwindow.h"
#include "ui_aboutwindow.h"

Aboutwindow::Aboutwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);

    // Set the about text
    QString aboutText = "Car Dealership App\n\n"
                        "Version: 1.0\n\n"
                        "Purpose:\n"
                        "This application is designed to help users easily search for and filter "
                        "cars available at a dealership. The app provides a comprehensive list of "
                        "cars, along with detailed information about each car, such as brand, model, "
                        "price, mileage, and age. Users can apply various filters to narrow down "
                        "their search and find the perfect car that meets their specific needs. "
                        "Additionally, users can view detailed information about each car by "
                        "double-clicking on the car in the list.\n\n"
                        "Features:\n"
                        "- Filter cars by brand, model, price, mileage, and age.\n"
                        "- Search for cars using a search bar.\n"
                        "- View detailed information about each car.\n"
                        "- Reset filters and search criteria to start a new search.\n\n"
                        "This app is designed to enhance the car buying experience by providing "
                        "a user-friendly interface and powerful search capabilities.";

    ui->aboutTextEdit->setPlainText(aboutText);
    ui->aboutTextEdit->setReadOnly(true); // Make the text edit read-only
}

Aboutwindow::~Aboutwindow()
{
    delete ui;
}
