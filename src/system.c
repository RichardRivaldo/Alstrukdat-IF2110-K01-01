#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include "boolean.h"
#include "peta.h"
#include "MatriksOfString.h"
#include "customString.h"
#include "stackt.h"
#include "PrepCommand.c"
#include "lokasi.h"
#include "wahana.h"
#include "prioqueuechar.h"

void loadingInitialFile(MatriksOfString * MWahana, MatriksOfString * MMaterial){
	LoadFileWahana(MWahana, 8, 12);
    LoadFileMaterial(MMaterial, 5, 2);
	InitializeStack(&S);
	IsiPohonUpgrade(*MWahana,&pohonUpgrade);

	for (int i = 0; i < barisMatriksWahana; ++i){
        PlokasiWahana[i].Koordinat = MakePOINT(-1,-1);
		PlokasiWahana[i].Submap = -1;
    }

	printf("File loaded!\n");
}

int startupPanel(int choice, boolean picked){
		if(picked){
			if(choice==0){
				printf("Starting your game...");
				return 1;
			}else{
				return 0;
			}
		}
    switch(choice){
			case 0:
				printf("--------------------------------------------------\n");
				printf("----------Welcome To Willy Wangky Tycoon----------\n");
				printf("--------------------------------------------------\n");
				printf("-                                                -\n");
				printf("-               >  START GAME  <                 -\n");
				printf("-                                                -\n");
				printf("-                     EXIT                       -\n");
				printf("-                                                -\n");
				printf("--------------------------------------------------\n");
				printf("----------PRESS SPACE TO START THE GAME-----------\n");
				printf("--------------------------------------------------\n");
				printf("\n");
				break;
			case 1:
				printf("--------------------------------------------------\n");
				printf("----------Welcome To Willy Wangky Tycoon----------\n");
				printf("--------------------------------------------------\n");
				printf("-                                                -\n");
				printf("-                  START GAME                    -\n");
				printf("-                                                -\n");
				printf("-                  >  EXIT  <                    -\n");
				printf("-                                                -\n");
				printf("--------------------------------------------------\n");
				printf("----------PRESS SPACE TO START THE GAME-----------\n");
				printf("--------------------------------------------------\n");
				printf("\n");
				break;
			default:
				printf("Something went wrong!");
				break;
    }

		char input;
		input = _getch();
		input = toupper(input);

		if(input =='P' || input=='S'){
			choice+=1;
		}else if(input=='H' || input=='W'){
			choice-=1;
		}else if(input==' '){
			picked=true;
		}

		if(choice < 0){
			choice = 1;
		}
		else if(choice > 1){
			choice = 0;
		}
		startupPanel(choice, picked);
}

void displayMap(Peta p){
	printf("--------------------------------------------------\n");
	printf("--------Willy Wangky's Amusement Park Map---------\n");
	printf("--------------------------------------------------\n");
	printf("\n\n");
	printCurrentArea(&p);
	printf("\n\n");
	printf("--------------------------------------------------\n");
	printf("- Legend                                         -\n");
	printf("-                                                -\n");
	printf("- P : Player                                     -\n");
	printf("- O : Office                                     -\n");
	printf("- W : Wahana                                     -\n");
	printf("- A : Antrian                                    -\n");
	printf("-                                                -\n");
	printf("--------------------------------------------------\n");
	printf("\n");
}

void preparationPhaseMsg(){
	printf("--------------------------------------------------\n");
	printf("-----------------PREPARATION PHASE----------------\n");
	printf("--------------------------------------------------\n");
	printf("-                                                -\n");
	printf("- You are currently on preparation phase, here   -\n");
	printf("- are several commands available for this phase  -\n");
	printf("-                                                -\n");
	printf("- W,A,S,D : Movement                             -\n");
	printf("- M       : Shows Map                            -\n");
	printf("- O       : Entering office                      -\n");
	printf("- G       : Start Main Phase                     -\n");
	printf("- I       : Isi Gudang                           -\n");
	printf("- B       : Build                                -\n");
	printf("- P       : Purchase                             -\n");
	printf("- U       : Upgrade                              -\n");
	printf("- E       : Execute                              -\n");
	printf("- Z       : Undo                                 -\n");
	printf("-                                                -\n");
	printf("- Q       : Quit game                            -\n");
	printf("-                                                -\n");
	printf("--------------------------------------------------\n");
	printf("\n");
}

