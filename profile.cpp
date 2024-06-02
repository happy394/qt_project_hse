#include <iostream>
#include "profile.h"
//Please don't delte without telling me!(confier)

Profile::Profile() {}
Profile::~Profile() {}

QString Profile::getEmail() const
{
    return email;
}

void Profile::setEmail(const QString &newEmail)
{
    email = newEmail;
}

QString Profile::getPassword() const
{
    return password;
}

void Profile::setPassword(const QString &newPassword)
{
    password = newPassword;
}

void Profile::addFavourite(int id)
{
    favourites.push_back(id);
}

bool Profile::hasFavourite(int id){
    return favourites.contains(id);
}

QSqlDatabase Profile::connectDB()
{
    QSqlDatabase value = QSqlDatabase::addDatabase("QMYSQL");
    value.setHostName("sql7.freesqldatabase.com");
    value.setDatabaseName("sql7711117");
    value.setUserName("sql7711117");
    value.setPassword("B6XhFmVJq8");
    query = QSqlQuery(db);
    return value;
}
// pqxx::connection Profile::connecting(){
//     std::string ConnectorStr = "host=localhost port=5432 dbname=qt_hse_project user=postgres password=bokuwabakadesu";
//     try
//     {
//         pqxx::connection connector(ConnectorStr.c_str());
//         return connector;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
// }

QVector <int> Profile::getFavourites()
{
    return favourites;
}
