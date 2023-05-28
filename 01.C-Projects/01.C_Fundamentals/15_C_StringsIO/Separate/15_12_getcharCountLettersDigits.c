/* 
Използвайте функцията getchar(), с която въвеждате
текст от клавиатурата, докато не подадете ЕОF.Текстът има
букви и цифри.Пребройте колко са въведените букви и колко са
въведените цифри.Определeте броя на цифрите в стринга, като
използвате оператор continue.
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };
	int countLetters = 0;
	int	countDigits = 0;
	io_strEnterMultilineEOF(buff);
	for (char* p = buff; *p != '\0'; ++p)
	{
		if (isalpha(*p))
		{
			++countLetters;
		}
		if (!isdigit(*p))
		{
			continue;
		}
		else
		{
			++countDigits;
		};
	}
	printf("\nNumber of letters: %d", countLetters);
	printf("\nNumber of digits: %d", countDigits);
	return 0;
}
