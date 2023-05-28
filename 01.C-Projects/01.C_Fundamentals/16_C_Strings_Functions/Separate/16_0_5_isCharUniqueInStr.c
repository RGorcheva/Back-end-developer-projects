/*
Напишете функция
is_char_unique_in_str
която приема стринг и char и връща 1 ако символът се среща точно един път
в стринга, 0 ако не се среща или се среща повече от веднъж.
Използвайте my_strchr и my_strrchr от предходните задачи
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	printf("\n%s", "Hallo, world!");
	printf("\nchar = %c", 'l');
	printf("\n%d", string_isCharUniqueInStr("Hallo, world!", 'l'));
	return 0;
}