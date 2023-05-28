/*
Дефинирайте следните функции:
● Функция, която приема като аргументи начален datetime(от предходната задача) и брой дни и връща
datetime, който репрезентира датата след <брой дни> от от началната дата. Ако <брой дни> има
отрицателна стойност, функцията връща датата, която е <-брой дни> преди началната дата (функция за
“събиране” на дата с цяло число за брой дни)
● Функция, която приема като аргументи два datetime обекта и връща разликата в дни от първия аргумент до
втория. Функцията връща отрицателна стойност ако първият аргумент е дата, която е хронологически след
датата от втория аргумент (функция за “изваждане на дата от дата”, която връща разликата в брой дни)
Задачи за самоподготовка
Нека направим модул за дни и дати за програмата за отдаване на ПС под наем (пример: datetime.h, datetime.c).
За целта, може да ползвате функцията strftime от <time.h> или sprintf от <stdio.h>
*/
#include "../Library/datetimeFunc.h"
#include "../Library/stringFunc.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) 
{
	const char* format = datetime_formatDate();

	dateTime startDate;
	printf("Enter start date:\n");
	datetime_enterDate(&startDate);

	printf("Enter number of days:");
	int countDays = 0;
	scanf_s("%d", &countDays);

	dateTime endDate;
	dateTime* end = &endDate;
	end = datetime_endDate(&startDate, countDays, &endDate);

	printf("\nStart date: ");
	datetime_printDate(&startDate, format);
	printf("Days: %d", countDays);
	printf("\nEnd date: ");
	datetime_printDate(&endDate, format);


	//////////////////////////
	
	printf("\n\nEnter start date:\n");
	datetime_enterDate(&startDate);

	printf("Enter end date:\n");
	datetime_enterDate(&endDate);

	countDays = datetime_countsDaysBetweenDates(startDate, endDate);

	printf("\nStart date: ");
	datetime_printDate(&startDate, format);
	printf("End date: ");
	datetime_printDate(&endDate, format);
	printf("Days between dates: %d", countDays);

	return 0;
}
