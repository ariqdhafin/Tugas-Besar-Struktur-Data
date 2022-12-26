#include "TUBES.h"

void createlistTim(listTim &T){
    firstTim(T) = NULL;
}

void createlistAnggota(listAnggota &A){
    firstAnggota(A);
}

adrTim newElemenTim(infotypeTim x){
    adrTim P = new elemenTim;
    info(P) = x;
    nextTim(P) = NULL;
    return P;
}

adrAnggota newElemenAnggota(infotypeAnggota y){
    adrAnggota P = new elemenAnggota;
    info(P) = y;
    parent(P) = NULL;
    nextAnggota(P) = NULL;
    return P;
}

void addElemenTim(listTim &T, adrTim P){
    adrTim Q;

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
}

void addElemenAnggota(listAnggota &A, adrAnggota P){
    adrAnggota Q;

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

void printAll(listTim T,listAnggota A){
    // Belum selese buat ngetes doang

    adrTim P = firstTim(T);
    adrTim Q = firstAnggota(A);

    if (firstTim(T) != NULL){
        while(P != NULL){
            cout<<info(P).nama<<" ";
            P = nextTim(P);
        }
    }else{
        cout<<"List Tim Kosong"<<endl;
    }

    cout<<endl;

    if(firstAnggota(A) != NULL){
        while(Q != NULL){
            cout<<info(Q).nama<<" ";
            Q = nextAnggota(Q);
        }
    }else{
        cout<<"List Anggota Kosong"<<endl;
    }

    cout<<endl;
}
