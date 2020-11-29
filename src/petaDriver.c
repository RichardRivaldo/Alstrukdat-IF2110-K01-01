#include "peta.c"
#include "point.c"
#include "matriks.c"
#include "system.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <conio.h>

void main(){
    Peta p = bacaPeta();
    printf("PEMAIN ANDA SEKARANG ADA DI %d\n", p.currentArea);
    // TulisMATRIKS(p.submap[p.currentArea]);
    char input;
    while(input!='Q'){
        printCurrentArea(&p);
        printf("Silahkan mau gerak kemana : WASD,O,Q\n");
        input = _getch();
        // scanf("%c",&input);
        input = toupper(input);
        if(input == 'W' || input =='A' || input=='S' || input=='D'){
            handleGerak(input, &p);
        }
        if(input == 'O'){
            if(isInOffice(&p)){
                printf("ANDA SEDANG ADA DI OFFICE\n");
            }else{
                printf("ANDA TIDAK SEDANG ADA DI OFFICE\n");
            }
        }
    }
    printf("Terima kasih telah menguji coba movement system!");
}