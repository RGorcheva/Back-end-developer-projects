/*
Декларирайте и дефинирайте функция float my_fabs(float), 
която връща абсолютната стойност (|модул|) от аргумента си - неговата положителна 
стойност ако е отрицателен и оригинална стойност ако е положителен или 0.
*/

#include "myMath_h/myMath.h"
#include <stdio.h>

int main(void)
{
	float a = -1.0f;

	printf("\nEntr a number: ");
	scanf("%f", &a);
	printf("\nModul(%.2f) = %.2f", a, myMath_fabs(a));

	return 0;
}