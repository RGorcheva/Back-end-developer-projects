#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (islower(ch))
		{
			ch = toupper(ch);
		}
		putchar(ch);
	}
	return 0;
}