/*
Напишете собствена версия на стандартната функция strstr от string.h със
същия интерфейс и функционалност.
char *strstr( const char* str, const char* substr );
Връща адреса на първия символ в глсвния стринг, ако е намерил подсстринга или връща 0, ако не го е намерил.
*/
#include "../Library/stringFunctions.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char str11[256] = "HI, world!";
	const char str12[256] = "rl";

	printf("\nstrSearchIn: %s", str11);
	printf("\nstrFind: %s", str12);
	printf("\n%d", string_searchStrInStr(str11, str12));
	printf("\nAdress of position - %p", string_strstr(str11, str12));
	printf("\nAdress of index 6 - %p", &str11[6]);

	printf("\n------------------");

	const char str21[256] = "HI, world!";
	const char str22[256] = "rl";

	printf("\nstrSearchIn: %s", str21);
	printf("\nstrFind: %s", str22);
	printf("\n%d", string_searchStrInStr(str21, str22));
	printf("\nAdress of position - %p", strstr(str21, str22));
	printf("\nAdress of index 6 - %p", &str21[6]);
	return 0;
}