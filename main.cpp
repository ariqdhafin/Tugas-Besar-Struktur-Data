#include <iostream>
#include "TUBES.h"

using namespace std;

int main()
{
    listTim T;
    listAnggota A;
    adrTim P;
    adrAnggota Q;
    infotypeTim x;
    infotypeAnggota y;
    int N; string namaTim, namaAnggota;

    createlistTim(T);
    createlistAnggota(A);

    string pilihan = printMenu();

    while(pilihan != "6"){
        system("cls");
        if(pilihan == "1"){
            while(pilihan != "4"){
                cout << "------------------------------------------------" << endl;
                cout << "1. Tambahkan tim baru" <<endl;
                cout << "2. Tambahkan anggota baru" << endl;
                cout << "3. Tambahkan anggota kedalam tim" << endl;
                cout << "4. Kembali" << endl;
                cout << "------------------------------------------------" << endl;
                cout << "Masukkan pilihan: "; cin>>pilihan;
                cout << endl;

                while(pilihan != "1" && pilihan != "2" && pilihan != "3" && pilihan != "4"){
                    cout << "Input invalid" << endl;
                    cout << "Masukkan pilihan: "; cin>>pilihan;
                    cout << endl;
                }

                system("cls");

                if(pilihan == "1"){
                    addElemenTim(T);
                }else if(pilihan == "2"){
                    addElemenAnggota(A);
                }else if(pilihan == "3"){
                    connectedFam(T,A);
                }
            }
            system("cls");
        }else if(pilihan == "2"){
            while(pilihan != "3"){
                cout << "------------------------------------------------" << endl;
                cout << "1. Cari tim" << endl;
                cout << "2. Cari anggota" << endl;
                cout << "3. Kembali" << endl;
                cout << "------------------------------------------------" << endl;
                cout << "Masukkan pilihan: "; cin>>pilihan;
                cout << endl;

                while(pilihan != "1" && pilihan != "2" && pilihan != "3"){
                    cout << "Input invalid" << endl;
                    cout << "Masukkan pilihan: "; cin>>pilihan;
                    cout << endl;
                }

                system("cls");

                if(pilihan == "1"){
                    cout<< "Masukkan nama tim yang ingin dicari: "; cin >> namaTim;
                    P = findTim(T,namaTim);
                    if(P  == NULL){
                        cout << "Nama tim tidak terdaftar"<<endl;
                        cout << endl;
                    }else{
                        cout << "Nama Tim : "<< info(P).nama<<endl;
                        cout << "Nama Pelatih: "<< info(P).pelatih<<endl;
                        cout << "Jumlah Anggota: " << info(P).jumlahAnggota << endl;
                        cout << endl;
                    }
                }else if(pilihan == "2"){
                    cout << "Masukkan nama anggota yang ingin dicari: "; cin >> namaAnggota;
                    Q = findAnggota(A, namaAnggota);
                    if(Q == NULL){
                        cout<< "Nama anggota tidak terdaftar" << endl;
                        cout << endl;
                    } else {
                        cout << "Nama Anggota: " << info(Q).nama << endl;
                        cout << "Umur Anggota: " << info(Q).umur << endl;
                        cout << endl;
                    }
                }

            }
        }else if(pilihan == "3"){
            while(pilihan != "4"){
                cout << "------------------------------------------------" << endl;
                cout << "1. Hapus Tim" <<endl;
                cout << "2. Hapus Anggota" << endl;
                cout << "3. Hapus Anggota dari Tim" << endl;
                cout << "4. Kembali" << endl;
                cout << "------------------------------------------------" << endl;
                cout << "Masukkan pilihan: "; cin>>pilihan;
                cout << endl;

                while(pilihan != "1" && pilihan != "2" && pilihan != "3" && pilihan != "4"){
                    cout << "Input invalid" << endl;
                    cout << "Masukkan pilihan: "; cin>>pilihan;
                    cout << endl;
                }

                system("cls");

                if(pilihan == "1"){
                    deleteTim(T, A);
                }else if (pilihan == "2"){
                    deleteAnggota(T,A);
                }else if (pilihan == "3"){
                    deleteAnggotadaritim(T,A);
                }

                system("cls");
            }
        }else if(pilihan == "4"){
            while(pilihan != "3"){
                cout << "------------------------------------------------" << endl;
                cout << "1. Nama tim dengan anggota terbanyak" <<endl;
                cout << "2. Nama tim dengan anggota tersedikit" << endl;
                cout << "3. Kembali" << endl;
                cout << "------------------------------------------------" << endl;
                cout << "Masukkan pilihan: "; cin>>pilihan;
                cout << endl;

                system("cls");

                while(pilihan != "1" && pilihan != "2" && pilihan != "3"){
                    cout << "Input invalid" << endl;
                    cout << "Masukkan pilihan: "; cin>>pilihan;
                    cout << endl;
                }

                if(pilihan == "1"){
                    maxAnggota(T,A);
                }else if (pilihan == "2"){
                    minAnggota(T,A);
                }
            }
        }else if(pilihan == "5"){
            while(pilihan != "3"){
                cout << "------------------------------------------------" << endl;
                cout << "1. Tampilkan semua" <<endl;
                cout << "2. Tampilkan jumlah tim dan anggota keseluruhan" << endl;
                cout << "3. Kembali" << endl;
                cout << "------------------------------------------------" << endl;
                cout << "Masukkan pilihan: "; cin>>pilihan;
                cout << endl;

                system("cls");

                while(pilihan != "1" && pilihan != "2" && pilihan != "3"){
                    cout << "Input invalid" << endl;
                    cout << "Masukkan pilihan: "; cin>>pilihan;
                    cout << endl;
                }

                if(pilihan == "1"){
                    printAll(T,A);
                }else if (pilihan == "2"){
                    printTimdanAnggota(T,A);
                }
            }
        }else{
            cout<<"Input invalid"<<endl;
            cout<<endl;
        }
        pilihan = printMenu();
    }
    cout<<"Anda telah keluar dari program"<<endl;
}
