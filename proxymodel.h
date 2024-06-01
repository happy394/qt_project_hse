#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>
#include "profile.h"

class ProxyModel : public QSortFilterProxyModel {
    Q_OBJECT

public:
    explicit ProxyModel(QObject *parent = nullptr);

    void setBrand(const QString &value);
    void setModel(const QString &value);
    void setSearch(const QString &value);
    void setFlag(bool value1, std::shared_ptr<Profile> &value2);

    bool searchCheck(int sourceRow, const QModelIndex &sourceParent) const;

    void setMinPrice(const int &value);
    void setMaxPrice(const long int &value);
    void setMinMileage(const int &value);
    void setMaxMileage(const long int &value);
    void setMinAge(const int &value);
    void setMaxAge(const int &value);

    void reset();

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QString _brand;
    QString _model;
    QString _search;
    bool favourites;
    QVector <int> favouritesVector;

    int _minPrice = 0;
    long int _maxPrice = 10000000000;
    int _minMileage = 0;
    long int _maxMileage = 10000000000;
    int _minAge = 0;
    int _maxAge = 1000;
};


#endif
