#include "hw_18.h"
#include <stdio.h>
#include "../Library/datetimeFunc.h"
#include <time.h>
#include <stdlib.h>

#define ARR_SIZE_8 8

typedef enum weekDays { Mon, Tu, Wed, Th, Fr, Sat, Sun } weekdays;
typedef enum workDays { Workday, Weekend } workdays;

typedef enum { Cat, Dog, Pig, Horse, Lion, Dove, Human } animalType;
typedef enum { Herbivore, Carnivore, Omnivore } foodType;

typedef struct {
	animalType type;
	foodType eat;
} Animal;
typedef Animal* PtrAnimal;

typedef int arr8_i[ARR_SIZE_8];
typedef arr8_i* arr8_i_ptr;
typedef arr8_i arr2d8_i[ARR_SIZE_8];
typedef arr2d8_i* arr2d8_i_ptr;

enum workDays isWorkingDay(enum weekDays weekday)
{
	if (Mon <= weekday && weekday <= Fr)
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
	case Mon: return p = "Monday";
	case Tu: return p = "Tuesday";
	case Wed: return p = "Wednsday";
	case Th: return p = "Thursday";
	case Fr: return p = "Friday";
	case Sat: return p = "Satyrday";
	case Sun: return p = "Sunday";
	default: return p;
	}
}
void print_animals(PtrAnimal ptrAnimal)
{
	PtrAnimal pt = ptrAnimal;
	for (; pt < ptrAnimal + 7; pt++)
	{
		switch (pt->type)
		{
		case Cat: printf("\nCat"); break;
		case Dog: printf("\nDog"); break;
		case Pig: printf("\nPig"); break;
		case Horse: printf("\nHorse"); break;
		case Lion: printf("\nLion"); break;
		case Dove: printf("\nDove"); break;
		case Human: printf("\nHuman"); break;
		default: break;
		};
		switch (pt->eat)
		{
		case Herbivore: printf("\nHerbivore"); break;
		case Carnivore: printf("\nCarnivore"); break;
		case Omnivore: printf("\nOmnivore"); break;
		default: break;
		};
		printf("\n");
	}
}
void print_arr8_i(arr8_i_ptr pArr, int elementCount)
{
	printf("\n");
	for (int i = 0; i < elementCount; i++)
	{
		printf("%d\t", *(*pArr + i));
	}
	printf("\n\n");
}
void print_arr2d8_i(arr2d8_i_ptr pArr2d, int ROWS, int COLS)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			printf("%d\t", *(*(*pArr2d + row) + col));
		}
		printf("\n");
	}
}

