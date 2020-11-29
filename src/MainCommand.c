#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Library buatan sendiri:
#include "prioqueuechar.h"
#include "jam.h"
#include "PrepCommand.h"
#include "customString.h"
#include "wahana.h"


// Variabel global
JAM timeMain;

void SistemQueue(PrioQueueChar *Q, Wahana listWahana[]){
    /* Sistem Queue yang akan digunakan dalam main phase */
    printf("INITIALIZING QUEUE SYSTEM...\n");
    // MakeEmpty(Q, 5);
    // printf("BRHASIL MAKE EMPTY\n");
    Pengunjung Y;
    for(int i = 0; i < 5; i++){
        Y.kesabaran = 20;
        Y.prio = (rand() % 100 + 1);
        int jumlahWahana = (rand() % 5) + 1; //jumlah wahana yang X mau naikin
        // printf("JUMLAH WAHANA ORANG KE - %d : %d\n",i+1, jumlahWahana);
        for(int j = 0; j < 5; j++){
            int randomWahana = (rand() % 8);
            StringCopy(lengthStr, Y.wahana[j], listWahana[randomWahana].nama);
            // printf("INI DARI SISTEM QUEUE: %s\n",Y.wahana[j]);
            // StringCopy(lengthStr, Y.wahana[j], listWahana[randomWahana].nama);
        }
        Enqueue(Q, Y);
    }
}

void Serve(PrioQueueChar *Q, Wahana ListWahana[], char Whn[255]){
    /* Melayani pengunjung yang masuk sesuai dengan wahana yang ingin dituju */

    Pengunjung X;
    int i = 0, j;
    boolean found = false;

    Dequeue(Q, &X);
    while(X.wahana[i][0] != '\0' && !found){
        char cekWahana[255]; 
        StringCopy(255, cekWahana, X.wahana[i]);
        if(StringTrueCompare(255, cekWahana, Whn)){
            j = i;
            found = true;
        }
        else{
            i++;
        }
    }

    if(found){
        for(int baris = 0; baris < 8; baris++){
            Wahana W = ListWahana[baris];
            char nama[255]; StringCopy(255, nama, W.nama);
            if(StringTrueCompare(255, Whn, nama)){
                if(IsNotFull(W)){
                    if(IsNotBroken(W)){
                        printf("SUKSES SERVE\n");
                        ListWahana[baris].kapasitas--;
                        ListWahana[baris].qty++;
                        ListWahana[baris].income += ListWahana[baris].profit;
                        ListWahana[baris].qtyAll++;
                        ListWahana[baris].incomeAll += W.profit;
                        ChanceRusak(ListWahana, nama);
                        while(X.wahana[j][0] != '\0'){
                            StringCopy(255, X.wahana[j], X.wahana[j+1]);
                            j++;
                        }
                        if(X.wahana[0][0] != '\0'){
                            if(X.prio - 2 < 1){
                                X.prio = 1;
                            }
                            else{
                                X.prio -= 3;
                            }
                            Enqueue(Q, X);
                        }
                    }
                    else{
                        printf("The ride you want to use is broken!\n");
                        X.kesabaran -= 2;
                        if(X.prio - 2 < 1){
                            X.prio = 1;
                        }
                        else{
                            X.prio -= 3;
                        }
                        if(X.kesabaran > 0){
                            Enqueue(Q, X);
                        }
                        else{
                            printf("The customer will now leave the Queue!\n");
                        }
                    }
                }
                else{
                    printf("The ride you want to use is full!\n");
                    X.kesabaran -= 2;
                    if(X.prio - 2 < 1){
                        X.prio = 1;
                    }
                    else{
                        X.prio -= 3;
                    }
                    if(X.kesabaran <= 0){
                        printf("The customer will now leave the Queue!\n");
                    }
                    Enqueue(Q, X);
                }
            }
        }
    }
    else{
        printf("Error 404: Not Found\n");
        Enqueue(Q, X);
    }
}


void ChanceRusak(Wahana ListWahana[], char Whn[255]){
    /* Probabilitas Wahana rusak (25%) */
    
    int i = rand() % 4;
    if (i == 1){
        for(int j = 0; j < 8; j++){
            if(StringTrueCompare(255, ListWahana[j].nama, Whn)){
                printf("WAHANA %S RUSAK!!!\n", Whn);
                ListWahana[j].status = 0;
            }
        }
    }
}


