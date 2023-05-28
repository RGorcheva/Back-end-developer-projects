/*
Напишете функция, която изчислява произведението на
елементите на масив от int.
*/

#include "functions_array.h"

int main()
{
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	int iProductArray = 0;

	io_arrEnter("iArr", iArr, size);
	iProductArray = multipleArr(iArr, size);
	printf("\nProduct of elements of the array is %d", iProductArray);
	return 0;
}

