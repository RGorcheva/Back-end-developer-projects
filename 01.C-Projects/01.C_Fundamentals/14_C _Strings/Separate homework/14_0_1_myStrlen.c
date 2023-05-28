/*
Напишете собствена версия на стандартната функция strlen от string.h
my_strlen 
която връща стойност от тип size_t - дължината подадения й стринг, без да 
брои терминиращия символ.
Тествайте с литерала и с null-терминиран масив от char
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	size_t sizeArr = 0;
	size_t sizeStr = 0;
	const char arr[] = "Hallo!";
	sizeArr = string_strlen(arr);
	sizeStr = string_strlen("Hallo!");

	printf("Arrsize = %d", (int)sizeArr);
	printf("\nStrsize = %d", (int)sizeStr);
	return 0;
}