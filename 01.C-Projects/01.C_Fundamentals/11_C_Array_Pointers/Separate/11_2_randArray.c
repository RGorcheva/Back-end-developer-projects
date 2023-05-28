/*
Напишете програма, която запълва масив от 20 елемента с произволно
избрани цели числа. За целта използвайте функцията rand(). Въведете
едно цяло число от клавиатурата. Проверете дали въведеното число от
клавиатурата е намерено в масива. Принтирайте масива и отговора дали
числото е намерено в масива.
*/

#include "functions_array.h"

int main()
{
	int iArr[20] = { 0 };
	int iNumberChoice = -1;
	int k = 0;
	int size = int size = (int)sizeof(iArr) / sizeof(int);

	srand(time(NULL));
	randomFillArr(iArr, size);

	printf("\nEnter a number:");
	scanf("%d", &iNumberChoice);

	for (int i = 0; i < size; ++i)
	{
		if (iArr[i] == iNumberChoice)
		{
			k = i;
			printf("Your number is part of the array!!!\n");
			break;
		}
	}
	if (iArr[k] == iNumberChoice)
	{
		printf("Your number is part of the array!!!\n");
	}
	else
	{
		printf("Your number is NOT part of the array!!!\n");
	}
	printArr("iArr", iArr, size);
	return 0;
}