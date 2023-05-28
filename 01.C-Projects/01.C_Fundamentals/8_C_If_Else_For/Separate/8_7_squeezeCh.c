/*
Напишете функция void squeeze(char s[], int c), която премахва
символа с от низа s[]
char str[] = "Hello\n";
squeeze(str, 'o'); // "Hell\n"
*/

#include <stdio.h>
#include <string.h>

void squeezeCh(char s[], char Ch);

int main()
{
	char str[] = "Hellllo\\n";
	printf("\n%s", str);

	squeezeCh(str, 'l');

	printf("\n%s", str);
	return 0;
}

void squeezeCh(char s[], char Ch)
{
	int i = 0;
	int j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != Ch)
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
}