void mainPhaseMsg(){
	printf("--------------------------------------------------\n");
	printf("--------------------MAIN PHASE--------------------\n");
	printf("--------------------------------------------------\n");
	printf("-                                                -\n");
	printf("- You are currently on main phase, here          -\n");
	printf("- are several commands available for this phase  -\n");
	printf("-                                                -\n");
	printf("- W,A,S,D : Movement                             -\n");
	printf("- M       : Shows Map                            -\n");
	printf("- O       : Entering office                      -\n");
	printf("- L       : Serve Queue Pengunjung               -\n");
	printf("- R       : Repair Wahana                        -\n");
	printf("- I       : Info Wahana                          -\n");
	printf("- P       : Prepare (Finish Current Session)     -\n");
	printf("-                                                -\n");
	printf("- Q       : Quit game                            -\n");
	printf("-                                                -\n");
	printf("--------------------------------------------------\n");
	printf("\n");
}

void unableMoveMsg(){
	printf("--------------------------------------------------\n");
	printf("-           Ouch! It seems like you              -\n");
	printf("-             bump into something!               -\n");
	printf("--------------------------------------------------\n");
}

void unableServeMsg(){
	printf("--------------------------------------------------\n");
	printf("-         You can't serve anyone here!           -\n");
	printf("-        make sure you're near A legend          -\n");
	printf("--------------------------------------------------\n");
}

void wahana404(){
	printf("--------------------------------------------------\n");
	printf("-         Uh oh! Wahana doesn't exist!           -\n");
	printf("-     maybe you have to built it tomorrow!       -\n");
	printf("--------------------------------------------------\n");
}

void tidakAdaWahanaMsg(){
	printf("--------------------------------------------------\n");
	printf("-           Are you drunk? You're in             -\n");
	printf("-               midst of nowhere!                -\n");
	printf("-                                                -\n");
	printf("-       Go near W to upgrade it's property!!     -\n");
	printf("--------------------------------------------------\n");
}

void ShowGudang(int PMat[5]){
    // ALGORITMA
    printf("Materialmu di gudang :\n");
	printf("    Semen : %d\n", PMat[0]);
	printf("    Baja : %d\n", PMat[1]);
	printf("    Sekrup : %d\n", PMat[2]);
	printf("    Kayu : %d\n", PMat[3]);
	printf("    Primogem : %d\n", PMat[4]);
}

char getCharInput(){
	char input;
	input = _getch();
	return toupper(input); //normalize the input
}

void handleEnteringOffice(Peta p, boolean * target){
	if(isInOffice(&p)){
		printf("--------------------------------------------------\n");
		printf("-              Got some work to do?              -\n");
		printf("-             ENTERING THE OFFICE...             -\n");
		printf("--------------------------------------------------\n");
		*target = true;
	}else{
		printf("--------------------------------------------------\n");
		printf("-             UH OH! It's seems like             -\n");
		printf("-         you're not in your office yet!         -\n");
		printf("--------------------------------------------------\n");
		printf("\n");
		*target = false;
	}
}

void bangunWahana(Peta * peta, MatriksOfString MWahana){
	char posisi;
	printf("Silahkan pilih mau bangun di bagian mana?\n");
	printf("W - Di atas posisi saat ini\n");
	printf("A - Di kanan posisi saat ini\n");
	printf("S - Di bawah posisi saat ini\n");
	printf("D - Di kiri posisi saat ini\n");

	posisi = getCharInput();

	while(!checkMovement(posisi)){
		printf("MASUKAN INPUT SALAH!\n");
		printf("Silahkan pilih mau bangun di bagian mana?\n");
		printf("W - Di atas posisi saat ini\n");
		printf("A - Di kanan posisi saat ini\n");
		printf("S - Di bawah posisi saat ini\n");
		printf("D - Di kiri posisi saat ini\n");
		posisi = getCharInput();
	}

	POINT target = (*peta).coords;

	switch(posisi){
		case 'W':
			target.Y--;break;
		case 'A':
			target.X--;break;
		case 'S':
			target.Y++;break;
		case 'D':
			target.X++;break;
		default:break;
	}

	Lokasi targetLokasi = CreateLokasi(target,(*peta).currentArea);

	boolean res = ShowBuild(MWahana, targetLokasi);
	if(res){
		switch(posisi){
			case 'W':
				if(getAtas(peta)=='-'){
					bangunAtas(peta);
				}
				break;
			case 'A':
				if(getKanan(peta)=='-'){
					bangunKanan(peta);
				}
				break;
			case 'S':
				if(getBawah(peta)=='-'){
					bangunBawah(peta);
				}
				break;
			case 'D':
				if(getKiri(peta)=='-'){
					bangunKiri(peta);
				}
				break;
    }
	}
    
}

