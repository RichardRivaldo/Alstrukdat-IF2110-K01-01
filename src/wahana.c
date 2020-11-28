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

void readWahanaRow(char data[], Wahana* wahana){
    char cc, line[255];
    memset(line,0,255); //ngosongin linenya
    int i = 0;
    int idx = 0;
    int part = 0;
    boolean point = false;
    // cc = (char)fgetc(fPointer);
    // printf("%c",cc);
    while(!point){
        cc = data[idx];
        if(cc != ',' && cc != '.'){
            line[i]=cc;
            i++;
        }else{
            mapToWahana(part, line, wahana);
            // printf("%s %d\n",line,part);
            memset(line, 0, 255);
            i=0;
            part++;
            if(cc == '.'){
                point = true;
            }
        }
        idx++;
    }
}

void cetakDetailWahana(Wahana* wahana){
    printf("ID WAHANA : %d\n",(*wahana).id);
    printf("NAMA WAHANA : %s\n",(*wahana).nama);
    printf("TIPE WAHANA : %s\n",(*wahana).tipe);
    printf("HARGA WAHANA : %d\n",(*wahana).harga);
    printf("POINT WAHANA : ");
    TulisPOINT((*wahana).point);
    printf("\n");
    printf("KAPASITAS WAHANA : %d\n",(*wahana).kapasitas);
    printf("DESKRIPSI WAHANA : %s\n",(*wahana).deskripsi);
    printf("STATE WAHANA : %d\n",(*wahana).state);
}