#ifndef FORMCADANGAN_H
#define FORMCADANGAN_H

#include <QWidget>
#include <cadangan.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class FormCadangan;
}

class FormCadangan : public QWidget
{
    Q_OBJECT

public:
    explicit FormCadangan(QWidget *parent = nullptr);
    ~FormCadangan();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::FormCadangan *ui;
    Cadangan cadangan;

    QSqlDatabase connect;
    QSqlQuery sql;
};

#endif // FORMCADANGAN_H
