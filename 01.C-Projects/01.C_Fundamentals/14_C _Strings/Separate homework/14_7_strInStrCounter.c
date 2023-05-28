/*
Напишете функция, която приема два стринга и връща число - колко пъти се
среща втория стринг в първия
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	const char strSearchIn[] = "a123.Hello. 123.chdffj123cncgmmh123 h";
	const char strFind[] = "123";
	printf("\n%s", strSearchIn);
	printf("\n%s", strFind);
	printf("\n%d", string_countSubstrings(strSearchIn, strFind));
	return 0;
}

