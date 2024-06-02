#ifndef PROFILE_H
#define PROFILE_H
#include <QString>
#include <QVector>
#include <QModelIndex>
#include <QSqlDatabase>
#include <QSqlQuery>

// Please don't delte without telling me!(confier)
class Profile
{
private:
    QString email;
    QString password;
    QSet <int> _favourites;

public:
    Profile();
    ~Profile();

    QSqlDatabase db = connectDB();
    bool ok = db.open();
    QSqlDatabase connectDB();
    // // Don't touch!
    // pqxx::connection connector = connecting();
    // pqxx::connection connecting();
    // //

    QString getEmail() const;
    void setEmail(const QString &newEmail);
    QString getPassword() const;
    void setPassword(const QString &newPassword);
    void addFavourite (int id);
    void removeFavourite(int id);
    bool hasFavourite (int id);
    QVector <int> getFavourites();

};

#endif // PROFILE_H
