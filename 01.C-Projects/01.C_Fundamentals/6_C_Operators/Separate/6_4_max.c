/*
Напишете функция, която връща по-голямото от две числа без да ползвате if-else или if
statements.
*/

#include <stdio.h>

int max(int a, int b)
{
	return  a > b ? a : b;
}

int main()
{
	int x = -1;
	int y = -1;

	printf("x= ");
	scanf("%d", &x);
	printf("y= ");
	scanf("%d", &y);

	printf("\nMax(%d,%d) = %d", x, y, max(x, y));

	return 0;
}
