/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "point.h"

#define Nil -1
#define MaxElStack 20
#define barisMatriksWahana 8
/* Nil adalah stack dengan elemen kosong . */
typedef struct 
{
	int Money;
	int Time; //Dalam Detik, digunakan jam.h untuk menampilkan jam nanti
	int Mat[5]; //Isinya [Semen,Baja,Sekrup,Kayu,Primogem]
	POINT Wah[barisMatriksWahana];//Isinya koordinat untuk wahana [Rumah Kaca, Bianglala,ARungJeram, Roller Coaster, Impact]. <-1,-1> = Kosong;
} Aksi;


/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  Aksi T[MaxElStack]; /* tabel penyimpan elemen */
  int TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */


/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define TopMoney(S) (S).T[(S).TOP].Money
#define TopTime(S) (S).T[(S).TOP].Time
#define TopMat(S,i) (S).T[(S).TOP].Mat[i]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

void InitializeStack (Stack *S);
/*Fungsi untuk main stack aksi*/
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Aksi X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, Aksi* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

Stack CopyStack(Stack S);
//Return Stack baru, tak mengubah stack lama

int stackToRequiredTime(Stack S);
//Menjumlahkan semua time di stack

int stackToRequiredMoney(Stack S);
//Menjumlahkan semua Money di stack

void stackToMaterial(Stack S, int material[5]);
//Menjumlahkan semua material di stack

void stackToLokasi(Stack S, POINT lokasiWahana[barisMatriksWahana]);

void CreateEmptyAksi(Aksi *X);
//Membuat Aksi dengan Money = 0, Time = 0, Mat =[0,0,0,0,0], Wah = [<-1,-1>*5]


#endif
