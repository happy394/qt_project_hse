#include "offerslist.h"

offersList::offersList()
{
    // qInfo() << qApp->applicationDirPath();
    QFile file("../../../../qt_project_hse/data/car_data.csv");
    file.open(QFile::ReadOnly | QFile::Text);
    // if (!file.isOpen()) we can make a message window with warning
    QTextStream ss(&file);
    QString s = ss.readLine(); // avoid header line
    QList<QString> buff;

    while (!ss.atEnd())
    {
        s = ss.readLine();
        buff = s.split(",");
        car currCar = car(buff[0],
                          buff[1],
                          buff[2],
                          buff[3],
                          buff[4],
                          buff[5],
                          buff[6],
                          buff[7],
                          buff[8],
                          buff[9],
                          buff[10],
                          buff[11],
                          buff[12]);

        // filling offer list
        this->list.append(currCar);
        this->stringList << currCar.getCarString();

        // sets for filling filters
        this->brandSet.insert(currCar.brand);
        this->countrySet.insert(currCar.country);

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
    }

    std::sort(stringList.begin(), stringList.end(), [](const QString &curr, const QString &other){return curr.split(' ')[0] < other.split(' ')[0];});

    // vars for adding items to comboBox (dropdown filters)
    brand = {""};
    country = {""};
    brand += brandSet.values();
    country += countrySet.values();

    std::sort(brand.begin()+1, brand.end(), [](const QString &curr, const QString &other){return curr < other;});
    std::sort(country.begin()+1, country.end(), [](const QString &curr, const QString &other){return curr < other;});

    file.close();
}

QList<car> offersList::getModel(const QString &key)
{
    return modelMap[key];
}
