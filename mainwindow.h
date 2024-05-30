#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <formuser.h>
#include <formwilayah.h>
#include <formkapal.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonFormUser_clicked();

    void on_pushButtonFormWilayah_clicked();

    void on_pushButtonFormKapal_clicked();

private:
    Ui::MainWindow *ui;
    FormUser *formUser;
    FormWilayah *formWilayah;
    FormKapal *formKapal;
};
#endif // MAINWINDOW_H
