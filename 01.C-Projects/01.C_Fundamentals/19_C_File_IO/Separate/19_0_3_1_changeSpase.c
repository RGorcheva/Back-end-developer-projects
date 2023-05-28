#include <stdio.h>

int main(void)
{
	char ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
		{
			ch = '_';
		}
		putchar(ch);
	}
	return 0;
}