#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase connect = QSqlDatabase::addDatabase("QODBC");
    connect.setDatabaseName("dsn_pertambangan");
    connect.setUserName("root");
    connect.setPassword("");

    if(connect.open()) {
        qDebug() << "Database terkoneksi";
    } else {
        qDebug() << connect.lastError().text();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
