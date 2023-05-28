/*
Напишете собствена версия на стандартната функция strncmp от string.h със
същия интерфейс и функционалност.
int strncmp( const char *lhs, const char *rhs, size_t count );
Сравнява определен брой символи от два низа, връща 0, ако са еднакви, >0 - ако първия е по-голям и <0 - ако втория е по-голям.
*/
#include "../Library/stringFunctions.h"
#include <string.h>

int main(void)
{
	const char str11[256] = "HI, m";
	const char str12[256] = "HI, morning!";
	printf("\nstr1: %s", str11);
	printf("\nstr2: %s", str12);
	printf("\nCompare to position %d - %d", 4, string_strncmp(str11, str12, 4));
	printf("\nCompare to position %d - %d", 5, string_strncmp(str11, str12, 5));
	printf("\nCompare to position %d - %d", 6, string_strncmp(str11, str12, 6));
	printf("\n------------------");
	const char str31[256] = "HI, m";
	const char str32[256] = "HI, morning!";
	printf("\nstr1: %s", str31);
	printf("\nstr2: %s", str32);
	printf("\nCompare to position %d - %d", 4, string_strncmp_includeNULL(str31, str32, 4));
	printf("\nCompare to position %d - %d", 5, string_strncmp_includeNULL(str31, str32, 5));
	printf("\nCompare to position %d - %d", 6, string_strncmp_includeNULL(str31, str32, 6));
	printf("\n------------------");
	const char str21[256] = "HI, m";
	const char str22[256] = "HI, morning!";
	printf("\nstr1: %s", str21);
	printf("\nstr2: %s", str22);
	printf("\nCompare to position %d - %d", 4, strncmp(str21, str22, 4));
	printf("\nCompare to position %d - %d", 5, strncmp(str21, str22, 5));
	printf("\nCompare to position %d - %d", 6, strncmp(str21, str22, 6));
	return 0;
}