/*
Дефинирайте макроси MIN, MAX и ABS, които връщат по-малкото и по-голямото от две числа и
абсолютната стойност на число, съответно.
*/

#include <stdio.h>

#define MIN(A,B) (((A)<(B))?(A):(B))
#define MAX(A,B) (((A)>(B))?(A):(B))
#define ABS(A) (((A)<0)?-(A):(A))

int main(void)
{
	int a = 10;
	int b = -5;
	printf("\nMIN(%d, %d) = %d", a, b, MIN(a, b));
	printf("\nMAX(%d, %d) = %d", a, b, MAX(a, b));
	printf("\nABS(%d) = %d", b, ABS(b));
	return 0;
}