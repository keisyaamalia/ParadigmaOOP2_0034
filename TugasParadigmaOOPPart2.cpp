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