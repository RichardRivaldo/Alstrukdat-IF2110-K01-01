/* File : customString.h */
/* Membuat ulagn procedure" dan fungsi" yang ada di string*/

#ifndef customString_H
#define customString_H

#include "boolean.h"

void MakeEmptyString(int lenMaxString, char input[lenMaxString]);
/* Mengisi string dengan null*/

boolean StringCompare(int panjang, char string1[panjang], char string2[panjang]);
/* Prekondisi: Panjang melebihi panjang string1 dan string2 sebenarnya, contoh: string1 = 5 huruf, string2 = 19 huruf, panjang bisa 100 huruf*/
/* Compare string, return true jika sama, return false jika tidak*/
/* String tidak di compare seluruhnya, jika bagian depan string sama, maka dianggap sama
	Contoh: StringCompare (100, "run", "runner") akan return true
*/

void StringCopy(int panjang,char output[panjang], char input[panjang]);
/* Prekondisi: Panjang melebihi panjang input dan output sebenarnya, contoh: input = 5 huruf,panjang bisa 100 huruf*/
/** Copy string *dari input ke output*/
#endif
