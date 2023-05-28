/*
Ако имаме символен низ char str[] = “Hеllo”, заменете
буквите l с х на същия символен низ и отпечатайте резултата на
конзолата.
*/

#include <stdio.h>

int main()
{
	char str[] = "Hello";
	int i = 0;
	size_t sizeStr = sizeof(str);

	for (i = 0; i < sizeStr; i++)
	{
		if (str[i] == 'l')
		{
			str[i] = 'x';
		}
	}

	for (i = 0; i < sizeStr; i++)
	{
		printf("%c", str[i]);
	}

	return 0;
}