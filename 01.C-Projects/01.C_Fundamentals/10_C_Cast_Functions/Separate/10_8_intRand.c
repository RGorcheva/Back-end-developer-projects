/*
Дефинирайте функциите 
int randPositive(int max)
int randRange(int min, int max), 
които връщат произволна стойност в зададен от потребителя на функцията интервал
За целта може да ползвате стандартните функции( от stdlib.h и time.h ):
● rand - за да генерирате произволно число на всяко извикване.
● srand - викнете я веднъж в началото на програмата за да seed-нете random генератора за да може
rand да връща различни числа на всяко различно пускане на програмата
● time - за да можем да seed-ваме с различно число на всяко стартиране на програмата
srand(time(NULL)); // init random number generator
int randomBooleanValue = rand() % 2 == 0; // use % to clamp large value from rand
*/

#include "../Library/myMath.h"
#include <stdio.h>
#include <time.h>
#include <ctype.h>

int main()
{
	int A = -1;
	int B = -1;

	srand(time(NULL));

	printf("\nEntr a number A:");
	scanf_s("%d", &A);
	printf("\nEntr a number B:");
	scanf_s("%d", &B);

	printf("\nRandom number between 0 and %d: %d", A, myMath_randToN(A));
	printf("\nRandom number between %d and %d: %d", A, B, myMath_randRange(A, B));
	return 0;
}
