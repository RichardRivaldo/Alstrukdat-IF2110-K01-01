#include "peta.h"
#include "point.c"

Peta bacaPeta(){
    FILE * fPointer = fopen("../data/map.txt","r");
    Peta peta;
    int q = 0, r=0;
    char line[255];
    memset(line,0,255); //ngosongin linenya
    // printf("Map 1\n");
    while(!feof(fPointer)){
        fgets(line, 255, fPointer);
        if(line[0]=='/'){
            q++;
            r=0;
            // printf("\nMap %d\n",(q+1));
        }else{
            for(int i = 0; i<255; i++){
                peta.areas[q][r][i] = line[i];
                if(line[i]=='P'){
                    peta.currentArea = q;
                    peta.coords = MakePOINT(i,r);
                }
            }
            // printf("%s\n", peta.areas[q][r]);
            r++;
        }
    }
    return peta;
}

void handleGerak(char opsi, Peta * peta){
    int currentArea = (*peta).currentArea;
    POINT targetPoin = (*peta).coords;
    switch(opsi){
        case 'W' :
            targetPoin.Y -= 1;
            break;
        case 'A':
            targetPoin.X -= 1;
            break;
        case 'S':
            targetPoin.Y += 1;
            break;
        case 'D':
            targetPoin.X += 1;
            break;
    }
    int Y = targetPoin.Y;
    int X = targetPoin.X;
    char target = (*peta).areas[currentArea][Y][X];
    boolean bisaGerak = verifyGerak(target);
    if(bisaGerak){
        printf("Bisa gerak bang!\n");
        updatePeta(target, targetPoin, currentArea, peta);
    }
}

boolean verifyGerak(char target){
    switch(target){
        case '*' :
            printf("Nabrak tembok bang!\n");
            return false;
        case 'W' :
            printf("Nabrak wahana bang!\n");
            return false;
        case 'P' :
            printf("Nabrak P bang!\n");
            return false;
    }
    return true;
}

void printCurrentArea(Peta *peta){
    printf("Player anda berada pada map ke %d dengan titik ", (*peta).currentArea+1);
    TulisPOINT((*peta).coords);
    printf("\n");
    int area = (*peta).currentArea;
    int rows = sizeof((*peta).areas[area]) / sizeof((*peta).areas[area][0]);
    // printf("Jumlah baris : %d\n",rows);
    for(int i = 0; i<rows; i++){
        printf("%s", (*peta).areas[area][i]);
    }
    printf("\n");
}

void removeP(Peta *peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X;
    int y = (*peta).coords.Y;
    printf("MENGHILANGKAN P di %d (%d,%d)\n",area,x,y);
    (*peta).areas[area][y][x] = '-';
}

void addP(Peta *peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X;
    int y = (*peta).coords.Y;
    printf("MENAMBAHKAN P di %d (%d,%d)\n",area,x,y);
    (*peta).areas[area][y][x] = 'P';
}

void updatePeta(char target, POINT P, int area, Peta *peta){
    removeP(peta);
    if(target=='^' || target=='V' || target=='<' || target=='>'){
        printf("PINDAH SUB MAP BANG!\n");
        switch(area){
            case 0: //target hanya bisa V atau >
                if(target == 'V'){
                    area=3;
                    P.Y=1;
                }else if(target=='>'){
                    area=1;
                    P.X=1;
                }
                break;
            case 1: //target hanya bisa < atau V
                if(target == '<'){
                    area=0;
                    P.X=18;
                }else if(target=='V'){
                    area=2;
                    P.Y=1;
                }
                break;
            case 2: //target hanya bisa ^ atau <
                if(target == '^'){
                    area=1;
                    P.Y=8;
                }else if(target=='<'){
                    area=3;
                    P.X=18;
                }
                break;
            case 3: //target hanya bisa ^ atau >
                if(target == '^'){
                    area=0;
                    P.Y=8;
                }else if(target=='>'){
                    area=2;
                    P.X=1;
                }
                break;
        }
    }
    (*peta).currentArea = area;
    (*peta).coords = P;
    addP(peta);
}