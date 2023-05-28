
#include "hw_15.h"
#include "../Library/stringFunc.h"
#include "../Library/inputOutputFunc.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SRT_MENU "\nEnter the operation of your choice:\na.add\t\ts.subtract\nm.multiply\td.divide\nq.quit\n"
#define SRT_WRONG_CHOICE "\nWrong choice! Please, try again!\n"
#define SRT_WRONG_FLOAT "\nPlease enter a float number, such as 2.5, -1.78E8, or 3:\n"
#define SRT_ENTER_NOT_NULL "\nEnter a float number other than 0:"

char chooseOption(void)
{
	char cChoice = 0;
	do
	{
		setbuf(stdin, NULL);
		cChoice = getc(stdin);
		if (!((cChoice == 'a') || (cChoice == 's') || (cChoice == 'm') || (cChoice == 'd') || (cChoice == 'q')))
		{
			printf(SRT_WRONG_CHOICE);
		}

	} while (!((cChoice == 'a') || (cChoice == 's') || (cChoice == 'm') || (cChoice == 'd') || (cChoice == 'q')));
	return cChoice;
}

void hw_15_0_1_fillArrWithChar(void)
/*
Да се напише функция, която напълва двумерен масив с определен символ.
*/
{
	printf("\n----------------task 15_0_1------------------\n");
	char matrix[3][4] = { 0 };
	char ch = 'f';
	int row = 3;
	int col = 4;
	string_matrixFillChar(*matrix, row, col, ch);
}
void hw_15_0_2_printBuffer(void)
/*
Да се въведе multiline стринг от клавиатрата и да се принтира.
*/
{
	printf("\n----------------task 15_0_2------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	printf(buff);
}
void hw_15_1_countLetterSymbol(void)
/*
Напишете програма, която моли потребителя да въведе текст на
няколко реда до достигането на EOF. След това принтирайте текста
и след него, на отделни редове:
● броя на всички символи от текста.
● броя на всички букви от текста.
● броя на всички пунктуационни знаци от текста.
*/
{
	printf("\n----------------task 15_1------------------\n");
	char buff[256] = { 0 };
	int countsymbols = 0;
	int countletters = 0;
	int countpunct = 0;
	io_strEnterMultilineEOF(buff);
	int lenght = (int)strlen(buff);
	printf(buff);
	for (const char* p = buff; *p != '\0'; ++p)
	{
		if (isalpha(*p))
		{
			++countletters;
		}
		if (ispunct(*p))
		{
			++countpunct;
		}
	}
	printf("\nnumber of symbols: %d", lenght);
	printf("\nnumber of letters: %d", countletters);
	printf("\nnumber of punctoation symbols: %d", countpunct);
}
void hw_15_2_countRowsSpaceTab(void)
/*
Напишете програма, която моли потребителя да въведе текст на
няколко реда до достигането на EOF. След това принтирайте на
отделни редове:
● броя на редовете.
● броя на space-овете (шпациите)
● броя на табулациите
*/
{
	printf("\n----------------task 15_2------------------\n");
	char buff[256] = { 0 };
	char c = 0;
	io_strEnterMultilineEOF(buff);
	printf(buff);

	printf("\nNumber of rows: %d", string_countRows(buff));
	printf("\nNumber of space: %d", string_countSymbols(buff, ' '));
	printf("\nNumber of tabs: %d", string_countSymbols(buff, '\t'));
}
void hw_15_3_removeSpace(void)
/*
Напишете програма, която моли потребителя да въведе текст на
няколко реда до достигането на EOF. След това принтирайте
въведения текст, но със премахнати дублиращи се последователни
space-а(шпации), пример:
hello,     world.
->
hello, world.
*/
{
	printf("\n----------------task 15_3------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	for (int i = 0; buff[i] != '\0'; ++i)
	{
		if ((buff[i] == ' ') && (buff[i + 1] == ' '))
		{
			for (int j = i; buff[j] != '\0'; ++j)
			{
				buff[j] = buff[j + 1];
			}
			i--;
		}
	}
	printf(buff);
}
void hw_15_4_printUpperLowerCaseNumbers(void)
/*
Напишете програма, която моли потребителя да въведе текст на няколко
реда до достигането на EOF. След това принтирайте въведения текст, но
само част от символите му:
● само главните букви от въведения текст
● само малки букви от въведения текст
● само числата от въведения текст
*/
{
	printf("\n----------------task 15_4------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	printf("\n\n");
	for (const char* p = buff; *p != '\0'; ++p)
	{
		if (isupper(*p))
		{
			putchar(*p);
		}
	}
	printf("\n\n");
	for (char* p = buff; *p != '\0'; ++p)
	{
		if (islower(*p))
		{
			putchar(*p);
		}
	}
	printf("\n\n");
	for (char* p = buff; *p != '\0'; ++p)
	{
		if (isdigit(*p))
		{
			putchar(*p);
		}
	}
	printf("\n");
}
void hw_15_5_printStrMoreThan3Symbols(void)
/*
Напишете програма, която моли потребителя да въведе текст на няколко
реда до достигането на EOF. След това принтирайте въведения текст, но
само редовете по-дълги от 3 символа.
*/
{
	printf("\n----------------task 15_5------------------\n");
	char buff[256] = { 0 };
	char temp[256] = { 0 };
	int countSymbol = 0;
	io_strEnterMultilineEOF(buff);
	int lenght = (int)strlen(buff);
	int j = 0;
	for (int i = 0; i <= lenght; ++i)
	{

		if (buff[i] != '\n')
		{
			temp[j] = buff[i];
			j++;
		}
		if ((buff[i] == '\n') || (buff[i] == '\0'))
		{
			temp[j] = '\0';
			if (strlen(temp) >= 3)
			{
				printf(temp);
				printf("\n");
			}
			j = 0;
		}

	}
}
void hw_15_6_averageLenghtOfWordsInStr(void)
/*
Напишете програма, която моли потребителя да въведе текст на няколко
реда до достигането на EOF. След това принтирайте средната дължина
на всички думи от текста (пунктуация и whitespace не е част от думите)
*/
{
	printf("\n----------------task 15_6------------------\n");
	char buff[256] = { 0 };
	int countletters = 0;
	int iNumberOfWords = 0;
	float averageLettersInWord = 0;
	io_strEnterMultilineEOF(buff);
	printf(buff);
	for (const char* p = buff; *p != '\0'; ++p)
	{
		if (('a' <= *p && *p <= 'z') || ('A' <= *p && *p <= 'Z'))
		{
			++countletters;
		}
	}
	iNumberOfWords = string_countWords(buff);
	printf("\nNumbers ofwords: %d", iNumberOfWords);
	averageLettersInWord = (float)countletters / (float)iNumberOfWords;
	printf("\nAverage numbers of symbols in word: %.1f", averageLettersInWord);
}
void hw_15_7_printStrWithoutWhitespce(void)
/*
Напишете програма, която моли потребителя да въведе текст на няколко
реда до достигането на EOF. След това принтирайте целия текст, но без
whitespace characters(space, newline, tab)
*/
{
	printf("\n----------------task 15_7------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	printf("\n\n");
	for (char* p = buff; *p != '\0'; ++p)
	{
		if (*p == ' ' || *p == '\t' || *p == '\n')
		{
			continue;
		}
		printf("%c", *p);
	}
	printf("\n\n");
}
void hw_15_8_floatMathMenu(void)
/*
Напишете програма за смятане на float числа, която има следното главно меню, което дава възможност на потребителя да избере
аритметична операция или да излезе от програмата. Програмата трябва да работи правилно и с невалидни данни - да уведомява
потребителя ако въведе невалидни данни и да му даде възможност да ги въведе отново. Примери за невалидни данни:
несъществуващо меню, въведени букви вместо числа, въведено деление на 0.
*/
{
	printf("\n----------------task 15_8------------------\n");
	char cChoice = '0';
	float fA = -1.0f;
	float fB = -1.0f;

	do
	{
		printf(SRT_MENU);
		cChoice = chooseOption();

		if (cChoice == 'q')
		{
			return;
		}
		int isFloat = 0;
		do
		{
			setbuf(stdin, NULL);
			printf("\nEnter first float number:\t");
			isFloat = scanf_s("%f", &fA);
			setbuf(stdin, NULL);
			if (isFloat != 1)
			{
				printf(SRT_WRONG_FLOAT);
			}
		} while (isFloat != 1);

		do
		{
			setbuf(stdin, NULL);
			printf("\nEnter second float number:\t");
			isFloat = scanf_s(" %f", &fB);
			setbuf(stdin, NULL);
			if (isFloat != 1)
			{
				printf(SRT_WRONG_FLOAT);
			}
		} while (isFloat != 1);

		if ((cChoice == 'd') && (fB == 0))
		{
			while (fB == 0)
			{
				setbuf(stdin, NULL);
				printf(SRT_ENTER_NOT_NULL);
				scanf_s(" %f", &fB);
				setbuf(stdin, NULL);
			}
		}

		switch (cChoice)
		{
		case 'a': printf("\n%.2f + %.2f = %.2f", fA, fB, fA + fB); break;
		case 's': printf("\n%.2f - %.2f = %.2f", fA, fB, fA - fB); break;
		case 'm': printf("\n%.2f * %.2f = %.2f", fA, fB, fA * fB); break;
		case 'd': printf("\n%.2f / %.2f = %.2f", fA, fB, fA / fB); break;
		}

	} while (cChoice = 'q');
}
void hw_15_9_printStrBackwords(void)
/*
Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на
EOF. След това принтирайте целия текст, но наобратно.
abc -> fed
def    cba
*/
{
	printf("\n----------------task 15_9------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	io_strPrintBackwords(buff);
}
void hw_15_10_printRowsBackwards(void)
/*
Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на
EOF. След това принтирайте целия текст, но обърнете реда на редовете (най-напред се принтира
последния въведен ред, най-накрая - първият въведен ред)
abc -> def
def    abc
*/
{
	printf("\n----------------task 15_10------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	io_strPrintRowsBackwards(buff);
}
void hw_15_11_printBackwardsEveryRow(void)
/*
Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на
EOF. След това принтирайте целия текст, но обърнете реда на буквите на всеки ред
abc -> cba
def    fed
*/
{
	printf("\n----------------task 15_11------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	io_strPrintBackwardsEveryRow(buff);
}
void hw_15_12_getcharCountLettersDigits(void)
/*
Използвайте функцията getchar(), с която въвеждате
текст от клавиатурата, докато не подадете ЕОF.Текстът има
букви и цифри.Пребройте колко са въведените букви и колко са
въведените цифри.Определeте броя на цифрите в стринга, като
използвате оператор continue.
*/
{
	printf("\n----------------task 15_12------------------\n");
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
}
void hw_15_13_printStrMoreThan80Symbols(void)
/*
 Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+Z). Текстът да отпечатва
само входни редове, които са по дълги от 80 символа.
*/
{
	printf("\n----------------task 15_13------------------\n");
	char buff[256] = { 0 };
	char temp[256] = { 0 };
	int countSymbol = 0;
	io_strEnterMultilineEOF(buff);
	int lenght = (int)strlen(buff);
	int j = 0;
	for (int i = 0; i <= lenght; ++i)
	{

		if (buff[i] != '\n')
		{
			temp[j] = buff[i];
			j++;
		}
		if ((buff[i] == '\n') || (buff[i] == '\0'))
		{
			temp[j] = '\0';
			if (strlen(temp) >= 80)
			{
				printf(temp);
				printf("\n");
			}
			j = 0;
		}

	}
}
void hw_15_14_printWithoutSpaceTab(void)
/*
Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+Z). Текстът има букви и
цифри. Принтирайте с putchar(). Използвайте условните оператори, за
да премахнете шпациите и табулациите в стринга
*/
{
	printf("\n----------------task 15_14------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	for (char* p = buff; *p != '\0'; ++p)
	{
		if ((*p == ' ') || (*p == '\t'))
		{
			continue;
		}
		else
		{
			putchar(*p);
		}
	}
}
void hw_15_15_printStrToLower(void)
/*
Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+Z). Текстът се принтира с
putchar(), като преобразува главните букви в малки.
*/
{
	printf("\n----------------task 15_15------------------\n");
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	for (char* p = buff; *p != '\0'; ++p)
	{
		*p = tolower(*p);
		putchar(*p);
	}
}
void hw_15_16_reverseRows(void)
/*
напишете функция reverse(s), която обръща символния низ
s. използвайте я, за да напишете програма, която преобръща входа си ред
по ред.
*/
{
	printf("\n----------------task 15_16------------------\n");
	char row[256] = { 0 };
	while (fgets(row, 256, stdin) != 0 && row[0] != EOF)
	{
		string_reverse(row);
		fputs(row, stdout);
		printf("\n");
	}
}
void hw_15_17_reverseStr(void)
/*
 Напишете функция void reverse(char s[]), която обръща
низа char s[].
*/
{
	printf("\n----------------task 15_17------------------\n");
	char s[] = "That's what!";
	string_reverse(s);
	printf("\nReversed:\n%s", s);
}