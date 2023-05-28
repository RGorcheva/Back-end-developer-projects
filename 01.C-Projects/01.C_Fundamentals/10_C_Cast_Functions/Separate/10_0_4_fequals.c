/*
Декларирайте и дефинирайте функция int fequals(float, float), 
която сравнява двата си float аргумента дали са равни с определена точност, зависеща от 
константа, която определя интервала за допустима грешка (разлика в стойностите на аргументите)
const float epsilon = 0.0001f;
Ползвайте my_fabs от предната задача за сравнението.
*/

#include "myMath_h/myMath.h"
#include <stdio.h>

int main(void)
{
	float A = -1.0f;
	float B = -1.0f;
	printf("\nEntr a number: ");
	scanf("%f", &A);
	printf("\nEntr a number: ");
	scanf("%f", &B);
	if (myMath_fequals(A, B))
	{
		printf("\nEquals!");
	}
	else
	{
		printf("\nNot equals!");
	}
	return 0;
}

