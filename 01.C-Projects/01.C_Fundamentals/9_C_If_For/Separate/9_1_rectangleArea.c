/*
Създайте програма, която показва на екран 
обиколката и лицето на правоъгълник с височина 12.5 
см и ширина 20.6 см.
*/

#include <stdio.h>

int main()
{
	const float a = 12.5f;
	const float b = 20.5f;
	const float Area = a * b;
	const float Perimeter = 2 * (a + b);

	printf("\nArea = a * b = %.1f * %.1f = %.2f", a, b, Area);
	printf("\nPerimeter = 2 * (a + b) = 2 * (%.1f + %.1f) = %.1f", a, b, Perimeter);

	return 0;
}