/*
Напишете собствена версия на стандартната функция strcat от string.h със
същия интерфейс и функционалност.
char *strcat( char *dest, const char *src );
Слепва два низа и връща поинтер към първия елемент от първия низ.
*/

#include "../Library/stringFunctions.h"
#include <string.h>

int main(void)
{
	char strCopyrTo1[256] = "HI, ";
	const char strCopyFrom1[256] = "HI, world!";
	const char* chP1 = 0;

	printf("\nstrCopyrTo: %s", strCopyrTo1);
	printf("\nstrCopyFrom: %s\n", strCopyFrom1);

	chP1 = string_strcat(strCopyrTo1, strCopyFrom1);
	printf("\nstrCopyrTo: %s", strCopyrTo1);
	printf("\nchP = %s", chP1);

	printf("\n------------------");

	char strCopyrTo2[256] = "HI, ";
	const char strCopyFrom2[256] = "HI, world!";
	const char* chP2 = 0;

	chP2 = strcat(strCopyrTo2, strCopyFrom2);
	printf("\nstrCopyrTo: %s", strCopyrTo2);
	printf("\nchP = %s", chP2);
	return 0;
}