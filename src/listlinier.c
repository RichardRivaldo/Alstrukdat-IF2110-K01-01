//NIM				: 13519189
//Nama				: Leonardus James Wang
//Tanggal			: 4 November 2020
//Topik praktikum	: List Linier, Praktikum 9
/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressList dengan pointer */
/* listInfo adalah integer */
#include <stdio.h>
#include "boolean.h"
#include "listlinier.h"
#include "MatriksOfString.h"
#include "customString.h"
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	//ALGORTIMA
	return (First(L) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	//ALGORITMA
	First(*L) = NULL;
}

/****************** Manajemen Memori ******************/
addressList Alokasi (listInfo X)
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak NULL, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
	//KAMUS
	addressList P;
	//ALGORITMA
	P = (addressList) malloc(sizeof(ElmtList));
	if (P != NULL)
	{
		StringCopy(lengthStr,Info(P),X);
		Next(P) = NULL;
	}
	return P;
}
void Dealokasi (addressList *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */
{
	//ALGORITMA
	Next(*P) = NULL;
	free(*P);
}



/****************** PRIMITIF BERDASARKAN NULLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, listInfo X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NULLai X jika alokasi berhasil */
{
	//KAMUS
	addressList P;
	//ALGORITMA
	P = Alokasi(X);
	if (IsEmpty(*L))
	{
		First(*L) = P;
	}
	else
	{
		Next(P) = First(*L);
		First(*L) = P;
	}
}
void InsVLast (List *L, listInfo X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNULLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	//KAMUS
	addressList P;
	addressList Last;
	//ALGORITMA
	if (IsEmpty(*L))
	{
		InsVFirst(L, X);
	}
	else
	{
		P = Alokasi(X);
		Last = First(*L);
		while(Next(Last) != NULL)
		{
			Last = Next(Last);
		}
		Next(Last) = P;
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, listInfo X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	//KAMUS
	addressList P;
	//ALGORTIMA
	P = First(*L);
	StringCopy(lengthStr,X,Info(P));
	if (Next(P) == NULL)
	{
		First(*L) = NULL;
	}
	else
	{
		First(*L) = Next(P);
	}
	Dealokasi(&P);
}
void DelVLast (List *L, listInfo X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//KAMUS
	addressList P, Last;
	//ALGORITMA
	P = First(*L);
	if (Next(P) == NULL)
	{
		StringCopy(lengthStr,X,Info(P));
		First(*L) = NULL;
	}
	else
	{
		while (Next(Next(P)) != NULL)
		{
			P = Next(P);
		}
		Last = Next(P);
		StringCopy(lengthStr,X,Info(Last));
		Dealokasi(&Last);
		Next(P) = NULL;
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	//KAMUS
	addressList P;
	//ALGORIMTA
	if (IsEmpty(L) == true)
	{
		printf("");
	}
	else
	{
		P = First(L);
		printf("%s", Info(P));
		while(Next(P) != NULL)
		{
			P = Next(P);
			printf("-> %s", Info(P));
		}
		printf(".");
	}
}

