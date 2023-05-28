/*
Напишете функция, която копира стойностите на елементите на
един масив в елементите на друг.
*/

#include "functions_array.h"

int main()
{
	int copyFrom[10] = { 0 };
	int copyTo[10] = { 0 };
	int size = (int)sizeof(copyFrom) / sizeof(int);

	io_arrEnter("copyFrom", copyFrom, size);
	copyArray(copyFrom, size, copyTo);

	io_arrPrintName("copyTo", copyTo, size);
	return 0;
}