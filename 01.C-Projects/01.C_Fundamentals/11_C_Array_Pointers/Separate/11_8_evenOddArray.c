/*
Напишете програма, която да отделя в два отделни масива четните и
нечетните числа от даден масив с цели числа. Масива да бъде въведен
от клавиатурата. Принтирайте оригиналния и двата резултатни масива.
*/

#include "functions_array.h"

int main(void)
{
	int iArr[10] = { 0 };
	int oddArr[10] = { 0 };
	int evenArr[10] = { 0 };
	int sizeArr = (int)sizeof(iArr) / sizeof(int);

	enterArr("iArr", iArr, sizeArr);

	oddArray(iArr, sizeArr, oddArr, sizeArr);
	evenArray(iArr, sizeArr, evenArr, sizeArr);

	printArr("oddArr", oddArr, sizeArr);
	printArr("evenArr", evenArr, sizeArr);

	return 0;
}



