#ifndef peta_H
#define peta_H

#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriks.h"
#include "lokasi.h"

typedef struct{
    int currentArea;
    int sizeR;
    int sizeC;
    MATRIKS submap[4];
    POINT coords;
    //get current position Elmt(submap[currentArea],coords.Y, coords.X) --> CHAR
} Peta;

#define areas(P) (P).areas
#define currentArea(P) (P).currentArea
#define coords(P) (P).coords
#define y(P) ((P).coords).y
#define x(P) ((P).coords).x

// baca peta dari file
Peta bacaPeta();

// buat ngubah hasil baca peta yang tadinya string ke int
int convertStringToInt(char line[]);

// handle W/A/S/D
void handleGerak(char opsi, Peta * P);

//cek collision detection
boolean verifyGerak(char target);

//print tempat player berada sekarang
void printCurrentArea(Peta *P);

//update peta
void updatePeta(char target, POINT P, int area, Peta *peta);

char getCurrentPosition(Peta * peta);

char getAtas(Peta * peta);

char getBawah(Peta * peta);

char getKiri(Peta * peta);

char getKanan(Peta * peta);

void bangunAtas(Peta * peta);

void bangunBawah(Peta * peta);

void bangunKanan(Peta * peta);

void bangunKiri(Peta * peta);

//check apakah posisi sekarang di office
boolean isInOffice(Peta * peta);

boolean nearA(Peta * peta);

Lokasi checkWahanaSurrounding(Peta * peta);

void resetPeta(Peta * peta, Lokasi lokasiWahana[]);

#endif