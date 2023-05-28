/*
Дефинирайте макроси IS_EVEN и IS_ODD за проверка на това дали цяло число е четно или
нечетно.
*/

#include <stdio.h>

#define IS_EVEN(X) ((((X)%2)==0)?(1):(0))
#define IS_ODD(X) ((((X)%2)==1)?(1):(0))

int main(void)
{
	int a = 10;
	int b = 5;
	printf("\nIS_EVEN(%d) = %d", a, IS_EVEN(a+2));
	printf("\nIS_EVEN(%d) = %d", b, IS_EVEN(b));
	printf("\nIS_ODD(%d) = %d", a, IS_ODD(a+2));
	printf("\nIS_ODD(%d) = %d", b, IS_ODD(b));
	return 0;
}
