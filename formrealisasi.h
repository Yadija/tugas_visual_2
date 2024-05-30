#ifndef FORMREALISASI_H
#define FORMREALISASI_H

#include <QWidget>
#include <realisasi.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class FormRealisasi;
}

class FormRealisasi : public QWidget
{
    Q_OBJECT

public:
    explicit FormRealisasi(QWidget *parent = nullptr);
    ~FormRealisasi();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::FormRealisasi *ui;

    Realisasi realisasi;

    QSqlDatabase connect;
    QSqlQuery sql;
};

#endif // FORMREALISASI_H
