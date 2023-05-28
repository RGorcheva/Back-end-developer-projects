#include "hw_12.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Library/arrayFunc.h"
#include "../Library/stringFunc.h"
#include "../Library/mathFunc.h"
#include "../Library/inputOutputFunc.h"

void hw_12_1_multipleMinToMax(void)
/* 1:
Напишете функция, която изчислява произведението на всички
цели числа в даден интервал [min, max].
*/
{
	printf("\n----------------task 12_1------------------\n");
	int iMin = 0;
	int iMax = 0;
	int iProduct = 0;

	iMin = io_intEnter("Min");
	iMax = io_intEnter("Max");

	iProduct = math_multipleMinMax(iMin, iMax);

	printf("\nProduct of numbers from %d to %d is  %d", iMin, iMax, iProduct);
}
void hw_12_2_multipleArray(void)
/*
Напишете функция, която изчислява произведението на
елементите на масив от int.
*/
{
	printf("\n----------------task 12_2------------------\n");
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	int iProductArray = 0;

	io_arrEnter("iArr", iArr, size);
	iProductArray = array_multipleElements(iArr, size);
	printf("\nProduct of elements of the array is %d", iProductArray);
}
void hw_12_3_averageArray(void)
/*
Напишете функция, която изчислява средното аритметично на
елементите на масив от int.
*/
{
	printf("\n----------------task 12_3------------------\n");
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	double dAverage = 0;

	io_arrEnter("iArr", iArr, size);
	dAverage = array_averageElements(iArr, size);
	printf("\nAverage of elements of array is %.2lf", dAverage);
}
void hw_12_4_printArray(void)
/*
Напишете функция, която принтира елементите на масив от int в следния формат:
[0][1][2][-1][1000][30][-70][1]
*/
{
	printf("\n----------------task 12_4------------------\n");
	int iArr[8] = { 0, 1, 2, -1, 1000, 30, -70, 1 };
	int size = (int)sizeof(iArr) / sizeof(int);
	io_arrPrintSquareScopes("iArr", iArr, size);
}
void hw_12_5_fillMinMax(void)
/* 5:
Напишете функция, която запълва елементите на масив от цели числа с произволни
числа от подаден интервал [min, max]
*/
{
	printf("\n----------------task 12_5------------------\n");
	srand((int)time(NULL));

	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	int min = -1;
	int max = -1;
	min = io_intEnter("min");
	max = io_intEnter("max");
	array_randomFillBetweenMinMax(iArr, size, min, max);

	io_arrPrintSquareScopes("iArr", iArr, size);
}
void hw_12_6_fillArray(void)
/* 6:
Напишете функция, която запълва масив от цели числа с въведени от потребителя
стойности
● Ползвайте функциите от горните три задачи за тестване с примерни стойности в
тестовите функции
*/
{
	printf("\n----------------task 12_6------------------\n");
	int iArr[8] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	io_arrEnter("iArr", iArr, size);
	io_arrPrintSquareScopes("iArr", iArr, size);
}
void hw_12_7_nullNegativeArray(void)
/*
Напишете функция, която занулява всички отрицателни стойности
на елементите на масив от цели числа
*/
{
	printf("\n----------------task 12_7------------------\n");
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	io_arrEnter("iArr", iArr, size);
	array_nullNegativeElements(iArr, size);
	io_arrPrintSquareScopes("iArr", iArr, size);
}
void hw_12_8_betweenMinMax(void)
/*
Напишете функция, която ограничава стойностите на елементите
на масив от цели числа в подаден интервал [min, max]
*/
{
	printf("\n----------------task 12_8------------------\n");
	int iArr[10] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	int min = -1;
	int max = -1;
	min = io_intEnter("min");
	max = io_intEnter("max");
	array_fillFromConsoleBetweenMinMax(iArr, size, min, max);
	io_arrPrintSquareScopes("iArr", iArr, size);
}
void hw_12_9_copyArray(void)
/*
Напишете функция, която копира стойностите на елементите на
един масив в елементите на друг.
*/
{
	printf("\n----------------task 12_9------------------\n");
	int copyFrom[10] = { 0 };
	int copyTo[10] = { 0 };
	int size = (int)sizeof(copyFrom) / sizeof(int);

	io_arrEnter("copyFrom", copyFrom, size);
	array_copyArrToArr(copyFrom, size, copyTo);

	io_arrPrintName("copyTo", copyTo, size);
}
void hw_12_10_exchangeArray(void)
/*
Напишете функция, която приема два масива от цели числа с
еднакъв размер и разменя стойностите на елементите им
*/
{
	printf("\n----------------task 12_10------------------\n");
	int arr1[10] = { 0 };
	int arr2[10] = { 0 };
	int size = (int)sizeof(arr1) / sizeof(int);

	io_arrEnter("arr1", arr1, size);
	io_arrEnter("arr2", arr2, size);
	array_exchangeTwoArraies(arr1, size, arr2);
	io_arrPrintSquareScopes("arr1", arr1, size);
	io_arrPrintSquareScopes("arr2", arr2, size);
}
void hw_12_11_printString(void)
/* 11
Напишете функция, която печата низ, като принтирате всеки символ
поотделно, използвайки библиотечната функция putchar(c).
void printstr(char *s);
Указателя към началото му е подаден като аргумент на функцията
Не забравяйте, низът винаги завършва с знак за терминираща нула '\0',
затова проверката в цикъла, който принтира всеки символ, трябва да е докато
не се стигне този знак.
*/
{
	printf("\n----------------task 12_11------------------\n");
	io_strPrintInCol("Hello!");
}
void hw_12_12_copyString(void)
/*
Напишете функция:
void copystr(char *to, char *from),
която копира една последователност от символи в друга.
*/
{
	printf("\n----------------task 12_12------------------\n");
	char from[] = "aaaaaa";
	io_strPrintInRow(from);
	char to[] = "bbbbbbbbbbbbbbbb";
	io_strPrintInRow(to);

	string_copyStrToStr(from, to);
	io_strPrintInRow(to);
}
void hw_12_13_swapInt(void)
/* 13:
Напишете функция, която обръща стойностите на две променливи
от тип int
*/
{
	printf("\n----------------task 12_13------------------\n");
	int a = 5;
	int b = 8;
	printf("\na= %d", a);
	printf("\nb= %d", b);

	math_swapInt(&a, &b);

	printf("\nAfter swap a= %d", a);
	printf("\nAfter swap b= %d\n", b);
}
void hw_12_14_swapPointerInt(void)
/* 14:
Напишете функция, която обръща стойностите на две променливи
от тип int*
*/
{
	printf("\n----------------task 12_14------------------\n");
	int a = 5;
	int b = 6;
	int* pa = &a;
	int* pb = &b;

	printf("\nBefore swap: a=%d, pa=%p", a, pa);
	printf("\nBefore swap: b=%d, pb=%p", b, pb);

	math_swapPointerInt(&pa, &pb);

	printf("\nAfter swap: a=%d, pa=%p", a, pa);
	printf("\nAfter swap: b=%d, pb=%p", b, pb);
}