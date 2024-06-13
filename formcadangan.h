#ifndef FORMCADANGAN_H
#define FORMCADANGAN_H

#include <QWidget>
#include <QShowEvent>
#include <cadangan.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class FormCadangan;
}

class FormCadangan : public QWidget
{
    Q_OBJECT

public:
    explicit FormCadangan(QWidget *parent = nullptr);

    void loadTableCadangan();
    void clearFormInput();

    ~FormCadangan();

    void showEvent(QShowEvent *event);

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonClear_clicked();

    void on_tableCadangan_activated(const QModelIndex &index);

private:
    Ui::FormCadangan *ui;
    Cadangan cadangan;

    QSqlDatabase connect;
    QSqlQuery sql;
    QSqlQueryModel *tableModel;
};

#endif // FORMCADANGAN_H
