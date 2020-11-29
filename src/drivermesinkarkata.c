#include <stdio.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "mesinkar.c"
#include "mesinkata.c"

int main(){
    printf("masukkan test input: ");
    STARTKATA();
    while (!EndKata){
        for (int i = 0; i < CKata.Length; i++)
        {
            printf("%c", CKata.TabKata[i]);
        }
        printf("\n");
        ADVKATA();
    }
    return 0;
}