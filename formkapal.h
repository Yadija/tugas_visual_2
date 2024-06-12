#ifndef FORMKAPAL_H
#define FORMKAPAL_H

#include <QWidget>
#include <kapal.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class FormKapal;
}

class FormKapal : public QWidget
{
    Q_OBJECT

public:
    explicit FormKapal(QWidget *parent = nullptr);

    void loadTableKapal();
    void clearFormInput();

    ~FormKapal();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonClear_clicked();

    void on_tableKapal_activated(const QModelIndex &index);

private:
    Ui::FormKapal *ui;
    Kapal kapal;

    QSqlDatabase connect;
    QSqlQuery sql;
    QSqlQueryModel *tableModel;
};

#endif // FORMKAPAL_H
