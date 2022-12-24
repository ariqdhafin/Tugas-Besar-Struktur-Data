#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

using namespace std;
#include <iostream>

#define info(P) (P)->info
#define nextTim(P) (P)->nextTim
#define nextAnggota(P) (P)->nextAnggota
#define parent(P) (P)->parent
#define firstTim(T) ((T).firstTim)
#define firstAnggota(A) ((A).firstAnggota)

struct infotypeTim{
    string nama;
    string pelatih;
};

struct infotypeAnggota{
    string nama;
    string umur;
};

typedef struct elemenTim* adrTim;
typedef struct elemenAnggota* adrAnggota;

struct elemenTim{
    infotypeTim info;
    adrTim nextTim;
};

struct elemenAnggota{
    infotypeAnggota info;
    adrTim parent;
    adrAnggota nextAnggota;
};

struct listTim{
    adrTim firstTim;
};

struct listAnggota{
    adrAnggota firstAnggota;
};

void createlistTim(listTim &T);
void createlistAnggota(listAnggota &T);
adrTim newElemenTim(infotypeTim x);
adrAnggota newElemenAnggota(infotypeAnggota y);

#endif // TUBES_H_INCLUDED
