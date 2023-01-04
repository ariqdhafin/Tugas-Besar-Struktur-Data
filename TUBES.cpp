#include "TUBES.h"

void createlistTim(listTim &T){
    firstTim(T) = NULL;
}
void createlistAnggota(listAnggota &A){
    firstAnggota(A) = NULL;
}

adrTim newElemenTim(){
    infotypeTim x;
    cout << "Masukkan nama tim : ";  cin >> x.nama;
    cout << "Masukkan pelatih : "; cin >> x.pelatih;
    adrTim P = new elemenTim;
    info(P) = x;
    info(P).jumlahAnggota = 0;
    nextTim(P) = NULL;
    return P;
}

adrAnggota newElemenAnggota(){
    infotypeAnggota y;
    cout << "Masukkan nama pemain : ";  cin >> y.nama;
    cout << "Masukkan umur : "; cin >> y.umur;
    cout << "Masukkan posisi : "; cin >> y.posisi;
    adrAnggota P = new elemenAnggota;
    info(P) = y;
    parent(P) = NULL;
    nextAnggota(P) = NULL;
    return P;
}

void addElemenTim(listTim &T){
    adrTim Q;adrTim P;
    int N;

    cout << "Jumlah tim yang ingin dibuat: "; cin >> N;
    cout<<endl;
    while(N != 0){
        P = newElemenTim();
        if(firstTim(T) != NULL){
            Q = firstTim(T);
            while(nextTim(Q) != NULL){
                Q = nextTim(Q);
            }
            nextTim(Q) = P;
        }else{
            firstTim(T) = P;
        }
        nextTim(P) = NULL;
        N--;
        cout<< "Tim berhasil dibuat"<<endl;
        cout << endl;
    }
}

void addElemenAnggota(listAnggota &A){
    adrAnggota Q;adrAnggota P;
    int N;
    cout << "Jumlah pemain yang ingin dibuat: "; cin >> N;
    cout<<endl;
    while(N != 0){
        P = newElemenAnggota();
        if(firstAnggota(A) != NULL){
            Q = firstAnggota(A);
            while(nextAnggota(Q) != NULL){
                Q = nextAnggota(Q);
            }
            nextAnggota(Q) = P;
        }else{
            firstAnggota(A) = P;
        }
        nextAnggota(P) = NULL;
        parent(P) = NULL;
        N--;
        cout<< "Pemain berhasil dibuat"<<endl;
        cout << endl;
    }
}

adrTim findTim(listTim T,string namaTim){
    adrTim P = firstTim(T);

    if(firstTim(T) == NULL){
        return NULL;
    }else{
        while((info(P).nama != namaTim) && nextTim(P) != NULL){
            P = nextTim(P);
        }
        if (info(P).nama == namaTim){
            return P;
        }else{
            return NULL;
        }
    }
}

adrAnggota findAnggota(listAnggota A,string namaAnggota){
    adrAnggota P = firstAnggota(A);
    if(firstAnggota(A) == NULL){
        return NULL;
    }else{
        while((info(P).nama != namaAnggota) && nextAnggota(P) != NULL){
            P = nextAnggota(P);
        }
        if (info(P).nama == namaAnggota){
            return P;
        }else{
            return NULL;
        }
    }
}

void connectedFam(listTim &T, listAnggota &A){
    int N;int i = 0; string namaAnggota; string namaTim;
    string Back = "n";

    cout << "Nama Tim yang ingin dimasukkan: "; cin >> namaTim;
        adrTim P = findTim(T, namaTim);
        if (P != NULL) {
            cout << "Jumlah pemain yang ingin dimasukkan: "; cin >> N;
            cout<<endl;
            while (N != 0){
                cout << "Nama pemain yang ingin dimasukkan: "; cin >> namaAnggota;
                adrAnggota Q = findAnggota(A, namaAnggota);
                if (Q!= NULL){
                    parent(Q) = P;
                    cout << "Pemain berhasil ditambahkan" << endl;
                    cout<<endl;
                    i++;
                } else {
                    cout << "Pemain gagal ditambahkan" << endl;
                    cout<<endl;
                }
                N--;
            }

            info(P).jumlahAnggota = i;
        } else {
            cout << "Tim tidak ditemukan" << endl;
        }
    cout<<endl;
}

