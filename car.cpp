#include "car.h"

car::car(const QString& id,
         const QString& brand,
         const QString& model,
         const QString& price,
         const QString& city,
         const QString& fuel,
         const QString& transmission,
         const QString& drive,
         const QString& mileage,
         const QString& country,
         const QString& engineCapacity,
         const QString& engineHp,
         const QString& age):
    id(id), brand(brand), model(model), price(price), city(city), fuel(fuel),
    transmission(transmission), drive(drive), mileage(mileage), country(country),
    engineCapacity(engineCapacity), engineHp(engineHp), age(age)
    {}

QStringList car::getCarString()
{
    return {this->brand + " " + this->model + " " + this->price};
}

car::~car(){};
