#include "formcadangan.h"
#include "ui_formcadangan.h"

FormCadangan::FormCadangan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormCadangan)
{
    ui->setupUi(this);

    Cadangan cadangan;

    loadTableCadangan();
}

void FormCadangan::loadTableCadangan()
{
    tableModel = new QSqlQueryModel(this);
    tableModel->setQuery("SELECT * FROM cadangan ORDER BY kd_cad ASC");

    tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Kode Cadangan"));
    tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Kapal"));
    tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Bulan"));
    tableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Tahun"));
    tableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Nomor IUP"));
    tableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Laut"));
    tableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Luas"));
    tableModel->setHeaderData(7, Qt::Horizontal, QObject::tr("DDH"));
    tableModel->setHeaderData(8, Qt::Horizontal, QObject::tr("IDH"));
    tableModel->setHeaderData(9, Qt::Horizontal, QObject::tr("TDH"));
    tableModel->setHeaderData(10, Qt::Horizontal, QObject::tr("PDH"));

    ui->tableCadangan->setModel(tableModel);
    ui->tableCadangan->setColumnWidth(0, 100);
    ui->tableCadangan->setColumnWidth(1, 100);
    ui->tableCadangan->setColumnWidth(2, 100);
    ui->tableCadangan->setColumnWidth(3, 100);
    ui->tableCadangan->setColumnWidth(4, 100);
    ui->tableCadangan->setColumnWidth(5, 100);
    ui->tableCadangan->setColumnWidth(6, 100);
    ui->tableCadangan->setColumnWidth(7, 100);
    ui->tableCadangan->setColumnWidth(8, 100);
    ui->tableCadangan->setColumnWidth(9, 100);
    ui->tableCadangan->setColumnWidth(10, 100);
}

FormCadangan::~FormCadangan()
{
    delete ui;
}

void FormCadangan::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    ui->namaKapalComboBox->clear();
    ui->nomorIUPComboBox->clear();

    QSqlQuery sql(connect);

    sql.prepare("SELECT kapal.nm_kpl, iup.no_iup FROM kapal, iup");
    sql.exec();
    while(sql.next()) {
        QString namaKapal = sql.value(sql.record().indexOf("nm_kpl")).toString();
        QString nomorIUP = sql.value(sql.record().indexOf("no_iup")).toString();
        ui->namaKapalComboBox->addItem(namaKapal);
        ui->nomorIUPComboBox->addItem(nomorIUP);
    }
}

void FormCadangan::on_pushButtonAdd_clicked()
{
    cadangan.setKodeCadangan(ui->kodeCadanganLineEdit->text());
    cadangan.setNamaKapal(ui->namaKapalComboBox->currentText());
    cadangan.setBulan(ui->bulanLineEdit->text());
    cadangan.setTahun(ui->tahunLineEdit->text());
    cadangan.setNomorIUP(ui->nomorIUPComboBox->currentText());
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
        QMessageBox::information(this, "information", "Data Berhasil Disimpan");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableCadangan();
}


void FormCadangan::on_pushButtonEdit_clicked()
{
    cadangan.setKodeCadangan(ui->kodeCadanganLineEdit->text());
    cadangan.setNamaKapal(ui->namaKapalComboBox->currentText());
    cadangan.setBulan(ui->bulanLineEdit->text());
    cadangan.setTahun(ui->tahunLineEdit->text());
    cadangan.setNomorIUP(ui->nomorIUPComboBox->currentText());
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
        QMessageBox::information(this, "information", "Data Berhasil Diubah");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableCadangan();
}


void FormCadangan::on_pushButtonDelete_clicked()
{
    cadangan.setKodeCadangan(ui->kodeCadanganLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM cadangan WHERE kd_cad = :kd_cad");
    sql.bindValue(":kd_cad", cadangan.getKodeCadangan());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Dihapus");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableCadangan();
}