void printAll(listTim T,listAnggota A){
    adrTim P = firstTim(T);
    bool isEmpty = false;
    int j = 1;

    if (firstTim(T) != NULL){
        while(P != NULL){
            adrAnggota Q = firstAnggota(A);
            cout <<"["<<j<<"] "<<"Nama Tim\t : " << info(P).nama << endl;
            cout << "    Pelatih\t : " << info(P).pelatih << endl;
            cout << "    Banyak Pemain: " << info(P).jumlahAnggota << endl;
            cout << "    Pemain Tim\t : ";
            int i = 1;
            while(Q != NULL){
                if(parent(Q) == P){
                    if(i == 1){
                        cout << i << ". "<< info(Q).nama << endl;
                    }else{
                        cout <<"\t\t   "<<i << ". "<< info(Q).nama << endl;
                    }
                    isEmpty = true;
                    i++;
                }
                Q = nextAnggota(Q);
            }
            if (isEmpty == false){
                cout << "Pemain Tim kosong" << endl;
            }
            isEmpty = false;
            P = nextTim(P);
            j++;
            cout << endl;
        }
        cout<<"Pemain yang belum masuk tim :"<<endl;
        adrAnggota Q = firstAnggota(A);
        isEmpty = false;
        int i = 1;
        while(Q != NULL){
            if(parent(Q) == NULL){
                cout << i << "."<< info(Q).nama << endl;
                isEmpty = true;
                i++;
            }
            Q = nextAnggota(Q);
        }
        if (isEmpty == false){
                cout << " - " << endl;
            }
        isEmpty = false;
        cout << endl;
    } else {
        cout<<"Belum ada Tim"<<endl;
    }

    cout<<endl;
}

void printPemain(listAnggota A){
    adrAnggota P = firstAnggota(A);
    int i = 1;

    if (firstAnggota(A) != NULL){
        while(P != NULL){
            cout <<"["<< i << "] "<< "Nama Pemain\t: " << info(P).nama << endl;
            cout << "    Umur\t: " << info(P).umur << endl;
            cout << "    Posisi\t: " << info(P).posisi << endl;
            if(parent(P) != NULL){
                cout << "    Tim\t\t: " << info(parent(P)).nama<<endl;
            }else{
                cout << "    Tim\t\t: " << " - "<<endl;
            }
            i++;
            P = nextAnggota(P);
            cout << endl;
        }
    } else {
        cout<<"Belum ada Pemain"<<endl;
    }

    cout<<endl;
}

void printJumlahTimdanAnggota(listTim T,listAnggota A){
    adrTim P = firstTim(T);
    adrAnggota Q = firstAnggota(A);
    int jumlahTim = 0;
    int jumlahAnggota = 0;

    while(P != NULL){
        jumlahTim++;
        P = nextTim(P);
    }
    while(Q != NULL){
        jumlahAnggota++;
        Q = nextAnggota(Q);
    }
    cout<<"Jumlah Tim : "<<jumlahTim<<endl;
    cout<<"Jumlah Pemain : "<<jumlahAnggota<<endl;
}

void deleteTim(listTim &T,listAnggota &A){
    string namaTim;
    adrTim Q = firstTim(T);
    adrAnggota X = firstAnggota(A);

    cout << "Nama Tim yang ingin dihapus: "; cin >> namaTim;
    adrTim P = findTim(T, namaTim);
    if (P != NULL){
        if(P == firstTim(T)){
            firstTim(T) = nextTim(P);
            nextTim(P) = NULL;
        }else{
            while(nextTim(Q) != P){
                Q = nextTim(Q);
            }
            nextTim(Q) = nextTim(P);
            nextTim(P) = NULL;
        }
        if(firstAnggota(A) != NULL){
            while(X != NULL){
            cout<<"halo"<<endl;
            if (parent(X) == P){
                parent(X) = NULL;
            }
            X = nextAnggota(X);
        }
        }
        cout<<"Tim berhasil dihapus"<<endl;
    }else{
        cout<<"Tim tidak ditemukan"<<endl;
    }
    cout<<endl;
}

