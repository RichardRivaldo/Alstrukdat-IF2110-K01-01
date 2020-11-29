#include <stdio.h>
#include "customString.h"
#include "customString.c"
#include "MatriksOfString.h"
#include "MatriksOfString.c"

int main(){
    // KAMUS
    char test1[lengthStr];
    char test2a[lengthStr];
    char test2b[lengthStr];
    char test3[lengthStr];
    char test4[lengthStr];
    // ALGORITMA
    test1[0] = 't';
    test1[1] = 'e';
    test1[2] = 's';
    test1[3] = 't';
    test1[4] = 'i';
    test1[5] = 'n';
    test1[6] = 'g';
    test1[7] = ' ';
    test1[8] = 'p';
    test1[9] = 'u';
    test1[10] = 'r';
    test1[11] = 'p';
    test1[12] = 'o';
    test1[13] = 's';
    test1[14] = 'e';

    test2a[0] = 't';
    test2a[1] = 'e';
    test2a[2] = 's';

    test2b[0] = 't';
    test2b[1] = 'e';
    test2b[2] = 's';
    test2b[3] = 't';

    test4[0] = '1';
    test4[1] = '2';
    test4[2] = '3';
    //test MakeEmptySting
    printf("(MakeEmptyString) %s -> ", test1);
    MakeEmptyString(lengthStr, test1);
    printf("%s\n", test1);

    // test StringCompare
    if (StringCompare(lengthStr, test2a, test2b)){
        printf("(StringCompare) Kedua string sama\n");
    }
    else {
        printf("(StringCompare) Kedua string tidak sama\n");
    }

    // test StringTrueCompare
    if (StringTrueCompare(lengthStr, test2a, test2b)){
        printf("(StringTrueCompare) Kedua string sama\n");
    }
    else {
        printf("(StringTrueCompare) Kedua string tidak sama\n");
    }

    // test StringCopy
    StringCopy(lengthStr,test3, test2a);
    printf("(StringCopy) %s\n", test3);

    // test StringToInt
    printf("(StringToInt) %d", StringToInt(lengthStr,test4));
    return 0;
}