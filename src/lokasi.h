#ifndef Lokasi_H
#define Lokasi_H

#include "point.h"

typedef struct 
{
	POINT Koordinat;
	int Submap; 
} Lokasi;

Lokasi CreateLokasi(POINT Koordinat,int Submap);
//Membuat Lokasi dengan POINT Koordinat, dan int submap.

#endif