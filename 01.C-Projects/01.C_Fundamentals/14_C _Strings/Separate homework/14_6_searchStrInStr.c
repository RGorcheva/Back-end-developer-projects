/*
Напишете функция, която приема два стринга и претърсва за втория в
първия. Ако го намери - връща индекса на символа, от който започва
подстринга в стринга. Ако не го намери, връща: -1
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	const char strSearchIn[] = "a.Hello. 123.";
	const char strFind[] = "123";
	printf("\n%s", strSearchIn);
	printf("\n%s", strFind);
	printf("\n%d", string_searchStrInStr(strSearchIn, strFind));
	return 0;
}

