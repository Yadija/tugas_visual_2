#include "formkapal.h"
#include "ui_formkapal.h"

FormKapal::FormKapal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormKapal)
{
    ui->setupUi(this);

    Kapal kapal;

    loadTableKapal();
}

void FormKapal::loadTableKapal()
{
    tableModel = new QSqlQueryModel(this);
    tableModel->setQuery("SELECT * FROM kapal ORDER BY nm_kpl ASC");

    tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Nama Kapal"));
    tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Instansi"));
    tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Kedalaman Gali"));

    ui->tableKapal->setModel(tableModel);
    ui->tableKapal->setColumnWidth(0, 200);
    ui->tableKapal->setColumnWidth(1, 200);
    ui->tableKapal->setColumnWidth(2, 100);
}

void FormKapal::clearFormInput()
{
    ui->namaKapalLineEdit->setText("");
    ui->instansiLineEdit->setText("");
    ui->kedalamanGaliLineEdit->setText("");
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
        QMessageBox::information(this, "information", "Data Berhasil Disimpan");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableKapal();
    clearFormInput();
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
        QMessageBox::information(this, "information", "Data Berhasil Diubah");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableKapal();
    clearFormInput();
}


void FormKapal::on_pushButtonDelete_clicked()
{
    kapal.setNamaKapal(ui->namaKapalLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM kapal WHERE nm_kpl = :nm_kpl");
    sql.bindValue(":nm_kpl", kapal.getNamaKapal());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Dihapus");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableKapal();
    clearFormInput();
}


void FormKapal::on_pushButtonClear_clicked()
{
    clearFormInput();
}


void FormKapal::on_tableKapal_activated(const QModelIndex &index)
{
    int row = ui->tableKapal->currentIndex().row();
    ui->namaKapalLineEdit->setText(tableModel->record(row).value(0).toString());
    ui->instansiLineEdit->setText(tableModel->record(row).value(1).toString());
    ui->kedalamanGaliLineEdit->setText(tableModel->record(row).value(2).toString());
}

