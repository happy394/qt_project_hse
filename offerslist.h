#ifndef OFFERSLIST_H
#define OFFERSLIST_H

#include <qfile.h>
#include <QList>
#include <QObject>
#include <QWidget>
#include <QAbstractTableModel>
#include <QStringList>
#include <QSet>
#include "car.h"

class offersList
{
public:
    QList<car> list; // vector
    QStringList stringList; // vector of string

    // dropdown filters
    QSet <QString> brandSet;
    QMap <QString, QList <car>> modelMap;
    QSet <QString> countrySet;
    QStringList brand;
    QStringList model;
    QStringList country;

    // returns all models for a given brand
    QList <car> getModel(const QString& branda);

    offersList();
};

#endif // OFFERSLIST_H
