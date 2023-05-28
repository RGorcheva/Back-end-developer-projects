/*
Напишете функция, която ограничава стойностите на елементите
на масив от цели числа в подаден интервал [min, max]
*/

#include "functions_array.h"
#include "myMath.h"

int main(void)
{
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	int min = -1;
	int max = -1;
	min = io_intEnter("min");
	max = io_intEnter("max");
	array_fillFromConsoleBetweenMinMax(iArr, size, min, max);
	io_arrPrintSquareScopes("iArr", iArr, size);
	return 0;
}