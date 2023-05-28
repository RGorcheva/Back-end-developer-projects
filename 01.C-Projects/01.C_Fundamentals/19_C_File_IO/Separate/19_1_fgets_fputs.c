/*
Напишете програма, която чете стринг от стандартния вход и го извежда на
стандартния изход с функциите fgets и fputs.
char *fgets(char *str, int n, FILE *stream);
int fputs(const char *str, FILE *stream)
*/

#include <stdio.h>

int main(void)
{
	char str[256];
	while (fgets(str, 256, stdin) != 0 && str[0] != '\n')
	{
		fputs(str, stdout);
	}
	return 0;
}