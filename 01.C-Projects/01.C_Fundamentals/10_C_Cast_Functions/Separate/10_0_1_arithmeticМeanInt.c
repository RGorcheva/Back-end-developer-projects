/*
Напишете програма, която пресмята средната аритметична стойност на три променливи от тип int.
*/

#include <stdio.h>

int main()
{
	int a = 10;
	int b = 12;
	int c = 13;
	double middle = -1.0f;

	middle = ((double)a + (double)b + (double)c) / 3.0;
	printf("%.3lf", middle);

	return 0;
}