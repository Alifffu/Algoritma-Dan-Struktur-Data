#include <iostream>
using namespace std;

struct Kendaraan {
    string plat;
    string jenis;
    string pemilik;
    string alamat;
    string kota;
};

int main() {
    Kendaraan k;

    k.plat = "DA1234MK";
    k.jenis = "RUSH";
    k.pemilik = "Andika Hartanto";
    k.alamat = "Jl. Kayu Tangi 1";
    k.kota = "Banjarmasin";

    cout << "Plat Nomor Kendaraan : " << k.plat << endl;
    cout << "Jenis Kendaraan : " << k.jenis << endl;
    cout << "Nama Pemilik : " << k.pemilik << endl;
    cout << "Alamat : " << k.alamat << endl;
    cout << "Kota : " << k.kota << endl;

    return 0;
}