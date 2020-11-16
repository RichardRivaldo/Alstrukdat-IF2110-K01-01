#include "peta.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

void main(){
    Peta p = bacaPeta();
    char input;
    while(input!='Q'){
        printCurrentArea(&p);
        printf("Silahkan mau gerak kemana : WASD,Q\n");
        scanf("%c",&input);
        input = toupper(input);
        if(input == 'W' || input =='A' || input=='S' || input=='D'){
            handleGerak(input, &p);
        }
    }
    printf("Terima kasih telah menguji coba movement system!");
}