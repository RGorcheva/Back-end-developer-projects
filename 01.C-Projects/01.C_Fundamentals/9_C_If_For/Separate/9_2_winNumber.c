﻿/*
Създайте програма, която при въвеждане на число от 
конзолата сравнява със зададена от вас константа и изписва 
на конзолата „Печелите!“, ако въведеното число е равно или по 
голямо и „Опитайте отново!“, ако е по-малко. Направете 
примера използвайки единствено конструкцията if.
Какви променливи и от какъв тип ще имам?(2)
Какви са последователните операции, които трябва да изпълня?
Направете примера с конструкцията if-else.
*/

#include <stdio.h>

int main()
{
	const int ciWinNumber = 13;
	int iChooseNumber = -1;

	printf("\nEnter a number: ");
	scanf("%d", &iChooseNumber);

	if (iChooseNumber >= ciWinNumber)
	{
		printf("\nYou winn!!!");
	}
	else
	{
		printf("\nTry again!!!");
	}
	return 0;
}

