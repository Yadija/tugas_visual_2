#include "formiup.h"
#include "ui_formiup.h"

FormIUP::FormIUP(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormIUP)
{
    ui->setupUi(this);

    IUP iup;
}

FormIUP::~FormIUP()
{
    delete ui;
}

void FormIUP::on_pushButtonAdd_clicked()
{
    iup.setNomorIUP(ui->nomorIUPLineEdit->text());
    iup.setLokasi(ui->lokasiLineEdit->text());
    iup.setNomorSK(ui->nomorSKLineEdit->text());
    iup.setTanggalBerlaku(ui->tanggalBerlakuLineEdit->text());
    iup.setNomorSertifikat(ui->nomorSertifikatLineEdit->text());
    iup.setKeterangan(ui->keteranganLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("INSERT INTO iup (no_iup, lokasi, no_sk, tgl_berlaku, no_sert, ket) "
                "VALUES (:no_iup, :lokasi, :no_sk, :tgl_berlaku, :no_sert, :ket)");
    sql.bindValue(":no_iup", iup.getNomorIUP());
    sql.bindValue(":lokasi", iup.getLokasi());
    sql.bindValue(":no_sk", iup.getNomorSK());
    sql.bindValue(":tgl_berlaku", iup.getTanggalBerlaku());
    sql.bindValue(":no_sert", iup.getNomorSertifikat());
    sql.bindValue(":ket", iup.getKeterangan());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Disimpan";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormIUP::on_pushButtonEdit_clicked()
{
    iup.setNomorIUP(ui->nomorIUPLineEdit->text());
    iup.setLokasi(ui->lokasiLineEdit->text());
    iup.setNomorSK(ui->nomorSKLineEdit->text());
    iup.setTanggalBerlaku(ui->tanggalBerlakuLineEdit->text());
    iup.setNomorSertifikat(ui->nomorSertifikatLineEdit->text());
    iup.setKeterangan(ui->keteranganLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("UPDATE iup SET lokasi = :lokasi, no_sk = :no_sk, tgl_berlaku = :tgl_berlaku, "
                "no_sert = :no_sert, ket = :ket WHERE no_iup = :no_iup");
    sql.bindValue(":no_iup", iup.getNomorIUP());
    sql.bindValue(":lokasi", iup.getLokasi());
    sql.bindValue(":no_sk", iup.getNomorSK());
    sql.bindValue(":tgl_berlaku", iup.getTanggalBerlaku());
    sql.bindValue(":no_sert", iup.getNomorSertifikat());
    sql.bindValue(":ket", iup.getKeterangan());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Diubah";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormIUP::on_pushButtonDelete_clicked()
{
    iup.setNomorIUP(ui->nomorIUPLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM iup WHERE no_iup = :no_iup");
    sql.bindValue(":no_iup", iup.getNomorIUP());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Dihapus";
    } else {
        qDebug() << sql.lastError().text();
    }
}

