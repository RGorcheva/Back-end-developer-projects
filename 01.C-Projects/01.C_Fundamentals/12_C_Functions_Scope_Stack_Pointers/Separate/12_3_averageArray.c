/*
Напишете функция, която изчислява средното аритметично на
елементите на масив от int.
*/

#include "functions_array.h"

int main()
{
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	double dAverage = 0;

	io_arrEnter("iArr", iArr, size);
	dAverage = array_averageElements(iArr, size);
	printf("\nAverage of elements of array is %.2lf", dAverage);
	return 0;
}
