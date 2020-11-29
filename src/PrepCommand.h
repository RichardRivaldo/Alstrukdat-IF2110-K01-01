/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"
#include "MatriksOfString.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "stackt.h"
#include "customString.h"
#include "point.h"
#include "bintree.h"

Stack S;
int PMat[5];
int Money = 10000;
int Time = 86400;
Lokasi PKoordinat;
Lokasi PlokasiWahana[8];
// = {MakePOINT(-1,-1),MakePOINT(-1,-1),MakePOINT(3,3),MakePOINT(-1,-1),MakePOINT(-1,-1)};
BinTree pohonUpgrade[5];

void LoadCabangPohonUpgrade(MatriksOfString wahana, BinTree pohonUpgrade[5]);

void IsiPohonUpgrade(MatriksOfString M, BinTree (*P)[5]);

void removeKomaMaterialWahana(int panjang,int output[5], char input[panjang]);

void LoadFileWahana(MatriksOfString * MatriksWahana, int brs, int klm);

void printMatriksWahana(MatriksOfString M);

void LoadFileMaterial(MatriksOfString * MatriksMaterial, int brs, int klm);

void build(MatriksOfString wahana,Stack *act, int PMoney /*Player's Money*/, int PTime /*Waktu yang ada*/,
            Lokasi PlokasiWahana[8],Lokasi PKoordinat /*Koordinat bangunan*/, int PMat[5], char namaWahana[lengthStr]);

void ShowBuild(MatriksOfString M, Lokasi lokasi);

void buy(MatriksOfString mat, Stack *act, int PMoney /*Player's Money*/, int PTime /*Waktu yang ada*/, char cjumlah[lengthStr], char namaMat[lengthStr]);

void ShowBuy(MatriksOfString mat);

void upgrade(MatriksOfString wahana,Stack *act, int PMoney /*Player's Money*/, int PTime /*Waktu yang ada*/,BinTree pohonUpgrade[5],
            Lokasi PlokasiWahana[8],Lokasi PKoordinat /*Koordinat player*/, int PMat[5], char namaWahana[lengthStr]);

void ShowUpgrade(MatriksOfString wahana,Stack *act, int PMoney /*Player's Money*/, int PTime /*Waktu yang ada*/,BinTree pohonUpgrade[5],
            Lokasi PlokasiWahana[8],Lokasi PKoordinat /*Koordinat player*/, int PMat[5], char namaWahana[lengthStr]);

void PrintHistory(MatriksOfString wahana,BinTree pohonUpgrade,char namaWahana[lengthStr]);

void Undo(Stack *S);

void Execute(Stack *S, int * Money, int * PMat[5], Lokasi * PlokasiWahana[8]);

void CallMain(Stack *S);

#endif