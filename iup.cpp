#include "iup.h"

IUP::IUP() {}

void IUP::setNomorIUP(QString nomorIUP)
{
    this->nomorIUP = nomorIUP;
}

QString IUP::getNomorIUP()
{
    return this->nomorIUP;
}

void IUP::setLokasi(QString lokasi)
{
    this->lokasi = lokasi;
}

QString IUP::getLokasi()
{
    return this->lokasi;
}

void IUP::setNomorSK(QString nomorSK)
{
    this->nomorSK = nomorSK;
}

QString IUP::getNomorSK()
{
    return this->nomorSK;
}

void IUP::setTanggalBerlaku(QString tanggalBerlaku)
{
    this->tanggalBerlaku = tanggalBerlaku;
}

QString IUP::getTanggalBerlaku()
{
    return this->tanggalBerlaku;
}

void IUP::setNomorSertifikat(QString nomorSertifikat)
{
    this->nomorSertifikat = nomorSertifikat;
}

QString IUP::getNomorSertifikat()
{
    return this->nomorSertifikat;
}

void IUP::setKeterangan(QString keterangan)
{
    this->keterangan = keterangan;
}

QString IUP::getKeterangan()
{
    return this->keterangan;
}
