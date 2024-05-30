#ifndef KAPAL_H
#define KAPAL_H
#include <QString>

class Kapal
{
public:
    Kapal();

    void setNamaKapal(QString namaKapal);
    QString getNamaKapal();

    void setInstansi(QString instansi);
    QString getInstansi();

    void setKedalamanGali(QString kedalamanGali);
    QString getKedalamanGali();

private:
    QString namaKapal, instansi, kedalamanGali;
};

#endif // KAPAL_H
