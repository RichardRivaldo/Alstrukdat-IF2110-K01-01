#include "prioqueuechar.h"
#include "MatriksOfString.h"
#include "customString.h"
// #include "peta.c"
// #include "peta.h"
#include <stdio.h>
#include <stdlib.h>
#include "PrepCommand.c"

boolean IsEmptyQ (PrioQueueChar Q){
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return(Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFullQ (PrioQueueChar Q){
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxElQ */
    return(NBElmtQ(Q) == MaxElQ(Q));
}

int NBElmtQ (PrioQueueChar Q){
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if(IsEmptyQ(Q)){
        return 0;
    }
    if(Tail(Q) >= Head(Q)){
        return(Tail(Q) - Head(Q) + 1);
    }
    else{
        return(((Tail(Q) - Head(Q) + MaxElQ(Q)) % MaxElQ(Q)) + 1);
    }
}

void MakeEmpty (PrioQueueChar * Q, int Max){
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
    /* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (Pengunjung*) malloc((Max) * sizeof(Pengunjung));

    if(((*Q).T) != NULL){
        Head(*Q) = Nil, Tail(*Q) = Nil;
        MaxElQ(*Q) = Max;
    }
    else{
        MaxElQ(*Q) = 0;
    }
}

void DeAlokasi(PrioQueueChar * Q){
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */
    MaxElQ(*Q) = 0;
    free((*Q).T);
}

void Enqueue (PrioQueueChar * Q, Pengunjung X){
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    if(IsEmptyQ(*Q)){
        Head(*Q) = 0, Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else{
        int idx = Tail(*Q), threshold = NBElmtQ(*Q);

        while((Prio(X) < Prio((*Q).T[idx])) && (threshold > 0)){
            (*Q).T[(idx % MaxElQ(*Q)) + 1] = (*Q).T[idx];

            idx -= 1;
            threshold -= 1;

            if(idx == -1){
                idx = MaxElQ(*Q) -1;
            }
        }

        (*Q).T[(idx + 1) % MaxElQ(*Q)] = X;
        Tail(*Q) = (Tail(*Q) + 1) % MaxElQ(*Q);
    }
}

void Dequeue (PrioQueueChar * Q, Pengunjung * X){
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    if(NBElmtQ(*Q) == 1){
        Prio(*X) = Prio(InfoHead(*Q));
        for(int i = 0; i < 5; i++){
            StringCopy(255, (*X).wahana[i], Wahana(InfoHead(*Q))[i]);
        }
        Sabar(*X) = Sabar(InfoHead(*Q));
        Head(*Q) = Nil; Tail(*Q) = Nil;
    }
    else{
        Prio(*X) = Prio(InfoHead(*Q));
        for(int i = 0; i < 5; i++){
            StringCopy(255, (*X).wahana[i], Wahana(InfoHead(*Q))[i]);
        }
        Sabar(*X) = Sabar(InfoHead(*Q));
        Head(*Q) = (Head(*Q) % MaxElQ(*Q)) + 1;
    }
}


void PrintPrioQueueChar (PrioQueueChar Q){
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <prio-1> <elemen-1>
    ...
    <prio-n> <elemen-n>
    #
    */
    Pengunjung CInfo;
    int count = 0;

    if(IsEmptyQ(Q)){
        printf("The Wangky's Queue is empty.\n");
    }
    else{
        printf("Queue [%d/%d]:\n", NBElmtQ(Q), MaxElQ(Q));
        while(!IsEmptyQ(Q)){
            Dequeue(&Q, &CInfo);
            printf("Wangkies %d ", count + 1);
            printf("(");
            int i = 0;
            while(CInfo.wahana[i][0] != '\0'){
                printf("%s", CInfo.wahana[i]);
                if(CInfo.wahana[i+1][0] != '\0'){
                    printf(", ");
                }
                i++;
            }
            printf("), Patience: %d\n", CInfo.kesabaran);
            count++;
        }
    }
}

void SistemQueue(PrioQueueChar *Q, MatriksOfString M){
    /* Sistem Queue yang akan digunakan dalam main phase */
    MakeEmpty(Q, 5);
    Pengunjung Y;
    for(int i = 0; i < 5; i++){
        Y.kesabaran = 20;
        Y.prio = (rand() % 100 + 1);
        int jumlahWahana = (rand() % 5) + 1;
        for(int j = 0; j < jumlahWahana; j++){
            int randomWahana = (rand() % 8);
            StringCopy(255, Y.wahana[j], M.Mem[randomWahana][0]);
        }
        Enqueue(Q, Y);
    }
}

void Serve(PrioQueueChar *Q, MatriksOfString M, char Whn[255]){
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
            char nama[255]; StringCopy(255, nama, M.Mem[baris][0]);
            if(StringTrueCompare(255, Whn, nama)){
                if(StringToInt(lengthStr, M.Mem[baris][1]) > 1){
                    if(StringToInt(lengthStr, M.Mem[baris][9]) == 1){
                        int Cpc = StringToInt(255, M.Mem[baris][1]) - 1;
                        char NewCpc[255];
                        sprintf(NewCpc, "%d", Cpc);
                        StringCopy(255, M.Mem[baris][1], NewCpc);
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


void ChanceRusak(MatriksOfString M, char Whn[255]){
    /* Probabilitas Wahana rusak (25%) */
    
    int i = rand() % 4;
    if (i == 1){
        for(int j = 0; j < 8; j++){
            if(StringTrueCompare(255, M.Mem[j][0], Whn)){
                StringCopy(255, M.Mem[j][9], "0");
            }
        }
    }
}


/*** Kurang Waktu ***/
void Repair(MatriksOfString M, char Whn[255]){
    /* Mengembalikan state wahana */
    for(int j = 0; j < 8; j++){
        if(StringTrueCompare(255, M.Mem[j][0], Whn)){
            StringCopy(255, M.Mem[j][9], "1");
        }
    }
} 


void Detail(MatriksOfString M, char Whn[255]){
    /* Mengecek detail wahana yang berada disekitar P  */
    /* Daftar kan wahana yang ada di sekitar player  */
    Wahana wahana;
    BinTree P;
    BinTree pohonUpgrade[5];
    IsiPohonUpgrade(M, &pohonUpgrade);

    StringCopy(255, wahana.nama, Whn);
    for (int i = 0; i < 8; i++){
        if(StringTrueCompare(255, M.Mem[i][0], Whn)){
            printf("NAMA WAHANA      : %s\n", M.Mem[i][0]);
            printf("HARGA WAHANA     : %d\n", StringToInt(255, M.Mem[i][2]));
            printf("POINT WAHANA     : "); TulisPOINT(wahana.point); printf("\n");
            printf("KAPASITAS WAHANA : %d\n", StringToInt(255, M.Mem[i][1]));
            int Waktu = StringToInt(255, M.Mem[i][3]);
            printf("DURASI WAHANA    : %d Menit\n", Waktu/60);
            printf("DESKRIPSI WAHANA : %s\n", M.Mem[i][11]);
            printf("STATE WAHANA     : %d\n", StringToInt(255, M.Mem[i][9]));
            printf("Keterangan: 0 -> Wahana sedang rusak.\n");
            printf("            1 -> Berfungsi dengan baik.\n");

            for (int i = 0; i < 5; ++i){
                if (SearchTree(pohonUpgrade[i], Whn)){
                    P = pohonUpgrade[i]; /*Cari pohon dengan nama upgrade*/
                }
            }
            printf("UPGRADE          : "), PrintHistory(M, P, Whn); printf("\n");
            
            printf("Total Dinaiki    : %d\n", StringToInt(255, M.Mem[i][10]));
            printf("Penghasilan      : %d\n", StringToInt(255, M.Mem[i][11]));
            printf("Dinaiki Harian   : %d\n", StringToInt(255, M.Mem[i][12]));
            printf("Total Penghasilan: %d\n\n", StringToInt(255, M.Mem[i][13]));
        }
    }
}


void Office(MatriksOfString M){ 
    /* Mengecek detail dan laporan Wahana */
    for(int i = 0; i < 8; i++){
        Detail(M, M.Mem[i][0]);
    }
}


void Prepare(PrioQueueChar *Q){
    printf("Starting Preparation Phase...\n");
    Pengunjung temp;
    while(!IsEmptyQ(*Q)){
        Dequeue(Q, &temp);
    }
    /* Call Prep Phase */
}