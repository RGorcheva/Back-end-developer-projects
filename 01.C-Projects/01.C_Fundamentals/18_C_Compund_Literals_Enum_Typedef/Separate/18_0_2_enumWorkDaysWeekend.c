/*
● Дефинирайте enum за дните от седмицата
● Дефинирайте enum за почивен и работен ден
● Дефинирайте функция, която приема параметър - ден от седмицата и връща дали е
почивен или не
● Дефинирайте функция, която приема ден от седмицата и връща името му като
указател към стринг литерала. Направете същото и за втория enum
● Напишете програма, която принтира всеки ден от седмицата и това дали е почивен или
не на отделен ред.
*/

#include <stdio.h>

enum weekDays  { Monday, Tuesday, Wednsday, Thursday, Friday, Satyrday, Sunday };
enum workDays { Workday, Weekend };

enum workDays isWorkingDay(enum weekDays weekday)
{
	if (Monday <= weekday && weekday <= Friday)
	{
		return Workday;
	}
	else return Weekend;
}

const char* nameOfDays(enum weekDays weekday)
{
	const char* p = NULL;
	switch (weekday)
	{
	case Monday: return p = "Monday";
	case Tuesday: return p = "Tuesday";
	case Wednsday: return p = "Wednsday";
	case Thursday: return p = "Thursday";
	case Friday: return p = "Friday";
	case Satyrday: return p = "Satyrday";
	case Sunday: return p = "Sunday";
	default: return p;
	}
}

int main(void) 
{
	enum weekDays day = 0;
	for (day = Monday; day <= Sunday; day++)
	{
		printf("\n%s - %d", nameOfDays(day), isWorkingDay(day));
	}
	return 0;
}