#include <stdio.h>

int main(void)
{
	char ch = 'c';
	putc(ch, stdout);

	ch = 'e';
	putc(ch, stderr);

	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
	return 0;
}