/*
Напишете функция, която приема стринг и char символ и връща броя на
срещанията на символа в стринга.
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char str[] = "Hello. World! 123.";
	char ch = 'l';
	int countChar = -1;

	printf("\n%s", str);
	countChar = string_countSymbols(str, ch);
	printf("\nSymbol %c exist %d times in string.", ch, countChar);
	return 0;
}