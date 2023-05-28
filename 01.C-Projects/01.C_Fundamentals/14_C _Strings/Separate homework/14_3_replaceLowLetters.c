/*
Напишете функция calmify_str, която заменя всички малки букви с главни и
всички точки с удивителни в подадения й стринг.
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char str[] = "Hello. 123.";
	printf("\n%s", str);
	string_callmify(str);
	printf("\n%s", str);
	return 0;
}
