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

/* Mengubah array of char menjadi integer */
int convertToInt(char data[]);

/* Mengubah array of char menjadi Point */
POINT convertToPoint(char data[]);

/* Memetakan array of char berdasarkan part yang sesuai kedalam struct wahana */
void mapToWahana(int part, char data[], Wahana * wahana);

/* Membaca 1 baris dari wahana.txt */
void readWahanaRow(char data[], Wahana* wahana);

/* Mencetak detil setiap wahana yang dibaca dari wahana.txt */
void cetakDetailWahana(Wahana* wahana);

#endif