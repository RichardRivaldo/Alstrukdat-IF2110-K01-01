//NIM				: 13519189
//Nama				: Leonardus James Wang
//Tanggal			: 22 Oktober 2020
//Topik praktikum	: Stack, Praktikum 8
//Deskripsi			:
#include <stdio.h>
#include "boolean.h"
#include "listlinier.h"
#include "MatriksOfString.h"
#include "customString.h"
#include <stdlib.h>
//PROGRAM
int main ()
{
	//KAMUS
	List L;
	addressList P;
	listInfo X;
	//ALGORTIMA
	CreateEmpty(&L);
	P = Alokasi("5th");
	printf("Apakah List empty? %d\n", IsEmpty(L));
	InsVFirst(&L, "2nd");
	InsVLast(&L, "3rd");
	InsVFirst(&L, "1st");
	PrintInfo(L);
	DelVFirst (&L, X);
	DelVLast (&L, X);
	printf("\n");
	PrintInfo(L);
	printf("\n");
	printf("%s\n", X);
	return 0;
}
