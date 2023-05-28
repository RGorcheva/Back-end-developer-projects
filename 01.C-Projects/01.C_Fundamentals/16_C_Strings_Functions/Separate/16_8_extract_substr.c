/*
Напишете функция, която връща подстринг от стринг по подадени индекси за начало
и край
char* extract_substr(const char* str, size_t idx_from, size_t idx_to, char result[])
Копира стринг в стринг от определени начална и крайна позиция.
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	const char strFrom[20] = "Hello, world!";
	char strTo[20] = { 0 };
    int iFrom = 2;
    int iTo = 5;
    puts(strFrom);
    printf("\nbegin pos: %d", iFrom);
    printf("\nend pos: %d", iTo);
    puts("\n");
	puts(string_extractSubstr(strFrom, iFrom, iTo, strTo));
	return 0;
}