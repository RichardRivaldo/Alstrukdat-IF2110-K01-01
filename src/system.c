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
	printf("- B       : Build                                -\n");
	printf("- P       : Purchase                             -\n");
	printf("- U       : Upgrade                              -\n");
	printf("- E       : Execute                              -\n");
	printf("- Z       : Undo                                 -\n");
	printf("- X       : Cek Wahana                           -\n");
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
	printf("- You are currently on preparation phase, here   -\n");
	printf("- are several commands available for this phase  -\n");
	printf("-                                                -\n");
	printf("- W,A,S,D : Movement                             -\n");
	printf("- M       : Shows Map                            -\n");
	printf("- O       : Entering office                      -\n");
	printf("- G       : Start Main Phase                     -\n");
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

void tidakAdaWahanaMsg(){
	printf("--------------------------------------------------\n");
	printf("-           Are you drunk? You're in             -\n");
	printf("-               midst of nowhere!                -\n");
	printf("-                                                -\n");
	printf("-       Go near W to upgrade it's property!!     -\n");
	printf("--------------------------------------------------\n");
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

void handleEnteringMainPhase(boolean *prep, boolean *main){
	printf("--------------------------------------------------\n");
	printf("-            What A Nice Preparation!            -\n");
	printf("-     Now entering the real deal! Get Ready!     -\n");
	printf("--------------------------------------------------\n");
	printf("\n");
	*prep = false;
	*main = true;
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