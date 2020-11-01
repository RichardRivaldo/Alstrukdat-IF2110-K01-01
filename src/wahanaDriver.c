#include "wahana.h"
#include "point.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

int convertToInt(char data[]){
    int res = atoi(data);
    return res;
}

POINT convertToPoint(char data[]){
    char x[5], y[5];
    boolean found = false;
    int i,j;
    for(i = 0; i<5 && !found; i++){
        if(data[i]!='_'){
            x[i] = data[i];
        }else{
            found = true;
        }
    }
    for(j = i; j<i+5; j++){
        y[j-i] = data[j];
    }
    return MakePOINT((float)convertToInt(x),(float)convertToInt(y));
}

void mapToWahana(int part, char data[], Wahana * wahana){
    int res;
    switch(part){
        case 0 :
            res = convertToInt(data);
            (*wahana).id=res;
            break;
        case 1 :
            strncpy((*wahana).nama, data, 255);
            break;
        case 2 :
            strncpy((*wahana).tipe, data, 255);
            break;
        case 3 :
            (*wahana).harga = convertToInt(data);
            break;
        case 4 :
            (*wahana).point = convertToPoint(data);
            break;
        case 5 :
            (*wahana).kapasitas = convertToInt(data);
            break;
        case 6 :
            strncpy((*wahana).deskripsi, data, 255);
            break;
    }
}

int main(){
    FILE * fPointer = fopen("../data/wahana.txt", "r");
    POINT currentPoint;
    Wahana wahana1;
    char cc, line[255];
    memset(line,0,255); //ngosongin linenya
    int part = 0;
    int i = 0;
    boolean point=false;
    while(!feof(fPointer)){
        cc = (char)fgetc(fPointer);
        // printf("%c",cc);
        if(cc!=',' && cc!='.'){
            line[i]=cc;
            i++;
        }else{
            mapToWahana(part, line, &wahana1);
            // printf("%s %d\n",line,part);
            memset(line, 0, 255);
            i=0;
            part++;
        }

    }
    printf("Sukses\n");
    printf("ID WAHANA : %d\n",wahana1.id);
    printf("NAMA WAHANA : %s\n",wahana1.nama);
    printf("TIPE WAHANA : %s\n",wahana1.tipe);
    printf("HARGA WAHANA : %d\n",wahana1.harga);
    printf("POINT WAHANA : ");
    TulisPOINT(wahana1.point);
    printf("\n");
    printf("KAPASITAS WAHANA : %d\n",wahana1.kapasitas);
    printf("DESKRIPSI WAHANA : %s",wahana1.deskripsi);
    return 0;
}