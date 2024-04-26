#include "offerslist.h"
#include "car.h"

offersList::offersList()
{
    QFile file("/Users/happy394/Qt_projects/qt_project_hse/data/car_data.csv");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ss(&file);
    QString s = ss.readLine();
    QList <QString> buff;

    while (!ss.atEnd())
    {
        s = ss.readLine();
        buff = s.split(",");
        this->list.append(buff);
        car currCar = car(buff[0], buff[1], buff[2], buff[3], buff[4], buff[5], buff[6], buff[7], buff[8], buff[9], buff[10], buff[11], buff[12]);

        this->stringList << currCar.id + ".   " + currCar.brand + "   " + currCar.model + "   " + currCar.price;
        this->brandSet.insert(currCar.brand);
        if (!modelMap.contains(currCar.brand))
            modelMap.insert(currCar.brand, {currCar.model});
        else
            this->modelMap[currCar.brand].insert(currCar.model);
        if (!modelMap.contains(currCar.country))
            modelMap.insert(currCar.country, {currCar.brand});
        else
            this->modelMap[currCar.country].insert(currCar.brand);
        this->countrySet.insert(currCar.country);
    }

    // vars for adding items to comboBox (dropdown filters)
    brand = brandSet.values();
    country = countrySet.values();

    file.close();
}

QStringList offersList::getModel(const QString& key)
{
    return modelMap[key].values();
}
