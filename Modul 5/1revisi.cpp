#include <iostream>
using namespace std;

char nama[] = "ahmad alif pratama putra";
char nim[] = "2410817310013";

void tukar(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void tekanEnter() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get(); 
}

int panjang(const char teks[]) {
    int i = 0;
    while (teks[i] != '\0') i++;
    return i;
}

void salin(char tujuan[], const char sumber[]) {
    int i = 0;
    while (sumber[i] != '\0') {
        tujuan[i] = sumber[i];
        i++;
    }
    tujuan[i] = '\0';
}

void hapusSpasi(char data[]) {
    int j = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] != ' ') {
            data[j++] = data[i];
        }
    }
    data[j] = '\0';
}

void insertionSort(char data[]) {
    int len = panjang(data);
    for (int i = 1; i < len; i++) {
        char key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void merge(char data[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    char L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = data[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) data[k++] = L[i++];
        else data[k++] = R[j++];
    }

    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
}

void mergeSort(char data[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

void shellSort(char data[]) {
    int n = panjang(data);
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = data[i];
            int j = i;
            while (j >= gap && data[j - gap] > temp) {
                data[j] = data[j - gap];
                j -= gap;
            }
            data[j] = temp;
        }
    }
}

int partition(char data[], int low, int high) {
    char pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] <= pivot) {
            i++;
            tukar(data[i], data[j]);
        }
    }
    tukar(data[i + 1], data[high]);
    return i + 1;
}

void quickSort(char data[], int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

void bubbleSort(char data[]) {
    int n = panjang(data);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (data[j] > data[j+1]) {
                tukar(data[j], data[j+1]);
            }
        }
    }
}

void selectionSort(char data[]) {
    int n = panjang(data);
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (data[j] < data[minIdx]) minIdx = j;
        }
        tukar(data[i], data[minIdx]);
    }
}

int main() {
    int pilihan;
    char temp[100];

    do {
        cout << "-------------------------------\n";
        cout << "|           SORTING           |\n";
        cout << "-------------------------------\n";
        cout << " 1. Insertion Sort\n";
        cout << " 2. Merge Sort\n";
        cout << " 3. Shell Sort\n";
        cout << " 4. Quick Sort\n";
        cout << " 5. Bubble Sort\n";
        cout << " 6. Selection Sort\n";
        cout << " 7. Keluar\n";
        cout << "-------------------------------\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;
        cin.get();

        cout << endl;
        switch(pilihan) {
            case 1:
                salin(temp, nama);
                hapusSpasi(temp);
                cout << "=== INSERTION SORT ===\n";
                cout << "Sebelum: " << nama << endl;
                insertionSort(temp);
                cout << "Sesudah: " << temp << endl;
                tekanEnter();
                break;
            case 2:
                salin(temp, nama);
                hapusSpasi(temp);
                cout << "=== MERGE SORT ===\n";
                cout << "Sebelum: " << nama << endl;
                mergeSort(temp, 0, panjang(temp) - 1);
                cout << "Sesudah: " << temp << endl;
                tekanEnter();
                break;
            case 3:
                salin(temp, nama);
                hapusSpasi(temp);
                cout << "=== SHELL SORT ===\n";
                cout << "Sebelum: " << nama << endl;
                shellSort(temp);
                cout << "Sesudah: " << temp << endl;
                tekanEnter();
                break;
            case 4:
                salin(temp, nim);
                cout << "=== QUICK SORT ===\n";
                cout << "Sebelum: " << temp << endl;
                quickSort(temp, 0, panjang(temp) - 1);
                cout << "Sesudah: " << temp << endl;
                tekanEnter();
                break;
            case 5:
                salin(temp, nim);
                cout << "=== BUBBLE SORT ===\n";
                cout << "Sebelum: " << temp << endl;
                bubbleSort(temp);
                cout << "Sesudah: " << temp << endl;
                tekanEnter();
                break;
            case 6:
                salin(temp, nim);
                cout << "=== SELECTION SORT ===\n";
                cout << "Sebelum: " << temp << endl;
                selectionSort(temp);
                cout << "Sesudah: " << temp << endl;
                tekanEnter();
                break;
            case 7:
                cout << "=== TERIMA KASIH ===\n";
                cout << "Program selesai!\n";
                cout << "Created by: Ahmad Alif Pratama Putra (2410817310013)" << endl;
                tekanEnter();
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                tekanEnter();
        }

        if (pilihan != 7)
            system("cls");

    } while (pilihan != 7);

    return 0;
}