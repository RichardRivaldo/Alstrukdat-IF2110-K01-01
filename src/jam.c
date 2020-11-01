/* File: jam.c */
/* Tanggal: 2 September 2020 */
/* *** Realisasi ABSTRACT DATA TYPE JAM *** */
#include <stdio.h>
#include "boolean.h"
#include "jam.h"


/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */



boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
	return (((0<=H && H<=23) && (0<=M && M <=59) && (0<=S && S <= 59))? true : false );
}


/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
	//KAMUS
	JAM J;
	//ALGORITMA
	Hour(J) = HH;
	Minute(J) = MM;
	Second(J) = SS;
	return J;
}


/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
	//KAMUS
	int HH, MM, SS;
	//ALGORITMA

	do {
		scanf("%d %d %d", &HH,&MM,&SS);
		if ((IsJAMValid(HH,MM,SS) == false))
		{
			printf("Jam tidak valid\n");
		}
	}while ((IsJAMValid(HH,MM,SS) == false));

	*J = MakeJAM(HH,MM,SS);
}


void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
{
	//ALGORITMA
	printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}




/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */

long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

{
	//ALGORITMA
	return (Hour(J)*3600 + Minute(J)*60 + Second(J) );
}


JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
	//KAMUS
	JAM J;
	//ALGORITMA
	N = N%86400;
	Hour(J) = N/3600;
	Minute(J) = (N%3600)/60;
	Second(J) = N%60;

	return J;
}


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
	//ALGORITMA
	return ( ( (Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2)) )  ? true : false);
}

boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
	//ALGORITMA
	return ( ( (Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2)) )  ? false : true);	
}


boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
	//KAMUS
	long d1,d2;
	//ALGORITMA

	d1 = JAMToDetik(J1);
	d2 = JAMToDetik(J2);
	return( (d1<d2) ? true : false);
}


boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
	//KAMUS
	long d1,d2;
	//ALGORITMA
	d1 = JAMToDetik(J1);
	d2 = JAMToDetik(J2);
	return( (d1>d2) ? true : false);
}


/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
	//KAMUS
	long d;
	//ALGORITMA
	d = JAMToDetik(J);
	d = d + 1;
	J = DetikToJAM(d);
	return J;
}


JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
	//KAMUS
	long d;
	//ALGORITMA
	d = JAMToDetik(J);
	d = d + N;
	J = DetikToJAM(d);
	return J;
}

JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
	//KAMUS
	long d;
	//ALGORITMA
	d = JAMToDetik(J);
	d = d - 1;
	if (d == -1)
	{
		d = 86399;
	}
	J = DetikToJAM(d);
	return J;	
}


JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
{
	//KAMUS
	long d;
	//ALGORITMA
	d = JAMToDetik(J);
	d = d - (N%86400);
	if (d < 0)
	{
		d = 86400 + d;
	}
	J = DetikToJAM(d);
	return J;
}


long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
	//KAMUS
	long dAw, dAkh, dFinal;
	//ALGORITMA
	dAw = JAMToDetik(JAw);
	dAkh = JAMToDetik(JAkh);
	if (JGT(JAw, JAkh) == true)
	{
		dFinal = 86400 + dAkh  - dAw;
	}
	else
	{
		dFinal = dAkh - dAw;
	}
	return dFinal;
}