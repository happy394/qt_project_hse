#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QStringList>

class car
{
public:
    QString brand;
    QString model;
    int price;
    QString city;
    QString fuel;
    QString transmission;
    QString drive;
    int mileage;
    QString country;
    double engineCapacity;
    int engineHp;
    int age;

    car(const QString &brand = "",
        const QString &model = "",
        const qint64 &price = 0,
        const QString &city = "",
        const QString &fuel = "",
        const QString &transmission = "",
        const QString &drive = "",
        const qint32 &mileage = 0,
        const QString &country = "",
        const double &engineCapacity = 0,
        const qint32 &engineHp = 0,
        const qint16 &age = 0);
    ~car();

    QString getCarString() const;
    bool operator<(const car& other) const;
};

#endif // CAR_H
