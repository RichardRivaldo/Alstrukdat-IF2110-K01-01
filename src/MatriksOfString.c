#include <stdio.h>
#include "boolean.h"
#include "MatriksOfString.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMatriksStr (int NB, int NK, MatriksOfString * M) 
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}