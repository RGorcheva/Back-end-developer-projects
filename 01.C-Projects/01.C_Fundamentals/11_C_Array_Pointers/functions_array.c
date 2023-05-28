#include "functions_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	enterArr(char* arrName, int* arr, int sizeArr)
{
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		printf("%s[%d]=", arrName, (int)(i - arr));
		scanf_s("\n%d", i);
	}
	printf("\n");
}
void	printArr(char* arrName, int* arr, int sizeArr)
{
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		printf("%s[%d]=%d\n", arrName, (int)(i - arr), *i);
	}
	printf("\n");
}
void	randomFillArr(int* arr, int sizeArr)
{
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		*i = rand();
	}
}
int		maxArr(int* arr, int sizeArr)
{
	int* i = arr;
	int max = *i;
	for (i = arr; i < arr + sizeArr; ++i)
	{
		if (*i >= max)
		{
			max = *i;
		}
	}
	return max;
}
int		minArr(int* arr, int sizeArr)
{
	int* i = arr;
	int min = *i;
	for (i = arr; i < arr + sizeArr; ++i)
	{
		if (*i <= min)
		{
			min = *i;
		}
	}
	return min;
}
void	printBackwardsArr(char* arrName, int* arr, int sizeArr)
{

	for (int* i = arr + sizeArr - 1; i >= arr; --i)
	{
		printf("%s[%d]=%d\n", arrName, (int)(i - arr), (int)*i);
	}
	printf("\n");
}
int		countNumber(int* arr, int sizeArr, int iNumber)
{
	int iCount = 0;
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		if (*i == iNumber)
		{
			++iCount;
		}
	}
	return iCount;
}
void	evenArray(int* arr, int sizeArr, int* evenArr, int sizeEvenArr)
{
	int* j = evenArr;
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		if (*i % 2 == 0)
		{
			*j = *i;
			++j;
		}
	}
}
void	oddArray(int* arr, int sizeArr, int* oddArr, int sizeOddArr)
{
	int* j = oddArr;
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		if (*i % 2 == 1)
		{
			*j = *i;
			++j;
		}
	}
}






