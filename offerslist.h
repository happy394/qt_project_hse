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
    // QSet <QString> genres;
    offersList();

};

#endif // OFFERSLIST_H
