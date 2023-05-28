/*
Към задача 16 да се добави втора функция, която изчислява 
лицето на елипса по зададени два параметъра ( Пи * A * B)
*/

#include <stdio.h>

#define PI_CONST (3.14)

double circleArea(double R)
{
	return R * R * PI_CONST;
}

double ellipseArea(double a, double b)
{
	return a * b * PI_CONST;
}

int main()
{
	double dR = -1.0;
	double dA = -1.0;
	double dB = -1.0;

	dR = 1.0;
	printf("\nScircle (R=1) = %.2lf", circleАrеа(dR));

	dR = 1.5;
	printf("\nScircle (R=1.5) = %.2lf", circleArea(dR));

	dR = 13.0;
	printf("\nScircle (R=13) = %.2lf", circleArea(dR));

	printf("\n A = ");
	scanf("%lf", &dA);
	printf("\n B = ");
	scanf("%lf", &dB);

	printf("\nSellipse (A=%.2lf, B=%.2lf) = %.2lf", dA, dB, ellipseArea(dA, dB));

	return 0;
}