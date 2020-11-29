/*Driver untuk ADT Stack Aksi, dalam file stackt.c*/
#include <stdio.h>	
#include "boolean.h"
#include <stdlib.h>	
#include "point.h"
#include "stackt.h"
int main ()
{
	//KAMUS
	Stack S,S2;
	Aksi X,Aksi1,Aksi2,Aksi3;
	int mat[5];
	Lokasi lokasiWahana[barisMatriksWahana];
	//ALGORTIMA
	InitializeStack(&S); /*Menggunakan CreateEmpty dan CreateEmptyAksi X*/
	while(!IsEmptyStack(S))
	{
		Pop(&S,&X);
		printf("Money: %d,Time: %d,\n", X.Money,X.Time);
		printf("Materials: ");
		for (int i = 0; i < 5; ++i)
		{
			printf("%d ", X.Mat[i]);
		}
		printf("\nPoint wahana : ");
		for (int i = 0; i < barisMatriksWahana; ++i)
		{
			TulisPOINT(X.Wah[i].Koordinat);
		}
		printf("\n");
	}
	
	InitializeStack(&S);
	CreateEmptyAksi(&Aksi1);
	CreateEmptyAksi(&Aksi2);
	CreateEmptyAksi(&Aksi3);
	Aksi1.Money = 1;
	Aksi1.Time = 1;
	Aksi2.Money = 2;
	Aksi2.Time = 3;
	Aksi3.Money = 3;
	Aksi3.Time = 5;
	Aksi2.Mat[3] = 50;
	Aksi3.Wah[5] = CreateLokasi(MakePOINT(3,4),0);
	Push(&S, Aksi1);
	Push(&S, Aksi2);
	Push(&S, Aksi3);

	S2 = CopyStack(S);
	printf("\n");
	printf("Semua dibawah ini dari S2, yang di copy dari stack S\n");
	printf("stackToRequiredTime = %d\n", stackToRequiredTime(S2));
	printf("stackToRequiredMoney = %d\n", stackToRequiredMoney(S2));
	stackToMaterial(S2,mat);
	printf("stackToMaterial = %d %d %d %d %d\n", mat[0], mat[1], mat[2], mat[3], mat[4]);
	stackToLokasi(S2,lokasiWahana);
	for (int i = 0; i < barisMatriksWahana; ++i)
	{
		TulisPOINT(X.Wah[i].Koordinat);
	}
	printf("\n");

	return 0;
}