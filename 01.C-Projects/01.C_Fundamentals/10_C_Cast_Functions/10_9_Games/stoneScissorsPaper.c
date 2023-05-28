#include "menuGames.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stoneScissorsPaper(void)
{
	srand((int)time(NULL));

	int iGuess = -1;
	int iChoose = -1;
	char cContinue = '0';
	int iCountWins = 0;
	int iCountLosts = 0;

	printf(STR_RULES);
	printf("\nA stone, a scissors or paper is chosen.\nYou choose too.\n");
	printf("\nThe stone breaks the scissors,\nthe scissors cuts the paper\nand the paper cover the stone.\n");

	do
	{
		printf("\nChoose from: \nSTONE - 1\tSCISSORS - 2\tPAPER - 3\n");
		scanf_s("%d", &iChoose);

		iGuess = 1 + (rand() % 3);

		switch (iChoose)
		{
		case 1:
			if (iGuess == 2)
			{
				printf(STR_WIN);
				printf("\nThe stone breaks the scissors!");
				++iCountWins;
			}
			else if (iGuess == 3)
			{
				printf(STR_LOOSE);
				printf("\nThe paper cover the stone!");
				++iCountLosts;
			}
			else
			{
				printf(STR_EQUAL);
				printf("\nWe both choose the stone!");
			}
			break;
		case 2:
			if (iGuess == 3)
			{
				printf(STR_WIN);
				printf("\nThe scissors cuts the paper!");
				++iCountWins;
			}
			else if (iGuess == 1)
			{
				printf(STR_LOOSE);
				printf("\nThe stone breaks the scissors!");
				++iCountLosts;
			}
			else
			{
				printf(STR_EQUAL);
				printf("\nWe both choose the scissos!");
			}
			break;
		case 3:
			if (iGuess == 1)
			{
				printf(STR_WIN);
				printf("\nThe paper cover the stone!");
				++iCountWins;
			}
			else if (iGuess == 2)
			{
				printf(STR_LOOSE);
				printf("\nThe scissors cuts the paper");
				++iCountLosts;
			}
			else
			{
				printf(STR_EQUAL);
				printf("\nWe both choose the paper!");
			}
			break;
		default:
			printf(STR_WRONG);
			break;
		}
			printf("\nDo you want to continue? Y/N");
			scanf_s(" %c", &cContinue, 1);
	} while (cContinue == 'y' || cContinue == 'Y');

	printf("\nYou have %d wins and %d losts!", iCountWins, iCountLosts);
}