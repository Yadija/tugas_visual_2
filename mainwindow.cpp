#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    formUser = new FormUser;
    formWilayah = new FormWilayah;
    formKapal = new FormKapal;
    formIUP = new FormIUP;
    formCadangan = new FormCadangan;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonFormUser_clicked()
{
    formUser->show();
}


void MainWindow::on_pushButtonFormWilayah_clicked()
{
    formWilayah->show();
}


void MainWindow::on_pushButtonFormKapal_clicked()
{
    formKapal->show();
}


void MainWindow::on_pushButtonFormIUP_clicked()
{
    formIUP->show();
}


void MainWindow::on_pushButtonFormCadangan_clicked()
{
    formCadangan->show();
}

