#include <iostream>
using namespace std;

class RekeningBank
{
protected:
    string nomorRekening;
    double saldo;

public:
    RekeningBank(string no, double saldoAwal)
        : nomorRekening(no), saldo(saldoAwal) {}

    virtual void potongAdmin() = 0;

    void tampilkanInfo() {
        cout << "No Rek : " << nomorRekening
             << " | Saldo Akhir : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string no, double saldoAwal)
        : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        cout << "Rekening Syariah: Tidak ada potongan admin bulanan." << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string no, double saldoAwal)
        : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Rekening Konvensional: Potongan admin Rp 15.000 berhasil dilakukan." << endl;
    }
};
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string no, double saldoAwal)
        : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Rekening Premium: Bebas biaya admin karena saldo di atas Rp 10.000.000." << endl;
        } else {
            saldo -= 50000;
            cout << "Rekening Premium: Potongan admin Rp 50.000 berhasil dilakukan." << endl;
        }
    }
};