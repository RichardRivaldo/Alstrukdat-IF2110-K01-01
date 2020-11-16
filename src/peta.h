#ifndef peta_H
#define peta_H

#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char areas[4][255][255];
    int currentArea;
    POINT coords;
} Peta;

#define areas(P) (P).areas
#define currentArea(P) (P).currentArea
#define coords(P) (P).coords
#define y(P) ((P).coords).y
#define x(P) ((P).coords).x

// baca peta dari file
Peta bacaPeta();

// handle W/A/S/D
void handleGerak(char opsi, Peta * P);

//cek collision detection
boolean verifyGerak(char target);

//print tempat player berada sekarang
void printCurrentArea(Peta *P);

//hapus posisi sebelumnya
void removeP(Peta *peta);

//menambahkan legend P di peta yang telah di update
void addP(Peta *peta);

//update peta
void updatePeta(char target, POINT P, int area, Peta *peta);
#endif