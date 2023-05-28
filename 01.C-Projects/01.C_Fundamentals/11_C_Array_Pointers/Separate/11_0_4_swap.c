/*
Да се напише функция, която разменя стойностите на две променливи.
*/

#include <stdio.h>

void swapValue(int* pa, int* pb)
{
	*pa = *pa - *pb;
	*pb = *pa + *pb;
	*pa = *pb - *pa;
}

int main()
{
	int a = 5;
	int b = 6;
	int* pa = &a;
	int* pb = &b;

	swapValue(&a, &b);

	printf("\na= %d", a);
	printf("\nb= %d", b);
	return 0;
}

