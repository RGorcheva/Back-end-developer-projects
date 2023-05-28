/*
напишете функция reverse(s), която обръща символния низ
s. използвайте я, за да напишете програма, която преобръща входа си ред
по ред.
*/

#include "../library/stringfunctions.h"

int main(void)
{
	char row[256] = { 0 };
	while (fgets(row, 256, stdin) != 0 && row[0] != EOF)
	{
		string_reverse(row);
		fputs(row, stdout);
		printf("\n");

	}
	return 0;
}
