/*
Дефинирайте макроси IS_IN_RANGE, който проверява дали дадено число се намира в даден
интервал.
*/

#include <stdio.h>

#define IS_IN_RANGE(X,A,B) ((((A)<=(X))&&((X)<=(B)))?1:0)

int main(void)
{
	int a = -2;
	int b = 10;
	int x = 5;
	printf("\nIS_IN_RANGE(%d,%d,%d) = %d", x, a, b, IS_IN_RANGE(x+x, a, b));
	return 0;
}