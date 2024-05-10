#include "database.h"
#include <iostream>

user::user(const qint32 &id, const QString &login, const QString &password, const QString &email):
    id(id), login(login), password(password), email(email){};

user::~user(){};

pqxx::connection connectDatabase()
{
    std::string connectionString = "host=localhost port=5432 dbname=qt_hse_project user=postgres password=bokuwabakadesu target_session_attrs=read-write";
    try
    {
        pqxx::connection db(connectionString.c_str());
        return db;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return pqxx::connection();
}

// bool checkUser(const user &currUser)
// {
//     pqxx::work worker(db);
//     pqxx::result query = worker.exec("SELECT * FROM profiles WHERE login");
//     return true;
// }
