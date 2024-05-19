#include "profile.h"

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

Profile::Profile() {}
