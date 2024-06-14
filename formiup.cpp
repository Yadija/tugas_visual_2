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

void FormIUP::clearFormInput()
{
    ui->nomorIUPLineEdit->setText("");
    ui->lokasiLineEdit->setText("");
    ui->nomorSKLineEdit->setText("");
    ui->tanggalBerlakuLineEdit->setText("");
    ui->nomorSertifikatLineEdit->setText("");
    ui->keteranganLineEdit->setText("");
}

FormIUP::~FormIUP()
{
    delete ui;
}

void FormIUP::on_pushButtonAdd_clicked()
{
    auto showMessageAndFocus = [](QWidget *widget, const QString &message) {
        QMessageBox::information(widget->parentWidget(), "warning", message);
        widget->setFocus();
    };

    if(ui->nomorIUPLineEdit->text().isEmpty()) {
        showMessageAndFocus(ui->nomorIUPLineEdit, "Nomor IUP Belum Di Isi");
        return;
    }
    if(ui->lokasiLineEdit->text().isEmpty()) {
        showMessageAndFocus(ui->lokasiLineEdit, "Lokasi Belum Di Isi");
        return;
    }
    if(ui->nomorSKLineEdit->text().isEmpty()) {
        showMessageAndFocus(ui->nomorSKLineEdit, "Nomor SK Belum Di Isi");
        return;
    }
    if(ui->tanggalBerlakuLineEdit->text().isEmpty()) {
        showMessageAndFocus(ui->tanggalBerlakuLineEdit, "Tgl. Berlaku Belum Di Isi");
        return;
    }
    if(ui->nomorSertifikatLineEdit->text().isEmpty()) {
        showMessageAndFocus(ui->nomorSertifikatLineEdit, "Nomor Sertifikat Belum Di Isi");
        return;
    }
    if(ui->keteranganLineEdit->text().isEmpty()) {
        showMessageAndFocus(ui->keteranganLineEdit, "Keterangan Belum Di Isi");
        return;
    }

    iup.setNomorIUP(ui->nomorIUPLineEdit->text());
    iup.setLokasi(ui->lokasiLineEdit->text());
    iup.setNomorSK(ui->nomorSKLineEdit->text());
    iup.setTanggalBerlaku(ui->tanggalBerlakuLineEdit->text());
    iup.setNomorSertifikat(ui->nomorSertifikatLineEdit->text());
    iup.setKeterangan(ui->keteranganLineEdit->text());

    QSqlQuery duplicate;
    duplicate.prepare("SELECT * FROM iup WHERE no_iup = :no_iup");
    duplicate.bindValue(":no_iup", iup.getNomorIUP());
    duplicate.exec();
    if(duplicate.next()) {
        QMessageBox::information(this, "warning", "Nomor IUP Sudah Ada");

        ui->lokasiLineEdit->setText(duplicate.value(1).toString());
        ui->nomorSKLineEdit->setText(duplicate.value(2).toString());
        ui->tanggalBerlakuLineEdit->setText(duplicate.value(3).toString());
        ui->nomorSertifikatLineEdit->setText(duplicate.value(4).toString());
        ui->keteranganLineEdit->setText(duplicate.value(5).toString());

        return;
    }

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
    clearFormInput();
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
    clearFormInput();
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
    clearFormInput();
}


void FormIUP::on_pushButtonClear_clicked()
{
    clearFormInput();
}


void FormIUP::on_tableIUP_activated(const QModelIndex &index)
{
    int row = ui->tableIUP->currentIndex().row();
    ui->nomorIUPLineEdit->setText(tableModel->data(tableModel->index(row, 0)).toString());
    ui->lokasiLineEdit->setText(tableModel->data(tableModel->index(row, 1)).toString());
    ui->nomorSKLineEdit->setText(tableModel->data(tableModel->index(row, 2)).toString());
    ui->tanggalBerlakuLineEdit->setText(tableModel->data(tableModel->index(row, 3)).toString());
    ui->nomorSertifikatLineEdit->setText(tableModel->data(tableModel->index(row, 4)).toString());
    ui->keteranganLineEdit->setText(tableModel->data(tableModel->index(row, 5)).toString());
}

