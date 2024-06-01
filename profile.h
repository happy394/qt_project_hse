#ifndef PROFILE_H
#define PROFILE_H
#include <QString>
#include <QVector>
#include <QModelIndex>
#include <pqxx/pqxx>


// Please don't delte without telling me!(confier)


class Profile
{
private:
    QString email;
    QString password;
    QVector <int> favourites;

public:
    Profile();
    ~Profile();

    // Don't touch!
    pqxx::connection connector = connecting();
    pqxx::connection connecting();
    //

    QString getEmail() const;
    void setEmail(const QString &newEmail);
    QString getPassword() const;
    void setPassword(const QString &newPassword);
    void addFavourite (int id);
    bool hasFavourite (int id);
    QVector <int> getFavourites();

};

#endif // PROFILE_H
