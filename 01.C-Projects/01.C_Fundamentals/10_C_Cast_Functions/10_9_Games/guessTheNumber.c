#include "menuGames.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessTheNumber(void)
{
	srand((int)time(NULL));

	int iNumberToGuess = -1;
	int iChoosenNumber = -1;
	int i = 0;

	iNumberToGuess = 1 + (rand() % 20);

	printf(STR_RULES);
	printf("\nA number from 1 to 20 is chosen.\nYou have to guess it.\nYou are entitled to 5 attempts.\n");

	while (i <= 5)
	{
		++i;
		printf("\nGuess the number:");
		scanf_s("%d", &iChoosenNumber);

		if (iChoosenNumber == iNumberToGuess)
		{
			printf(STR_WIN);
			break;
		}
		else if (iChoosenNumber < iNumberToGuess)
		{
			printf("Number to guess is bigger than yours!\n");
		}
		else
		{
			printf("Number to guess is smaller than yours!\n");
		}
		if (i == 5 && (iChoosenNumber != iNumberToGuess))
		{
			printf(STR_LOOSE);
			printf("\nThe number is %d!", iNumberToGuess);
		}
	}	
	
}