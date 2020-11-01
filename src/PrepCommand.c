#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>
#include <math.h>
#include "stackt.h"
#include "jam.h"
#include "point.h"
#include <string.h>
#include "matriks.h"
#include "mesinkar.h"
#include "mesinkata.c"
#include <string.h>

void build(){
    FILE * fPointer = fopen("../data/wahana.txt", "r");
}

void buy(MATRIKS mat, Stack * act, int *Money, int *Time){
	//KAMUS
	int i,j;
	int jumlah;
	int harga;
	char cjumlah[];
	char namaMat[];
	Aksi X;
	//ALGORITMA
	i = 0;
	STARTKATA();
	strcpy(cjumlah, CKata);
	ADVKATA();
	strcpy(namaMat, CKata);

	while(strcmp(mat.Mem[i][0], namaMat) != 0 && i <= GetLastIdxBrs(M))
	{
		i++;
	}
	if (i > GetLastIdxBrs(M))
	{
		printf("Error, silahkan input ulang\n");
	}
	else
	{
		jumlah = atoi(cjumlah);
		harga = atoi(mat.Mem[i][1]);
		if (*Money >= jumlah*harga)
		{
			*Money = *Money - jumlah*harga
			X.Money = -1*jumlah*harga;
			X.Time = -5;
			for (j = 0; j < 5; ++j)
			{
				X.Mat[j] = 0;
				if (i == j)
				{
					X.Mat[j] = jumlah;
				}
			}

			Push(act, X);
		}
	}
}