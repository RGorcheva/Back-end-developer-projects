/*
Направете задачата за точна възраст - за жени 25 или 35 години;
За мъже 30 или 40 години.
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
		switch (iAge)
		{
			case 25:
			case 35: 
				printf("\nYou are eligible for the study!"); 
				break; 
			default:
				printf("\nYou are not eligible for the study!"); 
				break; 
		}
	}
	if (iGender == 2)
	{
		switch (iAge)
		{
			case 30:
			case 40: 
				printf("\nYou are eligible for the study!"); 
				break;
			default:
				printf("\nYou are not eligible for the study!");
				break;
		}
	}
	return 0;
}