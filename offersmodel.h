#ifndef OFFERSMODEL_H
#define OFFERSMODEL_H

#include <QAbstractTableModel>

class offersmodel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit offersmodel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QStringList header;
    // dropdown filters
    QSet<QString> brandSet;
    QHash<QString, QStringList> modelMap;
    QStringList brand;
    QStringList model;

    // returns all cars for a given key
    QStringList getModel(const QString &key);

    QList<QList<QVariant>> carsList;
private:

};

#endif // OFFERSMODEL_H
