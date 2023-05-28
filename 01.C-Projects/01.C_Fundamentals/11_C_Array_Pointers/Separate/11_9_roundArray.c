/*
Напишете програма, която да завърти даден масив от цели числа с
N позиции наляво. Масива и числото N трябва да бъдат въведени
от клавиатурата. Принтирайте оригиналния и резултатния масиви.
*/

#include "../11/functions_array.h"
#include <stdio.h>

int main()
{
	int iArr[10] = { 0 };
	int reverseArr[10] = { 0 };
	int sizeArr = (int)sizeof(iArr) / sizeof(int);
	int iNumber = -1;

	enterArr("iArr", iArr, sizeArr);

	printf("\nEnter a number:");
	scanf_s("%d", &iNumber);

	for (int i = 0; i < sizeArr - iNumber; ++i)
	{
			reverseArr[i] = iArr[iNumber + i];
	}
	int j = 0;
	for (int i = sizeArr - iNumber; i < sizeArr; ++i, ++j)
	{
		reverseArr[i] = iArr[j];
	}
	
	printArr("iArr", iArr, sizeArr);
	printArr("reverseArr", reverseArr, sizeArr);
	return 0;
}