void	hw_18_0_1_printCol(void)
/*
● Дефинирайте масив 3x3 от int.
int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
● Дефинирайте променлива от тип указател към масив с три int елемента:
int(*arrPtr)[3]
● Принтирайте първата колона на масива(първия елемент на всеки ред от масива). За целта
обходете масива с указателя(указател към редове) и адресна ариритметика, без да ползвате
индексиране - [] или целочислени променливи.
*/
{
	printf("\n-----------------task 18_0_1-----------------------");
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int(*arrPtr)[3];
	arrPtr = &(*arr);
	int countElements = (int)sizeof(arr[3]) / (int)sizeof(int);
	for (; arrPtr < &(*arr) + countElements; arrPtr++)
	{
		printf("\n%d", **arrPtr);
	}
}
void	hw_18_0_2_enumWorkDaysWeekend(void)
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
{
	printf("\n-----------------task 18_0_2-----------------------");
	enum weekDays day = 0;
	for (day = Mon; day <= Sun; day++)
	{
		printf("\n%s - %d", nameOfDays(day), isWorkingDay(day));
	}
}
void	hw_18_1_animals(void)
/*
Дефинирайте структура Animal с два member-а: име на вида на животното и това
дали е тревопасно, хищник или всеядно ( Herbivore, Carnivore, Omnivore
съответно ). Използвайте enum за класификацията на видовете животни според
вида на храната им.
● Използвайте typedef при дефиницията на структурата и enum-a за да не се
налага да пишем struct или enum всеки път когато декларираме променлива от
тези типове.
● Използвайте typedef за да дадете алтернативно име на тип : указател към Animal
● Напишете функция, която приема масив от Animal и принтира информацията за
всеки елемент от масива. За целта ползвайте “новия тип” от предходната точка.
Дефинирайте и инициализирайте масив от животни, тествайте функцията с
масива
*/
{
	printf("\n-----------------task 18_1-----------------------");
	Animal animals[7] = {
		{
			.type = Cat,
			.eat = Carnivore
		},
		{
			.type = Dog,
			.eat = Carnivore
		},
				{
			.type = Pig,
			.eat = Omnivore
		},
		{
			.type = Horse,
			.eat = Herbivore
		},
				{
			.type = Lion,
			.eat = Carnivore
		},
		{
			.type = Dove,
			.eat = Herbivore
		},
		{
			.type = Human,
			.eat = Omnivore
		}
	};

	PtrAnimal ptrAnimal = animals;
	print_animals(ptrAnimal);
}
void	hw_18_2_typedef(void)
/*
Използвайте typedef за да дефинирате алтернативни имена на следните типове:
● масив с 8 int елемента: arr8_i
● указател към arr8_i: arr8_i_ptr
● масив с 8 елемента от тип arr8_i: arr2d8_i
● указател към arr2d8_i: arr2d8_i_ptr
Използвайте enum константа за размера - 8
Дефинирайте функции за принтиране на arr8_i и на arr2d8_i.
Създайте променливи от четирите типа, като ги инициализирате(при дефиницията).
Инициализирайте arr8_i_ptr и arr2d8_i_ptr променливите с адреси на compound literalи(при дефиницията).
*/
{
	printf("\n-----------------task 18_2-----------------------");
	arr8_i arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
	arr8_i_ptr pArr = &(int[ARR_SIZE_8]) { 0 };
	arr2d8_i arr2d = { { 1, 2, 3, 4, 5, 6, 7, 8 },
					   { 9, 2, 3, 4, 5, 6, 7, 8 },
					   { 10, 3, 3, 4, 5, 6, 7, 8 },
					   { 11, 4, 4, 4, 5, 6, 7, 8 },
					   { 12, 5, 5, 5, 5, 6, 7, 8 },
					   { 13, 6, 6, 6, 6, 6, 7, 8 },
					   { 14, 7, 7, 7, 7, 7, 7, 8 },
					   { 15, 8, 8, 8, 8, 8, 8, 8 }
	};
	arr2d8_i_ptr pArr2d = &(int[ARR_SIZE_8][ARR_SIZE_8]) { 0 };
	pArr = &arr;
	print_arr8_i(pArr, ARR_SIZE_8);
	pArr2d = &arr2d;
	print_arr2d8_i(pArr2d, ARR_SIZE_8, ARR_SIZE_8);
}
void	hw_18_3_enumDayMonth(void)
/*
Дефинирайте enum константи за ден в седмицата и месец в годината (например: enum
weekday, enum month, E_Weekday, E_Month, ..).
Дефинирайте алтернативно име на типовете с typedef, така че да не се налага да
ползваме ключовата дума enum при дефиниция на променливи от типовете.
*/
{
	printf("\n-----------------task 18_3-----------------------");
	typedef enum weekday {
		Mon,
		Tu,
		Wed,
		Th,
		Fr,
		Sat,
		Sun
	} E_weekday;

	typedef enum month {
		Jan,
		Feb,
		Mar,
		Apr,
		May,
		Jun,
		Jul,
		Aug,
		Sep,
		Oct,
		Nov,
		Dec
	} E_month;
}
void	hw_18_4_structDateTime(void)
/*
Дефинирайте структура, която репрезентира календарна дата (например: struct datetime)
и има членове за:
● Година
● Месец
● Ден от месеца
Нека направим модул за дни и дати за програмата за отдаване на ПС под наем (пример: datetime.h, datetime.c).
За целта, може да ползвате типовете (tm, например) и функциите от <time.h>
*/
{
	printf("\n-----------------task 18_4-----------------------");
	typedef enum weekday {
		Mon, Tu, Wed, Th, Fr, Sat, Sun
	} E_weekday;

	typedef enum month {
		Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
	} E_month;

	struct datetime {
		unsigned year;
		E_month month;
		unsigned day;
	};
}
void	hw_18_5_startDateEndDateDays(void)
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
{
	printf("\n-----------------task 18_5-----------------------");
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
}
void	hw_18_6_formatDate(void)
/*
Дефинирайте функция, която приема datetime обект и указател към стринг, форматира стринга по избран от вас
формат (“Jan 20, 2023”, “20.01.2023”, “1/20/2023”, .. ). За удобство, функцията може да връща указател към
началото на стринга. По желание добавете параметри за избор на форматиране (стринг със спецификатори за
форматиране, или пък дефинирайте enum за конкретни формати за календарна дата или пък дори езици, които
поддържа приложението)
*/
{
	printf("\n-----------------task 18_6-----------------------");
	const char* format = datetime_formatDate();

	dateTime date;
	printf("Enter date:\n");
	datetime_enterDate(&date);

	printf("\nDate: ");
	datetime_printDate(&date, format);
}