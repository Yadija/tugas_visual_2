#include "formrealisasi.h"
#include "ui_formrealisasi.h"

FormRealisasi::FormRealisasi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormRealisasi)
{
    ui->setupUi(this);

    Realisasi realisasi;

    loadTableRealisasi();
}

void FormRealisasi::loadTableRealisasi()
{
    tableModel = new QSqlQueryModel(this);
    tableModel->setQuery("SELECT * FROM realisasi ORDER BY kd_real ASC");

    tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Kode Realisasi"));
    tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Kode Cadangan"));
    tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("DSB"));
    tableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("ISB"));
    tableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("TSB"));
    tableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("PSB"));

    ui->tableRealisasi->setModel(tableModel);
    ui->tableRealisasi->setColumnWidth(0, 100);
    ui->tableRealisasi->setColumnWidth(1, 100);
    ui->tableRealisasi->setColumnWidth(2, 100);
    ui->tableRealisasi->setColumnWidth(3, 100);
    ui->tableRealisasi->setColumnWidth(4, 100);
    ui->tableRealisasi->setColumnWidth(5, 100);

    ui->tableRealisasi->show();
}

void FormRealisasi::clearFormInput()
{
    ui->kodeRealisasiLineEdit->setText("");
    ui->kodeCadanganComboBox->setCurrentIndex(0);
    ui->dSBLineEdit->setText("");
    ui->iSBLineEdit->setText("");
    ui->tSBLineEdit->setText("");
    ui->pSBLineEdit->setText("");
}

FormRealisasi::~FormRealisasi()
{
    delete ui;
}

void FormRealisasi::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    ui->kodeCadanganComboBox->clear();

    QSqlQuery sql(connect);

    sql.prepare("SELECT kd_cad FROM cadangan");
    sql.exec();
    while(sql.next()) {
        QString kodeCadangan = sql.value(sql.record().indexOf("kd_cad")).toString();
        ui->kodeCadanganComboBox->addItem(kodeCadangan);
    }
}

void FormRealisasi::on_pushButtonAdd_clicked()
{
    auto showMessageAndFocus = [](QWidget *widget, const QString &message) {
        QMessageBox::information(widget->parentWidget(), "warning", message);
        widget->setFocus();
    };

    if(ui->kodeRealisasiLineEdit->text().isEmpty()) {
        showMessageAndFocus(this, "Kode Realisasi Tidak Boleh Kosong");
        return;
    }
    if(ui->kodeCadanganComboBox->currentText().isEmpty()) {
        showMessageAndFocus(this, "Kode Cadangan Tidak Boleh Kosong");
        return;
    }
    if(ui->dSBLineEdit->text().isEmpty()) {
        showMessageAndFocus(this, "DSB Tidak Boleh Kosong");
        return;
    }
    if(ui->iSBLineEdit->text().isEmpty()) {
        showMessageAndFocus(this, "ISB Tidak Boleh Kosong");
        return;
    }
    if(ui->tSBLineEdit->text().isEmpty()) {
        showMessageAndFocus(this, "TSB Tidak Boleh Kosong");
        return;
    }
    if(ui->pSBLineEdit->text().isEmpty()) {
        showMessageAndFocus(this, "PSB Tidak Boleh Kosong");
        return;
    }

    realisasi.setKodeRealisasi(ui->kodeRealisasiLineEdit->text());
    realisasi.setKodeCadangan(ui->kodeCadanganComboBox->currentText());
    realisasi.setDSB(ui->dSBLineEdit->text());
    realisasi.setISB(ui->iSBLineEdit->text());
    realisasi.setTSB(ui->tSBLineEdit->text());
    realisasi.setPSB(ui->pSBLineEdit->text());

    QSqlQuery duplicate;
    duplicate.prepare("SELECT kd_real FROM realisasi WHERE kd_real = :kd_real");
    duplicate.bindValue(":kd_real", realisasi.getKodeRealisasi());
    duplicate.exec();
    if(duplicate.next()) {
        QMessageBox::information(this, "warning", "Kode Realisasi Tidak Boleh Sama");

        ui->kodeCadanganComboBox->setCurrentText(duplicate.value(1).toString());
        ui->dSBLineEdit->setText(duplicate.value(2).toString());
        ui->iSBLineEdit->setText(duplicate.value(3).toString());
        ui->tSBLineEdit->setText(duplicate.value(4).toString());
        ui->pSBLineEdit->setText(duplicate.value(5).toString());

        return;
    }

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
        QMessageBox::information(this, "information", "Data Berhasil Disimpan");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableRealisasi();
    clearFormInput();
}


void FormRealisasi::on_pushButtonEdit_clicked()
{
    realisasi.setKodeRealisasi(ui->kodeRealisasiLineEdit->text());
    realisasi.setKodeCadangan(ui->kodeCadanganComboBox->currentText());
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
        QMessageBox::information(this, "information", "Data Berhasil Diubah");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableRealisasi();
    clearFormInput();
}


void FormRealisasi::on_pushButtonDelete_clicked()
{
    realisasi.setKodeRealisasi(ui->kodeRealisasiLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM realisasi WHERE kd_real = :kd_real");
    sql.bindValue(":kd_real", realisasi.getKodeRealisasi());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Dihapus");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableRealisasi();
    clearFormInput();
}


void FormRealisasi::on_pushButtonClear_clicked()
{
    clearFormInput();
}


void FormRealisasi::on_tableRealisasi_activated(const QModelIndex &index)
{
    int row = ui->tableRealisasi->currentIndex().row();
    ui->kodeRealisasiLineEdit->setText(ui->tableRealisasi->model()->data(ui->tableRealisasi->model()->index(row, 0)).toString());
    ui->kodeCadanganComboBox->setCurrentText(ui->tableRealisasi->model()->data(ui->tableRealisasi->model()->index(row, 1)).toString());
    ui->dSBLineEdit->setText(ui->tableRealisasi->model()->data(ui->tableRealisasi->model()->index(row, 2)).toString());
    ui->iSBLineEdit->setText(ui->tableRealisasi->model()->data(ui->tableRealisasi->model()->index(row, 3)).toString());
    ui->tSBLineEdit->setText(ui->tableRealisasi->model()->data(ui->tableRealisasi->model()->index(row, 4)).toString());
    ui->pSBLineEdit->setText(ui->tableRealisasi->model()->data(ui->tableRealisasi->model()->index(row, 5)).toString());
}

