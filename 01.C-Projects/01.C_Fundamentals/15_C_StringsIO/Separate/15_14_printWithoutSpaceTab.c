/*
Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+Z). Текстът има букви и
цифри. Принтирайте с putchar(). Използвайте условните оператори, за
да премахнете шпациите и табулациите в стринга
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	for (char * p = buff; *p != '\0'; ++p)
	{
		if ((* p == ' ')|| (*p == '\t'))
		{
			continue;
		}
		else
		{
			putchar(*p);
		}	
	}
	return 0;
}