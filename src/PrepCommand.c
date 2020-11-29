// gcc PrepCommand.c mesinkar.c mesinkata.c MatriksOfString.c stackt.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// Library buatan sendiri:
#include "boolean.h"
#include "MatriksOfString.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "stackt.h"
#include "customString.h"
#include "point.h"
#include "bintree.h"

#include "MatriksOfString.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include "stackt.c"
#include "customString.c"
#include "point.c"
#include "bintree.c"

//gcc PrepCommand.c MatriksOfString.c mesinkar.c mesinkata.c stackt.c customString.c point.c bintree.c

Stack S;
int PMat[5];
int Money = 10000;
int Time = 43200;
POINT PKoordinat;
POINT PlokasiWahana[8];
// = {MakePOINT(-1,-1),MakePOINT(-1,-1),MakePOINT(3,3),MakePOINT(-1,-1),MakePOINT(-1,-1)};
BinTree pohonUpgrade[5];

void LoadCabangPohonUpgrade(MatriksOfString wahana, BinTree pohonUpgrade[5])
{
 int i,j;
 upgradeInfo U;
 boolean found;
 for (i = 0; i < NBrsEff(wahana); ++i)
 {
  
  if (StringTrueCompare(lengthStr, wahana.Mem[i][10], "base") == 0)
  {
   found = false;
   U = CreateUpgradeInfo(wahana.Mem[i][0],wahana.Mem[i][10]);

   for (j = 0; j < 5 && found == false; ++j)
   {
    if (SearchTree(pohonUpgrade[j],wahana.Mem[i][10]))
    {
     AddCabang(&pohonUpgrade[j],wahana.Mem[i][10],U);
     found = true;
    }
   }
  }
 }
}

void IsiPohonUpgrade(MatriksOfString M, BinTree (*P)[5]){
    // KAMUS
    int j = 0;
    // AGLROTMA
    for (int i = 0; i < M.NBrsEff; i++)
    {
        if (StringTrueCompare(lengthStr, M.Mem[i][10], "base")){
            (*P)[j] = AlokNode(CreateUpgradeInfo(M.Mem[i][0], M.Mem[i][10]));
            j++;
        }
    }
    LoadCabangPohonUpgrade(M,*P);
}

void removeKomaMaterialWahana(int panjang,int output[5], char input[panjang])
{
 //KAMUS
 int incrOutput = 0;
 int j = 0;
 char num[8];
 //ALGORIMTA
 for (int i = 0; i < panjang; i++)
    {
        
        if (input[i] == '\0')
        {
         break;
        }
        if (input[i] != ',')
        {
         MakeEmptyString(8,num);
         j = 0;
         while (input[i] != ',' && input[i] != '\0')
         {
          num[j] = input[i];
          i++;
          j++;
         }
         output[incrOutput] = StringToInt(lengthStr,num);
         incrOutput++;
        }
    }
}

