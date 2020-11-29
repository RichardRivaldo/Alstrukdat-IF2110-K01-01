#include <stdio.h>
#include "MatriksOfString.h"
#include "MatriksOfString.c"

int main(){
    // KAMUS
    int NB = 5, NK = 5;
    MatriksOfString M;
    // ALGORITMA
    MakeMatriksStr(NB, NK, &M);
    printf("Matriks berukuran %d x %d.", M.NBrsEff, M.NKolEff);
    return 0;
}