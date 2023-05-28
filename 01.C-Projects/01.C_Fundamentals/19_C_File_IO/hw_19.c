#include "hw_19.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum E_DrivingLicenseCategory { A1, A2, A, B, B1, C, D, BE, CE, DE, T } DrivingLicense;

static const char* FORMAT_USERINFO_IN = "(%[^,], %[^,], %[^,], %[^,], %d)\n";
static const char* FORMAT_USERINFO_OUT = "(%s, %s, %s, %s, %d)\n";

typedef struct UserData {
	char name[20];
	char middleName[20];
	char surname[20];
	char PIN[11];
	DrivingLicense driveCategory;
} UserData;

void print_UserData(FILE* in)
{
	UserData user;
	int ifscan = fscanf(in, FORMAT_USERINFO_IN, &user.name, &user.middleName, &user.surname, &user.PIN, &user.driveCategory);
	fprintf(stdout, FORMAT_USERINFO_OUT, user.name, user.middleName, user.surname, user.PIN, user.driveCategory);
}
void insert_UserData(FILE* out)
{
	UserData user;
	printf("\nEnter user name:");
	scanf_s(" %s", &(user.name), 20);
	printf("\nEnter user middleName:");
	scanf_s(" %s", &(user.middleName), 20);
	printf("\nEnter user surname:");
	scanf_s(" %s", &(user.surname), 20);
	printf("\nEnter user PIN:");
	scanf_s(" %s", &(user.PIN), 11);
	printf("\nEnter user drive category: \nA1\t0\nA2\t1\nB\t2\nB1\t3\nC\t4\nD\t5\nBE\t6\nCE\t7\nDE\t8\nT\t9\n");
	scanf_s("%d", &(user.driveCategory));
	fprintf(out, FORMAT_USERINFO_OUT, user.name, user.middleName, user.surname, user.PIN, user.driveCategory);
}
void print_UserDataArr(FILE* in)
{
	UserData userArr[3];
	for (int i = 0; i < 3; i++)
	{
		int ifscan = fscanf(in, FORMAT_USERINFO_IN, &userArr[i].name, &userArr[i].middleName, &userArr[i].surname, &userArr[i].PIN, &userArr[i].driveCategory);
		fprintf(stdout, FORMAT_USERINFO_OUT, userArr[i].name, userArr[i].middleName, userArr[i].surname, userArr[i].PIN, userArr[i].driveCategory);
	}
}
void insert_UserDataArr(FILE* out)
{
	UserData userArr[3];
	for (int i = 0; i < 3; i++)
	{
		printf("\nEnter user name:");
		scanf_s(" %s", &(userArr[i].name), 20);
		printf("\nEnter user middleName:");
		scanf_s(" %s", &(userArr[i].middleName), 20);
		printf("\nEnter user surname:");
		scanf_s(" %s", &(userArr[i].surname), 20);
		printf("\nEnter user PIN:");
		scanf_s(" %s", &(userArr[i].PIN), 11);
		printf("\nEnter user drive category: \nA1\t0\nA2\t1\nB\t2\nB1\t3\nC\t4\nD\t5\nBE\t6\nCE\t7\nDE\t8\nT\t9\n");
		scanf_s("%d", &(userArr[i].driveCategory));
		fprintf(out, FORMAT_USERINFO_OUT, userArr[i].name, userArr[i].middleName, userArr[i].surname, userArr[i].PIN, userArr[i].driveCategory);
	}
}

