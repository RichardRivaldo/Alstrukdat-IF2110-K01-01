#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include "boolean.h"
#include "peta.h"

int startupPanel(int choice, boolean picked){
		if(picked){
			if(choice==0){
				printf("Starting your game...");
				return 1;
			}else{
				return 0;
			}
			return;
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

		if(input =='P'){
			choice+=1;
		}else if(input=='H'){
			choice-=1;
		}else if(input==' '){
			picked=true;
		}

		if(choice!=0 && choice!=1){
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

void exitGame(boolean *quit){
	*quit = true;
	printf("--------------------------------------------------\n");
	printf("-               THANKS FOR PLAYING!              -\n");
	printf("-                  SEE YOU LATER!                -\n");
	printf("--------------------------------------------------\n");
}