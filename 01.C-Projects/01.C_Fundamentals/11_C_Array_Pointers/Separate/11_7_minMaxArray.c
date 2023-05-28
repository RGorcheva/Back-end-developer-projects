/*
Напишете програма, която да намери максималния и минималния
елемент в масив от цели числа. Масива трябва да бъде въведен от
клавиатурата. Принтирайте целия масив и резултатите.
*/

#include "functions_array.h"

int main(void)
{
	int iArr[10] = { 0 };
	int sizeArr = (int)sizeof(iArr) / sizeof(int);
	int iMax = iArr[0];
	int iMin = iArr[0];
	
	enterArr("iArr", iArr, sizeArr);

	iMax = maxArr(iArr, sizeArr);
	iMin = minArr(iArr, sizeArr);

	printf("Min element of iArr is %d\n", iMin);
	printf("Max element of iArr is %d\n", iMax);
	printArr("iArr", iArr, sizeArr);

	return 0;
}
