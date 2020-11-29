#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include "boolean.h"
#include "peta.h"
#include "MatriksOfString.h"
#include "customString.h"
#include "PrepCommand.h"
#include "point.h"
#include "stackt.h"
#include "lokasi.h"
#include "wahana.h"
#include "prioqueuechar.h"

//loading initial file (data wahana sama data material)
void loadingInitialFile(MatriksOfString * MWahana, MatriksOfString * MMaterial);

// pada saat pertama kali di run akan menampilkan ini dan berisi pilihan start/quit
int startupPanel(int choice, boolean picked);

// menampilkan map yang saat ini player berada dan legenda
void displayMap(Peta p);

// pesan bahwa masih pada preparation phase dan tidak akan hilang sebelum keluar phase tsb
void preparationPhaseMsg();

// pesan bahwa sudah ada pada main phase
void mainPhaseMsg();

//pesan kalau tidak ada wahana di sekitar
void tidakAdaWahanaMsg();

//tampilkan inventory user
void ShowGudang(int PMat[5]);

// pesan yang ditampilkan hanya jika player bergerak tidak bisa bergerak ke arah tersebut alias bertemu dengan wahana/antrian/tembok
void unableMoveMsg();

//pesan jika tidak bisa serve
void unableServeMsg();

//pesan jika wahana tidak ada
void wahana404();

// fungsi untuk mengenali char yang dimasukkan player
char getCharInput();

// menentukan apakah pemain sedang ada di office/tidak apabila pemain ingin memasukki office
void handleEnteringOffice(Peta p, boolean * target);

// menampilkan pesan bahwa pemain sudah memasukki main phase
void handleEnteringMainPhase(boolean *prep, boolean *main, Stack * S);

//handle ganti hari
void handleFinishDay(boolean *prep, boolean *main, PrioQueueChar * Q);

//bangun wahana di W/A/S/D dari posisi user
void bangunWahana(Peta * peta, MatriksOfString MWahana);

//intiialize nilai awal list wahana
void initializeListWahana(Wahana listWahana[8], MatriksOfString MWahana, Lokasi PlokasiWahana[barisMatriksWahana]);

//updating list wahana untuk main phase
void updateListWahana(Wahana listWahana[], MatriksOfString MWahana, Lokasi PlokasiWahana[]);

// fungsi yang berguna untuk mengecek move input yang digunakan pemain valid ato tidak
boolean checkMovement(char input);

//mapping dari lokasi ke nama wahana
void PointToNama(MatriksOfString M, Stack S, Lokasi P,Lokasi PlokasiWahana[],str Nama);

// menampilkan pesan bahwa pemain sudah keluar dari permainan
void exitGame(boolean *quit);