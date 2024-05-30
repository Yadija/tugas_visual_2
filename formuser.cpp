#include "formuser.h"
#include "ui_formuser.h"

FormUser::FormUser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormUser)
{
    ui->setupUi(this);

    User user;
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
        qDebug() << "Data Berhasil Disimpan";
    } else {
        qDebug() << sql.lastError().text();
    }
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
        qDebug() << "Data Berhasil Diubah";
    } else {
        qDebug() << sql.lastError().text();
    }
}


void FormUser::on_pushButtonDelete_clicked()
{
    user.setNik(ui->nIKLineEdit->text());

    QSqlQuery sql(connect);

    sql.prepare("DELETE FROM user WHERE nik = :nik");
    sql.bindValue(":nik", user.getNik());

    if(sql.exec()) {
        qDebug() << "Data Berhasil Dihapus";
    } else {
        qDebug() << sql.lastError().text();
    }
}

