/*
Напишете собствена версия на стандартната функция strchr от string.h,
my_strchr
която приема стринг и char и връща адреса на първия елемент на стринга,
който е равен на символът, подаден като аргумент. Ако символът не е
намерен, функцията връща нулев указател. 
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char ch = 'w';
	printf("\nch= %c", ch);
	printf("\n%s", "HI, world!");

	const char* myStrchr_chP = 0;
	myStrchr_chP = string_strchrFindFirstChar("HI, world!", ch);
	printf("\nmyStrchr_chP = %p", myStrchr_chP);
	printf("\n------------------");
	const char* originalStrchr_chP = 0;
	originalStrchr_chP = strchr("HI, world!", ch);
	printf("\noriginalStrchr_chP = %p", originalStrchr_chP);

	return 0;
}
