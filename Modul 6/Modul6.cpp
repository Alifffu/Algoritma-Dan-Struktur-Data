#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void sequentialSearch() {
    system("cls");
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();

    cout << "Generating 100 number...\n";
    for (int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        cout << data[i] << " ";
    }
    cout << "\n\n";

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        cout << "Data ada, sebanyak " << counter << "!\n";
        cout << "pada indeks ke-" << save << endl;
    } else {
        cout << "Data tidak ada!\n";
    }
}

void binarySearch() {
    system("cls");
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data: ";
    cin >> n;
    int angka[n];

    for (int i = 0; i < n; i++) {
        cout << "Angka ke-[" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "\n=============================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }

    cout << "\n=============================================================\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true) {
        cout << "Angka ditemukan!\n";
    } else {
        cout << "Angka tidak ditemukan!\n";
    }
}

void penjelasan() {
    system("cls");
    cout << "Perbedaan Sequential dan Binary Searching:\n";
    cout << "Sequential Searching (pencarian sekuensial) memeriksa setiap elemen dalam daftar satu per satu dari awal hingga ditemukan atau data habis, sedangkan Binary Searching (pencarian biner) membagi daftar yang sudah terurut menjadi dua bagian dan hanya memeriksa bagian yang relevan, sehingga proses pencarian lebih cepat. Binary search membutuhkan data yang sudah terurut, sedangkan sequential search tidak.\n";
    cout << "Sequential Searching\n";
    cout << "Kelebihan: Dapat digunakan pada semua jenis data tanpa harus diurutkan terlebih dahulu.\n";
    cout << "Kekurangan: Tidak efisien untuk data besar karena harus memeriksa elemen satu per satu hingga ditemukan atau data habis.\n";
    cout << "Binary Searching\n";
    cout << "Kelebihan: Sangat cepat dan efisien untuk data besar karena jumlah perbandingan jauh lebih sedikit dibandingkan sequential search.\n";
    cout << "Kekurangan: Hanya dapat digunakan jika data sudah dalam keadaan terurut, sehingga membutuhkan proses tambahan jika data belum diurutkan.\n";
}

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                sequentialSearch();
                break;
            case 2:
                binarySearch();
                break;
            case 3:
                penjelasan();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

        if (pilihan != 4) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 4);

    return 0;
}