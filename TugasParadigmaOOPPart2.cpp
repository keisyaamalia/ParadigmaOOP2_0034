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

int main() {

    RekeningBank* rekening1 = new RekeningSyariah("SYR001", 5000000);
    RekeningBank* rekening2 = new RekeningKonvensional("KON001", 3000000);
    RekeningBank* rekening3 = new RekeningPremium("PRM001", 12000000);
    RekeningBank* rekening4 = new RekeningPremium("PRM002", 7000000);

    cout << "=== Proses Potongan Admin Akhir Bulan ===" << endl;

    rekening1->potongAdmin();
    rekening1->tampilkanInfo();

    cout << endl;

    rekening2->potongAdmin();
    rekening2->tampilkanInfo();

    cout << endl;

    rekening3->potongAdmin();
    rekening3->tampilkanInfo();

    cout << endl;

    rekening4->potongAdmin();
    rekening4->tampilkanInfo();

    delete rekening1;
    delete rekening2;
    delete rekening3;
    delete rekening4;

    return 0;
}