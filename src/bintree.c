#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "bintree.h"
#include "MatriksOfString.h"
#include "customString.h"

void PrintTrees(BinTree P, int h, int a)
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
{
    // ALGORITMA
    if (IsTreeEmpty(P)){/*gabut*/}
    else{
        printf("%s\n", Nama(P));
        if (!IsTreeEmpty(Left(P))){
            for (int i = 0; i < h*a; i++)
            {
                printf(" ");
            }
        }
        PrintTrees(Left(P), h, (a+1));
        if (!IsTreeEmpty(Right(P))){
            for (int i = 0; i < h*a; i++)
            {
                printf(" ");
            }
        }
        PrintTrees(Right(P), h, (a+1));
    }
}

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
    // KAMUS
    BinTree P;
    // ALGORITMA
    P = AlokNode(Akar);
    if (P != NULL){
        Right(P) = R;
        Left(P) = L;
    }
    return P;
}
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = NULL jika alokasi gagal. */
{
    // ALGORITMA
    *P = Tree(Akar, L, R);
}
/* Manajemen Memory */
addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NULL, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = NULL, Right(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    // KAMUS
    BinTree P;
    // ALGORITMA
    P = ((Node*) malloc(sizeof(Node)));
    if (P != NULL){
        Akar(P) = X;
        Left(P) = NULL;
        Right(P) = NULL;
    }
    return P;
}
void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    // ALGORITMA
    Left(P) = NULL;
    Right(P) = NULL;
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return (P == NULL);
}
boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    return ((P != NULL) && (Right(P) == NULL) && (Left(P) == NULL));
}
boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    return ((P != NULL) && (Left(P) != NULL) && (Right(P) == NULL));
}
boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    return ((P != NULL) && (Left(P) == NULL) && (Right(P) != NULL));
}
boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    return ((P != NULL) && (Left(P) != NULL) && (Right(P) != NULL));
}

/* *** Traversal *** */

void PrintTree(BinTree P, int h)
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
{
    // ALGORITMA
    if (IsTreeEmpty(P)){/*gabut*/}
    else{
        printf("%s\n", Nama(P));
        if (!IsTreeEmpty(Left(P))){
            for (int i = 0; i < h; i++)
            {
                printf(" ");
            }
        }
        PrintTrees(Left(P), h, 2);
        if (!IsTreeEmpty(Right(P))){
            for (int i = 0; i < h; i++)
            {
                printf(" ");
            }
        }
        PrintTrees(Right(P), h, 2);
    }
}

/* *** Searching *** */
boolean SearchTree(BinTree P, str X)
/* Mengirimkan true jika ada node dari P yang berNULLai X */
{
    // ALGORITMA
    if (IsTreeEmpty(P)){
        return false;
    }
    else{
        if (StringTrueCompare(lengthStr,Nama(P),X)){
            return true;
        }
        else if (SearchTree(Left(P),X)){
            return true;
        }
        else if (SearchTree(Right(P),X)){
            return true;
        }
        return false;
    }
}

upgradeInfo FindTreeNode(BinTree P, str X)
{
    // ALGORITMA
    if (IsTreeEmpty(P)){
        return CreateUpgradeInfo("","");
    }
    else{
        if (StringTrueCompare(lengthStr,Nama(P),X)){
            return Akar(P);
        }
        else if (SearchTree(Left(P),X)){
            return FindTreeNode(Left(P),X);
        }
        else if (SearchTree(Right(P),X)){
            return FindTreeNode(Right(P),X);
        }
        return CreateUpgradeInfo("","");
    }
}
/* *** Operasi lain *** */
void AddDaun(BinTree *P, str X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun berNULLai X, diambil daun yang paling kiri */
{
    // KAMUS
    BinTree P1;
    // ALGORITMA
    if (StringTrueCompare(lengthStr,Nama(*P),X) && (IsTreeOneElmt(*P))){
        P1 = AlokNode(Y);
        if (Kiri){
            Left(*P) = P1;
        }
        else{
            Right(*P) = P1;
        }
    }
    else{
        if (SearchTree(Left(*P),X)){
            AddDaun(&Left(*P), X, Y, Kiri);
        }
        else{
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}

void AddCabang(BinTree *P, str X, infotype Y)
/* I.S. P tidak kosong, X adalah salah satu node Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*      Jika ada > 1 daun berNULLai X, diambil daun yang paling kiri */
{
    // KAMUS
    BinTree P1;
    // ALGORITMA
    if (StringTrueCompare(lengthStr,Nama(*P),X)){
        
        if (Left(*P) == NULL){
            P1 = AlokNode(Y);
            Left(*P) = P1;
        }
        else if (Right(*P) == NULL){
            P1 = AlokNode(Y);
            Right(*P) = P1;
        }
    }
    else{
        if (SearchTree(Left(*P),X)){
            AddCabang(&Left(*P), X, Y);
        }
        else{
            AddCabang(&Right(*P), X, Y);
        }
    }
}


upgradeInfo CreateUpgradeInfo(str Nama, str Wahanasblm)
/*Membuat upgradeInfo baru dengan string nama dan string wahanasblm*/
{
    //KAMUS
    upgradeInfo U;
    //ALGORITMA
    StringCopy(lengthStr,U.nama,Nama);
    StringCopy(lengthStr,U.wahanasblm,Wahanasblm);
    return U;
}