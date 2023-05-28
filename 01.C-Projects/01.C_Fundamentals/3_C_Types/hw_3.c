#include "hw_3.h"
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void print_bin(unsigned n)
{
	unsigned i;
	for (i = 1 << 7; i > 0; i = i >> 1)
		(n & i) ? printf("1") : printf("0");
	printf("\n");
}

int yearDaysCount(int year)
{
	if (year % 4 == 0)
	{
		return 366;
	}
	else
	{
		return 365;
	}
}

void hw_3_1_sizeOfType(void)
/*
Изведете размерите в байтове и битове на основните типове на вашата машина
● char
● int
● short
● long
● long long
● size_t
● float
● double
● bool
*/
{
	printf("\n----------------task 3_1------------------\n");
	int bitsPerByte = CHAR_BIT;
	printf("\nbits per byte %d", bitsPerByte);

	size_t intSizeBytes1 = sizeof(char);
	printf("\nBytes per char: %zu", intSizeBytes1);
	size_t intSizeBits1 = intSizeBytes1 * bitsPerByte;
	printf("\tBits per char: %zu", intSizeBits1);

	size_t intSizeBytes2 = sizeof(int);
	printf("\nBytes per int: %zu", intSizeBytes2);
	size_t intSizeBits2 = intSizeBytes2 * bitsPerByte;
	printf("\tBits per int: %zu", intSizeBits2);

	size_t intSizeBytes3 = sizeof(short int);
	printf("\nBytes per short int: %zu", intSizeBytes3);
	size_t intSizeBits3 = intSizeBytes3 * bitsPerByte;
	printf("\tBits per short int: %zu", intSizeBits3);

	size_t intSizeBytes4 = sizeof(long int);
	printf("\nBytes per long int: %zu", intSizeBytes4);
	size_t intSizeBits4 = intSizeBytes4 * bitsPerByte;
	printf("\tBits per long int: %zu", intSizeBits4);

	size_t intSizeBytes5 = sizeof(long long int);
	printf("\nBytes per long long int: %zu", intSizeBytes5);
	size_t intSizeBits5 = intSizeBytes5 * bitsPerByte;
	printf("\tBits per long long int: %zu", intSizeBits5);

	size_t intSizeBytes6 = sizeof(size_t);
	printf("\nBytes per size_t: %zu", intSizeBytes6);
	size_t intSizeBits6 = intSizeBytes6 * bitsPerByte;
	printf("\tBits per size_t: %zu", intSizeBits6);

	size_t intSizeBytes7 = sizeof(float);
	printf("\nBytes per float: %zu", intSizeBytes7);
	size_t intSizeBits7 = intSizeBytes7 * bitsPerByte;
	printf("\tBits per float: %zu", intSizeBits7);

	size_t intSizeBytes8 = sizeof(double);
	printf("\nBytes per double: %zu", intSizeBytes8);
	size_t intSizeBits8 = intSizeBytes8 * bitsPerByte;
	printf("\tBits per double: %zu", intSizeBits8);

	size_t intSizeBytes9 = sizeof(bool);
	printf("\nBytes per bool: %zu", intSizeBytes9);
	size_t intSizeBits9 = intSizeBytes9 * bitsPerByte;
	printf("\tBits per bool: %zu", intSizeBits9);
}
void hw_3_2_charMax(void)
/*
Използвайте израз който да направи така че unsigned char да прехвърли
максималната си стойност.Изведете резултата преди и след това.
Направете същото със signed char.
*/
{
	printf("\n----------------task 3_2------------------\n");
	printf("%d\n", (unsigned char)UCHAR_MAX);
	printf("%d\n", (unsigned char)(UCHAR_MAX + 1));

	printf("%d\n", (signed char)SCHAR_MAX);
	printf("%d\n", (signed char)(SCHAR_MAX + 1));
}
void hw_3_3_printBin(void)
/*
Променете програмата от задача 2 да използва следната функция за побитово
принтиране(копирайте си я над main функцията):
	void print_bin(unsigned n)
{
	unsigned i;
	for (i = 1 << 7; i > 0; i = i >> 1)
		(n & i) ? printf("1") : printf("0");
	printf("\n");
}
Пробвайте да направите и преливане отдолу на signed char и unsigned char
*/
{
	printf("\n----------------task 3_3------------------\n");
	print_bin(UCHAR_MAX);
	print_bin(UCHAR_MAX + 1);
	print_bin(SCHAR_MAX);
	print_bin(SCHAR_MAX + 1);
}
void hw_3_4_typePrint(void)
/*
Дефинирайте променливи със стойности:
-127,
255,
63 498,
4 294 967 292,
-9 000 000 000 000 775 845.
Изведете всяка променлива на екрана със printf()
*/
{
	printf("\n----------------task 3_4------------------\n");
	char c1 = -127;
	unsigned char c2 = 255;
	int i1 = 63498;
	long long int i2 = 4294967292;
	signed long long int i3 = -9000000000000775845;
	printf("\nchar: %d", c1);
	printf("\nunsigned char: %d", c2);
	printf("\nint: %d", i1);
	printf("\nlong long int: %lli", i2);
	printf("\nsigned long long int: %lli", i3);
}
void hw_3_5_typePrint(void)
/*
Дефинирайте променливи със стойност
24 212,
-1 357 674,
1 357 674,
-1 357 674 000,
3 657 895 000.
Изведете всяка променлива на екрана със printf().
*/
{
	printf("\n----------------task 3_5------------------\n");
	short int i1 = 24212;
	int i2 = -1357674;
	int i3 = 1357674;
	long int i4 = -1357674000;
	long long int i5 = 3657895000;
	printf("\nshort int: %hd", i1);
	printf("\nint: %d", i2);
	printf("\nint: %d", i3);
	printf("\nlong int: %li", i4);
	printf("\nlong long int: %lli", i5);
}
void hw_3_7_typePrint(void)
/*
Дефинирайте променливи със стойност:
4.9876543,
7.123456789012345678890,
18 398 458 438 583 853.28,
18 398 458 438 583 853.39875937284928422.
Изведете всяка променлива на екрана с printf()
*/
{
	printf("\n----------------task 3_7------------------\n");
	double d1 = 4.9876543;
	double d2 = 7.123456789012345678890;
	long double d3 = 18398458438583853.28;
	long double d4 = 18398458438583853.39875937284928422;

	printf("\n%.7lf", d1);
	printf("\n%.21lf", d2);
	printf("\n%.2lf", d3);
	printf("\n%.20lf", d4);
}
void hw_3_8_caravan(void)
/*
Представете си, че имате фирма за отдаване на каравани и кемпери под наем, за
която трябва да разработите софтуер.
Имате общо 3 каравани на цена 90 лв. на ден и 3 кемпера на цена 100 лв. на ден.
Декларирайте променливи за броя на караваните, цената на караваните, броя на
кемперите и цената им.
Направете меню, което пита клиента каравана или кемпер ще иска.
Направете променлива, в която да се събират парите, които клиента дължи на
компанията.
Принтирайте резултата.
*/
{
	printf("\n----------------task 3_8------------------\n");
	int iCount = -1;
	int iPrice = -1;
	int iFinalPrice = -1;
	int iVehicle = -1;

	printf("\nHallo! What type of vehicle do you need? - Caravan=1/Camper=2");
	scanf_s("%d", &iVehicle);

	if (iVehicle == 1)
	{
		iPrice = 90;
	}
	else
	{
		iPrice = 100;
	}

	printf("\nHow many vehicles do you need? - max 3:");
	scanf_s("%d", &iCount);

	iFinalPrice = iPrice * iCount;

	printf("\nYour account is: %d", iFinalPrice);
}
void hw_3_9_1store(void)
/*
Създайте С програма, която калкулира стойността на покупки в магазин за хранителни
стоки. Клиентът може да закупи различна комбинация от продукти. В магазина има
следните налични продукти и цени:
Домати- 4.5 лв.за килограм,
Брашно 1.80 лв. за килограм,
Кисело мляко - 0.50 лв. за брой,
Сладолед на фунийки 0.60 лв. броя
Бонбони 1.50 лв. за килограм,
Близалки 0.15 лв. за брой.
*/
{
	printf("\n----------------task 3_9------------------\n");
	int iChooseProduct = -1;
	double dProductPrice = -1;
	double dChooseQuantity = -1;
	double dPrice = -1;
	double dFinalPrice = 0;
	char cContinue = '0';
	printf("\n1. Tomato - 4.50 lv");
	printf("\n2. Flavour - 1.80 lv");
	printf("\n3. Yogurt - 0.50 lv");
	printf("\n4. Icecream - 0.60 lv");
	printf("\n5. Candies - 1.50 lv");
	printf("\n6. Lolypop - 0.15 lv");

	do
	{
		printf("\nChoose product 1-6?");
		scanf_s("%d", &iChooseProduct);

		switch (iChooseProduct)
		{
		case 1: {dProductPrice = 4.50; break; }
		case 2: {dProductPrice = 1.80; break; }
		case 3: {dProductPrice = 0.50; break; }
		case 4: {dProductPrice = 0.60; break; }
		case 5: {dProductPrice = 1.50; break; }
		case 6: {dProductPrice = 0.15; break; }
		default: {dProductPrice = 0.00;
			printf("No such product!"); }
		}

		printf("\nQuantity?");
		scanf_s("%lf", &dChooseQuantity);

		dPrice = dProductPrice * dChooseQuantity;
		dFinalPrice += dPrice;
		printf("\nDo you need something else? - Y/N");
		scanf_s(" %c", &cContinue, 1);
	} while (cContinue == 'y' || cContinue == 'Y');

	printf("\nYour account is %02lf!", dFinalPrice);
}
void hw_3_10_printPatterns(void)
/*Напишете програма PrintPatterns, която отпечата следните текстови графики наекрана. Графиките една под друга:
 # # # # # # # # # # #
   # # # # # # # # #
	 # # # # # # #
	   # # # # #
		 # # #
		   #

		   #
		 # # #
	   # # # # #
	 # # # # # # #
   # # # # # # # # #
 # # # # # # # # # # #

			#
		 # # #
	   # # # # #
	 # # # # # # #
   # # # # # # # # #
 # # # # # # # # # # #
   # # # # # # # # #
	 # # # # # # #
	   # # # # #
		 # # #
		   #
*/
{
	printf("\n----------------task 3_10------------------\n");
	int rows = 0;
	printf("Number of rows:");
	scanf_s("%d", &rows);

	for (int i = rows; i >= 1; i--)
	{
		for (int in = 1; in <= rows - i; in++) { printf("  "); };
		for (int st = 1; st <= 2 * i - 1; st += 1) { printf("* "); };
		printf("\n");
	}

	printf("\n");

	for (int i = 1; i <= rows; i++)
	{
		for (int in = 1; in <= rows - i; in++) { printf("  "); };
		for (int st = 1; st <= 2 * i - 1; st += 1) { printf("* "); };
		printf("\n");
	}

	printf("\n");

	for (int i = 1; i <= rows; i++)
	{
		for (int in = 1; in <= rows - i; in++) { printf("  "); };
		for (int st = 1; st <= 2 * i - 1; st += 1) { printf("* "); };
		printf("\n");
	}
	for (int i = rows - 1; i >= 1; i--)
	{
		for (int in = 1; in <= rows - i; in++) { printf("  "); };
		for (int st = 1; st <= 2 * i - 1; st += 1) { printf("* "); };
		printf("\n");
	}
}
void hw_3_11_yearSeconds(void)
/*
Напишете програма, която изчислява броя на секундите в една година.
*/
{
	printf("\n----------------task 3_11------------------\n");
	int iYear = -1;
	int iSeconds = -1;

	printf("\nEnter year:");
	scanf_s("%d", &iYear);

	iSeconds = yearDaysCount(iYear) * 24 * 60 * 60;

	printf("\nYear %d has %d seconds.", iYear, iSeconds);
}
/////