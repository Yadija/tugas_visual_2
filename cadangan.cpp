#include "cadangan.h"

Cadangan::Cadangan() {}

void Cadangan::setKodeCadangan(QString kodeCadangan)
{
    this->kodeCadangan = kodeCadangan;
}

QString Cadangan::getKodeCadangan()
{
    return kodeCadangan;
}

void Cadangan::setNamaKapal(QString namaKapal)
{
    this->namaKapal = namaKapal;
}

QString Cadangan::getNamaKapal()
{
    return this->namaKapal;
}

void Cadangan::setBulan(QString bulan)
{
    this->bulan = bulan;
}

QString Cadangan::getBulan()
{
    return this->bulan;
}

void Cadangan::setTahun(QString tahun)
{
    this->tahun = tahun;
}

QString Cadangan::getTahun()
{
    return this->tahun;
}

void Cadangan::setNomorIUP(QString nomorIUP)
{
    this->nomorIUP = nomorIUP;
}

QString Cadangan::getNomorIUP()
{
    return this->nomorIUP;
}

void Cadangan::setLaut(QString laut)
{
    this->laut = laut;
}

QString Cadangan::getLaut()
{
    return this->laut;
}

void Cadangan::setLuas(QString luas)
{
    this->luas = luas;
}

QString Cadangan::getLuas()
{
    return this->luas;
}

void Cadangan::setDDH(QString ddh)
{
    this->ddh = ddh;
}

QString Cadangan::getDDH()
{
    return this->ddh;
}

void Cadangan::setIDH(QString idh)
{
    this->idh = idh;
}

QString Cadangan::getIDH()
{
    return this->idh;
}

void Cadangan::setTDH(QString tdh)
{
    this->tdh = tdh;
}

QString Cadangan::getTDH()
{
    return this->tdh;
}

void Cadangan::setPDH(QString pdh)
{
    this->pdh = pdh.toDouble();
}

double Cadangan::getPDH()
{
    return this->pdh;
}
