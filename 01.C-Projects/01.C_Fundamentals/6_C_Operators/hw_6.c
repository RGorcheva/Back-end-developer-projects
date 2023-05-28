#include "hw_6.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <conio.h>

int intMax(int a, int b)
{
	return  a > b ? a : b;
}
int isLetter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
unsigned randNum(unsigned A)
{
	A ^= A << 13;
	printf("\nA = %d", A);
	A ^= A >> 17;
	printf("\nA = %d", A);
	A ^= A << 5;
	printf("\nA = %d", A);
	return A;
}
void print_bin(unsigned n)
{
	unsigned i;
	for (i = 1 << 31; i > 0; i = i >> 1)
		(n & i) ? printf("*") : printf(" ");
	printf("\r");
}

void hw_6_1_bool(void)
/*
Дефинирайте 2 променливи: a и b от тип int и ги инициализирайте.
Запазете в други 2 променливи резултатите от сравненията за
равенство и различие на първите две променливи.
Изведете двата резултата от сравненията на командния ред.
*/
{
	printf("\n----------------task 6_1------------------\n");
	int a = -1;
	int b = -1;
	bool bAnd = 0;
	bool bNot = 0;

	printf("a= ");
	scanf_s("%d", &a);
	printf("b= ");
	scanf_s("%d", &b);

	bAnd = (a == b);
	bNot = (a != b);

	printf("\na and b = %d", bAnd);
	printf("\na not b = %d", bNot);
}
void hw_6_2_priority(void)
/*
Какъв ще бъде резултатът в променливата t:
int x = 10;
int y = 10;
int z = 30;
int t = x==y + (z < y) != 20;
*/
{
	printf("\n----------------task 6_2------------------\n");
	int x = 10;
	int y = 10;
	int z = 30;

	int t = x == y + (z < y) != 20;

	printf("\nt = %d", t);
}
void hw_6_3_incrDecr(void)
{
	printf("\n----------------task 6_3------------------\n");
	int i = 0;
	int j = i++;
	printf("\ni=%d, j=%d", i, j);
	j = ++i;
	printf("\ni=%d, j=%d", i, j);
	j = i--;
	printf("\ni=%d, j=%d", i, j);
}
void hw_6_4_max(void)
/*
Напишете функция, която връща по-голямото от две числа без да ползвате if-else или if
statements.
*/
{
	printf("\n----------------task 6_4------------------\n");	int x = -1;
	int y = -1;

	printf("x= ");
	scanf_s("%d", &x);
	printf("y= ");
	scanf_s("%d", &y);

	printf("\nMax(%d,%d) = %d", x, y, intMax(x, y));
}
void hw_6_10_isLetter(void)/*
 Напишете функция int isLetter(char c), която проверява дали
подадения параметър е буква или не е буква от ASCII таблицата.
*/
{
	printf("\n----------------task 6_10------------------\n");
	char c = '0';

	printf("c = ");
	scanf_s(" %c", &c, 1);

	if (isLetter(c) == 1)
	{
		printf("Letter");
	}
	else
	{
		printf("Is not letter");
	}
}
void hw_6_11_arithmeticOperators(void)
/*
Аритметични оператори
#include <stdio.h>
int main()
{
	int iX = 13;
	int iY = 44;
	int iResult = 0;
	iResult = iX - iY;
	printf("%d - %d = %d \n", iX, iY, iResult);
	iResult = iY / iX;
	printf("%d / %d = %d \n", iY, iX, iResult);
	iResult = iY % iX;
	printf("%d / %d Remainder: %d\n", iY, iX, iResult);
	return 0;
}
homework: examples for '*' и '+', float - използвайте вместо int
*/
{
	printf("\n----------------task 6_11------------------\n");
	int iX = 13;
	int iY = 44;
	int iResult = 0;

	float fX = 13.0f;
	float fY = 44.0f;
	float fResult = 0.0f;

	iResult = iX - iY;
	printf("%d - %d = %d \n", iX, iY, iResult);
	iResult = iY + iX;
	printf("%d + %d = %d\n", iY, iX, iResult);
	iResult = iY * iX;
	printf("%d * %d = %d\n", iY, iX, iResult);
	iResult = iY / iX;
	printf("%d / %d = %d \n", iY, iX, iResult);
	iResult = iY % iX;
	printf("%d / %d Remainder: %d\n", iY, iX, iResult);

	fResult = fX - fY;
	printf("%f - %f = %f \n", fX, fY, fResult);
	fResult = fY + fX;
	printf("%f + %f = %f\n", fY, fX, fResult);
	fResult = fY * fX;
	printf("%f * %f = %f\n", fY, fX, fResult);
	fResult = fY / fX;
	printf("%f / %f = %f \n", fY, fX, fResult);
	fResult = (float)(iY % iX);
	printf("%f / %f Remainder: %f\n", fY, fX, fResult);
}
void hw_6_12_assignmentOperators(void)
/*
# include <stdio.h>
int main() {
int nResult = 13; /* опитайте с други стойности
int nX = 4;
printf("Result = %d\n", nResult);
nResult += nX;
printf("Result += %d -> %d\n", nX, nResult);
nResult = 1;
nResult <<= nX;
printf("Result <<= %d -> %d\n", nX, nResult);
} /* използвайте и други оператори за присвояване
*/
{
	printf("\n----------------task 6_12------------------\n");
	int nResult = 15;
	int nX = 5;

	printf("Result = %d\n", nResult);
	nResult += nX;
	printf("Result += %d -> %d\n", nX, nResult);
	nResult -= nX;
	printf("Result -= %d -> %d\n", nX, nResult);
	nResult *= nX;
	printf("Result *= %d -> %d\n", nX, nResult);
	nResult /= nX;
	printf("Result /= %d -> %d\n", nX, nResult);
	nResult++;
	printf("Result++ = %d\n", nResult);
	++nResult;
	printf("++Result = %d\n", nResult);
	nResult = 1;
	nResult <<= nX;
	printf("Result <<= %d -> %d\n", nX, nResult);
}
void hw_6_13_incrDecr(void)
/*
#include <stdio.h>
int main() {
 int iCounter = 0;
 while( ++ iCounter < 3 ) {
 printf("Counter %d\n", iCounter);
 printf("++ Counter: %d\n", ++ iCounter);
 printf("-- Counter: %d\n", -- iCounter);
 printf("Counter ++: %d\n", iCounter ++);
 printf("Counter --: %d\n", iCounter --);
 }
 return 0;
*/
{
	printf("\n----------------task 6_13------------------\n");
	int iCounter = 0;

	while (++iCounter < 3)
	{
		printf("Counter %d\n", iCounter);
		printf("++Counter: %d\n", ++iCounter);
		printf("--Counter: %d\n", --iCounter);
		printf("Counter++: %d\n", iCounter++);
		printf("Counter--: %d\n", iCounter--);
	}
}
void hw_6_14_relationalOperators(void)
/*
#include <stdio.h>
int main() {
 int nX = 33; /* homework, input with scanf
int nY = 20;
if (nX == nY) {
	printf("%d and %d are equal\n", nX, nY);
}
else {
	printf("%d and %d are not equal\n", nX, nY);
}
if (nX > nY) {
	printf("%d is greater than %d\n", nX, nY);
}
} /* използвайте и останалите оператори за сравнение
*/
{
	printf("\n----------------task 6_14------------------\n");
	int nX = 33;
	int nY = 20;

	printf("Enter x: ");
	scanf_s(" %d", &nX);
	printf("Enter y: ");
	scanf_s(" %d", &nY);

	if (nX == nY)
	{
		printf("%d and %d are equal\n", nX, nY);
	}
	if (nX != nY)
	{
		printf("%d and %d are not equal\n", nX, nY);
	}
	if (nX > nY)
	{
		printf("%d is greater than %d\n", nX, nY);
	}
	if (nX < nY)
	{
		printf("%d is smaller than %d\n", nX, nY);
	}
	if (nX >= nY)
	{
		printf("%d is equal or greater than %d\n", nX, nY);
	}
	if (nX <= nY)
	{
		printf("%d is equal or smaller than %d\n", nX, nY);
	}
}
void hw_6_15_bool(void)
/*
#include <stdio.h>
int main() {
int nA = 40; /* използвайте scanf
int nB = 20;
int nX = 20;
int nY = 30;
if (nA > nB && nA != 0) {
	printf("&& Operator : Both conditions are true\n");
}
if (nX > nY || nY != 20) {
	printf("|| Operator : Only one condition is true\n");
}
if (!(nA > nB && nB != 0)) {
	printf(" ! Operator : Both conditions are true\n");
}
else {
	printf("Both conditions are true.\n");
}
}
опитайте различни комбинации
*/
{
	printf("\n----------------task 6_15------------------\n");
	int nA = 40;
	int nB = 20;
	int nX = 20;
	int nY = 30;

	printf("Enter A: ");
	scanf_s(" %d", &nA);
	printf("Enter B: ");
	scanf_s(" %d", &nB);
	printf("Enter x: ");
	scanf_s(" %d", &nX);
	printf("Enter y: ");
	scanf_s(" %d", &nY);

	if (nA > nB && nA != 0)
	{
		printf("A>B && A!=0 - && Operator : Both conditions are true\n");
	}
	if (nX > nY || nY != 20)
	{
		printf("X>Y || Y!=20 - || Operator : One or both conditions are true\n");
	}
	if (!(nA > nB && nB != 0))
	{
		printf("A>B && B!=0 - ! One or both conditions are false.\n");
	}
	else
	{
		printf("A>B && B!=0 - Both conditions are true.\n");
	}
	if (nX == nY || nY == 10)
	{
		printf("X=Y || Y=10 - || Operator : One or both conditions are true\n");
	}
	if (0 < nA && nA < nB)
	{
		printf("0<A && A<B - && Operator : Both conditions are true\n");
	}
}
void hw_6_16_address(void)
/*
Оператор за вземане на адрес (&) и дереференция (*)
#include <stdio.h>
int main()
{
 int iA = 13;
 int* pValue = NULL; /* pointer to int
pValue = &iA; /* assigning address of iA to the pointer
printf("\nAddress of variable iA is: %p\n", pValue);
printf("\nValue of variable iA is: %d\n", *pValue);
return 0;
}
*/
{
	printf("\n----------------task 6_16------------------\n");
	int iA = 13;
	int* pValue = NULL;
	pValue = &iA;

	printf("\nAddress of variable iA is: %p\n", pValue);
	printf("\nValue of variable iA is: %d\n", *pValue);
}
void hw_6_17_generator(void)
/* Направете генератор на случайни числа по следния алгоритъм (xorshift):
 int A = 1, акумулатор с начална стойност
 При всяко вземане на число от генератора се прави следното:
 (i) A ^= A << 13;
 (ii) A ^= A >> 17;
 (iii) A ^= A << 5;
При всяка итерация изведете числото на екрана.
(Направете вариация с акумулатор long long int)
*/
{
	printf("\n----------------task 6_17------------------\n");
	unsigned B = 1;
	B = randNum(B);
	printf("\nB = %d\n", B);
	B = randNum(B);
	printf("\nB = %d\n", B);
	B = randNum(B);
	printf("\nB = %d", B);
}
void hw_6_18_runningLights(void)
/*
Направете бягаща светлина, като приемете, че всеки бит от
дадена променлива, е свързан с лампа (или светодиод). Когато битът е
нула, лампата не свети, когато е единица свети.
Примерно, ако генерирате последователност:
1, 2, 3, 4, се получава следното:
1 *....................
2 .*...................
4 ..*..................
8 ...*................. ...
За да генерирате закъснение, използвайте следната функция от C runtime:
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
*/
{
	printf("\n----------------task 6_18------------------\n");
	unsigned int uiNumber = 0;
	unsigned int pow2 = 0;

	for (int i = 32; i > 0; --i)
	{
		system("cls");
		uiNumber = (unsigned int)pow(2, i);
		print_bin(uiNumber);
		Sleep(10);
	}
}