#include "formiup.h"
#include "ui_formiup.h"

FormIUP::FormIUP(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormIUP)
{
    ui->setupUi(this);

    IUP iup;

    loadTableIUP();
}

void FormIUP::loadTableIUP()
{
    tableModel = new QSqlQueryModel(this);
    tableModel->setQuery("SELECT * FROM iup ORDER BY no_iup ASC");

    tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Nomor IUP"));
    tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Lokasi"));
    tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Nomor SK"));
    tableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Tgl. Berlaku"));
    tableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Nomor Sertifikat"));
    tableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Keterangan"));

    ui->tableIUP->setModel(tableModel);
    ui->tableIUP->setColumnWidth(0, 100);
    ui->tableIUP->setColumnWidth(1, 100);
    ui->tableIUP->setColumnWidth(2, 100);
    ui->tableIUP->setColumnWidth(3, 100);
    ui->tableIUP->setColumnWidth(4, 100);
    ui->tableIUP->setColumnWidth(5, 100);

    ui->tableIUP->show();
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
        QMessageBox::information(this, "information", "Data Berhasil Disimpan");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableIUP();
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
        QMessageBox::information(this, "information", "Data Berhasil Diubah");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableIUP();
}


void FormIUP::on_pushButtonDelete_clicked()
{
    iup.setNomorIUP(ui->nomorIUPLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM iup WHERE no_iup = :no_iup");
    sql.bindValue(":no_iup", iup.getNomorIUP());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Dihapus");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableIUP();
}

