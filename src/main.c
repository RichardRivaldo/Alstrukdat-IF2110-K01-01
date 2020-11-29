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
#include "wahana.c"
#include "prioqueuechar.c"
#include "jam.c"
#include "MainCommand.c"


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

		//initial setup
		boolean isPreparationPhase = true;
		boolean isMainPhase = false;
		boolean isInOffice = false;	
		boolean quit = false;
 
		MatriksOfString MWahana;
    MatriksOfString MMaterial;

		PrioQueueChar Q;
		Wahana listWahana[8];


		loadingInitialFile(&MWahana, &MMaterial);

		initializeListWahana(listWahana, MWahana, PlokasiWahana);

		// printMatriksWahana(MWahana);

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
						case 'G': handleEnteringMainPhase(&isPreparationPhase, &isMainPhase, &S);break;
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
						case 'Z':Undo(&S); break;
						case 'E':{
							Execute(&S, &Money, PMat, PlokasiWahana);
							handleEnteringMainPhase(&isPreparationPhase, &isMainPhase, &S);
							}
						break;
						case 'Q': exitGame(&quit);break;
					}
				} 
			}

			//update listWahana
			updateListWahana(listWahana, MWahana, PlokasiWahana);
			SistemQueue(&Q, listWahana);
			printf("INI HASIL PRIO QUEUE\n");
			PrintPrioQueueChar(Q);
			//main phase
			while(isMainPhase){
				//do something here;
				mainPhaseMsg(); 
				input = getCharInput();
				if(checkMovement(input)){
					handleGerak(input, &p);
				}else{
					switch(input){
						case 'M': displayMap(p);break;
						case 'O': handleEnteringOffice(p, &isInOffice);break;
						case 'L': {
								if(nearA(&p)){
									char nama[255];
									printf("Silahkan masukan nama wahana yang ingin dilayani : ");
									scanf("%s",&nama);
									Wahana target = findWahana(listWahana, nama);
									if(StringTrueCompare(lengthStr, target.nama, "404")){
										wahana404();
									}else{
										Serve(&Q, listWahana, nama);
									}
								}else{
									unableServeMsg();
								}
							}
							break;
						case 'I':{
							Lokasi res;
							res = checkWahanaSurrounding(&p);
							if(res.Submap!=-1){
								//point to nama
								str nama;
								PointToNama(MWahana,S, res, PlokasiWahana, nama);
								printf("INI NAMA WAHANA DISEKITARMU : %s\n",nama);
								Wahana target = findWahana(listWahana, nama);
								displayWahana(target);
							}else{
								tidakAdaWahanaMsg();
							}
						}
						break;
						case 'Q': exitGame(&quit); isMainPhase=false;break;
					}
				}
				// isMainPhase=false;
			}
			// quit = true;
		}
	}
}