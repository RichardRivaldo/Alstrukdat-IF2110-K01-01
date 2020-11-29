/* Driver PrioQueueChar */
/* Make PrepCommand Main into a comment first */

#include "prioqueuechar.c"
// #include "customString.c"
// #include "MatriksOfString.c"
// #include "PrepCommand.c"
#include <stdio.h>

int main(){

    /* Deklarasi Variabel */
    PrioQueueChar Q;
    Pengunjung A, B, X;
    MatriksOfString M;
    MakeMatriksStr(8, 12, &M);
    LoadFileWahana(&M, 8, 12);

    char Whn[255];

    /* Assign nilai variabel B */
    Prio(A) = 10; Sabar(A) = 4;
    StringCopy(255, A.wahana[0], "HalilintarV2");
    StringCopy(255, A.wahana[1], "Halilintar");

    /* Assign nilai variabel A */
    Prio(B) = 11; Sabar(B) = 5;
    StringCopy(255, B.wahana[0], "Bianglala");

    /* 
    for(int baris = 0; baris < 8; baris++){
        printf("%s\n", M.Mem[baris][0]);
        if(StringTrueCompare(255, B.wahana[0], M.Mem[baris][0])){
            printf("True");
        }
        else{
            printf("False");
        }
    }
    */
    
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
    scanf("%s", &Whn);
    Serve(&Q, M, Whn);

    /* Cek isi Queue */
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
    if(IsEmptyQ(Q)){
        printf("Prepare success\n");
    }
    else{
        printf("Queue not empty yet\n");
    }

    return 0;
}
