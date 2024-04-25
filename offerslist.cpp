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
        // this->brands.insert(buff[1]);
    }

    file.close();
}
