#include "../Library/stringFunctions.h"

int main(void)
/*
Напишете собствена версия на стандартната функция strchr от string.h,
my_strchr
която приема стринг и char и връща адреса на първия елемент на стринга,
който е равен на символът, подаден като аргумент. Ако символът не е
намерен, функцията връща нулев указател. Функцията трябва да може да
работи и с ‘\0’ като втори аргумент.
*/
{
	const char str[20] = "HI, world!";
	char ch = 'w';
	const char* chP = 0;
	chP = string_strchrFindFirstChar(str, ch);
	printf("\n%s", str);
	printf("\nch= %c", ch);
	printf("\nstr[4] = %p", &str[4]);
	printf("\nchP = %p", chP);
	return 0;
}