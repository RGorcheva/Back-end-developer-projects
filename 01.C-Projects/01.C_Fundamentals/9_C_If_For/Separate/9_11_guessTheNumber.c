/*
Игра „Познай числото“
Въведете в програмата си число от 0 до 20, което другите ще трябва да познаят
(константа).
Помолете играещият да направи предположение. Играещият има право на 5
опита.
Програмата трябва да сравни, дали числото е по-голямо или по-малко от
константата и да каже на потребителя.
Играещият да може да въведе само число от 0-20, проверете.
*/

#include <stdio.h>

int main()
{
	const int ciNumberToGuess = -1;
	int iChoosenNumber = -1;
	int i = 1;

	do
	{
		printf("\nEnter number to guess from 1 to 20:");
		scanf("%d", &ciNumberToGuess);
	} while (ciNumberToGuess < 1 || 20 < ciNumberToGuess);

	while (i<=5)
	{
		i++;
		printf("Guess the number:");
		scanf("%d", &iChoosenNumber);

		if (iChoosenNumber == ciNumberToGuess)
		{
			printf("You win!!! The number is %d!", ciNumberToGuess);
			break;
		}
		else if (iChoosenNumber < ciNumberToGuess)
		{
			printf("Number to guess is bigger than yours!\n");
		}
		else 
		{
			printf("Number to guess is smaller than yours!\n");
		}
		if (i==5 && (iChoosenNumber != ciNumberToGuess))
		{
			printf("\nSorry, you loose!!! The number is %d!", ciNumberToGuess);
			break;
		}
	}
	return 0;
}