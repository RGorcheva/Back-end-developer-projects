/*
Напишете програма на С, която съдържа 2 функции.
1. Първата смята лице на правоъгълен триъгълник.
2. Втората използва лицето на триъгълника, за да сметне лице на
четириъгълник със същите дължини на страните, като раменете на
триъгълника.
Напишете прототипите на функциите най-отгоре, а телата им под мейн
функцията.
*/

#include <stdio.h>

#define CONST_PI (3.14)

double triangleArea(double a, double b);
double rectangularArea(double a, double b);

int main(void)
{
	double dA = -1.0;
	double dB = -1.0;
	double trArea = -1;
	double rectArea = -1;

	printf("\nEnter A: ");
	scanf("%lf", &dA);
	printf("\nEnter B: ");
	scanf("%lf", &dB);

	trArea = triangleArea(dA, dB);
	rectArea = rectangularArea(dA, dB);
	printf("\nTriangle area (A=%.2lf, B=%.2lf) = %.4lf", dA, dB, trArea);
	printf("\nRectangle area (A=%.2lf, B=%.2lf) = %.4lf", dA, dB,rectArea);
	return 0;
}

double triangleArea(double a, double b)
{
	return a * b / 2.0;
}

double rectangularArea(double a, double b)
{
	return 2 * triangleArea(a, b);
}