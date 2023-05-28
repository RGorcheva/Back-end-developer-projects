/*
Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на
EOF. След това принтирайте целия текст, но обърнете реда на редовете (най-напред се принтира
последния въведен ред, най-накрая - първият въведен ред)
abc -> def
def    abc
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	const char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	io_strPrintRowsBackwards(buff);
	return 0;
}