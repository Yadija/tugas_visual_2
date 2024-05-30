#include "realisasi.h"

Realisasi::Realisasi() {}

void Realisasi::setKodeRealisasi(QString kodeRealisasi)
{
    this->kodeRealisasi = kodeRealisasi;
}

QString Realisasi::getKodeRealisasi()
{
    return this->kodeRealisasi;
}

void Realisasi::setKodeCadangan(QString kodeCadangan)
{
    this->kodeCadangan = kodeCadangan;
}

QString Realisasi::getKodeCadangan()
{
    return this->kodeCadangan;
}

void Realisasi::setDSB(QString dsb)
{
    this->dsb = dsb;
}

QString Realisasi::getDSB()
{
    return this->dsb;
}

void Realisasi::setISB(QString isb)
{
    this->isb = isb;
}

QString Realisasi::getISB()
{
    return this->isb;
}

void Realisasi::setTSB(QString tsb)
{
    this->tsb = tsb;
}

QString Realisasi::getTSB()
{
    return this->tsb;
}

void Realisasi::setPSB(QString psb)
{
    this->psb = psb.toDouble();
}

double Realisasi::getPSB()
{
    return this->psb;
}
