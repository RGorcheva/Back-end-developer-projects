/*
За целите на научно изследване търсите хора, които отговарят на следните критерии
Жени на възраст от 25 до 35 години.
Мъже на възраст от 30 до 40 години.
Правите онлайн проучване, в което кандидатите въвеждат данните си и вие трябва да им кажете, дали 
са подходящи или не. Ползвайте променливи за пол и възраст.
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
		if (25 <= iAge && iAge <= 35)
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
		if (30 <= iAge && iAge <= 40)
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