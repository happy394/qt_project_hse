#include "offerslist.h"

offersList::offersList()
{
    QFile file("/Users/happy394/Qt_projects/qt_project_hse/data/car_data.csv");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ss(&file);
    QString s = ss.readLine();
    QList <QString> buff;
    this->countrySet.insert("None");

    while (!ss.atEnd())
    {
        s = ss.readLine();
        buff = s.split(",");
        car currCar = car(buff[0], buff[1], buff[2], buff[3], buff[4], buff[5], buff[6], buff[7], buff[8], buff[9], buff[10], buff[11], buff[12]);
        this->list.append(currCar);
        this->stringList << currCar.getCarString();
        this->brandSet.insert(currCar.brand);

        if (!modelMap.contains(currCar.brand))
            modelMap.insert(currCar.brand, {currCar});
        else
            this->modelMap[currCar.brand].append(currCar);
        if (!modelMap.contains(currCar.country))
            modelMap.insert(currCar.country, {currCar});
        else
            this->modelMap[currCar.country].append(currCar);
        if (!modelMap.contains(currCar.model))
            modelMap.insert(currCar.model, {currCar});
        else
            this->modelMap[currCar.model].append(currCar);

        this->countrySet.insert(currCar.country);
    }
    std::sort(stringList.begin(), stringList.end(), [](const QString& curr, const QString& other){return curr[0] < other[0];});
    // vars for adding items to comboBox (dropdown filters)
    brand = brandSet.values();
    country = countrySet.values();

    file.close();
}

QList <car> offersList::getModel(const QString& key)
{
    return modelMap[key];
}
