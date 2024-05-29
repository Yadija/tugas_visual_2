#include "user.h"

User::User() {}

void User::setNik(QString nik)
{
    this->nik = nik;
}

QString User::getNik()
{
    return this->nik;
}

void User::setNama(QString nama)
{
    this->nama = nama;
}

QString User::getNama()
{
    return this->nama;
}

void User::setEmail(QString email)
{
    this->email = email;
}

QString User::getEmail()
{
    return this->email;
}

void User::setRole(QString role)
{
    this->role = role;
}

QString User::getRole()
{
    return this->role;
}

void User::setPassword(QString password)
{
    this->password = password;
}

QString User::getPassword()
{
    return this->password;
}
