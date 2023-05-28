/* 14:
Напишете функция, която обръща стойностите на две променливи
от тип int*
*/

#include "functions_array.h"

int main()
{
	int a = 5;
	int b = 6;
	int* pa = &a;
	int* pb = &b;

	printf("\nBefore swap: a=%d, pa=%p", a, pa);
	printf("\nBefore swap: b=%d, pb=%p", b, pb);

	swapPointerInt(&pa, &pb);

	printf("\nAfter swap: a=%d, pa=%p", a, pa);
	printf("\nAfter swap: b=%d, pb=%p", b, pb);
	return 0;
}
