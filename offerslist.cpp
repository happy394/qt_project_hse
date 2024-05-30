#include "offerslist.h"
#include <QSettings>
#include "datapath.h"

offersList::offersList()
{
    QSettings settings("drumdrum");
    int pathAmount = settings.value("path_amount").toInt();
    QString filePath = "";
    for (int i = 0; i < pathAmount; ++i) {
        QFile file(settings.value("path_" + QString::number(i + 1)).toString());
        if (file.exists()) {
            filePath = file.fileName();
            break;
        }
    }
    if (filePath == "" && pathAmount != 0) {
        std::mutex mtx;
        std::condition_variable cv;
        dataPath d;
        d.exec();
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&d] { return d.functionCalled || !d.isVisible(); });
        filePath = settings.value("path_" + QString::number(pathAmount + 1)).toString();
    }

    QFile file(filePath);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ss(&file);
    QString s = ss.readLine(); // avoids header line
    QList<QString> buff;
    while (!ss.atEnd()) {
        s = ss.readLine();
        buff = s.split(",");
<<<<<<< HEAD
        car currCar = car(buff[1], buff[2], buff[3].toUInt(), buff[4], buff[5], buff[6], buff[7], buff[8].toInt(), buff[9], buff[10].toDouble(),
                          buff[11].toInt(), buff[12].toShort(),buff[0].toInt());
=======
        car currCar = car(buff[1],
                          buff[2],
                          buff[3].toUInt(),
                          buff[4],
                          buff[5],
                          buff[6],
                          buff[7],
                          buff[8].toInt(),
                          buff[9],
                          buff[10].toDouble(),
                          buff[11].toInt(),
                          buff[12].toShort());
>>>>>>> 554c83b (cleaned code to start remaking offerstable)

        // filling offer list
        this->carsList.append(currCar);

        // sets for filling filters
        this->brandSet.insert(currCar.brand);

        if (!modelMap.contains(currCar.brand))
            modelMap.insert(currCar.brand, {currCar.model});
        else
            this->modelMap[currCar.brand].append(currCar.model);
        if (!modelMap.contains(currCar.country))
            modelMap.insert(currCar.country, {currCar.brand});
        else
            this->modelMap[currCar.country].append(currCar.brand);
    }

    std::sort(carsList.begin(), carsList.end());

    // initial vars for adding items to comboBox (dropdown filters)
    brand = {"All"};
    brand += brandSet.values();

    // sort brand and country dropdown filters
    std::sort(brand.begin() + 1, brand.end(), [](const QString &curr, const QString &other) {
        return curr < other;
    });
    file.close();
}

QStringList offersList::getModel(const QString &key)
{
    return modelMap[key];
}
