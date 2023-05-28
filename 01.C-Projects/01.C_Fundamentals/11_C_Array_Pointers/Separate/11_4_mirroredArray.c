/*
Напишете програма, която приема 10 цели числа от клавиатурата, запазва ги в
масив и ги принтира в обратен ред.
*/

#include "functions_array.h"

int main()
{
	int iArr[10] = { 0 };
	int size = int size = (int)sizeof(iArr) / sizeof(int);

	enterArr("iArr", iArr, size);
	printBackwardsArr("iArr", iArr, size);
	return 0;
}