#include "wahana.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "wahana.c"

int main(){
    FILE * fPointer = fopen("../data/wahana.txt", "r");
    Wahana daftarWahana[10];
    char line[255];
    memset(line,0,255); //ngosongin linenya
    int i = 0;
    while(!feof(fPointer)){
        fgets(line, 255, fPointer);
        readWahanaRow(line, &daftarWahana[i]);
        // printf("Sukses\n");
        cetakDetailWahana(&daftarWahana[i]);
        i++;
    }

    return 0;
}