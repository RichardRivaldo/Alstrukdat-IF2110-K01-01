#ifndef wahana_H
#define wahana_H

#include "boolean.h"
#include "point.h"
#include "lokasi.h"

#define Nil -1 //wahana yang kosong diberi ini
#define MaxEl 100 //100 wahana

typedef struct{
    char nama[255];
    int kapasitas;
    int profit;
    int durasi;
    int reparationTime;
    int status;
    char deskripsi[255];
    Lokasi lokasi;
    int qtyAll;
    int incomeAll;
    int qty;
    int income;
} Wahana;

extern Wahana CWahana;

//setter and getter
#define nama(W) (W).nama
#define kapasitas(W) (W).kapasitas
#define profit(W) (W).profit
#define durasi(W) (W).durasi
#define reparationTime(W) (W).reparationTime
#define status(W) (W).status
#define deskripsi(W) (W).deskripsi
#define lokasi(W) (W).lokasi
#define qtyAll(W) (W).qtyAll
#define incomeAll(W) (W).incomeAll
#define qty(W) (W).qty
#define income(W) (W).income

void displayWahana(Wahana wahana);

void setQtyAll(Wahana * wahana);

Wahana findWahana(Wahana listWahana[], char nama[]);

boolean IsNotFull(Wahana wahana);

boolean IsNotBroken(Wahana wahana);

boolean IsBuilt(Wahana wahana);

#endif