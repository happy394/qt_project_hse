#include "car.h"

car::car(const QString &brand,
         const QString &model,
         const qint64 &price,
         const QString &city,
         const QString &fuel,
         const QString &transmission,
         const QString &drive,
         const qint32 &mileage,
         const QString &country,
         const double &engineCapacity,
         const qint32 &engineHp,
         const qint16 &age)
    : brand(brand)
    , model(model)
    , price(price)
    , city(city)
    , fuel(fuel)
    , transmission(transmission)
    , drive(drive)
    , mileage(mileage)
    , country(country)
    , engineCapacity(engineCapacity)
    , engineHp(engineHp)
    , age(age)
{}

car::~car(){};

QString car::getCarString() const
{
    return brand + " " + model + " " + QString::number(price) + " " + QString::number(mileage)
           + " " + QString::number(age) + " " + country;
}

QString car::getCarName() const
{
    return brand + " " + model + '\n' + QString::number(price);
}
QString car::getCarInfo() const
{
    return "Mileage:    " + QString::number(mileage) + '\n' + "Age:    " + QString::number(age) + '\n' +
           "Fuel:   " + fuel + '\n' + "Transmission type:   " + transmission + '\n' +
           "Drive type:    " + drive + '\n' +  "Engine capacity:    " + QString::number(engineCapacity) + '\n' +
           "Horse power:    " + QString::number(engineHp) + '\n' + "Country:    " + country;
}

bool car::operator<(const car& other) const
{
    return this->brand < other.brand;
}
