/*
Напишете програма, която чете стринг от стандартния вход и го извежда на
стандартния изход с функциите getc и putc.
Moже да ползвате fgetc и fputc, които са почти същите.
Потърсете информация за разликата между различните версии - при
едната двойка не можем да имаме аргументи със странични ефекти. При
кои?
int getc(FILE *stream);
int putc(int char, FILE *stream);
int fgetc(FILE *stream);
int fputc(int char, FILE *stream);
*/

#include <stdio.h>

int main(void)
{
	char ch = 0;
	while ((ch = getc(stdin)) != EOF)
	{
		putc(ch, stdout);
	}
	return 0;
}



