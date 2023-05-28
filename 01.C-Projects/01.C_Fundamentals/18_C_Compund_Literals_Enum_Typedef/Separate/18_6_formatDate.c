/*
Дефинирайте функция, която приема datetime обект и указател към стринг, форматира стринга по избран от вас
формат (“Jan 20, 2023”, “20.01.2023”, “1/20/2023”, .. ). За удобство, функцията може да връща указател към
началото на стринга. По желание добавете параметри за избор на форматиране (стринг със спецификатори за
форматиране, или пък дефинирайте enum за конкретни формати за календарна дата или пък дори езици, които
поддържа приложението)
*/

#include "../Library/datetimeFunc.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

	const char* format = datetime_formatDate();

	dateTime date;
	printf("Enter date:\n");
	datetime_enterDate(&date);

	printf("\nDate: ");
	datetime_printDate(&date, format);

	return 0;
}
