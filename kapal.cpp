#include "kapal.h"

Kapal::Kapal() {}

void Kapal::setNamaKapal(QString namaKapal)
{
    this->namaKapal = namaKapal;
}

QString Kapal::getNamaKapal()
{
    return this->namaKapal;
}

void Kapal::setInstansi(QString instansi)
{
    this->instansi = instansi;
}

QString Kapal::getInstansi()
{
    return this->instansi;
}

void Kapal::setKedalamanGali(QString kedalamanGali)
{
    this->kedalamanGali = kedalamanGali;
}

QString Kapal::getKedalamanGali()
{
    return this->kedalamanGali;
}
