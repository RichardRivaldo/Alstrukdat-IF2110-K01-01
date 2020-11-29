#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include "boolean.h"
#include "peta.h"

// pada saat pertama kali di run akan menampilkan ini dan berisi pilihan start/quit
int startupPanel(int choice, boolean picked);

// menampilkan map yang saat ini player berada dan legenda
void displayMap(Peta p);

// pesan bahwa masih pada preparation phase dan tidak akan hilang sebelum keluar phase tsb
void preparationPhaseMsg();

// pesan bahwa sudah ada pada main phase
void mainPhaseMsg();

// pesan yang ditampilkan hanya jika player bergerak tidak bisa bergerak ke arah tersebut alias bertemu dengan wahana/antrian/tembok
void unableMoveMsg();

// fungsi untuk mengenali char yang dimasukkan player
char getCharInput();

// menentukan apakah pemain sedang ada di office/tidak apabila pemain ingin memasukki office
void handleEnteringOffice(Peta p, boolean * target);

// menampilkan pesan bahwa pemain sudah memasukki main phase
void handleEnteringMainPhase(boolean *prep, boolean *main);

// fungsi yang berguna untuk mengecek move input yang digunakan pemain valid ato tidak
boolean checkMovement(char input);

// menampilkan pesan bahwa pemain sudah keluar dari permainan
void exitGame(boolean *quit);