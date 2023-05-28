/*
Напишете собствена версия на стандартната функция strncat от string.h със
същия интерфейс и функционалност.
char *strncat( char *dest, const char *src, size_t count );
Залепва n символа от низ в края на дриг низ, връща поинтер към началото на слепения низ.
*/

#include "../Library/stringFunctions.h"
#include <string.h>

int main(void)
{
	char strTo1[256] = "HI, world!";
	const char strFrom1[256] = "HI, world!";
	const char* chP1 = 0;
	printf("\nstrTo: %s", strTo1);
	printf("\nstrFrom: %s", strFrom1);
	chP1 = string_strncat(strTo1, strFrom1, 2);
	printf("\nstrTo: %s", strTo1);
	printf("\nchP1 = %p", chP1);
	printf("\nchP1 = %s", chP1);
	printf("\n------------------");
	char strTo2[256] = "HI, world!";
	const char strFrom2[256] = "HI, world!";
	const char* chP2 = 0;
	printf("\nstrTo: %s", strTo2);
	printf("\nstrFrom: %s", strFrom2);
	chP2 = strncat(strTo2, strFrom2, 2);
	printf("\nstrTo: %s", strTo2);
	printf("\nchP2 = %p", chP2);
	printf("\nchP2 = %s", chP2);
	return 0;
}