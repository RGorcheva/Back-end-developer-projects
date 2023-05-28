/* 13:
Напишете функция, която обръща стойностите на две променливи
от тип int
*/

#include "functions_array.h"

int main()
{
	int a = 5;
	int b = 8;
	printf("\na= %d", a);
	printf("\nb= %d", b);

	swapInt(&a, &b);

	printf("\nAfter swap a= %d", a);
	printf("\nAfter swap b= %d\n", b);
	return 0;
}
