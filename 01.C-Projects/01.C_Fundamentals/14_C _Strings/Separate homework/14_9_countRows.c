/*
Напишете функция, която брои броя на редовете в един multi-line стринг
(стринг, който е на няколко реда)
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char str[] = "Hello. World! 123.\ntsbdbhs jfsdu sdjffis dsij.\nhdfubwu nchdu dhu.\n";
	int countRows = -1;

	printf("\n%s", str);
	countRows = string_countRows(str);
	printf("\nThere are %d lines in the string.", countRows);
	return 0;
}

