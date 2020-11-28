/* Driver PrioQueueChar */

#include "prioqueuechar.h"
#include "customString.h"
#include <stdio.h>

int main(){

    /* Deklarasi Variabel */
    PrioQueueChar Q;
    Pengunjung A, B, X;

    /* Assign nilai variabel B */
    Prio(A) = 10; Sabar(A) = 4;
    StringCopy(100, A.wahana[0], "Wangky");
    StringCopy(100, A.wahana[1], "Coaster");

    /* Assign nilai variabel A */
    Prio(B) = 6; Sabar(B) = 5;
    StringCopy(100, B.wahana[0], "RollerCoaster");

    /* Inisiasi Queue */
    MakeEmpty(&Q, 5);

    /* Memasukkan elemen ke dalam Queue */
    Enqueue(&Q, A);
    Enqueue(&Q, B);

    /* Cek Isi Queue */
    PrintPrioQueueChar(Q);

    /* Dequeue Head dari Queue */
    /* Assign nilai Head ke X */

    /*
    Dequeue(&Q, &X); */

    /* Cek nilai variabel X */
    /*
    printf("%s ", X.wahana[0]);
    printf("%d ", X.prio);
    printf("%d\n", X.kesabaran); */
    /* Fungsi Serve Queue */
    Serve(&Q);

    /* Cek isi Queue */
    PrintPrioQueueChar(Q);

    Serve(&Q);
    PrintPrioQueueChar(Q);

    /* Tes Dequeue 2
    Dequeue(&Q, &X); printf("%d\n", X.prio);
    printf("%d\n", Prio(X));
    printf("%d\n", Sabar(X));

    PrintPrioQueueChar(Q);
    */

    /* Fungsi Prepare */
    Prepare(&Q);

    /* Cek isi Queue */
    if(IsEmpty(Q)){
        printf("Prepare success\n");
    }
    else{
        printf("Queue not empty yet\n");
    }

    return 0;
}
