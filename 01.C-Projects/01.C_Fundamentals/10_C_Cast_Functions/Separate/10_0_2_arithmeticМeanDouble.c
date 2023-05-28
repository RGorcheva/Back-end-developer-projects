/*
Напишете програма, която пресмята средната аритметична стойност на три променливи, 
които имат следните типове: 
int
unsigned long
float
*/

#include <stdio.h>

int main()
{
	int a = 10;
	unsigned long int b = 12;
	float c = 13.0f;
	double middle = -1.0;

	middle = ((double)a + (double)b + (double)c) / 3.0;
	printf("%.3lf", middle);

	return 0;
}