/*Driver untuk ADT Stack Aksi, dalam file jam.c*/
#include <stdio.h>	
#include "boolean.h"
#include "jam.h"
#include <stdlib.h>

/* Program */
int main()
{
    //KAMUS
    int H1, H2, H3, M1, M2, M3, S1, S2, S3, N;
    long S;
    JAM T1, T2, T3, T4;

    //ALGORITMA
    H1 = 17;
    M1 = 8;
    S1 = 45;

    H2 = 3;
    M2 = 70;
    S2 = 25;

    H3 = 23;
    M3 = 59;
    S3 = 58;

    S = 43200;

    printf("Is Jam Valid? %d\n", IsJAMValid(H1,M1,S1));
    printf("Is Jam Valid? %d\n", IsJAMValid(H2,M2,S2));
    printf("Is Jam Valid? %d\n", IsJAMValid(H3,M3,S3));

    T1 = MakeJAM(H1,M1,S1);
    BacaJAM(&T2);
    T3 = MakeJAM(H3,M3,S3);

    TulisJAM(T1); TulisJAM(T2); TulisJAM(T3);
    printf("T2 = %d detik\n", JAMToDetik(T2));
    printf("43200 detik = %d jam\n", DetikToJAM(S));

    printf("Apakah T2 = 23.59.58? %d\n", JEQ(T2,T3));
    printf("Apakah T2 = 23.59.58? %d\n", JNEQ(T2,T3));
    printf("Apakah T2 < 23.59.58? %d\n", JLT(T2,T3));
    printf("Apakah T2 > 23.59.58? %d\n", JGT(T2,T3));

    printf("Next detik dari 23.59.58 adalah %d\n", NextDetik(T3));
    scanf("Masukkan N : %d\n", &N);
    printf("Next N detik dari T2 : %d\n", NextNDetik(T2,N));
    printf("Prev detik dari 23.59.59 adalah %d\n", PrevDetik(T3));
    printf("Prev N detik dari T2 : %d\n", PrevNDetik(T2,N));
    printf("Durasi T2 dengan 23.59.58 adalah : %d\n", Durasi(T2,T3));

    return 0;
}