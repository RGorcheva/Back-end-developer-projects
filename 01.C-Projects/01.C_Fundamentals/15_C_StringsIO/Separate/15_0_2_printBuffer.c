/*
Да се въведе multiline стринг от клавиатрата и да се принтира.
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	printf(buff);
	return 0;
}

