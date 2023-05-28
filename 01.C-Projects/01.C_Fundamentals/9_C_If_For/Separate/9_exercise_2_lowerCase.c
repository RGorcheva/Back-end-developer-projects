/*
Write a program that creates an array with 26 elements
and stores the 26 lowercase letters in it.
Also have it show the array contents.
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
	char cArr[27];
	int size = 27;
	char ch = '0';
	int i = 0;

	printf("\nEnter a lowercase letters:");
	while (i < size - 1)
	{
		scanf_s(" %c", &ch, 1);
		if ('a' <= ch && ch <= 'z')
		{
			cArr[i] = ch;
			i++;
		}
	}
	cArr[size - 1] = '\0';
	printf("\n%s", cArr);
	setbuf(stdin, NULL);
	return 0;
}