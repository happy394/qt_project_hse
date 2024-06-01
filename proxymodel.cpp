#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent): QSortFilterProxyModel(parent) {}

bool ProxyModel::searchCheck(int sourceRow, const QModelIndex &sourceParent) const
{
    for (int i = 0; i < 13; ++i)
    {
        QModelIndex index = sourceModel()->index(sourceRow, i, sourceParent);
        // qInfo() << sourceModel()->data(index).toString();
        if (sourceModel()->data(index).toString() == _search.toLower() ||
            sourceModel()->data(index).toString() == _search ||
            sourceModel()->data(index).toString() == _search.sliced(1))
            return true;
    }
    return false;
}

bool ProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex indexBrand = sourceModel()->index(sourceRow, 0, sourceParent);
    QModelIndex indexModel = sourceModel()->index(sourceRow, 1, sourceParent);
    QModelIndex indexPrice = sourceModel()->index(sourceRow, 2, sourceParent);
    QModelIndex indexMileage = sourceModel()->index(sourceRow, 7, sourceParent);
    QModelIndex indexAge = sourceModel()->index(sourceRow, 11, sourceParent);

    if (!_search.isEmpty())
    {
        if (_brand != "All" && !_brand.isEmpty() && !_model.isEmpty() && _model != "All")
            return (sourceModel()->data(indexModel).toString() == _model &&
                    sourceModel()->data(indexBrand).toString() == _brand &&
                    sourceModel()->data(indexPrice).toInt() < _maxPrice &&
                    sourceModel()->data(indexPrice).toInt() > _minPrice &&
                    sourceModel()->data(indexMileage).toInt() < _maxMileage &&
                    sourceModel()->data(indexMileage).toInt() > _minMileage &&
                    sourceModel()->data(indexAge).toInt() < _maxAge &&
                    sourceModel()->data(indexAge).toInt() > _minAge &&
                    searchCheck(sourceRow, sourceParent));
        else if (_brand != "All" && !_brand.isEmpty() && (_model.isEmpty() || _model == "All"))
            return (sourceModel()->data(indexBrand).toString() == _brand &&
                    sourceModel()->data(indexPrice).toInt() < _maxPrice &&
                    sourceModel()->data(indexPrice).toInt() > _minPrice &&
                    sourceModel()->data(indexMileage).toInt() < _maxMileage &&
                    sourceModel()->data(indexMileage).toInt() > _minMileage &&
                    sourceModel()->data(indexAge).toInt() < _maxAge &&
                    sourceModel()->data(indexAge).toInt() > _minAge &&
                    searchCheck(sourceRow, sourceParent));
        else
        {
            return (sourceModel()->data(indexPrice).toInt() <= _maxPrice &&
                    sourceModel()->data(indexPrice).toInt() >= _minPrice &&
                    sourceModel()->data(indexMileage).toInt() <= _maxMileage &&
                    sourceModel()->data(indexMileage).toInt() >= _minMileage &&
                    sourceModel()->data(indexAge).toInt() <= _maxAge &&
                    sourceModel()->data(indexAge).toInt() >= _minAge &&
                    searchCheck(sourceRow, sourceParent));
        }
    }
    else
    {
        if (_brand != "All" && !_brand.isEmpty() && !_model.isEmpty() && _model != "All")
            return (sourceModel()->data(indexModel).toString() == _model &&
                    sourceModel()->data(indexBrand).toString() == _brand &&
                    sourceModel()->data(indexPrice).toInt() < _maxPrice &&
                    sourceModel()->data(indexPrice).toInt() > _minPrice &&
                    sourceModel()->data(indexMileage).toInt() < _maxMileage &&
                    sourceModel()->data(indexMileage).toInt() > _minMileage &&
                    sourceModel()->data(indexAge).toInt() < _maxAge &&
                    sourceModel()->data(indexAge).toInt() > _minAge);
        else if (_brand != "All" && !_brand.isEmpty() && (_model.isEmpty() || _model == "All"))
            return (sourceModel()->data(indexBrand).toString() == _brand &&
                    sourceModel()->data(indexPrice).toInt() < _maxPrice &&
                    sourceModel()->data(indexPrice).toInt() > _minPrice &&
                    sourceModel()->data(indexMileage).toInt() < _maxMileage &&
                    sourceModel()->data(indexMileage).toInt() > _minMileage &&
                    sourceModel()->data(indexAge).toInt() < _maxAge &&
                    sourceModel()->data(indexAge).toInt() > _minAge);
        else
        {
            return (sourceModel()->data(indexPrice).toInt() <= _maxPrice &&
                    sourceModel()->data(indexPrice).toInt() >= _minPrice &&
                    sourceModel()->data(indexMileage).toInt() <= _maxMileage &&
                    sourceModel()->data(indexMileage).toInt() >= _minMileage &&
                    sourceModel()->data(indexAge).toInt() <= _maxAge &&
                    sourceModel()->data(indexAge).toInt() >= _minAge);
        }
    }
}

void ProxyModel::reset()
{
    _brand.clear();
    _model.clear();
    _search.clear();

    _minPrice = 0;
    _maxPrice = 10000000000;
    _minMileage = 0;
    _maxMileage = 10000000000;
    _minAge = 0;
    _maxAge = 1000;

    this->sort(0);
    invalidateFilter();
}

void ProxyModel::setSearch(const QString &value)
{
    _search = value;
    invalidateFilter();
}

void ProxyModel::setBrand(const QString &value)
{
    _brand = value;
    invalidateFilter();
}

void ProxyModel::setModel(const QString &value)
{
    _model = value;
    invalidateFilter();
}

void ProxyModel::setMinPrice(const int &value)
{
    _minPrice = value;
    invalidateFilter();
}

void ProxyModel::setMaxPrice(const long int &value)
{
    _maxPrice = value;
    invalidateFilter();
}

void ProxyModel::setMinMileage(const int &value)
{
    _minMileage = value;
    invalidateFilter();
}

void ProxyModel::setMaxMileage(const long int &value)
{
    _maxMileage = value;
    invalidateFilter();
}

void ProxyModel::setMinAge(const int &value)
{
    _minAge = value;
    invalidateFilter();
}

void ProxyModel::setMaxAge(const int &value)
{
    _maxAge = value;
    invalidateFilter();
}
