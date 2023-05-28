/*
Напишете функция void replace(char *str, int oldChar, int newChar),
която подменя всяко срещане на даден символ в стринг аргумента
си с с друг
char str[] = "Hello\n";
replace(str, 'e', '3'); // "H3llo\n"
*/

#include <stdio.h>
#include <string.h>

char replace(char arr[], char oldCh, char newCh)
{
	int size = (int)strlen(arr);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == oldCh)
		{
			arr[i] = newCh;
		}
	}
	return *arr;
}

int main()
{
	char str[] = "Hello";
	int sizeStr = (int)strlen(str);

	*str = replace(str, 'e', '3');
	for (int i = 0; i < sizeStr; i++)
	{
		printf("%c", str[i]);
	}
	return 0;
}