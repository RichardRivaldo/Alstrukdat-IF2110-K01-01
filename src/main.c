#include "peta.c"
#include "point.c"
#include "lokasi.c"
#include "PrepCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <conio.h>
#include "boolean.h"
#include "matriks.c"
#include "MatriksOfString.c"
#include "customString.c"
#include <string.h>
#include "mesinkar.c"
#include "mesinkata.c"
#include "stackt.c"
#include "bintree.c"

//global variables
Stack S;
int PMat[5];
int Money = 10000;
int Time = 86400;
Lokasi PKoordinat;
Lokasi PlokasiWahana[8];
BinTree pohonUpgrade[5];

#include "system.c"

void main(){
	int start = startupPanel(0,false);
	if(start==0){
		//exit dari menu utama
		printf("See you later!");
		return;
	}else if(start==1){
		printf("MASUK KE GAME\n");

		//initial setup
		boolean isPreparationPhase = true;
		boolean isMainPhase = false;
		boolean isInOffice = false;
		boolean quit = false;
 
		MatriksOfString MWahana;
    MatriksOfString MMaterial;

		loadingInitialFile(&MWahana, &MMaterial);

		printMatriksWahana(MWahana);

		Peta p = bacaPeta();
		// printf("berhasil masuk sini");
		displayMap(p);

		//the whole game
		while(!quit){
			char input;
			//preparation phase
			while(isPreparationPhase && !quit){
				preparationPhaseMsg(); 
				input = getCharInput();
				if(checkMovement(input)){
					handleGerak(input, &p);
				}else{
					switch(input){
						case 'M': displayMap(p);break;
						case 'O': handleEnteringOffice(p, &isInOffice);break;
						case 'G': handleEnteringMainPhase(&isPreparationPhase, &isMainPhase);break;
						case 'B': bangunWahana(&p, MWahana); break;
						case 'P': ShowBuy(MMaterial); break;
						case 'U': {
							Lokasi res;
							res = checkWahanaSurrounding(&p);
							if(res.Submap!=-1){
								//point to nama
								str nama;
								PointToNama(MWahana,S, res, PlokasiWahana, nama);
								printf("INI NAMA WAHANA DISEKITARMU : %s\n",nama);
								ShowUpgrade(MWahana,&S,Money,Time,pohonUpgrade,PlokasiWahana,res,PMat,nama);
							}else{
								tidakAdaWahanaMsg();
							}
						}
						break;
						case 'Q': exitGame(&quit);break;
					}
				} 
			}

			//main phase
			while(isMainPhase){
				//do something here;
				printf("INI TINGGAL DIKERJAIN MAIN PHASENYA");
				isMainPhase=false;
				break;
			}
			quit = true;
		}
	}
}