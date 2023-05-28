/*
Напишете функция, която приема указател към низ и положително цяло число
и скъсява подадения й низ до броя на символите, указани от втория аргумент
shorten_str
Функцията не трябва да води до грешка ако са й подадени невалидни
аргументи, например:
char str[] = “hello”;
shorten_str(str, 10000);
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char str[20] = "HI, world!";
	int pos = 5;
	printf("\n%s", str);
	printf("\n%d", pos);
	string_shortenN(str, pos);
	printf("\n%s", str);
	return 0;
}