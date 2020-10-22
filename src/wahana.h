#ifndef wahana_H
#define wahana_H

#include "boolean.h"
#include "point.h"

#define Nil -1 //wahana yang kosong diberi ini
#define MaxEl 100 //100 wahana

typedef struct{
    int id;
    char nama[255];
    char tipe[255];
    int harga;
    POINT point;
    int kapasitas;
    char deskripsi[255];
} Wahana;

extern Wahana CWahana;

//setter and getter
#define id(W) (W).id
#define nama(W) (W).nama
#define tipe(W) (W).tipe
#define harga(W) (W).harga
#define point(W) (W).point
#define kapasitas(W) (W).kapasitas
#define deskripsi(W) (W).deskripsi

#endif