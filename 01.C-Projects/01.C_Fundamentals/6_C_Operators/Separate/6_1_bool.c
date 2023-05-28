/*
Дефинирайте 2 променливи: a и b от тип int и ги инициализирайте.
Запазете в други 2 променливи резултатите от сравненията за
равенство и различие на първите две променливи.
Изведете двата резултата от сравненията на командния ред.
*/

#include <stdio.h>
#include <stdbool.h>


int main()
{
	int a = -1;
	int b = -1;
	bool bAnd = 0;
	bool bNot = 0;

	printf("a= ");
	scanf("%d", &a);
	printf("b= ");
	scanf("%d", &b);

	bAnd = (a == b);
	bNot = (a != b);

	printf("\na and b = %d", bAnd);
	printf("\na not b = %d", bNot);

	return 0;

}
