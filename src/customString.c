#include "customString.h"
#include "boolean.h"

void MakeEmptyString(int lenMaxString, char input[lenMaxString]){
    // ALGORITMA
    for (int i = 0; i < lenMaxString; i++)
    {
        input[i] = '\0';
    }
}

boolean StringCompare(int panjang, char string1[panjang], char string2[panjang]){
    // ALGORITMA
    for (int i = 0; i < panjang; i++)
    {

    	if (string1[i] == '\0' || string2[i] == '\0')
    	{
    		break;
    	}

        if (string1[i] != string2[i]){

            return false;
        }
    }
    return true;
}

void StringCopy(int panjang,char output[panjang], char input[panjang]){
    // ALGORITMA
    for (int i = 0; i < panjang; i++)
    {
        (output)[i] = input[i];
        if (input[i] == '\0')
        {
        	break;
        }
    }
}