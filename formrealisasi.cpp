#include "formrealisasi.h"
#include "ui_formrealisasi.h"

FormRealisasi::FormRealisasi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormRealisasi)
{
    ui->setupUi(this);

    Realisasi realisasi;

    QSqlDatabase connect = QSqlDatabase::addDatabase("QODBC");
    connect.setDatabaseName("dsn_pertambangan");
    connect.setUserName("root");
    connect.setPassword("");

    if(connect.open()) {
        qDebug() << "Database terkoneksi";
    } else {
        qDebug() << connect.lastError().text();
    }
}

FormRealisasi::~FormRealisasi()
{
    delete ui;
}

void FormRealisasi::on_pushButtonAdd_clicked()
{
    realisasi.setKodeRealisasi(ui->kodeRealisasiLineEdit->text());
    realisasi.setKodeCadangan(ui->kodeCadanganLineEdit->text());
    realisasi.setDSB(ui->dSBLineEdit->text());
    realisasi.setISB(ui->iSBLineEdit->text());
    realisasi.setTSB(ui->tSBLineEdit->text());
    realisasi.setPSB(ui->pSBLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("INSERT INTO realisasi (kd_real, kd_cad, dsb, isb, tsb, psb) "
                "VALUES (:kd_real, :kd_cad, :dsb, :isb, :tsb, :psb)");
    sql.bindValue(":kd_real", realisasi.getKodeRealisasi());
    sql.bindValue(":kd_cad", realisasi.getKodeCadangan());
    sql.bindValue(":dsb", realisasi.getDSB());
    sql.bindValue(":isb", realisasi.getISB());
    sql.bindValue(":tsb", realisasi.getTSB());
    sql.bindValue(":psb", realisasi.getPSB());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Disimpan";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormRealisasi::on_pushButtonEdit_clicked()
{
    realisasi.setKodeRealisasi(ui->kodeRealisasiLineEdit->text());
    realisasi.setKodeCadangan(ui->kodeCadanganLineEdit->text());
    realisasi.setDSB(ui->dSBLineEdit->text());
    realisasi.setISB(ui->iSBLineEdit->text());
    realisasi.setTSB(ui->tSBLineEdit->text());
    realisasi.setPSB(ui->pSBLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("UPDATE realisasi SET kd_cad = :kd_cad, dsb = :dsb, isb = :isb, tsb = :tsb, psb = :psb "
                "WHERE kd_real = :kd_real");
    sql.bindValue(":kd_real", realisasi.getKodeRealisasi());
    sql.bindValue(":kd_cad", realisasi.getKodeCadangan());
    sql.bindValue(":dsb", realisasi.getDSB());
    sql.bindValue(":isb", realisasi.getISB());
    sql.bindValue(":tsb", realisasi.getTSB());
    sql.bindValue(":psb", realisasi.getPSB());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Diubah";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormRealisasi::on_pushButtonDelete_clicked()
{
    realisasi.setKodeRealisasi(ui->kodeRealisasiLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM realisasi WHERE kd_real = :kd_real");
    sql.bindValue(":kd_real", realisasi.getKodeRealisasi());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Dihapus";
    } else {
        qDebug() << sql.lastError().text();
    }
}

