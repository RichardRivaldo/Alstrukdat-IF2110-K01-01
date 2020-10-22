/* File: point.h */
/* Tanggal: 1 September 2020 */
/* *** Realisasi ABSTRACT DATA TYPE POINT *** */

// Nama : Michael Philip Gunadi
// NIM : 13519121
// Kelas : 01

#include "point.h"
#include <stdio.h>
#include "boolean.h"
#include "math.h"

POINT MakePOINT(float X, float Y)
{
    POINT p1;
    Absis(p1) = X;
    Ordinat(p1) = Y;
    return p1;
}

void BacaPOINT(POINT *P)
{
    float x, y;
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x, y);
}

void TulisPOINT(POINT P)
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2)
{
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ(POINT P1, POINT P2)
{
    return (!EQ(P1, P2));
}

boolean IsOrigin(POINT P)
{
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P)
{
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P)
{
    return (Absis(P) == 0);
}

int Kuadran(POINT P)
{
    if (Absis(P) > 0)
    {
        return (Ordinat(P) > 0 ? 1 : (Ordinat(P) < 0 ? 4 : -1));
    }
    else if (Absis(P) < 0)
    {
        return (Ordinat(P) > 0 ? 2 : (Ordinat(P) < 0 ? 3 : -1));
    }
    else
    {
        return (-1);
    }
}

POINT NextX(POINT P)
{
    return (MakePOINT(Absis(P) + 1, Ordinat(P)));
}

POINT NextY(POINT P)
{
    return (MakePOINT(Absis(P), Ordinat(P) + 1));
}

POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
    return (MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY));
}

POINT MirrorOf(POINT P, boolean SbX)
{
    return (SbX ? MakePOINT(Absis(P), Ordinat(P) * -1) : MakePOINT(Absis(P) * -1, Ordinat(P)));
}

float Jarak0(POINT P)
{
    return (sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P)));
}

float Panjang(POINT P1, POINT P2)
{
    float dx, dy;
    dx = Absis(P1) - Absis(P2);
    dy = Ordinat(P1) - Ordinat(P2);
    return (sqrt(dx * dx + dy * dy));
}

void Geser(POINT *P, float deltaX, float deltaY)
{
    *P = MakePOINT(Absis(*P) + deltaX, Ordinat(*P) + deltaY);
}

void GeserKeSbX(POINT *P)
{

    *P = MakePOINT(Absis(*P), 0);
}

void GeserKeSbY(POINT *P)
{
    *P = MakePOINT(0, Ordinat(*P));
}

void Mirror(POINT *P, boolean SbX)
{
    *P = (SbX ? MakePOINT(Absis(*P), Ordinat(*P) * -1) : MakePOINT(Absis(*P) * -1, Ordinat(*P)));
}

void Putar(POINT *P, float Sudut)
{
    float X, Y;
    Sudut = Sudut * 0.0174532925;
    X = cos(Sudut) * Absis(*P) + sin(Sudut) * Ordinat(*P);
    Y = sin(Sudut) * Absis(*P) * -1 + cos(Sudut) * Ordinat(*P);
    *P = MakePOINT(X, Y);
}