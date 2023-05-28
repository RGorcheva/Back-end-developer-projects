/*
Напишете функцията void toLower(char s[]), която преобразува всички
главни букви в малки.
char str[] = "HEllo, 123\n";
toLower(str);
printf("%s", str); // should print "hello, 123\n"
*/

#include <stdio.h>
#include <stdlib.h>

void toLower(char* s)
{
	int size = (int)strlen(s);
	for (int i = 0; i < size; i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			s[i] += 32;
		}
	}
}

int main()
{
	char str[] = "HEllo, 123\\n";
	printf("%s", str);
	toLower(str);
	printf("\n%s", str);
	return 0;
}