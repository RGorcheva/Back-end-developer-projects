/*
Напишете фунцкия, която приема стринг и връща указател към началото на 
най-дългата дума, която намери в стринга
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	const char str[] = "The longest word.";
	const char* theLongestWord = '\0';
	printf("\n%s", str);
	theLongestWord = string_searchLongestWordInStr(str);
	//printf("\nThe longest word is %s", theLongestWord);
	printf("\nThe longest word pointer is %p", theLongestWord);
	return 0;
}