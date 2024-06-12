#ifndef FORMUSER_H
#define FORMUSER_H

#include <QWidget>
#include <user.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class FormUser;
}

class FormUser : public QWidget
{
    Q_OBJECT

public:
    explicit FormUser(QWidget *parent = nullptr);

    void loadTableUser();
    void clearFormInput();

    ~FormUser();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonClear_clicked();

    void on_tableUser_activated(const QModelIndex &index);

private:
    Ui::FormUser *ui;
    User user;

    QSqlDatabase connect;
    QSqlQuery sql;
    QSqlQueryModel *tableModel;
};

#endif // FORMUSER_H
