/*
Напишете програма, която чете стринг от стандартния вход и го извежда на
стандартния изход с функциите fprintf и fscanf.
*/

#include <stdio.h>

int main(void)
{
	char str [256] = { 0 };
	while (fscanf(stdin, " %[^\n]s", str) && str[0] != '^Z')
	{
		fprintf(stdout, "%s", str);
		setbuf(stdin, NULL);
		fprintf(stdout, "\n");
	}

	return 0;
}