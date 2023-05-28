/*
Напишете програма, която да брои колко пъти се среща едно число в даден
масив от цели числа. Масивът и числото трябва да бъдат въведени от
клавиатурата. Принтирайте резултатите.
*/

#include "functions_array.h"

int main(void)
{
	int iArr[10];
	int iNumber = -1;
	int iCount = 0;
	int size = (int)sizeof(iArr) / sizeof(int);

	enterArr("iArr", iArr, size);

	printf("\nEnter a number:");
	scanf("%d", &iNumber);

	iCount = countNumber(iArr, size, iNumber);
	printf("\nNumber %d exist in the array %d times!", iNumber, iCount);
	return 0;
}

