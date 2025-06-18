#include <iostream>

using namespace std ;

struct Mhs
{
    char Nama[20], Nim[10], Jurusan[2];
    int sks, program;
};

struct Mhs bayar[2];

main(){
    int bts, var, tetap;
    for (int i=0; i<2; i++)
    {
        cout << "\n\n-----------------------------\n";
        cout << "\nNama Mhs               = "; cin >> bayar[i].Nama;
        cout << "NIM                    = "; cin >> bayar[i].Nim;
        cout << "Jurusan[TI, PTK]       = "; cin >> bayar[i].Jurusan;
        input: 
            cout << "Program [1=D3, 2=S1]   = ";
            cin >> bayar[i].program;

            if(bayar[i].program<0 || bayar[i].program>2)
            {
                cout << "program tidak sesuai\n";
                goto input;
            }
            cout << "Jumlah sks             = "; cin >> bayar[i].sks;
            
            if (bayar[i].program==1)
            {
                tetap = 500000;
                var = bayar[i].sks*25000;
            }
            
            else if (bayar[i].program==2)
            {
                tetap = 750000;
                var = bayar[i].sks*50000;
            }
            cout << endl;

            cout << "\n\n----------------------------\n";
            cout << "Output ";
            cout << "\n------------------------------\n";
            cout << "\nNama Mhs      = " << bayar[i].Nama;
            cout << "\nNIM           = " << bayar[i].Nim;
            cout << "\nJurusan       = " << bayar[i].Jurusan;
            cout << "\nProgram       = " << bayar[i].program;
            cout << "\nJumlah sks    = " << bayar[i].sks;
            cout << "\nnSPP tetap    = " << tetap;
            cout << "\nnSPP variabel = " << var;
            cout << endl << endl;
    }
}