void deleteAnggota(listTim &T,listAnggota &A){
    string namaAnggota;
    adrAnggota Q = firstAnggota(A);
    cout << "Nama pemain yang ingin dihapus: "; cin >> namaAnggota;
    adrAnggota P = findAnggota(A, namaAnggota);

    if (P != NULL){
        if(P == firstAnggota(A)){
            firstAnggota(A) = nextAnggota(P);
            nextAnggota(P) = NULL;
        }else{
            while(nextAnggota(Q) != P){
                Q = nextAnggota(Q);
            }
            nextAnggota(Q) = nextAnggota(P);
            nextAnggota(P) = NULL;
        }
        cout<<"Pemain berhasil dihapus"<<endl;
        adrTim X = parent(P);
        if (X != NULL){
            info(X).jumlahAnggota = info(X).jumlahAnggota - 1;
        }
    }else{
        cout<<"Pemain tidak ditemukan"<<endl;
    }
    cout<<endl;
}

void deleteAnggotadaritim(listTim &T,listAnggota &A){
    string namaAnggota;
    cout << "Nama pemain yang ingin dihapus dari tim: "; cin >> namaAnggota;
    adrAnggota P = findAnggota(A, namaAnggota);

    if (P != NULL){
        adrTim X = parent(P);
        parent(P) = NULL;
        cout << "Pemain berhasil dihapus dari tim" << endl;
        if(X != NULL){
            info(X).jumlahAnggota = info(X).jumlahAnggota - 1 ;
        }
    } else {
        cout << "Pemain gagal dihapus dari tim" << endl;
    }
}

void maxAnggota(listTim T,listAnggota A){
    int i = 1;

    if(firstTim(T) != NULL){
        adrTim P = firstTim(T);
        int Max = info(P).jumlahAnggota;
        while(P != NULL){
            if (info(P).jumlahAnggota > Max){
                Max = info(P).jumlahAnggota;
            }
            P = nextTim(P);
        }

        cout<<"Tim dengan pemain terbanyak: "<<endl;
        P = firstTim(T);
        while(P != NULL){
            if (info(P).jumlahAnggota == Max){
                cout<<i<<"."<<info(P).nama<<endl;
                i++;
            }
            P = nextTim(P);
        }
        cout<<"Banyak pemain: "<<Max<<endl;
    }else{
        cout<<"Tidak ada Tim"<<endl;
    }
    cout<<endl;
}

void minAnggota(listTim T, listAnggota A){
    int i = 1;

    if(firstTim(T) != NULL){
        adrTim P = firstTim(T);
        int Min = info(P).jumlahAnggota;
        while(P != NULL){
            if (info(P).jumlahAnggota < Min){
                Min = info(P).jumlahAnggota;
            }
            P = nextTim(P);
        }
        cout<<"Tim dengan pemain tersedikit: "<<endl;

        P = firstTim(T);
        while(P != NULL){
            if (info(P).jumlahAnggota == Min){
                cout<<i<<"."<<info(P).nama<<endl;
                i++;
            }
            P = nextTim(P);
        }
        cout<<"Banyak pemain: "<<Min<<endl;
    }else{
        cout<<"Tidak ada Tim"<<endl;
    }
    cout<<endl;
}

string printMenu(listTim T,listAnggota A){
    string input;
    cout << "================================================" << endl;
    cout << "\t\tKLUB OLAH RAGA"<<endl;
    cout << "\t\t  SEPAK BOLA"<<endl;
    cout << "\t       TELKOM UNIVERSITY"<<endl;
    cout << "=====================MENU=======================" << endl;
    cout << "1. Tambahkan tim dan pemain" << endl;
    cout << "2. Cari tim dan pemain" << endl;
    cout << "3. Hapus tim dan pemain" << endl;
    cout << "4. Tim dengan pemain terbanyak dan tersedikit" << endl;
    cout << "5. Tampilkan tim beserta pemainya" << endl;
    cout << "6. Close program" << endl;
    cout << "------------------------------------------------" << endl;
    printJumlahTimdanAnggota(T,A);
    cout << "------------------------------------------------" << endl;
    cout << "Masukkan pilihan: "; cin>>input;

    cout<<endl;
    return input;
}
