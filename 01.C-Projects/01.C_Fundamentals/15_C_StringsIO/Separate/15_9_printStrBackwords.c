/*
Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на
EOF. След това принтирайте целия текст, но наобратно.
abc -> fed
def    cba
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	const char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	io_strPrintBackwords(buff);
	return 0;
}
