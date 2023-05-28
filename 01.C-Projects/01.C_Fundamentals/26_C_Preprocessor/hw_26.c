#include "hw_26.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MIN(A,B) (((A)<(B))?(A):(B))
#define MAX(A,B) (((A)>(B))?(A):(B))
#define ABS(A) (((A)<0)?-(A):(A))

#define IS_EVEN(X) ((((X)%2)==0)?(1):(0))
#define IS_ODD(X) ((((X)%2)==1)?(1):(0))

#define IS_IN_RANGE(X,A,B) ((((A)<=(X))&&((X)<=(B)))?1:0)

#define PI 3.14
#define DEG_TO_RAD(A) ((PI*(A))/180)
#define RAD_TO_DEG(B) ((180*(B))/PI)

#define ARRAY_SIZE(ARR) (sizeof(ARR) / sizeof((ARR)[0]))

#define SUM_DIGITS(num,type) {\
	type num2=num;\
	sum = 0;\
	while(num2>0)\
	{\
		sum+=num2%10;\
		num2/=10;\
	}\
}

#define IS_PALINDROME(num,type) {\
	char str[10]={'\0'};\
	_itoa(num,str,10);\
	size_t len=strlen(str);\
	int i=0;\
	int count=0;\
	for(; i<(len/2); i=(i+1))\
	{\
		if(str[i]!=str[len-1-i])\
		{\
			count=(count+1);\
			break;\
		}\
	}\
	if(count == 0)\
	{\
		isPalindrome = 1;\
	}\
	else\
	{\
		isPalindrome = 0;\
	}\
}

#define SWAP(A,B,TYPE) { TYPE TMP; TMP=A; A=B; B=TMP; }

#define SORT(arr,size,type) {\
	int i=0;\
	for(; i<(size-1); i=(i+1))\
	{\
		int min=arr[i];\
		int p=i;\
		for(int j=(i+1); j<size; j=(j+1))\
		{\
			if(min>arr[j])\
			{\
				min=arr[j];\
				p=j;\
			}\
        }\
		arr[p]=arr[i]; arr[i]=min;\
	}\
}

void hw_26_1_minMaxAbs(void)
/*
Дефинирайте макроси MIN, MAX и ABS, които връщат по-малкото и по-голямото от две числа и
абсолютната стойност на число, съответно.
*/
{
	printf("\n-----------------task 26_1-----------------------\n");
	int a = 10;
	int b = -5;
	printf("\nMIN(%d, %d) = %d", a, b, MIN(a, b));
	printf("\nMAX(%d, %d) = %d", a, b, MAX(a, b));
	printf("\nABS(%d) = %d", b, ABS(b));
}
void hw_26_2_isEvenOdd(void)
/*
Дефинирайте макроси IS_EVEN и IS_ODD за проверка на това дали цяло число е четно или
нечетно.
*/
{
	printf("\n-----------------task 26_2-----------------------\n");
	int a = 10;
	int b = 5;
	printf("\nIS_EVEN(%d) = %d", a, IS_EVEN(a + 2));
	printf("\nIS_EVEN(%d) = %d", b, IS_EVEN(b));
	printf("\nIS_ODD(%d) = %d", a, IS_ODD(a + 2));
	printf("\nIS_ODD(%d) = %d", b, IS_ODD(b));
}
void hw_26_3_isInRange(void)
/*
Дефинирайте макроси IS_IN_RANGE, който проверява дали дадено число се намира в даден
интервал.
*/
{
	printf("\n-----------------task 26_3-----------------------\n");
	int a = -2;
	int b = 10;
	int x = 5;
	printf("\nIS_IN_RANGE(%d,%d,%d) = %d", x, a, b, IS_IN_RANGE(x + x, a, b));
}
void hw_26_4_degRad(void)
/*
Дефинирайте макроси DEG_TO_RAD и RAD_TO_DEG за преобразуване на ъгъл от градуси в
радиани и обратно, съответно.
*/
{
	printf("\n-----------------task 26_4-----------------------\n");
	int a = 90;
	double b = 0.5 * PI;
	printf("\nDEG_TO_RAD(%d) = %lf", a, DEG_TO_RAD(a));
	printf("\nRAD_TO_DEG(%lf) = %lf", b, RAD_TO_DEG(b));
}
void hw_26_5_arrSize(void)
/*
Дефинирайте макрос ARRAY_SIZE, който връща броя на елементи на масив
*/
{
	printf("\n-----------------task 26_5-----------------------\n");
	int arr[5] = { 1, 2, 3, 4, 5 };
	printf("\nARRAY_SIZE(arr) = %zu", ARRAY_SIZE(arr));
}
void hw_26_6_sumDigits(void)
/*
Дефинирайте макрос SUM_DIGITS(num, type), който връща сумата от цифрите на цяло число. Вторият
параметър указва типа и е нужен за дефиниция на променлива за сумата. Пример за извикване:
int num1 = 12345;
printf("The sum of the digits of %d is %d\n", num1, SUM_DIGITS(num1, int));
long num2 = 12345L;
printf("The sum of the digits of %ld is %ld\n", num1, SUM_DIGITS(num2, long));
*/
{
	printf("\n-----------------task 26_6-----------------------\n");
	int num = 12345;
	int sum = 0;
	SUM_DIGITS(num, int);
	printf("\nThe sum of the digits of %d is %d", num, sum);

	long int numTwo = 123456L;
	SUM_DIGITS(numTwo, long int);
	printf("\nThe sum of the digits of %ld is %d", numTwo, sum);
}
void hw_26_7_isPalindrome(void)
/*
Дефинирайте макрос IS_PALINDROME(num, type), който проверява дали дадено цяло число е палиндром
(първата цифра е равна на последната, втората - на предпоследната и т.н.)
*/
{
	printf("\n-----------------task 26_7-----------------------\n");
	int a = 12321;
	bool isPalindrome = 0;
	char str[10] = { '\0' };
	IS_PALINDROME(a, int);
	printf("\nIs %d palindrom: %d", a, isPalindrome);
}
void hw_26_8_swap(void)
/*
Дефинирайте макрос SWAP, който сменя стойностите на две променливи
*/
{
	printf("\n-----------------task 26_8-----------------------\n");
	int a = 5;
	int b = 10;
	printf("\na=%d, b=%d", a, b);
	SWAP(a, b, int);
	printf("\na=%d, b=%d", a, b);
}
void hw_26_9_arrSort(void)
/*
Дефинирайте макрос SORT, който сортира масив от целочислени стойности
*/
{
	printf("\n-----------------task 26_9-----------------------\n\n");
	int arr[10] = { 3, 1, 5, 9, 4, 8, 7, 2, 6, 10 };
	int size = 10;
	SORT(arr, size, int);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}