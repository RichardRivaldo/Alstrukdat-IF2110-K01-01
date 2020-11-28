/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
} 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
    return ((BrsMin <= i)&&(i <= BrsMax) && (KolMin <= j)&&(j <= KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    return BrsMin;
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
    return NBrsEff(M)-1;
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
    return NKolEff(M)-1;
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return ((GetFirstIdxBrs(M) <= i)&&(i <= GetLastIdxBrs(M)) && (GetFirstIdxKol(M) <= j)&&(j <= GetLastIdxKol(M)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return Elmt(M, i, i);
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    indeks i, j;
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    for(i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++){
        for(j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++){
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    indeks i, j;
    ElType x;
    MakeMATRIKS(NB, NK, &*M);
    for(i = 0; i < NB; i++){
        for(j = 0; j < NK; j++){
            scanf("%d", &x);
            Elmt(*M, i, j) = x;
        }
    }
}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
    indeks i, j;
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            printf("%d", Elmt(M, i, j));
            if(j != GetLastIdxKol(M)){
                printf(" ");
            }
        }
        if(i != GetLastIdxBrs(M)){
            printf("\n");
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    indeks i, j;
    MATRIKS MNew;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MNew);
    for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for(j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
            Elmt(MNew, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }
    return MNew;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    indeks i, j;
    MATRIKS MNew;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MNew);
    for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for(j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
            Elmt(MNew, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }
    return MNew;
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS MNew;
    indeks i, j, k;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MNew);
    for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for(j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++){
            ElType x = 0;
            for(k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++){
                x = x + (Elmt(M1, i, k) * Elmt(M2, k, j));
            }
            Elmt(MNew, i, j) = x;
        }
    }
    return MNew;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
    MATRIKS MNew;
    indeks i, j;
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &MNew);
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
       for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
           Elmt(MNew, i, j) = (X * Elmt(M, i, j));
       } 
    }
    return MNew;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
    indeks i, j;
    for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
       for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
           Elmt(*M, i, j) = (K * Elmt(*M, i, j));
       } 
    }
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
// boolean EQ (MATRIKS M1, MATRIKS M2){
//     indeks i, j;
//     if((NBElmt(M1) == NBElmt(M2)) && (NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2))){
//         for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
//             for(j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
//                 if(Elmt(M1, i, j) != Elmt(M2, i, j)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     return false;
// }
// /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
// /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
// /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
//    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
// boolean NEQ (MATRIKS M1, MATRIKS M2){
//     return !EQ(M1, M2);
// }
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
    return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
    return (NBrsEff(M) * NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
    return (NBrsEff(M) == NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
    indeks i, j;
    if(IsBujurSangkar(M)){
        for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
            for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
                if(Elmt(M, i, j) != Elmt(M, j, i)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M){
    indeks i, j;
    if(IsBujurSangkar(M)){
        for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
            for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
                if((i == j) && (GetElmtDiagonal(M, i) != 1)){
                    return false;
                }
                else if((i != j) && (Elmt(M, i, j) != 0)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean IsSparse (MATRIKS M){
    indeks i, j;
    float hasil = 0;
    float count = 0;
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            if(Elmt(M, i, j) != 0){
                count += 1;
            }
        }
    }
    hasil = count / (NBrsEff(M) * NKolEff(M));
    return (hasil <= 0.05);
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS Inverse1 (MATRIKS M){
    MATRIKS MNew;
    indeks i, j;
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &MNew);
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            Elmt(MNew, i, j) = ((-1)*Elmt(M, i, j));
        }
    }
    return MNew;
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M){
    indeks i, j, k, i2, j2;
    MATRIKS MTemp;
    float det = 0;

    MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &MTemp);
    if(!IsBujurSangkar(M)){
        return 0.0;
    }
    
    if(NBElmt(M) == 1){
        return (Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M)));
    }
    else if((NBrsEff(M) == 2) && (NKolEff(M) == 2)){
        return ((Elmt(M, 0, 0) * Elmt(M, 1, 1)) - (Elmt(M, 1, 0) * Elmt(M, 0, 1)));
    }
    else{
        for(i = GetFirstIdxKol(M); i <= GetLastIdxKol(M); i++){
            i2 = 0;
            j2 = 0;
            for(j = GetFirstIdxBrs(M)+1; j <= GetLastIdxBrs(M); j++){
                for(k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++){
                    if(i == k){
                        continue;
                    }
                    Elmt(MTemp, i2, j2) = Elmt(M, j, k);
                    j2++;
                    if(j2 == GetLastIdxKol(M)){
                        j2 = 0;
                        i2++;
                    }
                }
            }
            det += ((i % 2 == 0 ? 1 : ~0) * Elmt(M, 0, i) * Determinan(MTemp));
            
        }
        return det;
    }
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
    indeks i, j;
    for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            Elmt(*M, i, j) = ((-1)*Elmt(*M, i, j));
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
    MATRIKS MTemp;
    indeks i, j;
    MakeMATRIKS(NBrsEff(*M), NKolEff(*M), &MTemp);
    for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            Elmt(MTemp, j, i) = Elmt(*M, i, j);
        }
    }
    CopyMATRIKS(MTemp, &*M);
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */