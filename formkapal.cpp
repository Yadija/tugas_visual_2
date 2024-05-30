#include "formkapal.h"
#include "ui_formkapal.h"

FormKapal::FormKapal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormKapal)
{
    ui->setupUi(this);

    Kapal kapal;
}

FormKapal::~FormKapal()
{
    delete ui;
}

void FormKapal::on_pushButtonAdd_clicked()
{
    kapal.setNamaKapal(ui->namaKapalLineEdit->text());
    kapal.setInstansi(ui->instansiLineEdit->text());
    kapal.setKedalamanGali(ui->kedalamanGaliLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("INSERT INTO kapal (nm_kpl, instansi, dlm_gali)"
                "VALUES (:nm_kpl, :instansi, :dlm_gali)");
    sql.bindValue(":nm_kpl", kapal.getNamaKapal());
    sql.bindValue(":instansi", kapal.getInstansi());
    sql.bindValue(":dlm_gali", kapal.getKedalamanGali());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Disimpan";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormKapal::on_pushButtonEdit_clicked()
{
    kapal.setNamaKapal(ui->namaKapalLineEdit->text());
    kapal.setInstansi(ui->instansiLineEdit->text());
    kapal.setKedalamanGali(ui->kedalamanGaliLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("UPDATE kapal SET instansi = :instansi, dlm_gali = :dlm_gali "
                "WHERE nm_kpl = :nm_kpl");
    sql.bindValue(":nm_kpl", kapal.getNamaKapal());
    sql.bindValue(":instansi", kapal.getInstansi());
    sql.bindValue(":dlm_gali", kapal.getKedalamanGali());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Diubah";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormKapal::on_pushButtonDelete_clicked()
{
    kapal.setNamaKapal(ui->namaKapalLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM kapal WHERE nm_kpl = :nm_kpl");
    sql.bindValue(":nm_kpl", kapal.getNamaKapal());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Dihapus";
    } else {
        qDebug() << sql.lastError().text();
    }
}

