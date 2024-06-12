#ifndef FORMWILAYAH_H
#define FORMWILAYAH_H

#include <QWidget>
#include <wilayah.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class FormWilayah;
}

class FormWilayah : public QWidget
{
    Q_OBJECT

public:
    explicit FormWilayah(QWidget *parent = nullptr);

    void loadTableWilayah();
    void clearFormInput();

    ~FormWilayah();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonClear_clicked();

    void on_tableWilayah_activated(const QModelIndex &index);

private:
    Ui::FormWilayah *ui;
    Wilayah wilayah;

    QSqlDatabase connect;
    QSqlQuery sql;
    QSqlQueryModel *tableModel;
};

#endif // FORMWILAYAH_H
