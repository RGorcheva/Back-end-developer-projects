/*
Заделете динамично памет за char* buffer с размер size = 2.
Използвайте getchar за въвеждане на текст от стандартния вход до достигане на EOF.
Реалокирайте динамично паметта при нужда (при въвеждане на все по-дълъг текст).
Принтирайте буфера и освободете паметта.
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Library/inputOutputFunc.h"

#define SIZE_2 2

int main(void)
{
	int size = SIZE_2;
	char* buffer = (char*)malloc(sizeof(char)*size);
	if (buffer == NULL)
	{
		printf("\nCannot alocate memory!");
		return -1;
	}
	char ch = '0';
	int i = 0;
	while ((ch = getchar()) != EOF)
	{
		buffer[i++] = ch;
		if (i >= size)
		{
			size = size * 2;
			char* new = (char*)realloc(buffer, sizeof(char)*size);
			if (new == NULL)
			{
				printf("\nCannot alocate memory!");
				return -1;
			}
			buffer = new;
		}
	}
	buffer[i] = '\0';
	printf("\n%s", buffer);
	free(buffer);
	return 0;
}
