/*
Напишете функция, която принтира елементите на масив от int в следния формат:
[0][1][2][-1][1000][30][-70][1]
*/

#include "functions_array.h"

int main()
{
	
	int iArr[8] = { 0, 1, 2, -1, 1000, 30, -70, 1};
	int size = (int)sizeof(iArr) / sizeof(int);
	io_arrPrintSquareScopes("iArr", iArr, size);

	return 0;
}