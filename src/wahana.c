#include "wahana.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

void displayWahana(Wahana wahana){
    printf("--------------------------------------------------\n");
    printf("Nama Wahana : %s\n", wahana.nama);
    printf("Deskripsi Wahana : %s\n", wahana.deskripsi);
    printf("Harga Wahana : $%d\n", wahana.profit);
    printf("Lokasi Wahana : \n");
    printf("    Submap : %d\n Koordinat : ", wahana.lokasi.Submap);
    TulisPOINT(wahana.lokasi.Koordinat);
    printf("Durasi Wahana : %d\n", wahana.durasi);
    printf("Kapasitas Wahana : %d\n", wahana.kapasitas);
    printf("--------------------------------------------------\n");
    printf("-----------------------REPORT---------------------\n");
    printf("-                                                -\n");
    printf("  Total Pengunjung : %d\n", wahana.qtyAll);
    printf("  Total Pendapatan : $ %d\n", wahana.incomeAll);
    printf("  Pengunjung Hari Ini : %d\n", wahana.qty);
    printf("  Pendapatan Hari Ini : $ %d\n", wahana.income);
    printf("-                                                -\n");
    printf("--------------------------------------------------\n");
}

Wahana findWahana(Wahana listWahana[], char nama[]){
    boolean found = false;
    Wahana target;
    printf("Finding wahana for name : %s\n", nama);
    StringCopy(lengthStr, target.nama, "404");
    for(int i = 0; i<8 && !found; i++){
        if(StringTrueCompare(lengthStr, nama, listWahana[i].nama) && listWahana[i].lokasi.Submap!=-1){
            found = true;
            target = listWahana[i];
        }
    }
    return target;
}

boolean IsNotFull(Wahana wahana){
    return wahana.kapasitas>1;
}

boolean IsNotBroken(Wahana wahana){
    return wahana.status==1;
}

boolean IsBuilt(Wahana wahana){
    return wahana.lokasi.Submap!=-1;
}