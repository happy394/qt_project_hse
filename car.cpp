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
         const qint16 &age,
         const int id)
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
    , id(id)
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

QStringList car::getCarList() const
{
    QStringList res = {this->brand, this->model, QString::number(this->price), this->city, this->fuel, this->transmission, this->drive,
                       QString::number(this->mileage), this->country, QString::number(this->engineCapacity), QString::number(this->engineHp), QString::number(this->age),QString::number(this->id)};
    return res;
}

bool car::operator<(const car& other) const
{
    return this->brand < other.brand;
}

bool car::operator==(const car& other) const
{
    if (this->brand != other.brand || this->model != other.model || this->price != other.price ||this->city != other.city ||
        this->fuel != other.fuel ||this->transmission != other.transmission ||this->drive != other.drive ||this->mileage != other.mileage ||
        this->country != other.country ||this->engineCapacity != other.engineCapacity ||this->engineHp != other.engineHp ||this->age != other.age)
        return false;
    return true;
}
