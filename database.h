#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <pqxx/pqxx>

class user
{
private:
    qint32 id;
    QString login;
    QString password;
    QString email;

public:
    user(const qint32 &id, const QString &login, const QString &password, const QString &email);
    ~user();
};

pqxx::connection connectDatabase();
bool checkUser(const user &currUser);

#endif // DATABASE_H
