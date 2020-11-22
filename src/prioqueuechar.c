#include "prioqueuechar.h"
#include "customString.h"
#include "wahana.c"
#include "peta.c"
#include <stdio.h>
#include <stdlib.h>


boolean IsEmpty (PrioQueueChar Q){
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return(Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q){
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    return(NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueChar Q){
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if(IsEmpty(Q)){
        return 0;
    }
    if(Tail(Q) >= Head(Q)){
        return(Tail(Q) - Head(Q) + 1);
    }
    else{
        return(((Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q)) + 1);
    }
}

void MakeEmpty (PrioQueueChar * Q, int Max){
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (Pengunjung*) malloc((Max) * sizeof(Pengunjung));

    if(((*Q).T) != NULL){
        Head(*Q) = Nil, Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
    else{
        MaxEl(*Q) = 0;
    }
}

void DeAlokasi(PrioQueueChar * Q){
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    MaxEl(*Q) = 0;
    free((*Q).T);
}

void Enqueue (PrioQueueChar * Q, Pengunjung X){
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    if(IsEmpty(*Q)){
        Head(*Q) = 0, Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else{
        int idx = Tail(*Q), threshold = NBElmt(*Q);

        while((Prio(X) < Prio((*Q).T[idx])) && (threshold > 0)){
            (*Q).T[(idx % MaxEl(*Q)) + 1] = (*Q).T[idx];

            idx -= 1;
            threshold -= 1;

            if(idx == -1){
                idx = MaxEl(*Q) -1;
            }
        }

        (*Q).T[(idx + 1) % MaxEl(*Q)] = X;
        Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
    }
}

void Dequeue (PrioQueueChar * Q, Pengunjung * X){
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    if(NBElmt(*Q) == 1){
        Prio(*X) = Prio(InfoHead(*Q));
        for(int i = 0; i < 5; i++){
            StringCopy(100, (*X).wahana[i], Wahana(InfoHead(*Q))[i]);
        }
        Sabar(*X) = Sabar(InfoHead(*Q));
        Head(*Q) = Nil; Tail(*Q) = Nil;
    }
    else{
        Prio(*X) = Prio(InfoHead(*Q));
        for(int i = 0; i < 5; i++){
            StringCopy(100, (*X).wahana[i], Wahana(InfoHead(*Q))[i]);
        }
        Sabar(*X) = Sabar(InfoHead(*Q));
        Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
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

    if(IsEmpty(Q)){
        printf("The Wangky's Queue is empty.\n");
    }
    else{
        printf("Queue [%d/%d]:\n", NBElmt(Q), MaxEl(Q));
        while(!IsEmpty(Q)){
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

void RandomizePrio (Pengunjung X){
    /* Melakukan randomize terhadap priority pengunjung */
    /* I.S. Pengunjung tidak memiliki priority */
    /* F.S. Pengunjung memiliki priority antara 0-100 */
    X.prio = rand() % 100 + 1;
    if(X.prio == 1){
        X.prio += 25;
    }
}

void SistemQueue(PrioQueueChar Q){
    /* Sistem Queue yang akan digunakan dalam main phase */
    MakeEmpty(&Q, 20);
}

void Serve(PrioQueueChar *Q){
    /* Melayani pengunjung yang masuk sesuai dengan wahana yang ingin dituju */
    char whnSelected[255];
    Pengunjung X;
    int i = 0;
    boolean found = false;

    scanf("%s", &whnSelected);

    Dequeue(Q, &X);
    while(X.wahana[i][0] != '\0' && !found){
        if(StringCompare(255, whnSelected, X.wahana[i])){
            found = true;
        }
        else{
            i++;
        }
    }
    if(found){
        if(X.wahana[i][0] != '\0'){
            if(X.prio - 2 < 1){
                X.prio = 1;
            }
            else{
                X.prio -= 3;
            }
            Enqueue(Q, X);
        }
    }
}

void ChanceRusak(Wahana* wahana){
    /* Probabilitas Wahana rusak (25%) */
    int i = rand() % 4;

    if (i == 1){
        wahana.state = false;
    }
}

/*** Kurang Waktu ***/
void Repair(Wahana* wahana){
    /* Mengembalikan state wahana */
    wahana.state = true;
}


void Detail(Peta * peta){
    /* Mengecek detail wahana yang berada disekitar P */
    int currentArea = (*peta).currentArea;
    Wahana wahana;
    /* Ngecek sekitar player */
    /* Daftar kan wahana yang ada di sekitar player */
    cetakDetailWahana(wahana);
}

/*** Tunggu ada detail wahana ***/
void Office(){
    /* Mengecek detail dan laporan Wahana */
    int i;
        cetakDetailWahana(wahana[i]);
}

void Prepare(PrioQueueChar *Q){
    printf("Starting Preparation Phase...\n");
    Pengunjung temp;
    while(!IsEmpty(*Q)){
        Dequeue(Q, &temp);
    }
    /* Call Prep Phase */
}
