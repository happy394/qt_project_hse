#include <QSettings>
#include <QCoreApplication>
#include <qfile.h>
#include "offersmodel.h"
#include "datapath.h"
#include "car.h"

offersmodel::offersmodel(QObject *parent)
    : QAbstractTableModel(parent)
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
    header = s.split(",").sliced(1);
    QStringList buff;

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
        this->carsList.append({buff[1], buff[2], buff[3].toUInt(), buff[4], buff[5], buff[6], buff[7], buff[8].toInt(), buff[9], buff[10].toDouble(), buff[11].toInt(), buff[12].toShort()});

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

    // initial vars for adding items to comboBox (dropdown filters)
    brand = {"All"};
    brand += brandSet.values();

    // sort brand and country dropdown filters
    std::sort(brand.begin() + 1, brand.end(), [](const QString &curr, const QString &other) {
        return curr < other;
    });
    file.close();
}

QStringList offersmodel::getModel(const QString &key)
{
    return modelMap[key];
}

QVariant offersmodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole){
        if (orientation == Qt::Horizontal){
            return header[section];
        }
        return section;
    }
    return QVariant();
}

int offersmodel::rowCount(const QModelIndex &parent) const
{

    if (parent.isValid())
        return 0;
    return carsList.size();
}

int offersmodel::columnCount(const QModelIndex &parent) const
{

    if (parent.isValid())
        return 0;

    return 12;
}

QVariant offersmodel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return QVariant(carsList[index.row()][index.column()]);
    }
    return QVariant();
}
