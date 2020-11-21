#include "prioqueuechar.c"
#include <stdio.h>

int main(){
    PrioQueueChar Q;
    Pengunjung A, B;
    Pengunjung X;
    Prio(A) = 10;
    StringCopy(100, A.wahana[0], "Wangky"); Sabar(A) = 4;
    StringCopy(100, A.wahana[1], "Coaster");

    Prio(B) = 6;
    StringCopy(100, B.wahana[0], "RollerCoaster"); Sabar(B) = 5;

    MakeEmpty(&Q, 5);
    Enqueue(&Q, A);
    Dequeue(&Q, &X);
    printf("%d\n", Prio(X));
    printf("%d\n", Sabar(X));

    PrintPrioQueueChar(Q);

    Enqueue(&Q,B);
    PrintPrioQueueChar(Q);

    return 0;
}
