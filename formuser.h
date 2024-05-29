#ifndef FORMUSER_H
#define FORMUSER_H

#include <QWidget>
#include <user.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class FormUser;
}

class FormUser : public QWidget
{
    Q_OBJECT

public:
    explicit FormUser(QWidget *parent = nullptr);
    ~FormUser();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::FormUser *ui;
    User user;

    QSqlDatabase connect;
    QSqlQuery sql;
};

#endif // FORMUSER_H
