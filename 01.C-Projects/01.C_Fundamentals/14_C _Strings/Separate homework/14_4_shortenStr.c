/*
Напишете функция, която скъсява подадения й стринг до първия whitespace.
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char str[] = "Hello. 123.";
	printf("\n%s", str);
	string_shortenFirstWhitespace(str);
	printf("\n%s", str);
	return 0;
}
