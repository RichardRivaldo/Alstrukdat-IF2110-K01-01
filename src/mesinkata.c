#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    // ALGORITMA
    while (CC == BLANK) {
        ADV();
    }
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    // ALGORITMA
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    }
    else{
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    // ALGORITMA
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    }
    else {
        SalinKata();
    }
}
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    // KAMUS
    int i;
    // ALGORITMA
    i = 0; /* inisialisasi */
    while ((CC != MARK) && (CC != BLANK) && (i < NMax)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    } /* CC = MARK or CC = BLANK */
    CKata.Length = i;
    IgnoreBlank();
}