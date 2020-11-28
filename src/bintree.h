/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_H_
#define _BINTREE_H_

/* Modul lain yang digunakan : */
#include "boolean.h"
#include "MatriksOfString.h"
/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */
typedef struct 
{
    str nama;
    str wahanasblm;
} upgradeInfo;
/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */ /* type infotype sesuai pada modul listrek */
typedef upgradeInfo infotype;
typedef struct tNode *addrNode;
typedef struct tNode
{
  infotype info;
  addrNode left;
  addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Nama(P) (P)->info.nama
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
/* Manajemen Memory */
addrNode AlokNode(infotype X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintTree(BinTree P, int h);
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, str X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

upgradeInfo FindTreeNode(BinTree P, str X);
/* Mengirimkan upgradeInfo dengan namanya jika ada node dari P yang bernilai X */

/* *** Operasi lain *** */
void AddDaun(BinTree *P, str X, infotype Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */

void AddCabang(BinTree *P, str X, infotype Y);
/* I.S. P tidak kosong, X adalah salah satu node Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak jika ada kiri jika 1 elmt, isi bagian kosong jika uner
tidak melakukan apa-apa jika biner */

upgradeInfo CreateUpgradeInfo(str nama, str wahanasblm);
//Membuat upgradeInfo baru dengan string nama dan string wahanasblm
#endif