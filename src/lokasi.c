#include "lokasi.h"
#include "point.h"

Lokasi CreateLokasi(POINT Koordinat,int Submap)
{
	Lokasi L;
	L.Koordinat = Koordinat;
	L.Submap = Submap;
	return L;
}