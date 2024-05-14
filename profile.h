#ifndef PROFILE_H
#define PROFILE_H
#include <QString>
#include <QVector>
#include <QModelIndex>
class Profile
{
private:
    QString email;
    QString password;
    QVector <QModelIndex> favourites;

public:
    Profile();

    QString getEmail() const;
    void setEmail(const QString &newEmail);
    QString getPassword() const;
    void setPassword(const QString &newPassword);
    void addFavourite (const QModelIndex &index);
};

#endif // PROFILE_H
