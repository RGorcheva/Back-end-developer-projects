/*
Дефинирайте структура, която репрезентира календарна дата (например: struct datetime)
и има членове за:
● Година
● Месец
● Ден от месеца
Нека направим модул за дни и дати за програмата за отдаване на ПС под наем (пример: datetime.h, datetime.c).
За целта, може да ползвате типовете (tm, например) и функциите от <time.h>
*/
typedef enum weekday {
	Mon = 1, Tu, Wed, Th, Fr, Sat, Sun
} E_weekday;

typedef enum month {
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
} E_month;

struct datetime {
	unsigned year;
	E_month month;
	unsigned day;
};