#include "hw_11.h"
#include <stdio.h>
#include "functions_array.h"
#include <time.h>
#include <stdlib.h>

void swapValue(int* pa, int* pb)
{
	*pa = *pa - *pb;
	*pb = *pa + *pb;
	*pa = *pb - *pa;
}

void hw_11_0_1_arrayFor(void)
/*
Дефинирайте масив от 8 елемента и инициализирайте елементите му на 0.
Обходете масива и променете стойността на всеки втори елемент на 1
00000000 -> 01010101
*/
{
	printf("\n----------------task 11_0_1------------------\n");
	int arr[8] = { 0,0,0,0,0,0,0,0 };
	int i = 0;

	for (i = 1; i < 8; i += 2)
	{
		arr[i] = 1;
	}
	for (i = 0; i < 8; i++)
	{
		printf("%d", arr[i]);
	}
}
void hw_11_0_2_arrayPointers(void)
/*
Дефинирайте масив от 8 елемента и инициализирайте елементите му на 0.
Обходете масива и променете стойността на всеки втори елемент на 1
Ползвайте само указатели, без индексиране с оператор []
00000000 -> 01010101
*/
{
	printf("\n----------------task 11_0_2------------------\n");
	int arr[8] = { 0 };
	int i = 0;
	int* p = arr;

	++p;
	while (p < &arr[7] + 1)
	{
		*p = 1;
		p = p + 2;
	}

	for (p = arr; p <= &arr[7]; p++)
	{
		printf("%d", *p);
	}
}
void hw_11_0_3_dereferencing(void)
/*
Да се разменят стойностите на две променливи чрез указатели.
*/
{
	printf("\n----------------task 11_0_3------------------\n");
	int a = 5;
	int b = 6;
	int c = -1;
	int* pa = &a;
	int* pb = &b;
	*pa = 6;

	c = *pa * *pb;

	printf("\nc = %d * %d = %d", *pa, *pb, c);
}
void hw_11_0_4_swap(void)
/*
Да се напише функция, която разменя стойностите на две променливи.
*/
{
	printf("\n----------------task 11_0_4------------------\n");
	int a = 5;
	int b = 6;
	int* pa = &a;
	int* pb = &b;	

	printf("\na= %d", a);
	printf("\nb= %d", b);

	swapValue(&a, &b);

	printf("\na= %d", a);
	printf("\nb= %d", b);
}
void hw_11_1_copyArray(void)
/*
Прочетете масив от цели числа от клавиатурата. Копирайте въведения
масив във втори масив, като умножите стойността на всеки елемент по 2.
Принтирайте двата масива.
*/
{
	printf("\n----------------task 11_1------------------\n");
	int copyFrom[10] = { 0 };
	int copyTo[10] = { 0 };
	int size = (int)sizeof(copyFrom) / sizeof(int);
	int iMultiple = 2;

	enterArr("copyFrom", copyFrom, size);
	for (int i = 0; i < size; ++i)
	{
		copyTo[i] = iMultiple * copyFrom[i];
	}
	printArr("copyFrom", copyFrom, size);
	printArr("copyTo", copyTo, size);
}
void hw_11_2_randArray(void)
/*
Напишете програма, която запълва масив от 20 елемента с произволно
избрани цели числа. За целта използвайте функцията rand(). Въведете
едно цяло число от клавиатурата. Проверете дали въведеното число от
клавиатурата е намерено в масива. Принтирайте масива и отговора дали
числото е намерено в масива.
*/
{
	printf("\n----------------task 11_2------------------\n");
	int iArr[20] = { 0 };
	int iNumberChoice = -1;
	int k = 0;
	int size = (int)sizeof(iArr) / sizeof(int);

	srand((int)time(NULL));
	randomFillArr(iArr, size);

	printf("\nEnter a number:");
	scanf_s("%d", &iNumberChoice);

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
}
void hw_11_3_maxArray(void)
/*
Напишете програма, която запълва масив от 20 елемента с произволно
избрани стойности. За целта използвайте функцията rand(). Намерете най- голямото число в масива.
Принтирайте намереното число и масива.
*/
{
	printf("\n----------------task 11_3------------------\n");
	int iArr[20] = { 0 };
	int iMax = iArr[0];
	int k = 0;
	int size = (int)sizeof(iArr) / sizeof(int);

	srand((int)time(NULL));

	randomFillArr(iArr, size);
	iMax = maxArr(iArr, size);

	printf("Max element of iArr is %d\n", iMax);
	printArr("iArr", iArr, size);
}
void hw_11_4_mirroredArray(void)
/*
Напишете програма, която приема 10 цели числа от клавиатурата, запазва ги в
масив и ги принтира в обратен ред.
*/
{
	printf("\n----------------task 11_4------------------\n");
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);

	enterArr("iArr", iArr, size);
	printBackwardsArr("iArr", iArr, size);
}
void hw_11_5_uniqueArray(void)
/*
Напишете програма, която принтира уникалните елементи от масив с цели
числа, въведени от клавиатурата.
*/
{
	printf("\n----------------task 11_5------------------\n");
	int iArr[10];
	int iCount = 0;
	int size = (int)sizeof(iArr) / sizeof(int);

	enterArr("iArr", iArr, size);

	int i = 0;
	int j = 0;
	for (i = 0; i < size; ++i)
	{
		iCount = 0;
		for (j = 0; j < size; ++j)
		{
			if (i == j)
			{
				continue;
			}
			if (iArr[i] == iArr[j])
			{
				++iCount;
			}
		}
		if (iCount == 0)
		{
			printf("\nUnique value: iArr[%d]=%d", i, iArr[i]);
		}
	}
}
void hw_11_6_countArray(void)
/*
Напишете програма, която да брои колко пъти се среща едно число в даден
масив от цели числа. Масивът и числото трябва да бъдат въведени от
клавиатурата. Принтирайте резултатите.
*/
{
	printf("\n----------------task 11_6------------------\n");
	int iArr[10];
	int iNumber = -1;
	int iCount = 0;
	int size = (int)sizeof(iArr) / sizeof(int);

	enterArr("iArr", iArr, size);

	printf("\nEnter a number:");
	scanf_s("%d", &iNumber);

	iCount = countNumber(iArr, size, iNumber);
	printf("\nNumber %d exist in the array %d times!", iNumber, iCount);
}
void hw_11_7_minMaxArray(void)
/*
Напишете програма, която да намери максималния и минималния
елемент в масив от цели числа. Масива трябва да бъде въведен от
клавиатурата. Принтирайте целия масив и резултатите.
*/
{
	printf("\n----------------task 11_7------------------\n");
	int iArr[10] = { 0 };
	int sizeArr = (int)sizeof(iArr) / sizeof(int);
	int iMax = iArr[0];
	int iMin = iArr[0];

	enterArr("iArr", iArr, sizeArr);

	iMax = maxArr(iArr, sizeArr);
	iMin = minArr(iArr, sizeArr);

	printf("Min element of iArr is %d\n", iMin);
	printf("Max element of iArr is %d\n", iMax);
	printArr("iArr", iArr, sizeArr);
}
void hw_11_8_evenOddArray(void)
/*
Напишете програма, която да отделя в два отделни масива четните и
нечетните числа от даден масив с цели числа. Масива да бъде въведен
от клавиатурата. Принтирайте оригиналния и двата резултатни масива.
*/
{
	printf("\n----------------task 11_8------------------\n");
	int iArr[10] = { 0 };
	int oddArr[10] = { 0 };
	int evenArr[10] = { 0 };
	int sizeArr = (int)sizeof(iArr) / sizeof(int);

	enterArr("iArr", iArr, sizeArr);

	oddArray(iArr, sizeArr, oddArr, sizeArr);
	evenArray(iArr, sizeArr, evenArr, sizeArr);

	printArr("oddArr", oddArr, sizeArr);
	printArr("evenArr", evenArr, sizeArr);
}
void hw_11_9_roundArray(void)
/*
Напишете програма, която да завърти даден масив от цели числа с
N позиции наляво. Масива и числото N трябва да бъдат въведени
от клавиатурата. Принтирайте оригиналния и резултатния масиви.
*/
{
	printf("\n----------------task 11_9------------------\n");
	int iArr[10] = { 0 };
	int reverseArr[10] = { 0 };
	int sizeArr = (int)sizeof(iArr) / sizeof(int);
	int iNumber = -1;

	enterArr("iArr", iArr, sizeArr);

	printf("\nEnter a number:");
	scanf_s("%d", &iNumber);

	for (int i = 0; i < sizeArr - iNumber; ++i)
	{
		reverseArr[i] = iArr[iNumber + i];
	}
	int j = 0;
	for (int i = sizeArr - iNumber; i < sizeArr; ++i)
	{
		reverseArr[i] = iArr[j];
		++j;
	}

	printArr("iArr", iArr, sizeArr);
	printArr("reverseArr", reverseArr, sizeArr);
}