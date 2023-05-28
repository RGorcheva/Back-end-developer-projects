/*
Напишете собствена версия на стандартната функция strncpy от string.h със
същия интерфейс и функционалност.
char* strncpy(char* dest, const char* src, size_t count);
Копира n символа от низ в низ.
*/

#include "../Library/stringFunctions.h"
#include <string.h>

int main(void) 
{
	const char strFrom[20] = "abcdefghij";
	char strTo[20] = "klmnopr";

	string_strncopy_terminated(strTo, strFrom, 5);
	puts(strTo);
	printf("------------------\n");
	const char strFrom1[20] = "abcdefghij";
	char strTo1[20] = "klmnopr";

	string_strncopy(strTo1, strFrom1, 5);
	puts(strTo1);
	printf("------------------\n");
	const char strFrom2[20] = "abcdefghij";
	char strTo2[20] = "klmnopr";
	strncpy(strTo2, strFrom2, 5);
	puts(strTo2);

	return 0;
}
