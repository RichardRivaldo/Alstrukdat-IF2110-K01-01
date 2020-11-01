#include "prioqueuechar.h"
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
        Nama(*X) = Nama(InfoHead(*Q)), Prio(*X) = Prio(InfoHead(*Q));
        Wahana(*X) = Nama(InfoHead(*Q)), Sabar(*X) = Sabar((InfoHead(*Q)));
        Head(*Q) = Nil, Tail(*Q) = Nil;
    }
    else{
        Nama(*X) = Nama(InfoHead(*Q)), Prio(*X) = Prio(InfoHead(*Q));
        Wahana(*X) = Nama(InfoHead(*Q)), Sabar(*X) = Sabar((InfoHead(*Q)));
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
    while(!IsEmpty(Q)){
        Dequeue(&Q, &CInfo);
        printf("%d %s %s %d\n", Prio(CInfo), Nama(CInfo), Wahana(CInfo), Sabar(CInfo));
    }
    printf("#\n");
}
