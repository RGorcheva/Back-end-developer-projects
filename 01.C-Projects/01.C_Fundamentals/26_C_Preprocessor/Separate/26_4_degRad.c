/*
Дефинирайте макроси DEG_TO_RAD и RAD_TO_DEG за преобразуване на ъгъл от градуси в
радиани и обратно, съответно.
*/

#include <stdio.h>

#define PI 3.14
#define DEG_TO_RAD(A) ((PI*(A))/180)
#define RAD_TO_DEG(B) ((180*(B))/PI)

int main(void)
{
	int a = 90;
	double b = 0.5*PI;
	printf("\nDEG_TO_RAD(%d) = %lf", a, DEG_TO_RAD(a));
	printf("\nRAD_TO_DEG(%lf) = %lf", b, RAD_TO_DEG(b));
	return 0;
}

