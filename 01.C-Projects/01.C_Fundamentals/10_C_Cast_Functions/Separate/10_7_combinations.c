/*
Използвайте factorial функцията за да пресметнете шанса да спечелите 6 от 49, по формулата за
комбинация (всяка топка има уникален номер и поредността на теглене няма значение):
*/

#include <stdio.h>
#include "../myMath_h/myMath.h"

int main()
{
	int allObjects = 49;
	int ChoosenObjects = 6;
	unsigned long long NumberCombinations = 0llu;
	int sum = 1; 

	for (int i = 1; i <= ChoosenObjects; i++)
	{
		sum *= allObjects - ChoosenObjects + i;
	}

	NumberCombinations = sum / (myMath_factorial(ChoosenObjects));
	printf("\nNumber of combinations to win 6/49 is %llu", NumberCombinations);
	return 0;
}