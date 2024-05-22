#ifndef OFFERSLIST_H
#define OFFERSLIST_H

#include <QAbstractTableModel>
#include <QCoreApplication>
#include <qfile.h>
#include "car.h"

class offersList
{
public:
    // two containers for cars (string, class)
    QList<car> carsList;

    // dropdown filters
    QSet<QString> brandSet;
    QHash<QString, QStringList> modelMap;
    QStringList brand;
    QStringList model;
    QStringList country;

    // returns all cars for a given key
    QStringList getModel(const QString &key);

    offersList();
};

#endif // OFFERSLIST_H
