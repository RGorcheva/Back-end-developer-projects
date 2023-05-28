/*
Добавете следните функции в персоналната си mymath.h бибилиотека:
int fceil(float);
int ffloor(float);
int fround(float);
float fpow(float, int);
първите три трябва да взимат число с плаваща запетая и да го закръглят в int:
● fceil - нагоре (fceil(0.1f) == 1)
● ffloor - надолу (fceil(0.9f) == 1)
● fround - математически (fceil(0.4f) == 0, fceil(0.6f) == 1)
fpow трябва да повдига число с плаваща запетая на степен цяло число.
● бонус : напишете рекурсивна версия на fpow
*/

#include "../myMath_h/myMath.h"

#include <stdio.h>

int main()
{
	float fC = -1.0f;
	int i = -1;

	printf("\nEnter float C: ");
	scanf("%f", &fC);
	printf("\nEnter int i: ");
	scanf(" %d", &i);

	printf("\nRound ceil(%.2f) = %d", fC, myMath_fceil(fC));
	printf("\nRound floor(%.2f) = %d", fC, myMath_ffloor(fC));
	printf("\nRound math(%.2f) = %d", fC, myMath_fround(fC));
	printf("\n%.2f power %d = %.2f", fC, i, myMath_fpow(fC, i));

	return 0;
}