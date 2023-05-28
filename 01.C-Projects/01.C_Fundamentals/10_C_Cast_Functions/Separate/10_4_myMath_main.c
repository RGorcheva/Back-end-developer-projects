/* 
Направете си собствена бибилиотека mymath.h(или друго име) с често-срещани
помощни математически функции.
Декларирайте функциите от предните задачи в .h файл (не забрявяйте header guards)
Дефинирайте ги в .c файл
Тествайте в отделен .c файл, който include-ва mymath.h и в който има main функция.
Не ползвайте съществуващата math.h библиотека освен за вдъхновение
*/

#include "../myMath_h/myMath.h"

#include <stdio.h>

int main()
{
	double lfA = -1.0;
	double lfB = -1.0;

	printf("\nEnter double A: ");
	scanf(" %lf", &lfA);
	printf("\nEnter double B: ");
	scanf(" %lf", &lfB);

	printf("\nRectangleArea = %.1lf * %.1lf = %.2lf", lfA, lfB, myMath_rectangleArea(lfA, lfB));
	printf("\nTriangleArea = %.1lf * %.1lf /2.0 = %.2lf", lfA, lfB, myMath_triangleArea(lfA, lfB));
	printf("\nRectangleArea = %.1lf * %.1lf * PI = %.2lf", lfA, lfA, myMath_circleArea(lfA));
	printf("\nRectangleArea = %.1lf * %.1lf * PI = %.2lf", lfA, lfB, myMath_ellipseArea(lfA, lfB));
	printf("\nMIN(%.1lf, %.1lf) = %.2lf", lfA, lfB, myMath_minDouble(lfA, lfB));
	printf("\nMAX(%.1lf, %.1lf) = %.2lf", lfA, lfB, myMath_maxDouble(lfA, lfB));
	printf("\nFactoriel(%d) = %d", (int)lfA, myMath_factoriel((int)lfA));

	return 0;
}