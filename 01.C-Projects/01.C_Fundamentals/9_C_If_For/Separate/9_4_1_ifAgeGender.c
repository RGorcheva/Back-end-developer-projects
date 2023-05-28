/*
Използвайте тернарен ( ? : ) оператор за едно от условията.
*/

#include <stdio.h>

int main()
{
	int iGender = -1;
	int iAge = -1;

	printf("\nPlease, enter your gender: \nWoman - 1\nMan - 2");
	scanf("%d", &iGender);

	printf("\nPlease, enter your age: ");
	scanf("%d", &iAge);

	if (iGender == 1)
	{
		(25 <= iAge && iAge <= 35) ? printf("\nYou are eligible for the study!") : printf("\nYou are not eligible for the study!");
	}
	if (iGender == 2)
	{
		(30 <= iAge && iAge <= 40) ? printf("\nYou are eligible for the study!") : printf("\nYou are not eligible for the study!");
	}
	return 0;
}