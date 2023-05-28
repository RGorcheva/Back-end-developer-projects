/*
Напишете функция:
void copystr(char *to, char *from),
която копира една последователност от символи в друга.
*/

#include "functions_array.h"

int main(void)
{
	char from[] = "aaaaaa"; 
	io_strPrintInRow(from);
	char to[] = "bbbbbbbbbbbbbbbb";
	io_strPrintInRow(to);

	string_copyStrToStr(from, to);
	io_strPrintInRow(to);
	return 0;
}