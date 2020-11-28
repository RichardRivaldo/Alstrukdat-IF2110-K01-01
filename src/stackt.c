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
void Push (Stack * S, Aksi X)
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
void Pop (Stack * S, Aksi* X)
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

Stack CopyStack(Stack S)
{
	//KAMUS
	Stack STemp;
	Stack SRet;
	Aksi X;
	//ALGORITMA
	CreateEmpty(&SRet);
	CreateEmpty(&STemp);
	while(!IsEmpty(S))
	{
		Pop(&S,&X);
		Push(&STemp,X);
	}
	while(!IsEmpty(STemp))
	{
		Pop(&STemp,&X);
		Push(&SRet,X);
		Push(&S,X);
	}
	return SRet;
}


int stackToRequiredTime(Stack S)
{
	//KAMUS
	Stack Stemp;
	Aksi x;
	int requiredTime;
	//ALGORIMTA
	Stemp = CopyStack(S);
	requiredTime = 0;
	while (!IsEmpty(Stemp))
	{
		Pop(&Stemp,&x);
		requiredTime += x.Time;
	}
	return requiredTime;
}

int stackToRequiredMoney(Stack S)
{
	//KAMUS
	Stack Stemp;
	Aksi x;
	int requiredMoney;
	//ALGORIMTA
	Stemp = CopyStack(S);
	requiredMoney = 0;
	while (!IsEmpty(Stemp))
	{
		Pop(&Stemp,&x);
		requiredMoney += x.Money;
	}
	return requiredMoney;
}

void stackToMaterial(Stack S, int material[5])
{
	//KAMUS
	Stack Stemp;
	Aksi x;
	int i;
	//ALGORIMTA
	Stemp = CopyStack(S);
	for (i = 0; i < 5; ++i)
	{
		material[i] = 0;
	}
	while (!IsEmpty(Stemp))
	{
		Pop(&Stemp,&x);
		for (i = 0; i < 5; ++i)
		{
			material[i] += x.Mat[i];
		}
	}
}

void stackToLokasi(Stack S, POINT lokasiWahana[barisMatriksWahana])
{
	//KAMUS
	Stack Stemp;
	Aksi x;
	int i;
	//ALGORIMTA
	Stemp = CopyStack(S);
	for (i = 0; i < barisMatriksWahana; ++i)
	{
		lokasiWahana[i] = MakePOINT(-1,-1);
	}
	while (!IsEmpty(Stemp))
	{
		Pop(&Stemp,&x);
		for (i = 0; i < barisMatriksWahana; ++i)
		{
			if (NEQ(x.Wah[i],MakePOINT(-1,-1)))
			{
				lokasiWahana[i] = x.Wah[i];
			}
		}
	}
}

void CreateEmptyAksi(Aksi *X)
{
	//KAMUS
	int i;
	//ALGORIMTA
	(*X).Money = 0;
	(*X).Time = 0;
	for (i = 0; i < 5; ++i)
	{
		(*X).Mat[i] = 0;
	}
	for (i = 0; i < barisMatriksWahana; ++i)
	{
		(*X).Wah[i] = MakePOINT(-1,-1);
	}
}