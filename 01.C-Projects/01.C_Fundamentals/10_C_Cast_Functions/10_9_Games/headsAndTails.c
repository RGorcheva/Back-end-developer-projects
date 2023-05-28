#include "menuGames.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void headsAndTails(void)
{
	srand((int)time(NULL));

	int iGuess = -1;
	int iChoose = -1;
	char cContinue = '0';
	int iCountWins = 0;
	int iCountLosts = 0;

	printf(STR_RULES);
	printf("\nA Head or Tail is chosen.\nYou have to guess it.\n");

	do
	{
		printf("\nChoose from HEAD - 1 and TAIL - 2\n");
		scanf_s("%d", &iChoose);
		
		iGuess = 1 + (rand() % 2);
	
		if (iChoose == iGuess)
		{
			printf(STR_WIN);
			++iCountWins;
		}
		else
		{
			printf(STR_LOOSE);
			++iCountLosts;
		}

			printf("\nDo you want to continue? Y/N");
			scanf_s(" %c", &cContinue, 1);

	} while (cContinue == 'y' || cContinue == 'Y');
	printf("\nYou have %d wins and %d losts!", iCountWins, iCountLosts);
}