/*
Да се разменят стойностите на две променливи чрез указатели.
*/

#include <stdio.h>

int main()
{
	int a = 5;
	int b = 6;
	int c = -1;
	int* pa = &a;
	int* pb = &b;
	*pa = 6;

	c = *pa * *pb;

	printf("\nc = %d * %d = %d", *pa, *pb, c);
	return 0;
}