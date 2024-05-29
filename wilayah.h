#ifndef WILAYAH_H
#define WILAYAH_H
#include <QString>

class Wilayah
{
public:
    Wilayah();

    void setKodeWilayah(QString kodeWilayah);
    QString getKodeWilayah();

    void setNamaWilayah(QString namaWilayah);
    QString getNamaWilayah();

private:
    QString kodeWilayah, namaWilayah;
};

#endif // WILAYAH_H
