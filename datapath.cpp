#include "datapath.h"
#include "ui_datapath.h"
#include <QSettings>
#include <QFile>

dataPath::dataPath(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dataPath)
{
    ui->setupUi(this);
}

dataPath::~dataPath()
{
    delete ui;
}

void dataPath::on_addPath_clicked()
{
    QSettings settings("drumdrum");
    int pathAmount = settings.value("path_amount").toInt();
    QString filePath = ui->lineEdit->text();
    QString fileName = *(filePath.split("/").end()-1);
    QFile file(filePath);
    if (file.exists() && fileName == "car_data.csv")
    {
        settings.setValue("path_amount", pathAmount+1);
        settings.setValue("path_" + QString::number(pathAmount+1), filePath);
        functionCalled = true;
        functionCalled = false;
        this->close();
    }
    else
    {
        ui->csvAskLabel->setText("There is no needed .csv file :(");
        ui->lineEdit->clear();
    }
}
