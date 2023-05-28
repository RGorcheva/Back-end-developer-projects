/*
Напишете функция, която изчислява площта на кръг, на която като
параметър подаваме радиуса и връща площта на кръга.
Използвайте глобална константа pi = 3.14 за да извършите
изчисленията.
Извикайте функцията в main() и покажете резултата.
*/

#include <stdio.h>

#define CONST_PI (3.14)

double myMath_circleArea(double r)
{
	return r * r * CONST_PI;
}

int main(void)
{
	double dRadius = -1.0;
	double dArea = -1.0;

	printf("\nEnter a radius: ");
	scanf_s("%lf", &dRadius);
	dArea = myMath_circleArea(dRadius);
	printf("\n Circle area (R=%.2lf) = %.4lf", dRadius, dArea);
	return 0;
}