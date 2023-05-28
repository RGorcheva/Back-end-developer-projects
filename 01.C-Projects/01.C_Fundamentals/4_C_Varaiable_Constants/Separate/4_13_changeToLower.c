/*
Ако имаме символен низ char str[] = “HELLO”, заменете
всичките символи с главна буква със съответните символи с малка
буква.
*/

#include <stdio.h>

int main()
{
	char str[] = "HELLO";
	int i = 0;
	size_t sizeStr = sizeof(str);

	for (i = 0; i < (sizeStr-1); i++)
	{
		str[i] = str[i] + 32;
	}

	for (i = 0; i < sizeStr; i++)
	{
		printf("%c", str[i]);
	}

	return 0;
}