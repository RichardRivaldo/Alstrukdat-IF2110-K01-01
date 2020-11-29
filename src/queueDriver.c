/* Driver PrioQueueChar */

#include "MainCommand.c"
#include "prioqueuechar.c"
#include <stdio.h>

int main(){

    /* Deklarasi Variabel */
    PrioQueueChar Q;

    /* MakeEmpty */
    MakeEmpty(&Q, 2);

    /* Cek isi Queue */
    if(IsEmptyQ(Q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue not empty yet\n");
    }

    /* Deklarasi Pengunjung */
    Pengunjung A, B, X;

    /* Assign nilai Pengunjung A */
    Prio(A) = 10; Sabar(A) = 4;
    StringCopy(100, A.wahana[0], "Wangky");
    StringCopy(100, A.wahana[1], "Coaster");

    Enqueue(&Q, A);

    printf("NBElmt = %d\n", NBElmtQ(Q));

    /* Assign nilai variabel B */
    Prio(B) = 6; Sabar(B) = 5;
    StringCopy(100, B.wahana[0], "RollerCoaster");
    Enqueue(&Q, B);

    /* Cek Isi Queue */
    PrintPrioQueueChar(Q);

    /* Cek isi Queue */
    if(IsFullQ(Q)){
        printf("Queue is full\n");
    }
    else{
        printf("Not full\n");
    }

    /* Cek Dequeue */
    Dequeue(&Q, &X);
    PrintPrioQueueChar(Q);

    return 0;
}
