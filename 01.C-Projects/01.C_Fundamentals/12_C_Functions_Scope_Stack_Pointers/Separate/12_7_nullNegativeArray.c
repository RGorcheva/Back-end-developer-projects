/*
Напишете функция, която занулява всички отрицателни стойности
на елементите на масив от цели числа
*/

#include "functions_array.h"

int main(void)
{
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	io_arrEnter("iArr", iArr, size);
	array_nullNegativeElements(iArr, size);
	io_arrPrintSquareScopes("iArr", iArr, size);

	return 0;
}