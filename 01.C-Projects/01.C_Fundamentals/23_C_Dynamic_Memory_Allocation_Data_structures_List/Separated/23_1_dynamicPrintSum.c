/*
Да се направи програма, която заделя динамичен масив с брой елементи зададени от
потребителя. За всеки елемент от масива се очаква потребителят да въведе цяло число и
след това се изчислява сумата на всички елементи от масива.
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
		return;
	}
	int* it = ptr;
	int sum = 0;
	for (; it < ptr + iNumberElements; it++)
	{
		printf("\nEnter number:");
		scanf_s("%d", it);
		sum += *it;
		printf("sum = %d", sum);
	}
	printf("\n");
	io_arrPrintSquareScopes("arr", ptr, iNumberElements);
	free(ptr);
	return 0;
}