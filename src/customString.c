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

boolean StringTrueCompare(int panjang, char string1[panjang], char string2[panjang])
/* Prekondisi: Panjang melebihi panjang string1 dan string2 sebenarnya, contoh: string1 = 5 huruf, string2 = 19 huruf, panjang bisa 100 huruf*/
/* Compare string, return true jika sama, return false jika tidak*/
/* String di compare seluruhnya, jika bagian depan string sama, maka dianggap sama
    Contoh: StringCompare (100, "run", "runner") akan return false
*/
{
    for (int i = 0; i < panjang; i++)
    {

        if (string1[i] == '\0' && string2[i] == '\0')
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
int StringToInt(int panjang,char input[panjang])
{
    int sum = 0;
    int i;
    for (i = 0; i < panjang; ++i)
    {
        if (input[i] == '\0')
        {
            break;
        }

        else if (input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9' || input[i] == '0')
        {
            sum = sum*10 + (input[i] - '0');
        }
    }
    return sum;
}

void StringConcat(int panjang,char output[panjang], char input1[panjang], char input2[panjang])
{
    int idx = 0;
    for (int i = 0; i < panjang; i++,idx++)
    {
        if (input1[i] == '\0')
        {
            break;
        }
        (output)[i] = input1[i];
    }

    for (int i = 0; i < panjang; ++i,idx++)
    {
        output[idx] = input2[i];
        if (input2[i] == '\0')
        {
            break;
        }
    }
}

void StringCutEnd(int panjang,char output[panjang], char input[panjang])
{
    for (int i = 0; i < panjang; i++)
    {
        (output)[i] = input[i];
        if (input[i+1] == '\0')
        {
            input[i] = '\0';
            break;
        }
    }
}