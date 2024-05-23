#include <iostream>
#include "profile.h"

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

void Profile::addFavourite(const QModelIndex &index)
{
    favourites.push_back(index);
}

pqxx::connection Profile::connecting(){
    std::string ConnectorStr = "host=localhost port=5432 dbname=postgres user=postgres password = 12345";
    try
    {
        pqxx::connection connector(ConnectorStr.c_str());
        return connector;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


// pqxx::work worker (connector);
// pqxx::result response = worker.exec("SELECT * FROM \"Profiles\"");

// for (int i = 0; i < response.size(); ++i)
// {
//     qInfo() << "Id: " << response[i][0].c_str() << " Email: " << response[i][1].c_str();
// }
