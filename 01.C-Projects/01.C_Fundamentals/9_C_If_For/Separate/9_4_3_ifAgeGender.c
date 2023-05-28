/*
Направете го за два диапазона – жени от 25 до 30 включително или от 35 до 40
включително.
Мъже от 30-35 включително или от 40 до 45 г включително.
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
		if ((25 <= iAge && iAge <= 30) || (35 <= iAge && iAge <= 40))
		{
			printf("\nYou are eligible for the study!");
		}
		else
		{
			printf("\nYou are not eligible for the study!");
		}
	}
	if (iGender == 2)
	{
		if ((30 <= iAge && iAge <= 35) || (40 <= iAge && iAge <= 45))
		{
			printf("\nYou are eligible for the study!");
		}
		else
		{
			printf("\nYou are not eligible for the study!");
		}
	}
	return 0;
}