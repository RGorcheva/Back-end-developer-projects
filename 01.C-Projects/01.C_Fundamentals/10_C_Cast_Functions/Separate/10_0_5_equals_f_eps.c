/*
Декларирайте и дефинирайте функция 
int equals_f_eps(float, float, float epsilon), 
която да приема трети аргумент, който да дава възможност на клиента на функцията да 
задава интервала за допустима грешка.
Променете equals_f така че да работи с помощта на equals_f_eps
*/

#include <stdio.h>

#define CONST_EPSILON (0.0001f)

float myMath_fabs(float b);
int myMath_fequals(float a, float b);
int equals_f_eps(float a, float b, float eps);
 
int main(void)
{
	float A = -1.0f;
	float B = -1.0f;
	float eps = -1.0f;

	printf("\nEntr a number: ");
	scanf("%f", &A);
	printf("\nEntr a number: ");
	scanf("%f", &B);
	printf("Enter epsilon: ");
	scanf("%f", &eps);

	myMath_fequals(A, B) ? printf("\nEps = %f : Equals!", CONST_EPSILON) : printf("\nEps = %f : Not equals!", CONST_EPSILON);
	equals_f_eps(A, B, eps) ? printf("\nEps = %f : Equals!", eps) : printf("\nEps = %f : Not equals!", eps);

	return 0;
}

float myMath_fabs(float b)
{
	return b < 0 ? -b : b;
}

int myMath_fequals(float a, float b)
{
	return  equals_f_eps(a, b, CONST_EPSILON);
}

int equals_f_eps(float a, float b, float eps)
{
	return eps >= myMath_fabs(a-b);
}

