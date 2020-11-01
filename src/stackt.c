//NIM				: 13519189
//Nama				: Leonardus James Wang
//Tanggal			: 20 Oktober 2020
//Topik praktikum	: Stack, Praktikum 8
//Deskripsi			:
#include <stdio.h>
#include "boolean.h"
#include "stackt.h"
//PROGRAM

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

{
	Top(*S) = Nil;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return (Top(S) == Nil ? true : false);
}
boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return (Top(S) == (MaxEl - 1) ? true : false);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	if (Top(*S) == Nil)
	{
		Top(*S) = 0;
	}
	else
	{
		Top(*S) = Top(*S) + 1;
	}
	InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = InfoTop(*S);
	if (Top(*S) == 0)
	{
		Top(*S) = Nil;
	}
	else
	{
		Top(*S) = Top(*S) - 1;
	}
}