#include "offerslist.h"

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
        this->stringList << buff[0] + ".   " + buff[1] + "   " + buff[2] + "   " + buff[3];
        this->brandSet.insert(buff[1]);
        this->modelSet.insert(buff[2]);
        this->countrySet.insert(buff[9]);
    }

    // vars for adding items to comboBox (dropdown filters)
    brand = brandSet.values();
    model = modelSet.values();
    country = countrySet.values();

    file.close();
}
