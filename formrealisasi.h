#ifndef FORMREALISASI_H
#define FORMREALISASI_H

#include <QWidget>
#include <QShowEvent>
#include <realisasi.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class FormRealisasi;
}

class FormRealisasi : public QWidget
{
    Q_OBJECT

public:
    explicit FormRealisasi(QWidget *parent = nullptr);

    void loadTableRealisasi();
    void clearFormInput();

    ~FormRealisasi();

    void showEvent(QShowEvent *event);

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonClear_clicked();

    void on_tableRealisasi_activated(const QModelIndex &index);

private:
    Ui::FormRealisasi *ui;

    Realisasi realisasi;

    QSqlDatabase connect;
    QSqlQuery sql;
    QSqlQueryModel *tableModel;
};

#endif // FORMREALISASI_H
