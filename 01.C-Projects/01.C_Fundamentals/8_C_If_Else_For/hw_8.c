#include "hw_8.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int minN(int a1, int b1)
{
	return a1 <= b1 ? a1 : b1;
}
int maxN(int a1, int b1)
{
	return a1 <= b1 ? b1 : a1;
}
unsigned charToInt(char a)
{
	if ('0' <= a && a <= '9')
	{
		return a - 48;
	}
	return a;
}
unsigned charToInt2(char a)
{
	if ('0' <= a && a <= '9')
	{
		return a = a - 48;
	}
	if ('A' <= a && a <= 'Z')
	{
		return a -= 55;
	}
	if ('a' <= a && a <= 'z')
	{
		return a -= 87;
	}
	return a;
}
unsigned maxUN(unsigned a, unsigned b)
{
	return a >= b ? a : b;
}
unsigned maxChar(char* cArr, int index)
{
	unsigned maxCh = charToInt(cArr[index]);
	while (cArr[index] != '\0')
	{
		if (charToInt(cArr[index]) > maxCh)
		{
			maxCh = charToInt(cArr[index]);
		}
		index++;
	}
	return maxCh;
}
void reverseString(char* arr)
{
	int sizeArr = (int)strlen(arr);
	int i = 0;
	int j = sizeArr - 1;

	for (i = 0, j = sizeArr - 1; i < j; i++, j--)
	{
		arr[i] = arr[i] - arr[j];
		arr[j] = arr[j] + arr[i];
		arr[i] = arr[j] - arr[i];
	}
}
void my_itoa(int iNumber, char* str)
{
	int i = 0;
	do
	{
		str[i] = iNumber % 10 + '0';
		iNumber /= 10;
		i++;
	} while (iNumber > 0);
	str[i] = '\0';
}
char replaceChWithCh(char* arr, char oldCh, char newCh)
{
	int size = (int)strlen(arr);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == oldCh)
		{
			arr[i] = newCh;
		}
	}
	return *arr;
}
void squeezeCh(char* s, char Ch)
{
	int i = 0;
	int j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != Ch)
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
}
void squeezeStr(char* s1, size_t sizeS1, const char* s2, const size_t sizeS2)
{
	const char* k = s2;
	char* i = s1;
	for (k = s2; k < s2 + sizeS2 - 1; ++k)
	{
		char* j = s1;
		for (i = s1; i < s1 + sizeS1 - 1; ++i)
		{
			if (*k != *i)
			{
				*j = *i;
				j++;
			}
		}
		*j = '\0';
	}
}
int find_any(const char* s1, const size_t sizeS1, const char* s2, const size_t sizeS2)
{
	const char* i = s1;
	const char* k = s2;
	for (i = s1; i < s1 + sizeS1 - 1; ++i)
	{
		for (k = s2; k < s2 + sizeS2 - 1; ++k)
		{
			if (*k == *i)
			{
				return (int)(i - s1);
			}
		}
	}
	return -1;
}
void toLower(char* s)
{
	int size = (int)strlen(s);
	for (int i = 0; i < size; i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			s[i] += 32;
		}
	}
}


