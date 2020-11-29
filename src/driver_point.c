//NIM: 13519189
//Nama: Leonardus James Wang
/* File: driver_point.c */
/* Tanggal: 2 September 2020 */
/* *** DRIVER ABSTRACT DATA TYPE POINT *** */

#include "point.h"
#include <stdio.h>

int main ()
{
	POINT P, P1, P2, P0;
	BacaPOINT(&P);
	TulisPOINT(P);

	printf("Geser x+5, y+5\n");
	Geser(&P, 5.0, 5.0);
	TulisPOINT(P);

	printf("Putar 180\n");
	Putar(&P, 180);
	TulisPOINT(P);

	printf("NextX\n");
	P = NextX(P);
	TulisPOINT(P);

	printf("NextY\n");
	P = NextY(P);
	TulisPOINT(P);

	printf("Masukkan P1: ");
	BacaPOINT(&P1);

	printf("Masukkan P2: ");
	BacaPOINT(&P2);

	printf("NEQ?\n");
	if (NEQ(P1, P2) == true)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	printf("Masukkan P0: ");
	BacaPOINT(&P0);

	printf("isOrigin\n");
	if (IsOrigin(P0))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	
	printf("IsOnSbX\n");
	if (IsOnSbX(P0))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	printf("IsOnSbY\n");
	if (IsOnSbY(P0))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	TulisPOINT(P);
	printf("Titik P terdapat di kuadran: %d", Kuadran(P));

	printf("Titik P + (2,2) = \n");
	P = PlusDelta(P, 2.0,2.0);
	TulisPOINT(P);

	printf("Jarak P ke 0 = %.2f\n", Jarak0(P));
	printf("Panjang P1 ke P2 = %.2f\n", Panjang(P1,P2));

	printf("Geser P (2+2)");
	Geser(&P, 2.0 , 2.0);
	TulisPOINT(P);

	printf("Geser P1 ke Sbx\n");
	GeserKeSbX(&P1);
	TulisPOINT(P1);

	printf("Geser P2 ke SbY\n");
	GeserKeSbY(&P2);
	TulisPOINT(P2);

	printf("Tiik P: \n");
	TulisPOINT(P);
	Mirror(&P, true);
	printf("Mirror ke SbX\n");
	TulisPOINT(P);

	printf("Putar P 180 derajat\n");
	Putar(&P, 180);
	TulisPOINT(P);

	return 0;
}

