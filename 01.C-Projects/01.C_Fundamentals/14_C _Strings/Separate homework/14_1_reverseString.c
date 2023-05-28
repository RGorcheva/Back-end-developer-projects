/*
Напишете функция, която обръща c string наобратно, използвайки само
адресна аритметика. Принтирайте оригиналния и обърнатия стринг един под
друг.
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char str[] = "That's what!";
	char rStr[] = "That's what!";
	string_copyBackwards(str, rStr);
	printf("\nstr: %s", str);
	printf("\nReversed str: %s", rStr);
	return 0;
}
