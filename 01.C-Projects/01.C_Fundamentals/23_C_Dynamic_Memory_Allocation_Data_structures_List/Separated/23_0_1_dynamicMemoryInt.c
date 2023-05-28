/*
Напишете програма, която иска от потребителя да въведе брой на елементите
на колекция от цели числа (int).
Заделете динамично точно толкова памет, колкото трябва за да се поберат
въведения брой цели числа. Използвайте malloc.
Напишете цикъл, в който искаме от потребителя да въведе стойност за всяко
число.
Използвайте функция, която принтира масив от int за да принтирате
въведените числа.
Освободете заделената динамична памет с free
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Library/inputOutputFunc.h"

int main(void)
{
	int iNumberElements = 0;
	printf("Enter number of elements:");
	scanf_s("%d", &iNumberElements);
	int* ptr = NULL;
	ptr = (int*)malloc(iNumberElements * sizeof(int));
	if (ptr == NULL)
	{
		printf("\nCannot alocate memory!");
		return -1;
	}
	int* it = ptr;
	for (; it < ptr + iNumberElements; it++)
	{
		printf("Enter number:");
		scanf_s("%d", it);
	}
	io_arrPrintSquareScopes("arr", ptr, iNumberElements);
	free(ptr);
	return 0;
}