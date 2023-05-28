/*
Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на
EOF. След това принтирайте целия текст, но обърнете реда на буквите на всеки ред
abc -> cba
def    fed
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	const char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	io_strPrintBackwardsEveryRow(buff);
	return 0;
}

