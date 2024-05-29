#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();

    void setNik(QString nik);
    QString getNik();

    void setNama(QString nama);
    QString getNama();

    void setEmail(QString email);
    QString getEmail();

    void setRole(QString role);
    QString getRole();

    void setPassword(QString password);
    QString getPassword();

private:
    QString nik, nama, email, role, password;
};

#endif // USER_H
