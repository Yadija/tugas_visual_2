#include "formcadangan.h"
#include "ui_formcadangan.h"

FormCadangan::FormCadangan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormCadangan)
{
    ui->setupUi(this);

    Cadangan cadangan;
}

FormCadangan::~FormCadangan()
{
    delete ui;
}

void FormCadangan::on_pushButtonAdd_clicked()
{
    cadangan.setKodeCadangan(ui->kodeCadanganLineEdit->text());
    cadangan.setNamaKapal(ui->namaKapalLineEdit->text());
    cadangan.setBulan(ui->bulanLineEdit->text());
    cadangan.setTahun(ui->tahunLineEdit->text());
    cadangan.setNomorIUP(ui->nomorIUPLineEdit->text());
    cadangan.setLaut(ui->lautLineEdit->text());
    cadangan.setLuas(ui->luasLineEdit->text());
    cadangan.setDDH(ui->dDHLineEdit->text());
    cadangan.setIDH(ui->iDHLineEdit->text());
    cadangan.setTDH(ui->tDHLineEdit->text());
    cadangan.setPDH(ui->pDHLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("INSERT INTO cadangan (kd_cad, nm_kpl, bulan, tahun, no_iup, laut, luas, ddh, idh, tdh, pdh) "
                "VALUES (:kd_cad, :nm_kpl, :bulan, :tahun, :no_iup, :laut, :luas, :ddh, :idh, :tdh, :pdh)");
    sql.bindValue(":kd_cad", cadangan.getKodeCadangan());
    sql.bindValue(":nm_kpl", cadangan.getNamaKapal());
    sql.bindValue(":bulan", cadangan.getBulan());
    sql.bindValue(":tahun", cadangan.getTahun());
    sql.bindValue(":no_iup", cadangan.getNomorIUP());
    sql.bindValue(":laut", cadangan.getLaut());
    sql.bindValue(":luas", cadangan.getLuas());
    sql.bindValue(":ddh", cadangan.getDDH());
    sql.bindValue(":idh", cadangan.getIDH());
    sql.bindValue(":tdh", cadangan.getTDH());
    sql.bindValue(":pdh", cadangan.getPDH());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Disimpan";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormCadangan::on_pushButtonEdit_clicked()
{
    cadangan.setKodeCadangan(ui->kodeCadanganLineEdit->text());
    cadangan.setNamaKapal(ui->namaKapalLineEdit->text());
    cadangan.setBulan(ui->bulanLineEdit->text());
    cadangan.setTahun(ui->tahunLineEdit->text());
    cadangan.setNomorIUP(ui->nomorIUPLineEdit->text());
    cadangan.setLaut(ui->lautLineEdit->text());
    cadangan.setLuas(ui->luasLineEdit->text());
    cadangan.setDDH(ui->dDHLineEdit->text());
    cadangan.setIDH(ui->iDHLineEdit->text());
    cadangan.setTDH(ui->tDHLineEdit->text());
    cadangan.setPDH(ui->pDHLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("UPDATE cadangan SET nm_kpl = :nm_kpl, bulan = :bulan, tahun = :tahun, no_iup = :no_iup, "
                "laut = :laut, luas = :luas, ddh = :ddh, idh = :idh, tdh = :tdh, pdh = :pdh WHERE kd_cad = :kd_cad");
    sql.bindValue(":kd_cad", cadangan.getKodeCadangan());
    sql.bindValue(":nm_kpl", cadangan.getNamaKapal());
    sql.bindValue(":bulan", cadangan.getBulan());
    sql.bindValue(":tahun", cadangan.getTahun());
    sql.bindValue(":no_iup", cadangan.getNomorIUP());
    sql.bindValue(":laut", cadangan.getLaut());
    sql.bindValue(":luas", cadangan.getLuas());
    sql.bindValue(":ddh", cadangan.getDDH());
    sql.bindValue(":idh", cadangan.getIDH());
    sql.bindValue(":tdh", cadangan.getTDH());
    sql.bindValue(":pdh", cadangan.getPDH());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Diubah";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormCadangan::on_pushButtonDelete_clicked()
{
    cadangan.setKodeCadangan(ui->kodeCadanganLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM cadangan WHERE kd_cad = :kd_cad");
    sql.bindValue(":kd_cad", cadangan.getKodeCadangan());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Dihapus";
    } else {
        qDebug() << sql.lastError().text();
    }
}

