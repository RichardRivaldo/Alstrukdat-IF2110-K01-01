/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressList dengan pointer */
/* listInfo adalah string */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"
#include "MatriksOfString.h"
#include "customString.h"

typedef str listInfo;
typedef struct tElmtlist *addressList;
typedef struct tElmtlist {
	listInfo info;
	addressList next;
} ElmtList;
typedef struct {
	addressList First;
} List;

/* Definisi list : */
/* List kosong : First(L) = NULL*/
/* Setiap elemen dengan addressList P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressListnya Last, maka Next(Last)=NULL*/

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList Alokasi (listInfo X);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL*/
/* Jika alokasi gagal, mengirimkan NULL*/
void Dealokasi (addressList *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, listInfo X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, listInfo X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, listInfo X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, listInfo X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: e1 -> e2 -> ... -> en. */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: 1 -> 20 -> 30. */
/* Jika list kosong : menulis blank */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */



#endif