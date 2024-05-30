#ifndef REALISASI_H
#define REALISASI_H
#include <QString>

class Realisasi
{
public:
    Realisasi();

    void setKodeRealisasi(QString kodeRealisasi);
    QString getKodeRealisasi();

    void setKodeCadangan(QString kodeCadangan);
    QString getKodeCadangan();

    void setDSB(QString dsb);
    QString getDSB();

    void setISB(QString isb);
    QString getISB();

    void setTSB(QString tsb);
    QString getTSB();

    void setPSB(QString psb);
    double getPSB();

private:
    QString kodeRealisasi, kodeCadangan, dsb, isb, tsb;
    double psb;
};

#endif // REALISASI_H