void handleEnteringMainPhase(boolean *prep, boolean *main, Stack * S){
	CallMain(S);
	printf("--------------------------------------------------\n");
	printf("-            What A Nice Preparation!            -\n");
	printf("-     Now entering the real deal! Get Ready!     -\n");
	printf("--------------------------------------------------\n");
	printf("\n");
	*prep = false;
	*main = true;
}

void handleFinishDay(boolean *prep, boolean *main, PrioQueueChar * Q){
	printf("--------------------------------------------------\n");
	printf("-               Huh! What a hustle!              -\n");
	printf("-           Get ready for the next day!!         -\n");
	printf("--------------------------------------------------\n");
	printf("\n");
	*prep = true;
	*main = false;
}

void initializeListWahana(Wahana listWahana[8], MatriksOfString MWahana, Lokasi PlokasiWahana[barisMatriksWahana]){
	for(int i = 0; i<8; i++){
		Wahana target;
		StringCopy(lengthStr, target.nama, MWahana.Mem[i][0]);
		target.kapasitas = StringToInt(lengthStr,MWahana.Mem[i][1]);
		target.profit = StringToInt(lengthStr,MWahana.Mem[i][2]);
		target.durasi = StringToInt(lengthStr, MWahana.Mem[i][3])/60;
		target.reparationTime = StringToInt(lengthStr, MWahana.Mem[i][4]);
		target.status = StringToInt(lengthStr, MWahana.Mem[i][9]);
		StringCopy(lengthStr, target.deskripsi, MWahana.Mem[i][11]);
		target.lokasi = PlokasiWahana[i];
		target.qty = 0;
		target.income = 0;
		target.qtyAll = 0;
		target.incomeAll = 0;
		listWahana[i] = target;
	}
}

void updateListWahana(Wahana listWahana[8], MatriksOfString MWahana, Lokasi PlokasiWahana[barisMatriksWahana]){
	for(int i = 0; i<8; i++){
		StringCopy(lengthStr, listWahana[i].nama, MWahana.Mem[i][0]);
		listWahana[i].kapasitas = StringToInt(lengthStr,MWahana.Mem[i][1]);
		listWahana[i].profit = StringToInt(lengthStr,MWahana.Mem[i][2]);
		listWahana[i].durasi = StringToInt(lengthStr, MWahana.Mem[i][3])/60;
		listWahana[i].reparationTime = StringToInt(lengthStr, MWahana.Mem[i][4]);
		listWahana[i].status = StringToInt(lengthStr, MWahana.Mem[i][9]);
		StringCopy(lengthStr, listWahana[i].deskripsi, MWahana.Mem[i][11]);
		listWahana[i].lokasi = PlokasiWahana[i];
		listWahana[i].qtyAll= qtyAll(listWahana[i]) + qty(listWahana[i]);
		listWahana[i].incomeAll= incomeAll(listWahana[i]) + income(listWahana[i]);
		listWahana[i].qty = 0;
		listWahana[i].income = 0;
	}
}

boolean checkMovement(char input){
	return input=='W' || input=='A' || input=='S' || input=='D';
}

void PointToNama(MatriksOfString M, Stack S,Lokasi P,Lokasi PlokasiWahana[barisMatriksWahana],str Nama)
{
	MakeEmptyString(lengthStr,Nama);
	Lokasi lokasiWahana[barisMatriksWahana] ;

	stackToLokasi(S,lokasiWahana);

	for (int j = 0; j < 8; ++j)
    {
        if (NEQ(PlokasiWahana[j].Koordinat, MakePOINT(-1,-1))){
            lokasiWahana[j] = PlokasiWahana[j];
        }
    }
	int idx = 0;
	for (int i = 0; i < barisMatriksWahana; ++i)
	{
		if (EQ(lokasiWahana[i].Koordinat,P.Koordinat) && (lokasiWahana[i].Submap == P.Submap))
		{
			idx = i;
		}
	}
	StringCopy(lengthStr,Nama,M.Mem[idx][0]);
}

void exitGame(boolean *quit){
	*quit = true;
	printf("--------------------------------------------------\n");
	printf("-               THANKS FOR PLAYING!              -\n");
	printf("-                  SEE YOU LATER!                -\n");
	printf("--------------------------------------------------\n");
}