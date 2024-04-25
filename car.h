#ifndef CAR_H
#define CAR_H

#include <QString>

struct car
{
public:
    QString id;
    QString brand;
    QString model;
    QString price;
    QString city;
    QString fuel;
    QString transmission;
    QString drive;
    QString mileage;
    QString country;
    QString engineCapacity;
    QString engineHp;
    QString age;

    car(const QString &id,
        const QString &brand,
        const QString &model,
        const QString &price,
        const QString &city,
        const QString &fuel,
        const QString &transmission,
        const QString &drive,
        const QString &mileage,
        const QString &country,
        const QString &engineCapacity,
        const QString &engineHp,
        const QString &age);

    ~car();
};

#endif // CAR_H
