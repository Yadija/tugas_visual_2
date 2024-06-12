#include "formuser.h"
#include "ui_formuser.h"

FormUser::FormUser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormUser)
{
    ui->setupUi(this);

    User user;

    loadTableUser();
}

void FormUser::loadTableUser()
{
    tableModel = new QSqlQueryModel(this);
    tableModel->setQuery("SELECT * FROM user ORDER BY nik ASC");

    tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("NIK"));
    tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Nama"));
    tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    tableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Role"));
    tableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("password"));

    ui->tableUser->setModel(tableModel);
    ui->tableUser->setColumnWidth(0, 100);
    ui->tableUser->setColumnWidth(1, 150);
    ui->tableUser->setColumnWidth(2, 200);
    ui->tableUser->setColumnWidth(3, 50);
    ui->tableUser->setColumnWidth(4, 100);

    ui->tableUser->show();
}

void FormUser::clearFormInput()
{
    ui->nIKLineEdit->setText("");
    ui->namaLineEdit->setText("");
    ui->emailLineEdit->setText("");
    ui->roleComboBox->setCurrentIndex(0);
    ui->passwordLineEdit->setText("");
}

FormUser::~FormUser()
{
    delete ui;
}

void FormUser::on_pushButtonAdd_clicked()
{
    user.setNik(ui->nIKLineEdit->text());
    user.setNama(ui->namaLineEdit->text());
    user.setEmail(ui->emailLineEdit->text());
    user.setRole(ui->roleComboBox->currentText());
    user.setPassword(ui->passwordLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("INSERT INTO user (nik, nama, email, role, password)"
                "VALUES (:nik, :nama, :email, :role, :password)");
    sql.bindValue(":nik", user.getNik());
    sql.bindValue(":nama", user.getNama());
    sql.bindValue(":email", user.getEmail());
    sql.bindValue(":role", user.getRole());
    sql.bindValue(":password", user.getPassword());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Disimpan");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableUser();
    clearFormInput();
}


void FormUser::on_pushButtonEdit_clicked()
{
    user.setNik(ui->nIKLineEdit->text());
    user.setNama(ui->namaLineEdit->text());
    user.setEmail(ui->emailLineEdit->text());
    user.setRole(ui->roleComboBox->currentText());
    user.setPassword(ui->passwordLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("UPDATE user SET nama = :nama, email = :email, role = :role, password = :password "
                "WHERE nik = :nik");
    sql.bindValue(":nik", user.getNik());
    sql.bindValue(":nama", user.getNama());
    sql.bindValue(":email", user.getEmail());
    sql.bindValue(":role", user.getRole());
    sql.bindValue(":password", user.getPassword());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Diubah");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableUser();
    clearFormInput();
}


void FormUser::on_pushButtonDelete_clicked()
{
    user.setNik(ui->nIKLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM user WHERE nik = :nik");
    sql.bindValue(":nik", user.getNik());

    if(sql.exec()) {
        QMessageBox::information(this, "information", "Data Berhasil Dihapus");
    } else {
        QMessageBox::information(this, "warning", sql.lastError().text());
    }

    loadTableUser();
    clearFormInput();
}

void FormUser::on_pushButtonClear_clicked()
{
    clearFormInput();
}


void FormUser::on_tableUser_activated(const QModelIndex &index)
{
    int row = ui->tableUser->currentIndex().row();
    ui->nIKLineEdit->setText(tableModel->data(tableModel->index(row, 0)).toString());
    ui->namaLineEdit->setText(tableModel->data(tableModel->index(row, 1)).toString());
    ui->emailLineEdit->setText(tableModel->data(tableModel->index(row, 2)).toString());
    ui->roleComboBox->setCurrentText(tableModel->data(tableModel->index(row, 3)).toString());
    ui->passwordLineEdit->setText(tableModel->data(tableModel->index(row, 4)).toString());
}