void hw_8_0_1_if(void)
/*
Използвайте конструкцията if-else, направете програма, която
прави едно от три различни неща(каквито си изберете), в
зависимост от избора на потребителя:
Press 1 to see a “Hello, World” message.
Press 2 to see a poem.
Press 3 to get a random dice roll. (може да ползвате функцията int rand() от stdlib.h)
*/
{
	printf("\n----------------task 8_0_1------------------\n");
	int iChoice = -1;

	printf("\nPress 1 to see a \"Hello, World\" message");
	printf("\nPress 2 to see a poem.");
	printf("\nPress 3 to get a random dice roll.");
	scanf_s("%d", &iChoice);
	time_t t = 0;

	srand((unsigned)time(&t));

	if (iChoice == 1)
	{
		printf("\nHello, World!");
	}
	else if (iChoice == 2)
	{
		printf("\nTwo lovely eyes - Peyo Yavorov");
		printf("\nTwo lovely eyes. The spirit of a child.\nTwo lovely eyes. Sunrays and music.");
		printf("\nThey don't want anything and they don't vow. \nMy soul is praying,");
		printf("Child! \nMy soul is praying.");
	}
	else if (iChoice == 3)
	{
		printf("\nThe dice shows %d", rand() % 6);
	}
}
void hw_8_0_2_swithc(void)
/*
ренапишете предишното упражнение като вместо if - else - if конструкцията
използвайте switch - case.
*/
{
	printf("\n----------------task 8_0_2------------------\n");
	int iChoice = -1;

	printf("\nPress 1 to see a \"Hello, World\" message");
	printf("\nPress 2 to see a poem.");
	printf("\nPress 3 to get a random dice roll.");
	scanf_s("%d", &iChoice);
	switch (iChoice)
	{
	case 1:
	{
		printf("\nHello, World!");
		break;
	}
	case 2:
	{
		printf("\nTwo lovely eyes - Peyo Yavorov");
		printf("\nTwo lovely eyes. The spirit of a child.\nTwo lovely eyes. Sunrays and music.");
		printf("\nThey don't want anything and they don't vow. \nMy soul is praying,");
		printf("Child! \nMy soul is praying.");
		break;
	}
	case 3:
	{
		printf("\n%d", rand() % 6);
		break;
	}
	default:
	{
		printf("\nWrong choice!");
		break;
	}
	}
}
void hw_8_0_3_while(void)
/*
Пренапишете предишното упражнение като вмъкнете
конструкцията switch-case в един цикъл while, така че питането
да се повтаря, докато потребителят не въведе числото 4, което е
поставено в питането за изход от програмата.
*/
{
	printf("\n----------------task 8_0_3------------------\n");
	int iChoice = -1;

	do
	{
		printf("\nHello!");
		printf("\nPress 1 to see a \"Hello, World\" message");
		printf("\nPress 2 to see a poem.");
		printf("\nPress 3 to get a random dice roll.");
		printf("\nPress 4 to exit.");
		scanf_s("%d", &iChoice);

		switch (iChoice)
		{
		case 1:
		{
			printf("\nHello, World!");
			break;
		}
		case 2:
		{
			printf("\nTwo lovely eyes - Peyo Yavorov");
			printf("\nTwo lovely eyes. The spirit of a child.\nTwo lovely eyes. Sunrays and music.");
			printf("\nThey don't want anything and they don't vow. \nMy soul is praying,");
			printf("Child! \nMy soul is praying.");
			break;
		}
		case 3:
		{
			printf("\n%d", rand() % 6);
			break;
		}
		case 4:
		{
			printf("\nThank you for your choice! Good bye!");
			break;
		}
		default:
		{
			printf("\nWrong choice!");
			break;
		}
		}
	} while (iChoice != 4);
}
void hw_8_0_4_sum(void)
/*
Да се изчисли сумата на целите числа в зададен диапазон [a, b] с while.
*/
{
	printf("\n----------------task 8_0_4------------------\n");
	int a = -1;
	int b = -1;
	int x = -1;
	int sum = 0;
	int min = -1;
	int max = -1;

	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);

	min = minN(a, b);
	max = maxN(a, b);

	x = min;
	while (min <= x && x <= max)
	{
		sum += x;
		x++;
	}

	printf("sum [%d;%d] = %d", min, max, sum);
}
void hw_8_0_5_for(void)
/*
Принтирайте числата от 13 до 19 като използваме for цикъл.
*/
{
	printf("\n----------------task 8_0_5------------------\n");
	for (int i = 13; i < 20; i++)
	{
		printf("\n%d", i);
	}
}
void hw_8_0_6_continue(void)
/*
Ползвайки continue, oбходете масив от числа и изведете:
● броя на положителните числа
● броя на положителните четни числа
● всяко четно число по-голямо от 100
*/
{
	printf("\n----------------task 8_0_6------------------\n");
	int arr[10];
	int size = 10;
	int i = 0;
	int iCountPozitive = 0;
	int iCountPozitiveEnum = 0;
	int iCountPozitiveEnum100 = 0;

	for (i = 0; i < size; i++)
	{
		printf("\narr[%d]=", i);
		scanf_s("%d", &arr[i]);
	}

	for (i = 0; i < size; i++)
	{
		if (arr[i] > 0 && arr[i] % 2 == 0 && arr[i] > 100)
		{
			iCountPozitive += 1;
			continue;
		}
		if (arr[i] > 0 && arr[i] % 2 == 0)
		{
			iCountPozitiveEnum += 1;
			continue;
		}
		if (arr[i] > 0)
		{
			iCountPozitiveEnum100 += 1;
		}

	}
	printf("\nPozitive\t\t  %d", iCountPozitive);
	printf("\nPozitive Enum\t\t  %d", iCountPozitiveEnum);
	printf("\nPozitive Enum > 100\t  %d", iCountPozitiveEnum100);
}
void hw_8_0_7_endlessFor(void)
/*
Създайте безкраен цикъл с for (;;) и принтирайте числото, което на
всеки цикъл се увеличава с едно. Когато числото стигне 48, излезте
от цикъла с break.
*/
{
	printf("\n----------------task 8_0_7------------------\n");
	for (int i = 0; i >= 0; i++)
	{
		printf("\n%d", i);
		if (i == 48)
		{
			break;
		}
	}
}
void hw_8_1_stringToNumber(void)
/*
Напишете програма, която преобразува string в целочислено число(unsigned int). Низът
може да е число от всяка [2-10]-мерна бройна система(т.е. може да има само символи,
които са цифри)
*/
{
	printf("\n----------------task 8_1------------------\n");
	char str[] = { '0','1','8','\0' };
	unsigned uNum = 0;
	unsigned max = 0;
	int size = 0;
	int i = 0;

	max = charToInt(str[0]);
	while (str[i] != '\0')
	{
		if (charToInt(str[i]) > max)
		{
			max = charToInt(str[i]);
		}
		i++;
	}

	printf("Number system base %d", max + 1);

	size = (int)strlen(str);
	for (int j = 0; j < size; j++)
	{
		uNum += charToInt(str[j]) * (unsigned)pow(max + 1, size - 1 - j);
	}
	printf("\nNumber is %d", uNum);
}
void hw_8_2_stringToNumber(void)
/*
Разширете възможностите на програмата от Задача 1:
Нека низът да може да е число от всяка [2-36]-мерна бройна система(т.е. може да има само
символи, които са цифри и букви)
*/
{
	printf("\n----------------task 8_2------------------\n");
	char str[] = { '0','0','0','0','0','1','z','\0' };
	unsigned uNum = 0;
	unsigned max = 0;
	int size = 0;
	int i = 0;

	max = charToInt2(str[0]);
	while (str[i] != '\0')
	{
		if (charToInt2(str[i]) > max)
		{
			max = charToInt2(str[i]);
		}
		i++;
	}

	printf("Number system base %d", max + 1);

	size = (int)sizeof(str);
	for (int j = 0; j <= size - 2; j++)
	{
		uNum += charToInt2(str[j]) * (unsigned)pow(max + 1, size - 2 - j);
	}
	printf("\nNumber is %d", uNum);
}
void hw_8_3_stringToNumber(void)
/*
Напишете програма, която преобразува c string литерала в целочислено
число(unsigned int). Низът може да има представка, коята променя типа на литералата:
○ 0b, 0B - binary
○ 0x, 0X - hex
○ 0 - oct
*/
{
	printf("\n----------------task 8_3------------------\n");
	char str[] = { "100007" };
	unsigned uNum = 0;
	unsigned max = 0;
	int size = (int)sizeof(str);
	int i = 0;

	if ((str[0] == '0') && (str[1] == 'b' || str[1] == 'B'))
	{
		max = maxChar(str, 2);
		printf("0b-Number system base %d", maxUN(2, max + 1));
		for (i = 2; i <= size - 2; i++)
		{
			uNum += charToInt(str[i]) * (unsigned)pow(maxUN(2, max + 1), size - i - 2);
		}
	}
	else if ((str[0] == '0') && (str[1] == 'x' || str[1] == 'X'))
	{
		max = maxChar(str, 2);
		printf("0x-Number system base %d", maxUN(16, max + 1));
		for (i = 2; i <= size - 2; i++)
		{
			uNum += charToInt(str[i]) * (unsigned)pow(maxUN(16, max + 1), size - 2 - i);
		}
	}
	else if (str[0] == '0')
	{
		max = maxChar(str, 1);
		printf("0-Number system base %d", maxUN(8, max + 1));
		for (i = 1; i <= size - 2; i++)
		{
			uNum += charToInt(str[i]) * (unsigned)pow(maxUN(8, max + 1), size - 2 - i);
		}
	}
	else
	{
		max = maxChar(str, 0);
		printf("Number system base %d", max + 1);
		for (i = 0; i <= size - 2; i++)
		{
			uNum += charToInt(str[i]) * (unsigned)pow(max + 1, size - 2 - i);
		}
	}
	printf("\nNumber is %d", uNum);
}
void hw_8_4_mirroredString(void)
/*
Напишете функция, която обръща string наобратно
char str[] = "Hello\n";
reverseString(str); // "\nolleH"
Използвайте единствен for цикъл с две променливи за индексация:
for(i = 0, j = strLength - 1; i < j; i++, j--)
*/
{
	printf("\n----------------task 8_4------------------\n");
	char str[] = "Hello\\n";
	int sizeStr = (int)strlen(str);
	reverseString(str);
	fputs(str, stdout);
}
void hw_8_5_my_itoa(void)
/*
Използвайте do-while цикъл, за да напишете функцията void itoa(int n, char
s[]), която преобразува число в символен низ (обратната функция на atoi).
do-while цикълът e необходим, тъй като в масива ще трябва да се постави
поне един символ, дори ако n е нула. Ако n = 123, за да вземем последната
цифра, трябва да разделим n по модул(%) на основата на бройната
система 10. За да получите чаръктър число, трябва да съберете резултата
с '0'. За да вземете следващото число, трябва да разделите n на 10. Това
продължава докато n е различно от нула. Това генерира низа в обратен ред
– 321, затова използваме reverse функцията от предходната задача.
*/
{
	printf("\n----------------task 8_5------------------\n");
	int iNumberToEnter = 1;
	char arrSymbols[10];

	printf("\nEnter a number:");
	scanf_s("%d", &iNumberToEnter);

	my_itoa(iNumberToEnter, arrSymbols);
	reverseString(arrSymbols);

	fputs(arrSymbols, stdout);
}
void hw_8_6_replaceChWithCh(void)
/*
Напишете функция void replace(char *str, int oldChar, int newChar),
която подменя всяко срещане на даден символ в стринг аргумента
си с с друг
char str[] = "Hello\n";
replace(str, 'e', '3'); // "H3llo\n"
*/
{
	printf("\n----------------task 8_6------------------\n");
	char str[] = "Hello";
	int sizeStr = (int)strlen(str);

	*str = replaceChWithCh(str, 'e', '3');
	for (int i = 0; i < sizeStr; i++)
	{
		printf("%c", str[i]);
	}
}
void hw_8_7_squeezeCh(void)
/*
Напишете функция void squeeze(char s[], int c), която премахва
символа с от низа s[]
char str[] = "Hello\n";
squeeze(str, 'o'); // "Hell\n"
*/
{
	printf("\n----------------task 8_7------------------\n");
	char str[] = "Hellllo\\n";
	printf("\n%s", str);

	squeezeCh(str, 'l');

	printf("\n%s", str);
}
void hw_8_8_squeezeStr(void)
/*
Напишете алтернативна версия на функцията
void squeeze(char s1[], const char s2[]), която премахва всеки символ в
s1[], който съответства на някой от символите в s2.
char str[] = "Hello\n";
squeeze(str, "Hl");
printf("%s", str); // "eo\n"
*/
{
	printf("\n----------------task 8_8------------------\n");
	char s1[8] = "Hello\\n";
	const char s2[3] = "Hl";
	size_t sizeS1 = sizeof(s1);
	const size_t sizeS2 = sizeof(s2);

	printf("\nS1 Before=\t%s", s1);
	printf("\nS2 =\t\t%s", s2);

	squeezeStr(s1, sizeS1, s2, sizeS2);

	printf("\nS1 After=\t%s", s1);
}
void hw_8_9_findAny(void)
/*
Напишете функцията int find_any(const char s1[], const char s2[]), която
връща първата позиция в низа s1, където се появява някой от
символите в низа s2, или -1 ако не е намерен нито един символ.
// returns 1, as "Hello"[1] == 'e', which is found in "oe"
int index = find_any("Hello", "oe");
if (index >= 0)
*/
{
	printf("\n----------------task 8_9------------------\n");
	const char s1[6] = "Hello";
	const char s2[3] = "oe";
	const size_t sizeS1 = sizeof(s1);
	const size_t sizeS2 = sizeof(s2);

	printf("\nS1 = %s", s1);
	printf("\nS2 = %s", s2);

	printf("\nFirst position of meeting element from 'oe' is %d", find_any(s1, sizeS1, s2, sizeS2));
}
void hw_8_10_toLower(void)
/*
Напишете функцията void toLower(char s[]), която преобразува всички
главни букви в малки.
char str[] = "HEllo, 123\n";
toLower(str);
printf("%s", str); // should print "hello, 123\n"
*/
{
	printf("\n----------------task 8_10------------------\n");
	char str[] = "HEllo, 123\\n";
	printf("%s", str);
	toLower(str);
	printf("\n%s", str);
}