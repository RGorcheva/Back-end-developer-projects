/*
Прочетете масив от цели числа от клавиатурата. Копирайте въведения 
масив във втори масив, като умножите стойността на всеки елемент по 2. 
Принтирайте двата масива.
*/

#include "functions_array.h"

int main()
{
	int copyFrom[10] = {0};
	int copyTo[10] = {0};
	int size = (int)sizeof(copyFrom)/sizeof(int);
	int iMultiple = 2;

	enterArr("copyFrom", copyFrom, size);
	for (int i = 0; i < size; ++i)
	{
		copyTo[i] = iMultiple * copyFrom[i];
	}
	printArr("copyFrom", copyFrom, size);
	printArr("copyTo", copyTo, size);
	return 0;
}
