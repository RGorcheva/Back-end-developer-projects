/*
Напишете програма, която запълва масив от 20 елемента с произволно
избрани стойности. За целта използвайте функцията rand(). Намерете най- голямото число в масива.
Принтирайте намереното число и масива.
*/

#include "functions_array.h"

int main()
{
	int iArr[20] = { 0 };
	int iMax = iArr[0];
	int k = 0;
	int size = (int)sizeof(iArr) / sizeof(int);

	srand(time(NULL));

	randomFillArr(iArr, size);
	iMax = maxArr(iArr, size);

	printf("Max element of iArr is %d\n", iMax);
	printArr("iArr", iArr, size);
	return 0;
}