/*
Да се дефинира константата Пи (3.14159...) и да се напише 
функция, която изчислява лицето на окръжност по даден радиус (Пи * R * R). 
В main() да се извика горната функция с радиуси 1, 1.5, 13.
*/

#include <stdio.h>

#define PI_CONST (3.14)

double circleArea(double R)
{
	return R * R * PI_CONST;
}

int main()
{
	double dR = 0.0;

	dR = 1.0;
	printf("\nS (R=1) = %.2lf", circleArea(dR));

	dR = 1.5;
	printf("\nS (R=1.5) = %.2lf", circleArea(dR));

	dR = 13.0;
	printf("\nS (R=13) = %.2lf", circleArea(dR));

	return 0;
}