#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fPointer = fopen("../data/map.txt", "r");
    char map[4][255][255];
    int q =0, r=0;
    char line[255];
    printf("Map 1\n");
    while(!feof(fPointer)){
        fgets(line, 255, fPointer);
        if(line[0]=='/'){
            q++;
            printf("\nMap %d\n",(q+1));
        }else{
            for(int i = 0; i<255; i++){
                map[q][r][i] = line[i];
            }
            printf("%s\n", map[q][r]);
            r++;
        }
    }

    return 0;
}