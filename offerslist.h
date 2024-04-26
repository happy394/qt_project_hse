#ifndef OFFERSLIST_H
#define OFFERSLIST_H

#include <qfile.h>
#include <QList>
#include <QObject>
#include <QWidget>
#include <QAbstractTableModel>
#include <QStringList>
#include <QSet>

class offersList
{
public:
    QList<QList<QString>> list; // vector
    QStringList stringList; // vector of string

    // dropdown filters
    QSet <QString> brandSet;
    QMap <QString, QSet <QString>> modelMap;
    QSet <QString> countrySet;
    QStringList brand;
    QStringList model;
    QStringList country;

    // returns all models for a given brand
    QStringList getModel(const QString& branda);

    offersList();
};

#endif // OFFERSLIST_H
