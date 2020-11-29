#include "peta.c"
#include "point.c"
#include "system.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <conio.h>
#include "boolean.h"
#include "matriks.c"

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