#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include "boolean.h"
#include "peta.h"

int startupPanel(int choice, boolean picked);

void displayMap(Peta p);

void preparationPhaseMsg();

void mainPhaseMsg();

void unableMoveMsg();

char getCharInput();

void handleEnteringOffice(Peta p, boolean * target);

void handleEnteringMainPhase(boolean *prep, boolean *main);

boolean checkMovement(char input);

void exitGame(boolean *quit);