#include "peta.h"
#include "point.h"
#include "string.h"
#include "stdio.h"
#include "system.h"
#include "lokasi.h"

Peta bacaPeta(){
    int q = 0, r=0;
    char line[255];
    FILE * fPointer = fopen("../data/map.txt","r");
    Peta peta;

    fgets(line, 255, fPointer); 
    int rowCount = convertStringToInt(line); //baca jumlah row pada satu submap
    peta.sizeR = rowCount;
    printf("%d\n", rowCount);
    fgets(line, 255, fPointer); 
    int colCount = convertStringToInt(line); //baca jumlah column pada satu submap
    peta.sizeC = colCount;
    printf("%d\n", colCount);
    fgets(line, 255, fPointer); //menghilangkan slash pertama

    while(!feof(fPointer)){
        fgets(line, 255, fPointer);
        if(line[0]=='/'){   
            q++;
            r=0;
        }else{
            for(int c = 0; c<255; c++){
                if(line[c]=='P'){
                    peta.currentArea = q;
                    peta.coords = MakePOINT(c,r);
                    Elmt(peta.submap[q],r,c) = '-';
                }else{
                    Elmt(peta.submap[q],r,c) = line[c];
                }
            }
            r++;
        }
    }
    return peta;
}

int convertStringToInt(char line[]){ //buat ngubah hasil baca peta(array of char)
    int res =0;
    for( int i = 0; line[i] != '\0' && line[i] >= '0' && line[i] <= '9'; ++i) {
        res = (line[i] - '0') + res*10;
    }
    return res;
    // int res = atoi(line);
    // return res;
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
    char target = Elmt((*peta).submap[currentArea],Y,X);
    boolean bisaGerak = verifyGerak(target);
    if(bisaGerak){
        updatePeta(target, targetPoin, currentArea, peta);
    }else{
        unableMoveMsg();
    }
}

boolean verifyGerak(char target){
    switch(target){
        case '*' :
        case 'W' :
        case 'A' :
            return false;
    }
    return true;
}

void printCurrentArea(Peta *peta){
    printf("Player anda berada pada map ke %d dengan titik ", (*peta).currentArea+1);
    TulisPOINT((*peta).coords);
    printf("\n");
    int area = (*peta).currentArea;
    int rows = (*peta).sizeR;
    // int rows = sizeof((*peta).areas[area]) / sizeof((*peta).areas[area][0]);
    // printf("Jumlah baris : %d\n",rows);
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<(*peta).sizeC; j++){
            if(i==(*peta).coords.Y && j==(*peta).coords.X){
                printf("P");
            }else{
                printf("%c", Elmt((*peta).submap[area],i,j));
            }
        }
        printf("\n");
        // printf("%s", (*peta).areas[area][i]);
    }
    printf("\n");
}

void updatePeta(char target, POINT P, int area, Peta *peta){
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
}

char getCurrentPosition(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X;
    int y = (*peta).coords.Y;
    return Elmt((*peta).submap[area],y,x);
}

char getAtas(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X;
    int y = (*peta).coords.Y-1;
    return Elmt((*peta).submap[area],y,x);
}

char getBawah(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X;
    int y = (*peta).coords.Y+1;
    return Elmt((*peta).submap[area],y,x);
}

char getKiri(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X-1;
    int y = (*peta).coords.Y;
    return Elmt((*peta).submap[area],y,x);
}

void bangunAtas(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X;
    int y = (*peta).coords.Y-1;
    Elmt((*peta).submap[area], y, x) = 'W';
}

void bangunBawah(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X;
    int y = (*peta).coords.Y+1;
    Elmt((*peta).submap[area], y, x) = 'W';
}

void bangunKanan(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X+1;
    int y = (*peta).coords.Y;
    Elmt((*peta).submap[area], y, x) = 'W';
}

void bangunKiri(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X-1;
    int y = (*peta).coords.Y;
    Elmt((*peta).submap[area], y, x) = 'W';
}

char getKanan(Peta * peta){
    int area = (*peta).currentArea;
    int x = (*peta).coords.X+1;
    int y = (*peta).coords.Y;
    return Elmt((*peta).submap[area],y,x);
}

boolean isInOffice(Peta * peta){
    return getCurrentPosition(peta) == 'O';
}

boolean nearA(Peta * peta){
    return (getAtas(peta)=='A' || getBawah(peta)=='A' || getKanan(peta)=='A' || getKiri(peta)=='A');
}

Lokasi checkWahanaSurrounding(Peta * peta){
    POINT targetPoin = (*peta).coords;  
    int y = targetPoin.Y;
    int x = targetPoin.X;
    int currentArea = (*peta).currentArea;
    char current = Elmt((*peta).submap[currentArea], y, x);
    printf("Ini posisi kamu sekarang : %c", current);

    Lokasi res;

    //cek atas
    char target = Elmt((*peta).submap[currentArea], y-1, x);
    if(target=='W'){
        targetPoin.Y -= 1;
        res = CreateLokasi(targetPoin,currentArea);
        return res;
    }
    //cek kanan
    target = Elmt((*peta).submap[currentArea], y, x+1);
    if(target=='W'){
        targetPoin.X += 1;
        res = CreateLokasi(targetPoin,currentArea);
        return res;
    }
    //cek bawah
    target = Elmt((*peta).submap[currentArea], y+1, x);
    if(target=='W'){
        targetPoin.Y += 1;
        res = CreateLokasi(targetPoin,currentArea);
        return res;
    }
    //cek kiri
    target = Elmt((*peta).submap[currentArea], y, x-1);
    if(target=='W'){
        targetPoin.X -= 1;
        res = CreateLokasi(targetPoin,currentArea);
        return res;
    }
    POINT null;
    null.X = -1; null.Y = -1;
    res = CreateLokasi(null,-1);
    return res;
}

void resetPeta(Peta * peta, Lokasi lokasiWahana[]){
    printf("UPDATING PETA....\n");
    //reset W
    for(int i = 0; i<4; i++){
        for(int r = 0; r<(*peta).sizeR; r++){
            for(int c = 0; c<(*peta).sizeC; c++){
                if(Elmt((*peta).submap[i], r, c) == 'W'){
                    Elmt((*peta).submap[i], r, c) = '-';
                }
            }
        }
    }

    //nambahin W
    for(int i = 0; i<8; i++){
        if(lokasiWahana[i].Submap != -1){
            int targetSub = lokasiWahana[i].Submap;
            int X = lokasiWahana[i].Koordinat.X;
            int Y = lokasiWahana[i].Koordinat.Y;
            Elmt((*peta).submap[targetSub], Y, X) = 'W';
        }
    }
}