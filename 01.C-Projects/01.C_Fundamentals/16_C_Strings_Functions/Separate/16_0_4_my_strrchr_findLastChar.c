/*
Напишете собствена версия на стандартната функция strrchr от string.h,
my_strrchr
която приема стринг и char и връща адреса на последния елемент на стринга,
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
	printf("\n%s", "HI, worldw!");

	const char* myStrrchr_chP = 0;
	myStrrchr_chP = string_strrchrFindLastChar("HI, worldw!", ch);
	printf("\nmyStrrchr_chP = %p", myStrrchr_chP);
	printf("\n%c", *myStrrchr_chP);
	printf("\n------------------");
	const char* originalStrrchr_chP = 0;
	originalStrrchr_chP = strrchr("HI, worldw!", ch);
	printf("\noriginalStrrchr_chP = %p", originalStrrchr_chP);
	printf("\n%c", *originalStrrchr_chP);
	
	return 0;
}