void hw_19_0_1_printToEOF(void)
//call from cmd:
{
	printf("\n-----------------task 19_0_1-----------------------\n");
	printf("Enter text:\n");
	char ch = 0;
	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
}
void hw_19_0_2_printErr(void)
//print to cmd in stdout and stderr
{
	printf("\n-----------------task 19_0_2-----------------------\n");
	printf("Enter text:\n");
	char ch = 'c';
	putc(ch, stdout);

	ch = 'e';
	putc(ch, stderr);

	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
}
void hw_19_0_3_1_changeSpace(void)
{
	printf("\n-----------------task 19_0_3_1-----------------------\n");
	printf("Enter text:\n");
	//program one for piping:
	char ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
		{
			ch = '_';
		}
		putchar(ch);
	}
}
void hw_19_0_3_2_toUpper(void)
//program two for piping:
{
	printf("\n----------------task 19_0_3_2------------------\n");
	printf("Enter text:\n");
	char ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (islower(ch))
		{
			ch = toupper(ch);
		}
		putchar(ch);
	}
}
void hw_19_1_fgets_fputs(void)
/*
Напишете програма, която чете стринг от стандартния вход и го извежда на
стандартния изход с функциите fgets и fputs.
char *fgets(char *str, int n, FILE *stream);
int fputs(const char *str, FILE *stream)
*/
{
	printf("\n-----------------task 19_1-----------------------\n");
	printf("Enter text:\n");
	char str[256];
	while (fgets(str, 256, stdin) != 0 && str[0] != '\n')
	{
		fputs(str, stdout);
	}
}
void hw_19_2_getc_putc(void)
/*
Напишете програма, която чете стринг от стандартния вход и го извежда на
стандартния изход с функциите getc и putc.
Moже да ползвате fgetc и fputc, които са почти същите.
Потърсете информация за разликата между различните версии - при
едната двойка не можем да имаме аргументи със странични ефекти. При
кои?
int getc(FILE *stream);
int putc(int char, FILE *stream);
int fgetc(FILE *stream);
int fputc(int char, FILE *stream);
*/
{
	printf("\n-----------------task 19_2-----------------------\n");
	printf("Enter text:\n");
	char ch = 0;
	while ((ch = getc(stdin)) != EOF)
	{
		putc(ch, stdout);
	}
}
void hw_19_3_fprintf_fscanf(void)
/*
Напишете програма, която чете стринг от стандартния вход и го извежда на
стандартния изход с функциите fprintf и fscanf.
*/
{
	printf("\n-----------------task 19_3-----------------------\n");
	printf("Enter text:\n");
	char str[256] = { 0 };
	while (fscanf(stdin, " %[^\n]s", str) && str[0] != '^Z')
	{
		fprintf(stdout, "%s", str);
		setbuf(stdin, NULL);
		fprintf(stdout, "\n");
	}
}
void hw_19_4_randomNames(void)
/*
Напишете програма, която отваря три файла едновременно:
● файл с имена, всяко на нов ред ( в режим на четене )
● файл с фамилии, всяка на нов ред ( в режим на четене )
● файл с произволно-генерирани двойки от име + фамилия. ( в режим на
писане )
Програмата трябва да пита потребителя за желан брой нови генерирания
на произволна двойка име-фамилия и за това дали да добави
новогенерираните имена в края на файла или да замести съдържанието
му изцяло.
*/
{
	printf("\n-----------------task 19_4-----------------------\n");
	srand((int)time(NULL));
	FILE* inName = 0;
	FILE* inSurname = 0;
	FILE* out = 0;
	inName = file_open(inName, "name.txt", "r");
	inSurname = file_open(inSurname, "surname.txt", "r");
	
	int choiceFileMode = 0;
	do
	{
		printf("\nPress 1 if you want to keep old data in file.");
		printf("\nPress 2 if you want to remove the old data from file.");
		scanf_s("%d", &choiceFileMode);
	} while (choiceFileMode != 1 && choiceFileMode != 2);
	if (choiceFileMode == 1)
	{
		out = file_open(out, "random_names.txt", "a");
	}
	else
	{
		out = file_open(out, "random_names.txt", "w");
	}
	int countCombinations = 0;
	printf("Enter number  of name-surname combinations:");
	scanf_s("%d", &countCombinations);
	for (int it = 0; it < countCombinations; it++)
	{
		char ch = '0';
		int countNewLine = 0;
		rewind(inName);
		while ((ch = getc(inName)) != EOF)
		{
			if (ch == '\n')
			{
				countNewLine++;
			}
		}
		int randName = rand() % countNewLine;
		rewind(inName);
		countNewLine = 0;
		while ((ch = getc(inName)) != EOF)
		{
			if (ch == '\n')
			{
				countNewLine++;
			}
			if ((countNewLine == randName) && isalpha(ch))
			{
				fputc(ch, out);
			}
		}
		fputc(' ', out);
		rewind(inSurname);
		countNewLine = 0;
		while ((ch = getc(inSurname)) != EOF)
		{
			if (ch == '\n')
			{
				countNewLine++;
			}
		}
		int randSurname = rand() % countNewLine;
		rewind(inSurname);
		countNewLine = 0;
		while ((ch = getc(inSurname)) != EOF)
		{
			if (ch == '\n')
			{
				countNewLine++;
			}
			if ((countNewLine == randSurname) && isalpha(ch))
			{
				fputc(ch, out);
			}
		}
		fputc('\n', out);
	}
	if (fclose(inSurname) != 0 || fclose(inName) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");
}
void hw_19_5_randomNames(void)
/*
Напишете алтернативна версия на горната програма, която да приема
входните си данни не от клавиатурата, ами от command-line аргументите
си (от аргументите на на main функцията)
*/
{
	printf("\n-----------------task 19_5-----------------------\n");
	printf("\nFile \"19_5.exe\" is for running from cmd.");

	int main_19_5(int argc, char* argv[])
	{
		srand(time(NULL));
		FILE* inName = 0;
		FILE* inSurname = 0;
		FILE* out = 0;

		if (argc != 4)
		{
			printf("Usage: %s filename\n", argv[0]);
			exit(EXIT_FAILURE);
		}

		inName = file_open(inName, argv[1], "r");
		inSurname = file_open(inSurname, argv[2], "r");
		int choiceFileMode = 0;
		do
		{
			printf("\nPress 1 if you want to keep old data in file.");
			printf("\nPress 2 if you want to remove the old data from file.");
			scanf_s("%d", &choiceFileMode);
		} while (choiceFileMode != 1 && choiceFileMode != 2);
		if (choiceFileMode == 1)
		{
			out = file_open(out, argv[3], "a");
		}
		else
		{
			out = file_open(out, argv[3], "w");
		}

		int countCombinations = 0;
		printf("Enter number  of name-surname combinations:");
		scanf_s("%d", &countCombinations);
		for (int it = 0; it < countCombinations; it++)
		{
			char ch = '0';
			int countNewLine = 0;
			rewind(inName);
			while ((ch = getc(inName)) != EOF)
			{
				if (ch == '\n')
				{
					countNewLine++;
				}
			}
			int randName = rand() % countNewLine;
			rewind(inName);
			countNewLine = 0;
			while ((ch = getc(inName)) != EOF)
			{
				if (ch == '\n')
				{
					countNewLine++;
				}
				if ((countNewLine == randName) && isalpha(ch))
				{
					fputc(ch, out);
				}
			}
			fputc(' ', out);
			rewind(inSurname);
			countNewLine = 0;
			while ((ch = getc(inSurname)) != EOF)
			{
				if (ch == '\n')
				{
					countNewLine++;
				}
			}
			int randSurname = rand() % countNewLine;
			rewind(inSurname);
			countNewLine = 0;
			while ((ch = getc(inSurname)) != EOF)
			{
				if (ch == '\n')
				{
					countNewLine++;
				}
				if ((countNewLine == randSurname) && isalpha(ch))
				{
					fputc(ch, out);
				}
			}
			fputc('\n', out);
		}
		if (fclose(inSurname) != 0 || fclose(inName) != 0 || fclose(out) != 0)
			fprintf(stderr, "Error in closing files\n");
		return EXIT_SUCCESS;
	}
}
void hw_19_6_insertPrintFileUser(void)
/*
Дефинирайте структура UserData със следните members:
● c-string масиви от char за име, презиме и фамилия
● PIN (ЕГН)
● enum E_DrivingLicenseCategory - категория за водач на МПС
Дефинирайте функции за четене и писане на UserData дата обекти в/от подаден
FILE* като аргумент(форматирайте текстовите данни както намерите за добре)
Прочетете UserData обект от текстов файл.
Запишете UserData обект в текстов файл.
*/
{
	printf("\n-----------------task 19_6-----------------------\n");
	FILE* in = NULL;
	FILE* out = NULL;
	char filename[20] = {0};
	printf("\nEnter output file name:");
	io_strEnter(filename, 20);

	out = file_open(out, filename, "a");
	insert_UserData(out);
	file_close(out);

	in = file_open(in, filename, "r");
	print_UserData(in);
	file_close(in);
}
void hw_19_7_insertPrintFileUserArr(void)
/*
Дефинирайте функции за четене и писане на масив от UserData обекти във FILE*.
Тествайте четенето и писането на колекции от UserData в/от файлове.
*/
{
	printf("\n-----------------task 19_7-----------------------\n");
	FILE* out = NULL;
	FILE* in = NULL;
	char filename[20] = {0};
	printf("\nEnter output file name:");
	io_strEnter(filename, 20);

	//out = file_open(out, filename, "a");
	//insert_UserDataArr(out);
	//file_close(out);

	in = file_open(in, filename, "r");
	print_UserDataArr(in);
	file_close(in);
}
void hw_19_8_fileStatistics(void)
/*
Напишете програма, която принтира статистики за текст от файл. Програмата трябва да работи със
следните command-line аргументи
● първи аргумент(задължителен): име на файл, който да прочете
● от 0 до 3 аргумента за това каква информация да изведе програмата
○ брой символи - ако има аргумент “-c”
○ брой думи - “-w”
○ брой редове - “-l”
○ Ако не е подаден нито един от трите аргумента, да принтира само броя думи във файла
Направете програмата да пише в stderr при грешки или невалидни аргументи.
*/
{
	printf("\n-----------------task 19_8-----------------------\n");
	printf("\nFile \"19_8.exe\" is for running from cmd.");

	int main(int argc, char* argv[])
	{
		FILE* in = 0;
		if (argc < 2)
		{
			fprintf(stderr, "%d - Not enough arguments.\n", argc);
			exit(EXIT_FAILURE);
		}
		in = file_open(in, argv[1], "r");
		_Bool isPrinted = 0;
		for (int i = 0; i < argc; i++)
		{
			if (!strcmp(argv[i], "-c"))
			{
				rewind(in);
				printf("\nSymbols in text: %lu", file_countSymbols(in));
				isPrinted = 1;
			}
			if (!strcmp(argv[i], "-l"))
			{
				rewind(in);
				printf("\nRows in text: %d", file_countRows(in));
				isPrinted = 1;
			}
			if (!strcmp(argv[i], "-w"))
			{
				rewind(in);
				printf("\nWords in text: %d", file_countWords(in));
				isPrinted = 1;
			}
		}
		if (isPrinted == 0)
		{
			rewind(in);
			printf("\nWords in text: %d", file_countWords(in));
		}
		file_close(in);
		return EXIT_SUCCESS;
		return 0;
	}
}
void hw_19_9_printLinuxFile(void)
/*
Напишете стандартната програма за Linux: cat, която приема като аргументи от командния ред
имена на файлове и изкарва съдържанието им на стандартния изход. Ако на програмата не са
подадени никакви аргументи, то тя да изкара съдържанието подадено от стандартния вход на
стандартния изход.
*/
{
	printf("\n-----------------task 19_9-----------------------\n");
	printf("\nFile \"19_9.exe\" is for running from cmd.");
	int main(int argc, char* argv[])
	{
		FILE* fp = 0;
		if (argc < 2)
		{
			fprintf(stderr, "%d - Not enough arguments.\n", argc);
			exit(EXIT_FAILURE);
		}
		for (int fileCount = 1; fileCount < argc; fileCount++)
		{
			fp = file_open(fp, argv[fileCount], "r");
			unsigned long countSymbolsInFile = file_countSymbols(fp);
			rewind(fp);
			char ch = '0';
			for (unsigned long count = 1L; count <= countSymbolsInFile; count++)
			{
				ch = getc(fp);
				//for Macintosh:
				if (ch == '\r')
				{
					putchar('\n');
				}
				else
				{
					putchar(ch);
				}
			}
			putchar('\n');
			file_close(fp);
			return EXIT_SUCCESS;
		}
		return 0;
	}
}
void hw_19_10_multipleFie(void)
/*
Напишете програма, която отваря файл по зададено име на файл от командния ред и умножава
всяко число, което отркие във файла по две.
*/
{
	printf("\n-----------------task 19_10-----------------------\n");
	printf("\nFile \"19_10.exe\" is for running from cmd.");

	int main(int argc, char* argv[])
	{
		FILE* in = 0;
		if (argc != 2)
		{
			fprintf(stderr, "Wrong number of arguments.\n");
			exit(EXIT_FAILURE);
		}
		in = file_open(in, argv[1], "r");
		char str[256] = { 0 };
		char ch = '0';
		int i = 0;
		while ((ch = getc(in)) != EOF)
		{
			str[i++] = ch;
		}
		str[i] = '\0';
		file_close(in);

		char* pStr = str;
		pStr = string_multipleNumbersBy2(str);

		in = file_open(in, argv[1], "w");
		int strLen = (int)strlen(str);
		for (int i = 0; i < strLen; i++)
		{
			fprintf(in, "%c", str[i]);
		}
		file_close(in);
		return EXIT_SUCCESS;
		return 0;
	}
}