void LoadFileWahana(MatriksOfString * MatriksWahana, int brs, int klm){
    // KAMUS
    FILE * fpointer;
    char singleLine[1000];
    int baris, kolom, i, j;

    // ALGORITMA
    MakeMatriksStr(brs, klm, MatriksWahana);
    if ((fpointer = fopen("../data/wahana.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    fgets(singleLine, 1000, fpointer);
    baris = 0;
    kolom = 0;
    while (!feof(fpointer)){
        i = 0;
        j = 0;
        while (singleLine[i] != '\n'){
            if (singleLine[i] == '-'){
                kolom = kolom + 1;
                j = 0;
            }
            else{
                ((*MatriksWahana).Mem[baris][kolom])[j] = singleLine[i];
                j = j + 1;
            }
            i = i + 1;
        }
        baris = baris + 1;
        kolom = 0;
        fgets(singleLine, 1000, fpointer);
    }
    fclose(fpointer);
}

void printMatriksWahana(MatriksOfString M){
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 12; i++)
        {
            printf("%s   ", M.Mem[j][i]);
        }
        printf("\n");
    }
}

void LoadFileMaterial(MatriksOfString * MatriksMaterial, int brs, int klm){
    // KAMUS
    FILE * fpointer;
    char singleLine[1000];
    int baris, kolom, i, j;

    // ALGORITMA
    MakeMatriksStr(brs, klm, MatriksMaterial);
    if ((fpointer = fopen("../data/material.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    fgets(singleLine, 1000, fpointer);
    baris = 0;
    kolom = 0;
    while (!feof(fpointer)){
        i = 0;
        j = 0;
        while (singleLine[i] != '\n'){
            if (singleLine[i] == '-'){
                kolom = kolom + 1;
                j = 0;
            }
            else{
                ((*MatriksMaterial).Mem[baris][kolom])[j] = singleLine[i];
                j = j + 1;
            }
            i = i + 1;
        }
        baris = baris + 1;
        kolom = 0;
        fgets(singleLine, 1000, fpointer);
    }
    fclose(fpointer);
}

void ShowHelp(){
	// Algoritma
    printf("Daftar Command:\n");
    printf("    - build\n");
    printf("    - upgrade\n");
    printf("    - buy\n");
    printf("    - execute\n");
    printf("    - undo\n");
    printf("    - main\n");
    printf("\n");
}

void build(MatriksOfString wahana,Stack *act, int PMoney /*Player's Money*/, int PTime /*Waktu yang ada*/,
            POINT PlokasiWahana[8],POINT PKoordinat /*Koordinat player*/, int PMat[5], char namaWahana[lengthStr])
{
    //KAMUS
    int i,j;
    int jumlah;
    int harga;
    Aksi X;

    int requiredMoney;
    int requiredTime;
    int availableMaterials[5];
    boolean enoughMaterial = true;
    int requiredWahanaMaterials[5];
    POINT lokasiWahana[8];
    boolean locationIsTaken = false;
    //ALGORITMA
    requiredTime = stackToRequiredTime(*act); //Hitung total waktu yang dibutuhkan dari stack Aksi
    requiredMoney = stackToRequiredMoney(*act); //Hitung total uang yang dibutuhkan dari stack Aksi
    stackToMaterial(*act,availableMaterials); //Hitung materials yang udah ada di stack
    stackToLokasi(*act,lokasiWahana);//Cari posisi dari wahana dari stack

    for (j = 0; j < 8; ++j)
    {
        if (NEQ(PlokasiWahana[j],MakePOINT(-1,-1)))
        {
            lokasiWahana[j] = PlokasiWahana[j];
        }

        if (EQ(lokasiWahana[j], PKoordinat))
        {
            locationIsTaken = true;
        }
    }

    /*BELUM ADA HANDLER LOKASI DIBANGUN*/

    i = 0;
    while(StringCompare(lengthStr, wahana.Mem[i][0], namaWahana) == 0 && i < wahana.NBrsEff)
    {
        i++;
    }
    if (i >= wahana.NBrsEff || namaWahana[0] == '\0')
    {
        printf("Error, tidak ada wahana dengan nama tersebut\n");
    }
    else if (StringTrueCompare(lengthStr, wahana.Mem[i][10], "base") == 0)
    {
        printf("Error, bukan wahana dasar\n");
    }
    else if (NEQ(lokasiWahana[i],MakePOINT(-1,-1))) 
    {
        printf("Error, wahana sudah dibangun\n");
    }
    else if (locationIsTaken)
    {
        printf("Error, sudah ada gedung di sini\n");
    }
    else
    {
        harga = StringToInt(lengthStr,wahana.Mem[i][4]);
        requiredMoney = requiredMoney + harga;
        requiredTime = StringToInt(lengthStr,wahana.Mem[i][5])+requiredTime;
        removeKomaMaterialWahana(lengthStr, requiredWahanaMaterials, wahana.Mem[i][6]); //Hitung material yang diperlukan wahana
        for (j = 0; j < 5; ++j)
        {
            availableMaterials[j] = availableMaterials[j] + PMat[j] - requiredWahanaMaterials[j];
            if (availableMaterials[j] < 0)
            {
                enoughMaterial = false;
            }
        }
        if (enoughMaterial)
        {
            if (PMoney >= requiredMoney)
            {
                if (PTime >= requiredTime)
                {
                    CreateEmptyAksi(&X);
                    X.Money = harga;
                    X.Time = StringToInt(lengthStr,wahana.Mem[i][5]);
                    for (j = 0; j < 5; ++j)
                    {
                        X.Mat[j] = requiredWahanaMaterials[j]*-1;
                    }
                    for (j = 0; j < wahana.NBrsEff; ++j)
                    {
                        X.Wah[j] = lokasiWahana[j];
                    }
                    X.Wah[i] = PKoordinat;
                    Push(act, X);
                    printf("%s telah dibangun\n\n", wahana.Mem[i][0]);
                }
                else
                {
                    printf("Error, waktu tidak cukup\n");
                }
            }
            else
            {
                printf("Error, uang tidak mencukupi\n");
            }
        }
        else
        {
            printf("Error, material tidak mencukupi\n");
        }
    }
}


void ShowBuild(MatriksOfString M){
    // fungsi dipanggil saat ada perintah "build"
    // untuk menampilkan pesan dan list wahana
    char namaWahana[lengthStr];
	// Algoritma
    printf("Daftar Gedung:\n");
    for (int i = 0; i < M.NBrsEff; i++)
    {
        if (StringCompare(lengthStr, M.Mem[i][10], "base")){
            printf("    - $%s %s\n", M.Mem[i][4], M.Mem[i][0]);
        }
    }
    printf("\nInput berupa: <Nama Gedung>\n");
    printf("Masukkan Input: ");
    STARTKATA();
    printf("\n");
    StringCopy(100, namaWahana, pita);
    build(M, &S, Money, Time, PlokasiWahana, PKoordinat, PMat, namaWahana);
}

void buy(MatriksOfString mat, Stack *act, int PMoney /*Player's Money*/, int PTime /*Waktu yang ada*/, char cjumlah[lengthStr], char namaMat[lengthStr]){
    //KAMUS
    int i,j;
    int jumlah;
    int harga;
    Aksi X;

    int requiredMoney;
    int requiredTime;
    //ALGORITMA
 
    requiredTime = stackToRequiredTime(*act); //Hitung total waktu yang dibutuhkan dari stack Aksi
    requiredMoney = stackToRequiredMoney(*act); //Hitung total uang yang dibutuhkan dari stack Aksi

    // STARTKATA();//Input berupa: jumlah nama_bahan, harus divalidasi
    // strcpy(cjumlah, CKata.TabKata); //1000 Primogem <-- contoh pembelian bahan primogem dengan jumlah 1000
    // ADVKATA();
    // strcpy(namaMat, CKata.TabKata);
    i = 0;
 
    while(StringCompare(lengthStr, mat.Mem[i][0], namaMat) == 0 && i < mat.NBrsEff){
        i++;
    }
    if (i >= mat.NBrsEff || namaMat[0] == '\0'){
        printf("Error, tidak ada bahan dengan nama tersebut\n");
    }
    else{
        jumlah = StringToInt(lengthStr,cjumlah);
        harga = StringToInt(lengthStr,mat.Mem[i][1]);
        requiredMoney = requiredMoney + jumlah*harga;
        requiredTime = 1800+requiredTime; 
        if (PMoney >= requiredMoney){
            if (PTime >= requiredTime){
                CreateEmptyAksi(&X);
                X.Money = jumlah*harga;
                X.Time = 1800;
                X.Mat[i] = jumlah;

                Push(act, X);
                printf("%d %s telah dibeli\n\n", jumlah, mat.Mem[i][0]);
            }
            else{
                printf("Error, waktu tidak cukup\n");
            }
        }
        else{
            printf("Error, uang tidak mencukupi\n");
        }
    }
}

void ShowBuy(MatriksOfString mat){
    //KAMUS
    int i;
    char cjumlah[lengthStr], namaMat[lengthStr];
    //ALGORITMA
    printf("Daftar Item:\n");
    for (i = 0; i < mat.NBrsEff; i++)
    {
        printf("    - $%s %s\n", mat.Mem[i][1],mat.Mem[i][0]);
    }
    printf("\nInput berupa: <Jumlah> <Nama Bahan>\n");
    printf("Masukkan Input: ");
    STARTKATA();
    printf("\n");
    if (!EndKata){
        StringCopy(lengthStr, cjumlah, CKata.TabKata);
        ADVKATA();
        if (!EndKata){
            StringCopy(lengthStr, namaMat, CKata.TabKata);
            buy(mat, &S, Money, Time, cjumlah, namaMat);
        }
    }
}

void upgrade(MatriksOfString wahana,Stack *act, int PMoney /*Player's Money*/, int PTime /*Waktu yang ada*/,BinTree pohonUpgrade[5],
            POINT PlokasiWahana[8],POINT PKoordinat /*Koordinat player*/, int PMat[5], char namaWahana[lengthStr])
{
    //KAMUS
    int i,j,idx,idx2;
    int jumlah;
    int harga;
    Aksi X;

    int requiredMoney;
    int requiredTime;
    int availableMaterials[5];
    boolean enoughMaterial = true;
    int requiredWahanaMaterials[5];
    POINT lokasiWahana[8];
    boolean locationIsTaken = false;
    BinTree P = NULL;
    //ALGORITMA
    requiredTime = stackToRequiredTime(*act); //Hitung total waktu yang dibutuhkan dari stack Aksi
    requiredMoney = stackToRequiredMoney(*act); //Hitung total uang yang dibutuhkan dari stack Aksi
    stackToMaterial(*act,availableMaterials); //Hitung materials yang udah ada di stack
    stackToLokasi(*act,lokasiWahana);//Cari posisi dari wahana dari stack

    for (j = 0; j < 8; ++j)
    {
        if (NEQ(PlokasiWahana[j],MakePOINT(-1,-1)))
        {
            lokasiWahana[j] = PlokasiWahana[j];
        }

        if (EQ(lokasiWahana[j], PKoordinat))
        {
            locationIsTaken = true;
        }
    }
    idx = 0;idx2 = 0;
    for (i = 0; i < 5; ++i)
    {
        if (SearchTree(pohonUpgrade[i],namaWahana))
        {
            P = pohonUpgrade[i]; /*Cari pohon dengan nama upgrade*/
        }
    }

    if (P == NULL)
    {
        printf("Error, tidak ada nama wahana\n");
    }
    else
    {
        for (i = 0; i < 8; ++i)
        {
            if (StringTrueCompare(lengthStr, wahana.Mem[i][0], namaWahana))
            {
                idx = i;/*Cari index dari nama upgrade di matriks*/
            }

        }
        upgradeInfo U;
        U = FindTreeNode(P,namaWahana); /*Cari nama wahana yang ingin di upgrade ke nama upgrade*/
        for (i = 0; i < wahana.NBrsEff; ++i)
        {
            if (StringTrueCompare(lengthStr, wahana.Mem[i][0], U.wahanasblm))
            {
                idx2 = i; /*Cari index dari nama wahana yang ingin di upgrade*/
            }
        }

        if (EQ(lokasiWahana[idx2], MakePOINT(-1,-1)))
        {
            printf("Error, wahana yang ingin diupgrade belum dibuat\n");
        }
        else
        {

            harga = StringToInt(lengthStr,wahana.Mem[idx][4]);

            requiredMoney = requiredMoney + harga;
            requiredTime = StringToInt(lengthStr,wahana.Mem[idx][5])+requiredTime;
            removeKomaMaterialWahana(lengthStr, requiredWahanaMaterials, wahana.Mem[idx][6]); //Hitung material yang diperlukan wahana
            for (j = 0; j < 5; ++j)
            {
                availableMaterials[j] = availableMaterials[j] + PMat[j] - requiredWahanaMaterials[j];
                if (availableMaterials[j] < 0)
                {
                    enoughMaterial = false;
                }
            }
            if (enoughMaterial)
            {
                if (PMoney >= requiredMoney)
                {
                    if (PTime >= requiredTime)
                    {

                        POINT PTemp;
                        PTemp = lokasiWahana[idx];
                        lokasiWahana[idx] = lokasiWahana[idx2];
                        lokasiWahana[idx2] = PTemp;


                        CreateEmptyAksi(&X);
                        X.Money = harga;
                        X.Time = StringToInt(lengthStr,wahana.Mem[idx][5]);
                        for (j = 0; j < 5; ++j)
                        {
                            X.Mat[j] = requiredWahanaMaterials[j]*-1;
                        }
                        for (j = 0; j < wahana.NBrsEff; ++j)
                        {
                            X.Wah[j] = lokasiWahana[j];
                        }
                        Push(act, X);
                        printf("%s telah diupgrade menjadi %s\n", wahana.Mem[idx2][0], wahana.Mem[idx][0]);
                    }
                    else
                    {
                        printf("Error, waktu tidak cukup\n");
                    }
                }
                else
                {
                    printf("Error, uang tidak mencukupi\n");
                }
            }
            else
            {
                printf("Error, material tidak mencukupi\n");
            }
        }
    }
}

void ShowUpgrade(MatriksOfString wahana,Stack *act, int PMoney /*Player's Money*/, int PTime /*Waktu yang ada*/,BinTree pohonUpgrade[5],
            POINT PlokasiWahana[8],POINT PKoordinat /*Koordinat player*/, int PMat[5], char namaWahana[lengthStr]){
    // KAMUS
    BinTree P;
    str input;
    // ALGORITMA
    for (int i = 0; i < 5; ++i)
    {
        if (SearchTree(pohonUpgrade[i],namaWahana))
        {
            P = pohonUpgrade[i]; /*Cari pohon dengan nama upgrade*/
        }
    }
    while (true){
        if (StringTrueCompare(lengthStr,Nama(P),namaWahana)){
            break;
        }
        else{
            if (SearchTree(Left(P), namaWahana)){
                P = Left(P);
            }
            else{
                P = Right(P);
            }
        }
    }
    if (Left(P) == NULL && Right(P) == NULL){
        printf("Wahana ini telah mencapai level tertinggi.\n");
    }
    else{
        printf("Ingin melakukan upgrade apa?\n");
        printf("List:\n");
        if (Left(P) != NULL){
            printf("    - %s\n", Nama(Left(P)));
        }
        if (Right(P) != NULL){
            printf("    - %s\n", Nama(Right(P)));
        }
        printf("\nInput berupa: <Nama Gedung>\n");
        printf("Masukkan Input: ");
        STARTKATA();
        printf("\n");
        StringCopy(100, input, pita);
        upgrade(wahana,act,PMoney,PTime,pohonUpgrade,PlokasiWahana,PKoordinat,PMat,input);
    }
}

void PrintHistory(MatriksOfString wahana,BinTree pohonUpgrade,char namaWahana[lengthStr]){//pakai fungsi SearchTree di array upgrade
    // KAMUS
    // ALGORITMA
    if (StringTrueCompare(lengthStr, Nama(pohonUpgrade), namaWahana)){
        printf("%s.\n", Nama(pohonUpgrade));
    }
    else{
        printf("%s -> ", Nama(pohonUpgrade));
        if (SearchTree(Left(pohonUpgrade), namaWahana)){
            PrintHistory(wahana, Left(pohonUpgrade), namaWahana);
        }
        else{
            PrintHistory(wahana, Right(pohonUpgrade), namaWahana);
        }
    }
}
void Undo(Stack *S){
    // KAMUS
    Aksi X;
    // ALGORITMA
    if (!IsEmptyStack(*S)){
        Pop(S, &X);
    }
}

void Execute(Stack *S, int Money, int PMat[5], POINT PlokasiWahana[8]){
    // KAMUS
    Aksi X;
    boolean firsttime = true;
    // ALGORITMA
    while (!IsEmptyStack(*S)){
        Pop(S, &X);
        Money = Money - X.Money;
        for (int i = 0; i < 5; i++)
        {
            PMat[i] = PMat[i] + X.Mat[i];
        }
        if (firsttime){
            for (int i = 0; i < 8; i++)
            {
                PlokasiWahana[i] = X.Wah[i];
            }
        }
        firsttime = false;
    }
}

void CallMain(Stack *S){
    // KAMUS
    Aksi X;
    // ALGORITMA
    if (!IsEmptyStack(*S)){
        Pop(S, &X);
        CallMain(S);
    }
}

void inputPrepPhase(MatriksOfString MWahana, MatriksOfString MMaterial){
    // ALGORITMA
    printf("Masukan Perintah: ");
    STARTKATA();
    printf("\n");
    if (StringCompare(lengthStr, CKata.TabKata, "build")){
        ShowBuild(MWahana);
    }
    else if (StringCompare(lengthStr, CKata.TabKata, "upgrade")){
        ShowUpgrade(MWahana,&S,Money,Time,pohonUpgrade,PlokasiWahana,PKoordinat,PMat,"Halilintar V2");
    }
    else if (StringCompare(lengthStr, CKata.TabKata, "buy")){
        ShowBuy(MMaterial);
    }
    else if (StringCompare(lengthStr, CKata.TabKata, "undo")){
        Undo(&S);
    }
    else if (StringCompare(lengthStr, CKata.TabKata, "execute")){
        Execute(&S,Money,PMat,PlokasiWahana);
    }
    else if (StringCompare(lengthStr, CKata.TabKata, "main")){
        CallMain(&S);
    }
    else if (StringCompare(lengthStr, CKata.TabKata, "help")){
        ShowHelp();
    }
    else{
        printf("Command ini belum tersedia! Silakan input command lain.\n");
    }
}


int main(){
    //Inisialisasi main
    for (int i = 0; i < barisMatriksWahana; ++i)
    {
        PlokasiWahana[i] = MakePOINT(-1,-1);
    }
    // KAMUS
    MatriksOfString MWahana;
    MatriksOfString MMaterial;
    CreateEmpty(&S);
    // ALGORITMA
    LoadFileWahana(&MWahana, 8, 12);
    LoadFileMaterial(&MMaterial, 5, 2);
    IsiPohonUpgrade(MWahana,&pohonUpgrade);
    printMatriksWahana(MWahana);
    while (true){
        inputPrepPhase(MWahana, MMaterial);
    }
    return 0;
}