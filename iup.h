#ifndef IUP_H
#define IUP_H
#include <QString>

class IUP
{
public:
    IUP();

    void setNomorIUP(QString nomorIUP);
    QString getNomorIUP();

    void setLokasi(QString lokasi);
    QString getLokasi();

    void setNomorSK(QString nomorSK);
    QString getNomorSK();

    void setTanggalBerlaku(QString tanggalBerlaku);
    QString getTanggalBerlaku();

    void setNomorSertifikat(QString nomorSertifikat);
    QString getNomorSertifikat();

    void setKeterangan(QString keterangan);
    QString getKeterangan();

private:
    QString nomorIUP, lokasi, nomorSK, tanggalBerlaku, nomorSertifikat, keterangan;
};

#endif // IUP_H
