/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MatriksOfString_H
#define MatriksOfString_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 15
#define KolMin 0
#define KolMax 15
#define lengthStr 50

typedef char str[lengthStr]; 
typedef struct { 
	str Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg dipakai */
	int NKolEff; /* banyaknya/ukuran kolom yg dipakai */
} MatriksOfString;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMatriksStr (int NB, int NK, MatriksOfString * M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

#endif