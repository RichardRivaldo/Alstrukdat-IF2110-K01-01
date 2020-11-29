/* Driver PrioQueueChar */
/* Make PrepCommand Main into a comment first */

#include "prioqueuechar.c"
#include <stdio.h>

int main(){

    /* Deklarasi Variabel */
    PrioQueueChar Q;

    /* Matriks Wahana */
    MatriksOfString M;
    MakeMatriksStr(8, 12, &M);
    LoadFileWahana(&M, 8, 12);
    
    /* Sistem Queue */
    SistemQueue(&Q, M);
    PrintPrioQueueChar(Q);

    /* Input */
    char Whn[255];

    /* Fungsi Serve Queue */
    scanf("%s", &Whn);
    Serve(&Q, M, Whn);

    /* Cek Isi Queue */
    PrintPrioQueueChar(Q);

    /* Fungsi Prepare */
    Prepare(&Q);

    /* Cek isi Queue */
    if(IsEmptyQ(Q)){
        printf("Prepare success\n");
    }
    else{
        printf("Queue not empty yet\n");
    }

    /* Fungsi Office */
    Office(M);

    return 0;
}
