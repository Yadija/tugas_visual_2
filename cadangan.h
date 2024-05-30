#ifndef CADANGAN_H
#define CADANGAN_H
#include <QString>

class Cadangan
{
public:
    Cadangan();

    void setKodeCadangan(QString kodeCadangan);
    QString getKodeCadangan();

    void setNamaKapal(QString namaKapal);
    QString getNamaKapal();

    void setBulan(QString bulan);
    QString getBulan();

    void setTahun(QString tahun);
    QString getTahun();

    void setNomorIUP(QString nomorIUP);
    QString getNomorIUP();

    void setLaut(QString laut);
    QString getLaut();

    void setLuas(QString luas);
    QString getLuas();

    void setDDH(QString ddh);
    QString getDDH();

    void setIDH(QString idh);
    QString getIDH();

    void setTDH(QString tdh);
    QString getTDH();

    void setPDH(QString pdh);
    double getPDH();

private:
    QString kodeCadangan, namaKapal, bulan, tahun, nomorIUP, laut, luas, ddh, idh, tdh;
    double pdh;
};

#endif // CADANGAN_H
