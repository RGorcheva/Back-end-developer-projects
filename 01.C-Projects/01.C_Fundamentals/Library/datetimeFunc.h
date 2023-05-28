#ifndef DATETIMEFUNC_H
#define DATETIMEFUNC_H

//typedef enum month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec } E_month;

typedef struct dateTime {
	unsigned year : 11; // 0 <= year <= 2048 (2^11 = 2048)
	unsigned month : 4;  // 0 <= month <= 11 (2^4 = 16)
	unsigned day : 5;  // 0 <= day <= 31 (2^5 = 32)
} dateTime;

dateTime*	datetime_endDate(dateTime* startDate, int dayCount, dateTime* endDate);
int			datetime_countsDaysBetweenDates(dateTime startDate, dateTime endDate);
const char* datetime_formatDate(void);
void		datetime_enterDate(dateTime* date);
void		datetime_printDate(dateTime* date, const char* format);

#endif