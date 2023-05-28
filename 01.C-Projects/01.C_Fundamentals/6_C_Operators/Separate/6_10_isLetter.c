/*
 Напишете функция int isLetter(char c), която проверява дали
подадения параметър е буква или не е буква от ASCII таблицата.
*/

#include <stdio.h>

int isLetter(char c)
{
	if ((c >='a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char c = "0";

	printf("c = ");
	scanf(" %c", &c);

	if (isLetter(c) == 1)
	{
		printf("Letter");
	}
	else
	{
		printf("Is not letter");
	}

	return 0;
}

