/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#ifndef prioqueuechar_H
#define prioqueuechar_H

#include "boolean.h"
#include "wahana.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    int prio;  /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas tertinggi) */
    int kesabaran; /* tingkat kesabaran */
    char wahana[5][255]; /* wahana yang dituju */
} Pengunjung;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    Pengunjung * T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxElQ;     /* Max elemen queue */
} PrioQueueChar;
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah Pengunjung dan Q adalah PrioQueueChar, maka akses elemen : */
#define Prio(e)     (e).prio
#define Wahana(e)   (e).wahana
#define Sabar(e)    (e).kesabaran
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQ(Q)   (Q).MaxElQ
#define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueChar Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, Pengunjung X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueChar * Q, Pengunjung * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

void RandomizePrio (Pengunjung X);
    /* Melakukan randomize terhadap priority pengunjung */
    /* I.S. Pengunjung tidak memiliki priority */
    /* F.S. Pengunjung memiliki priority antara 0-100 */

void RandomizeWahana (Pengunjung X);
    /* Melakukan randomize terhadap wahana yang ingin dikunjungi pengunjung */
    /* I.S. Pengunjung tidak memiliki tujuan wahana */
    /* F.S. Pengunjung memiliki wahana yang ingin dituju */

void SistemQueue(PrioQueueChar Q);
    /* Sistem Queue yang akan digunakan dalam main phase */

void Serve(PrioQueueChar *Q);
    /* Melayani pengunjung yang masuk sesuai dengan wahana yang ingin dituju */

void ChanceRusak(Wahana* wahana);
    /* Probabilitas Wahana rusak (30%) */

void Repair(Wahana* wahana);
    /* Mengembalikan state wahana */

void Detail();
    /* Mengecek detail wahana yang berada disekitar P */

void Office();

void Prepare(PrioQueueChar *Q);
    /* Masuk ke dalam Prepare Phase */

#endif
