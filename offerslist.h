#ifndef OFFERSLIST_H
#define OFFERSLIST_H

#include <QAbstractTableModel>
#include <qfile.h>
#include <QCoreApplication>
#include "car.h"

class offersList
{
public:
    QList<car> list;        // vector of cars
    QStringList stringList; // vector of preview info of cars

    // dropdown filters
    QSet<QString> brandSet;
    QMap<QString, QList<car>> modelMap;
    QSet<QString> countrySet;
    QStringList brand;
    QStringList model;
    QStringList country;

    // returns all cars for a given key
    QList<car> getModel(const QString &key);

    offersList();
};

#endif // OFFERSLIST_H
