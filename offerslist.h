#ifndef OFFERSLIST_H
#define OFFERSLIST_H

#include <QAbstractTableModel>
#include <QCoreApplication>
#include "car.h"
#include <qfile.h>

struct offersList
{
public:
    QList<car> carsList;

    // dropdown filters
    QSet<QString> brandSet;
    QHash<QString, QStringList> modelMap;
    QStringList brand;
    QStringList model;

    // returns all cars for a given key
    QStringList getModel(const QString &key);

    offersList();
};

#endif // OFFERSLIST_H
