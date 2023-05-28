/*
Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+Z). Текстът се принтира с
putchar(), като преобразува главните букви в малки.
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	for (char* p = buff; *p != '\0'; ++p)
	{
		*p = tolower(*p);
		putchar(*p);
	}
	return 0;
}