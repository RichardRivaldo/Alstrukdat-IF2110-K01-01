#include "peta.c"
#include "point.c"
#include "matriks.c"
#include "system.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <conio.h>

void main(){
    Peta p = bacaPeta();
    char x = getAtas(&p);
    printf("%c",x);
}