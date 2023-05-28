#include "datetimeFunc.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const char* FORMAT_PRINT_DATE_1 = "%x\n";
const char* FORMAT_PRINT_DATE_2 = "%d/%m/%y\n";
const char* FORMAT_PRINT_DATE_3 = "%y/%m/%d\n";
const char* FORMAT_PRINT_DATE_4 = "%F\n";
const char* FORMAT_PRINT_DATE_5 = "%d.%m.%y\n";
const char* FORMAT_PRINT_DATE_6 = "%b, %d, %Y\n";
const char* FORMAT_PRINT_DATE_7 = "%d %B %Y\n";

dateTime*	datetime_endDate(dateTime* startDate, int dayCount, dateTime* endDate)
{
	struct tm tm_start = {
		.tm_year = startDate->year - 1900,
		.tm_mon = startDate->month,
		.tm_mday = startDate->day
	};
	struct tm tm_end = {
		.tm_year = startDate->year - 1900,
		.tm_mon = startDate->month,
		.tm_mday = startDate->day + dayCount
	};
	mktime(&tm_end);
	endDate->year = tm_end.tm_year + 1900;
	endDate->month = tm_end.tm_mon;
	endDate->day = tm_end.tm_mday;

	return endDate;
}
int			datetime_countsDaysBetweenDates(dateTime startDate, dateTime endDate)
{
	struct tm tm_start = {
		.tm_year = startDate.year - 1900,
		.tm_mon = startDate.month,
		.tm_mday = startDate.day,
	};
	struct tm tm_end = { .tm_year = endDate.year - 1900,
			  .tm_mon = endDate.month,
			  .tm_mday = endDate.day,
	};
	time_t start = mktime(&tm_start);
	time_t end = mktime(&tm_end);
	double seconds = difftime(end, start);
	int days = (int)seconds/60/60/24;
	return days;
}
const char*	datetime_formatDate(void)
{
	int formatChoice = 0;
	const char* format = NULL;
	printf("\nChoose date format between:");
	printf("\nPress 1: mm/dd/yy");
	printf("\nPress 2: dd/mm/yy");
	printf("\nPress 3: yy/mm/dd");
	printf("\nPress 4: yyyy-mm-dd");
	printf("\nPress 5: dd.mm.yy");
	printf("\nPress 6: Month, dd, yyyy");
	printf("\nPress 7: dd Month yyyy\n");
	do
	{
		scanf_s("%d", &formatChoice);
		switch(formatChoice)
		{
		case 1: format = FORMAT_PRINT_DATE_1; break;
		case 2: format = FORMAT_PRINT_DATE_2; break;
		case 3: format = FORMAT_PRINT_DATE_3; break;
		case 4: format = FORMAT_PRINT_DATE_4; break;
		case 5: format = FORMAT_PRINT_DATE_5; break;
		case 6: format = FORMAT_PRINT_DATE_6; break;
		case 7: format = FORMAT_PRINT_DATE_7; break;
		default: printf("\n wrong choice. Try again!"); break;
		}
	} while ((formatChoice!= 1) && (formatChoice != 2) && (formatChoice != 3) && (formatChoice != 4) && (formatChoice != 5) && (formatChoice != 6) && (formatChoice != 7));
	return format;
}
void		datetime_enterDate(dateTime* date)
{
	printf("\nEnter date in format DD/MM/YYYY:\n");
	unsigned day = 0u;
	unsigned month = 0u;
	unsigned year = 0u;
	scanf_s("%u/%u/%u", &day, &month, &year);
	date->day = day;
	date->month = month;
	date->year = year;
}
void		datetime_printDate(dateTime* date, const char* format)
{
	struct tm tm_date = {
	.tm_year = date->year - 1900,
	.tm_mon = date->month,
	.tm_mday = date->day,
	};
	char str[20];
	strftime(str, sizeof(str), format, &tm_date);
	printf("%s", str);
}
