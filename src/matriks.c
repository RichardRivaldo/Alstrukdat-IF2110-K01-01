#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    (*M).NBrsEff = NB;
    (*M).NKolEff = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    if ((BrsMin <= i) && (i <= BrsMax) && (KolMin <= j) && (j <= KolMax)){
        return true;
    }
    else{
        return false;
    }
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return M.NBrsEff - 1;
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return M.NKolEff - 1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    if ((BrsMin <= i) && (i < M.NBrsEff) && (KolMin <= j) && (j < M.NKolEff)){
        return true;
    }
    else{
        return false;
    }
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    // KAMUS
    int i, j;
    // ALGORITMA
    for (i = BrsMin; i < MIn.NBrsEff ; ++i)
    {
        for (j = KolMin; j < MIn.NKolEff; ++j)
        {
            (*MHsl).Mem[i][j] = MIn.Mem[i][j];
        }   
    }
    MakeMATRIKS(i, j, MHsl);
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    // KAMUS
    int i, j;
    // ALGORITMA
    MakeMATRIKS(NB, NK, M);
    for (i = BrsMin; i < (*M).NBrsEff ; ++i)
    {
        for (j = KolMin; j < (*M).NKolEff; ++j)
        {
            scanf("%d", &(*M).Mem[i][j]);
        }   
    }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    // KAMUS
    int i, j;
    // ALGORITMA
    for (i = 0; i < 10; ++i){
        for (j = 0; j < 20; ++j)
        {
            printf("%c", (M).Mem[i][j]);
        }
        printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    // KAMUS
    int i, j;
    MATRIKS M;
    // ALGORITMA
    MakeMATRIKS(M1.NBrsEff, M2.NKolEff, &M);
    for (i = BrsMin; i < (M1).NBrsEff ; ++i)
    {
        for (j = KolMin; j < (M1).NKolEff; ++j)
        {
            M.Mem[i][j] = M1.Mem[i][j] + M2.Mem[i][j];
        }   
    }
    return M;  
} 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    // KAMUS
    int i, j;
    MATRIKS M;
    // ALGORITMA
    MakeMATRIKS(M1.NBrsEff, M2.NKolEff, &M);
    for (i = BrsMin; i < (M1).NBrsEff ; ++i)
    {
        for (j = KolMin; j < (M1).NKolEff; ++j)
        {
            M.Mem[i][j] = M1.Mem[i][j] - M2.Mem[i][j];
        }   
    }
    return M;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    // KAMUS
    int i, j, k;
    MATRIKS M;
    // ALGORITMA
    MakeMATRIKS(M1.NBrsEff, M2.NKolEff, &M);
    for (i = BrsMin; i < (M1).NBrsEff ; ++i)
    {
        for (j = KolMin; j < (M2).NKolEff; ++j)
        {
            M.Mem[i][j] = 0;
            for (k = BrsMin; k < (M2).NBrsEff; ++k)
            {
                M.Mem[i][j] = M.Mem[i][j] + (M1.Mem[i][k] * M2.Mem[k][j]);
            }
        }   
    }
    return M;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    // KAMUS
    int i, j;
    MATRIKS M1;
    // ALGORITMA
    MakeMATRIKS(M.NBrsEff, M.NKolEff, &M1);
    for (i = BrsMin; i < M.NBrsEff ; ++i)
    {
        for (j = KolMin; j < M.NKolEff; ++j)
        {
            M1.Mem[i][j] = M.Mem[i][j] * X;
        }   
    }
    return M1;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    // KAMUS
    int i, j;
    // ALGORITMA
    for (i = BrsMin; i < (*M).NBrsEff ; ++i)
    {
        for (j = KolMin; j < (*M).NKolEff; ++j)
        {
            (*M).Mem[i][j] = (*M).Mem[i][j] * K;
        }   
    }
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    if ((M1.NBrsEff == M2.NBrsEff) && (M1.NKolEff == M2.NKolEff)){
        return true;
    }
    else{
        return false;
    }
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return (M.NBrsEff * M.NKolEff);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    if (M.NBrsEff == M.NKolEff){
        return true;
    }
    else{
        return false;
    }
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    // KAMUS
    int i, j;
    boolean simetri = true;
    // ALGORITMA
    if (IsBujurSangkar(M) == false){
        return false;
    }
    else{
        for (i = BrsMin; i < (M).NBrsEff; ++i)
        {
            for (j = i; j < (M).NKolEff; ++j)
            {
                if ((M).Mem[i][j] != (M).Mem[j][i]){
                    simetri = false;
                }
            }   
        }
        return simetri;
    }
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    // KAMUS
    int i, j;
    boolean satuan = true;
    // ALGORITMA
    if (IsBujurSangkar(M) == false){
        return false;
    }
    else{
        for (i = BrsMin; ((i < M.NBrsEff) && (satuan == true)); ++i)
        {
            for (j = KolMin; ((j < M.NKolEff) && (satuan == true)); ++j)
            {
                if ((i == j) && (M.Mem[i][j] != 1)){
                    satuan = false;
                }
                else if ((i != j) && (M.Mem[i][j] != 0)){
                    satuan = false;
                }
            }   
        }
        return satuan;
    }
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    // KAMUS
    int i, j;
    float banyak = 0.00;
    // ALGORITMA
    for (i = BrsMin; i < (M).NBrsEff; ++i)
    {
        for (j = KolMin; j < (M).NKolEff; ++j)
        {
            if ((M).Mem[i][j] != 0){
                banyak = banyak + 1.00;
            }
        }   
    }
    if (banyak / NBElmt(M) <= 0.05){
        return true;
    }
    else{
        return false;
    }
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    return KaliKons(M, -1);
}
float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    // KAMUS
    int i, j, k;
    float determinan = 0.;
    MATRIKS MTemp;
    // ALGORITMA
    if (NBElmt(M) == 4){
        return ((M.Mem[0][0] * M.Mem[1][1]) - (M.Mem[0][1] * M.Mem[1][0]));
    }
    else{
        for (i = 0; i < M.NKolEff; ++i)
        {
            MakeMATRIKS(M.NBrsEff - 1, M.NKolEff - 1, &MTemp);
            for (j = 0; j < M.NKolEff; ++j)
            {
                for (k = 1; k < M.NBrsEff; ++k)
                {
                    if (i > j){
                        MTemp.Mem[k-1][j] = M.Mem[k][j];
                    }
                    else if (i < j){
                        MTemp.Mem[k-1][j-1] = M.Mem[k][j];
                    }
                }
            }
            if (i % 2 == 0){
                determinan = determinan + (M.Mem[0][i] * Determinan(MTemp));
            }
            else{
                determinan = determinan - (M.Mem[0][i] * Determinan(MTemp));
            }
        }
        return determinan;
    }
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    PKaliKons(M, -1);
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    // KAMUS
    int i, j;
    MATRIKS M1;
    // ALGORITMA
    MakeMATRIKS((*M).NKolEff, (*M).NBrsEff, &M1);
    for (i = BrsMin; i < (*M).NBrsEff; ++i)
    {
        for (j = 0; j < (*M).NBrsEff; ++j)
        {
            M1.Mem[j][i] = (*M).Mem[i][j];
        }
    }
    CopyMATRIKS(M1, M);
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    // KAMUS
    int j;
    float num = 0.;
    int banyak = 0;
    // ALGORITMA
    for (j = KolMin; j < M.NKolEff ; ++j)
    {
        num = num + M.Mem[i][j];
        banyak = banyak + 1;
    }
    return (num/banyak);
}
float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    // KAMUS
    int i;
    float num = 0.;
    int banyak = 0;
    // ALGORITMA
    for (i = BrsMin; i < M.NBrsEff ; ++i)
    {
        num = num + M.Mem[i][j];
        banyak = banyak + 1;
    }
    return (num/banyak);
}
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    // KAMUS
    int j;
    // ALGORITMA
    *max = M.Mem[i][0];
    *min = M.Mem[i][0];
    for (j = KolMin; j < M.NKolEff ; ++j)
    {
        if (*max < M.Mem[i][j]){
            *max = M.Mem[i][j];
        }
        if (*min > M.Mem[i][j]){
            *min = M.Mem[i][j];
        }
    }
}
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    // KAMUS
    int i;
    // ALGORITMA
    *max = M.Mem[0][j];
    *min = M.Mem[0][j];
    for (i = BrsMin; i < M.NBrsEff ; ++i)
    {
        if (*max < M.Mem[i][j]){
            *max = M.Mem[i][j];
        }
        if (*min > M.Mem[i][j]){
            *min = M.Mem[i][j];
        }
    }
}
int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    // KAMUS
    int j;
    int banyak = 0;
    // ALGORITMA
    for (j = KolMin; j < M.NKolEff ; ++j)
    {
        if (X == M.Mem[i][j]){
            banyak = banyak + 1;
        }
    }
    return banyak;
}
int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    // KAMUS
    int i;
    int banyak = 0;
    // ALGORITMA
    for (i = BrsMin; i < M.NBrsEff ; ++i)
    {
        if (X == M.Mem[i][j]){
            banyak = banyak + 1;
        }
    }
    return banyak;
}

