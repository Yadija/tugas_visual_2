#include "formwilayah.h"
#include "ui_formwilayah.h"

FormWilayah::FormWilayah(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormWilayah)
{
    ui->setupUi(this);

    Wilayah wilayah;
}

FormWilayah::~FormWilayah()
{
    delete ui;
}

void FormWilayah::on_pushButtonAdd_clicked()
{
    wilayah.setKodeWilayah(ui->kodeWilayahLineEdit->text());
    wilayah.setNamaWilayah(ui->namaWilayahLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("INSERT INTO wilayah (kd_wil, nm_wil)"
                "VALUES (:kd_wil, :nm_wil)");
    sql.bindValue(":kd_wil", wilayah.getKodeWilayah());
    sql.bindValue(":nm_wil", wilayah.getNamaWilayah());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Disimpan";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormWilayah::on_pushButtonEdit_clicked()
{
    wilayah.setKodeWilayah(ui->kodeWilayahLineEdit->text());
    wilayah.setNamaWilayah(ui->namaWilayahLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("UPDATE wilayah SET nm_wil = :nm_wil WHERE kd_wil = :kd_wil");
    sql.bindValue(":kd_wil", wilayah.getKodeWilayah());
    sql.bindValue(":nm_wil", wilayah.getNamaWilayah());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Diubah";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormWilayah::on_pushButtonDelete_clicked()
{
    wilayah.setKodeWilayah(ui->kodeWilayahLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM wilayah WHERE kd_wil = :kd_wil");
    sql.bindValue(":kd_wil", wilayah.getKodeWilayah());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Dihapus";
    } else {
        qDebug() << sql.lastError().text();
    }
}

