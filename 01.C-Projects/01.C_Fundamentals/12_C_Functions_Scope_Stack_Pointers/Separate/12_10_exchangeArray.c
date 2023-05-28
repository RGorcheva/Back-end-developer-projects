/*
Напишете функция, която приема два масива от цели числа с
еднакъв размер и разменя стойностите на елементите им
*/

#include "functions_array.h"

int main(void)
{
	int arr1[10] = { 0 };
	int arr2[10] = { 0 };
	int size = (int)sizeof(arr1) / sizeof(int);
	
	io_arrEnter("arr1", arr1, size);
	io_arrEnter("arr2", arr2, size);
	exchangeArray(arr1, size, arr2);
	io_arrPrintSquareScopes("arr1", arr1, size);
	io_arrPrintSquareScopes("arr2", arr2, size);

	return 0;
}