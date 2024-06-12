#ifndef FORMIUP_H
#define FORMIUP_H

#include <QWidget>
#include <iup.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class FormIUP;
}

class FormIUP : public QWidget
{
    Q_OBJECT

public:
    explicit FormIUP(QWidget *parent = nullptr);

    void loadTableIUP();

    ~FormIUP();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::FormIUP *ui;
    IUP iup;

    QSqlDatabase connect;
    QSqlQuery sql;
    QSqlQueryModel *tableModel;
};

#endif // FORMIUP_H
