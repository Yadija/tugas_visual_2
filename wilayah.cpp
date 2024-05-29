#include "wilayah.h"

Wilayah::Wilayah() {}

void Wilayah::setKodeWilayah(QString kodeWilayah)
{
    this->kodeWilayah = kodeWilayah;
}

QString Wilayah::getKodeWilayah()
{
    return this->kodeWilayah;
}

void Wilayah::setNamaWilayah(QString namaWilayah)
{
    this->namaWilayah = namaWilayah;
}

QString Wilayah::getNamaWilayah()
{
    return this->namaWilayah;
}