/*** Kurang Waktu ***/
void Repair(Wahana ListWahana[], char Whn[255]){
    /* Mengembalikan state wahana */
    for(int j = 0; j < 8; j++){
        if(StringTrueCompare(255, ListWahana[j].nama, Whn)){
            if(ListWahana[j].status==0){
                 printf("WAHANA %s SEDANG DIPERBAIKI!!!\n", Whn);
                ListWahana[j].status = 1;
            }else{
                printf("WAHANA %s DALAM KEADAAN BAIK-BAIK SAJA\n", Whn);
            }
           
        }
    }
} 


// void Detail(MatriksOfString M, char Whn[255]){
//     /* Mengecek detail wahana yang berada disekitar P  */
//     /* Daftar kan wahana yang ada di sekitar player  */
//     Wahana wahana;
//     BinTree P;
//     BinTree pohonUpgrade[5];
//     IsiPohonUpgrade(M, &pohonUpgrade);

//     StringCopy(255, wahana.nama, Whn);
//     for (int i = 0; i < 8; i++){
//         if(StringTrueCompare(255, M.Mem[i][0], Whn)){
//             printf("NAMA WAHANA      : %s\n", M.Mem[i][0]);
//             printf("HARGA WAHANA     : %d\n", StringToInt(255, M.Mem[i][2]));
//             printf("POINT WAHANA     : "); TulisPOINT(wahana.point); printf("\n");
//             printf("KAPASITAS WAHANA : %d\n", StringToInt(255, M.Mem[i][1]));
//             int Waktu = StringToInt(255, M.Mem[i][3]);
//             printf("DURASI WAHANA    : %d Menit\n", Waktu/60);
//             printf("DESKRIPSI WAHANA : %s\n", M.Mem[i][11]);
//             printf("STATE WAHANA     : %d\n", StringToInt(255, M.Mem[i][9]));
//             printf("Keterangan: 0 -> Wahana sedang rusak.\n");
//             printf("            1 -> Berfungsi dengan baik.\n");

//             for (int i = 0; i < 5; ++i){
//                 if (SearchTree(pohonUpgrade[i], Whn)){
//                     P = pohonUpgrade[i]; /*Cari pohon dengan nama upgrade*/
//                 }
//             }
//             printf("UPGRADE          : "), PrintHistory(M, P, Whn); printf("\n");
            
//             printf("Total Dinaiki    : %d\n", StringToInt(255, M.Mem[i][10]));
//             printf("Penghasilan      : %d\n", StringToInt(255, M.Mem[i][11]));
//             printf("Dinaiki Harian   : %d\n", StringToInt(255, M.Mem[i][12]));
//             printf("Total Penghasilan: %d\n\n", StringToInt(255, M.Mem[i][13]));
//         }
//     }
// }


void Office(Wahana ListWahana[]){ 
    /* Mengecek detail dan laporan Wahana */
    for(int i = 0; i < 8; i++){
        displayWahana(ListWahana[i]);
    }
}


void Prepare(PrioQueueChar *Q){
    printf("Starting Preparation Phase...\n");
    Pengunjung temp;
    while(!IsEmptyQ(*Q)){
        Dequeue(Q, &temp);
    }
    // DeAlokasi(Q);
    /* Call Prep Phase */
}

// int main(){

//     /* Deklarasi Variabel */
//     PrioQueueChar Q;

//     /* Deklarasi Jam */
//     timeMain = MakeJAM(9,0,0);

//     /* Waktu saat Main Phase */
//     while (JAMToDetik(timeMain) < 75600){
//         // Ntar fungsinya dimasukin disini ?
//     }

//     /* Matriks Wahana */
//     MatriksOfString M;
//     MakeMatriksStr(8, 12, &M);
//     LoadFileWahana(&M, 8, 12);
    
//     /* Sistem Queue */
//     SistemQueue(&Q, M);
//     PrintPrioQueueChar(Q);

//     /* Input */
//     char Whn[255];

//     /* Fungsi Serve Queue */
//     scanf("%s", &Whn);
//     Serve(&Q, M, Whn);

//     /* Cek Isi Queue */
//     PrintPrioQueueChar(Q);

//     /* Fungsi Prepare */
//     Prepare(&Q);

//     /* Cek isi Queue */
//     if(IsEmptyQ(Q)){
//         printf("Prepare success\n");
//     }
//     else{
//         printf("Queue not empty yet\n");
//     }

//     /* Fungsi Office */
//     Office(M);

//     return 0;
// }    
