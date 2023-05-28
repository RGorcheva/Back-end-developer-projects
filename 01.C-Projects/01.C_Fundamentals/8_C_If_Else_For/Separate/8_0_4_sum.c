/*
Да се изчисли сумата на целите числа в зададен диапазон [a, b] с while.
*/

#include <stdio.h>

int minN(int a1, int b1)
{
	return a1 <= b1 ? a1 : b1;
}

int maxN(int a1, int b1)
{
	return a1 <= b1 ? b1 : a1;
}

int main()
{
	int a = -1;
	int b = -1;
	int x = -1;
	int sum = 0;
	int min = -1;
	int max = -1;

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	min = minN(a, b);
	max = maxN(a, b);

	x = min;
	while (min <= x && x <= max)
	{
		sum += x;
		x++;
	}

	printf("sum [%d;%d] = %d", min, max, sum);
	return 0;
}