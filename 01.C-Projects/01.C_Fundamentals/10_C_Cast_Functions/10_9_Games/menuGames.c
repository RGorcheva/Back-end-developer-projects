#include "menuGames.h"

#include <stdio.h>

int main()
{
	int iChoice = -1;

	printf(STR_WELCOME);
	printf(STR_OPTION_CHOICE);
	printf("\nGuess the number: 1");
	printf("\nHeads and tails: 2");
	printf("\nStone, scissors and paper: 3");

	do
	{
		scanf_s("%d", &iChoice);
		switch (iChoice)
		{
		case 1:
			printf("\nYou've choosen GUESS THE NUMBER!");
			guessTheNumber();
			break;
		case 2:
			printf("\nYou've choosen HEADS AND TAILS!");
			headsAndTails();
			break;
		case 3:
			printf("\nYou've choosen STONE, SCISSORS AND PAPER!");
			stoneScissorsPaper();
			break;
		default:
			printf(STR_WRONG);
			break;
		}
	} while (iChoice < 0 || iChoice > 3);
		return 0;
}
