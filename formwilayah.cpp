#include "formwilayah.h"
#include "ui_formwilayah.h"

FormWilayah::FormWilayah(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormWilayah)
{
    ui->setupUi(this);

    Wilayah wilayah;

    loadTableWilayah();
}

void FormWilayah::loadTableWilayah()
{
    tableModel = new QSqlQueryModel(this);
    tableModel->setQuery("SELECT * FROM wilayah ORDER BY kd_wil ASC");

    tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Kode Wilayah"));
    tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Nama Wilayah"));

    ui->tableWilayah->setModel(tableModel);
    ui->tableWilayah->setColumnWidth(0, 100);
    ui->tableWilayah->setColumnWidth(1, 200);

    ui->tableWilayah->show();
}

void FormWilayah::clearFormInput()
{
    ui->kodeWilayahLineEdit->setText("");
    ui->namaWilayahLineEdit->setText("");
}

FormWilayah::~FormWilayah()
{
    delete ui;
}

void FormWilayah::on_pushButtonAdd_clicked()
{
    auto showMessageAndFocus = [](QWidget *widget, const QString &message) {
        QMessageBox::information(widget->parentWidget(), "warning", message);
        widget->setFocus();
    };

    if(ui->kodeWilayahLineEdit->text().isEmpty()) {
        showMessageAndFocus(ui->kodeWilayahLineEdit, "Kode Wilayah Belum Di Isi");
        return;
    }
    if(ui->namaWilayahLineEdit->text().isEmpty()) {
        showMessageAndFocus(ui->namaWilayahLineEdit, "Nama Wilayah Belum Di Isi");
        return;
    }

    wilayah.setKodeWilayah(ui->kodeWilayahLineEdit->text());
    wilayah.setNamaWilayah(ui->namaWilayahLineEdit->text());

    QSqlQuery duplicate;
    duplicate.prepare("SELECT kd_wil FROM wilayah WHERE kd_wil = :kd_wil");
    duplicate.bindValue(":kd_wil", wilayah.getKodeWilayah());
    duplicate.exec();
    if(duplicate.next()) {
        QMessageBox::information(this, "warning", "Kode Wilayah Sudah Ada");

        ui->namaWilayahLineEdit->setText(duplicate.value(1).toString());

        return;
    }

    QSqlQuery sql(connect);

    sql.prepare("INSERT INTO wilayah (kd_wil, nm_wil)"
                "VALUES (:kd_wil, :nm_wil)");
    sql.bindValue(":kd_wil", wilayah.getKodeWilayah());
    sql.bindValue(":nm_wil", wilayah.getNamaWilayah());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Disimpan");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableWilayah();
    clearFormInput();
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
        QMessageBox::information(this, "information", "Data Berhasil Diubah");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableWilayah();
    clearFormInput();
}


void FormWilayah::on_pushButtonDelete_clicked()
{
    wilayah.setKodeWilayah(ui->kodeWilayahLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM wilayah WHERE kd_wil = :kd_wil");
    sql.bindValue(":kd_wil", wilayah.getKodeWilayah());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Dihapus");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableWilayah();
    clearFormInput();
}


void FormWilayah::on_pushButtonClear_clicked()
{
    clearFormInput();
}


void FormWilayah::on_tableWilayah_activated(const QModelIndex &index)
{
    int row = ui->tableWilayah->currentIndex().row();
    ui->kodeWilayahLineEdit->setText(tableModel->data(tableModel->index(row, 0)).toString());
    ui->namaWilayahLineEdit->setText(tableModel->data(tableModel->index(row, 1)).toString());
}

