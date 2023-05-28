#include "../Library/inputOutputFunc.h"
#include "../Library/arrayFunc.h"
#include "../Library/stringFunc.h"
#include <stdio.h>
#include <string.h>

#define SIZE 6

void print_str_tokens(const char* str, const char* delimiters)
{
	const char* subStrStart[20] = { 0 };
	const char* subStrEnd[20] = { 0 };
	const char* pStr = str;
	int i = 0;
	for (; pStr != '\0'; ++i)
	{
		pStr = string_findSubstringStart(pStr, delimiters);
		subStrStart[i] = pStr;
		if (pStr != '\0')
		{
			pStr = string_findSubstringEnd(pStr, delimiters);
			subStrEnd[i] = pStr;
		}
	}
	subStrStart[i] = '\0';
	subStrEnd[i] = '\0';
	int countSubstrings = i - 1;
	for (int j = 0; j < countSubstrings; ++j)
	{
		for (int subSymbol = 0; subStrStart[j] + subSymbol < subStrEnd[j]; ++subSymbol)
		{
			printf("%c", *(subStrStart[j] + subSymbol));
		}
		printf("\n");
	}
}

void hw_16_0_1_copyMatrixToArr(void)
/*
Да се напише функция, която копира двумерен масив в едномерен със същия брой елементи.
*/
{
	printf("\n------------------task 16_0_1------------------\n");
	const int matrix[2][3] = { 0 };
	int arr[SIZE] = { 0 };

	io_matrixIntEnter(*matrix, 2, 3);
	martix_copyMatrixToArr(*matrix, arr, SIZE);
	io_matrixIntPrint(*matrix, 2, 3);
	printf("\n");
	io_matrixIntPrint(arr, 1, SIZE);
}
void hw_16_0_2_copyMatrixToArrBackwards(void)
/*
Да се напише функция, която копира двумерен масив в едномерен със същия 
брой елементи, но в обратен ред.
*/
{
	printf("\n------------------task 16_0_2------------------\n");
	const int matrix[2][3] = { 0 };
	int arr[SIZE] = { 0 };

	io_matrixIntEnter(*matrix, 2, 3);
	martix_copyMatrixToArrBackwards(*matrix, arr, SIZE);
	io_matrixIntPrint(*matrix, 2, 3);
	printf("\n");
	io_matrixIntPrint(arr, 1, SIZE);
}
void hw_16_0_3_my_strchr_findFirstChar(void)
/*
Напишете собствена версия на стандартната функция strchr от string.h,
my_strchr
която приема стринг и char и връща адреса на първия елемент на стринга,
който е равен на символът, подаден като аргумент. Ако символът не е
намерен, функцията връща нулев указател.
*/
{
	printf("\n------------------task 16_0_3------------------\n");
	char ch = 'w';
	printf("\nch= %c", ch);
	printf("\n%s", "HI, world!");
	const char* myStrchr_chP = 0;
	myStrchr_chP = string_strchrFindFirstChar("HI, world!", ch);
	printf("\nmyStrchr_chP = %p", myStrchr_chP);
	printf("\n------------------");
	const char* originalStrchr_chP = 0;
	originalStrchr_chP = strchr("HI, world!", ch);
	printf("\noriginalStrchr_chP = %p", originalStrchr_chP);
}
void hw_16_0_4_my_strrchr_findLastChar(void)
/*
Напишете собствена версия на стандартната функция strrchr от string.h,
my_strrchr
която приема стринг и char и връща адреса на последния елемент на стринга,
който е равен на символът, подаден като аргумент. Ако символът не е
намерен, функцията връща нулев указател.
*/
{
	printf("\n------------------task 16_0_4------------------\n");
	char ch = 'w';
	printf("\nch= %c", ch);
	printf("\n%s", "HI, worldw!");
	const char* myStrrchr_chP = 0;
	myStrrchr_chP = string_strrchrFindLastChar("HI, worldw!", ch);
	printf("\nmyStrrchr_chP = %p", myStrrchr_chP);
	printf("\n%c", *myStrrchr_chP);
	printf("\n------------------");
	const char* originalStrrchr_chP = 0;
	originalStrrchr_chP = strrchr("HI, worldw!", ch);
	printf("\noriginalStrrchr_chP = %p", originalStrrchr_chP);
	printf("\n%c", *originalStrrchr_chP);
}
void hw_16_0_5_isCharUniqueInStr(void)
/*
Напишете функция
is_char_unique_in_str
която приема стринг и char и връща 1 ако символът се среща точно един път
в стринга, 0 ако не се среща или се среща повече от веднъж.
Използвайте my_strchr и my_strrchr от предходните задачи
*/
{
	printf("\n------------------task 16_0_5------------------\n");
	printf("\n%s", "Hallo, world!");
	printf("\nchar = %c", 'l');
	printf("\n%d", string_isCharUniqueInStr("Hallo, world!", 'l'));
}
void hw_16_0_6_shortenStrN(void)
/*
Напишете функция, която приема указател към низ и положително цяло число
и скъсява подадения й низ до броя на символите, указани от втория аргумент
shorten_str
Функцията не трябва да води до грешка ако са й подадени невалидни
аргументи, например:
char str[] = “hello”;
shorten_str(str, 10000);
*/
{
	printf("\n------------------task 16_0_6------------------\n");
	char str[20] = "HI, world!";
	int pos = 5;
	printf("\n%s", str);
	printf("\n%d", pos);
	string_shortenN(str, pos);
	printf("\n%s", str);
}
void hw_16_1_my_strCopy(void)
/*
Напишете собствена версия на стандартната функция strcpy от string.h със
същия интерфейс и функционалност.
char* my_strcpy(char* dest, const char* src);
Връща адреса на главния стринг, в който се копира друг стринг.
*/
{
	printf("\n------------------task 16_1------------------\n");
	const char strFrom[20] = "ab";
	char strTo[20] = "abcde";
	string_strcopy(strTo, strFrom);
	puts(strTo);
	printf("------------------\n");
	const char strFrom1[20] = "ab";
	char strTo1[20] = "abcde";
	strcpy(strTo1, strFrom1);
	puts(strTo1);
}
void hw_16_2_my_strnCopy(void)
/*
Напишете собствена версия на стандартната функция strncpy от string.h със
същия интерфейс и функционалност.
char* strncpy(char* dest, const char* src, size_t count);
Копира n символа от низ в низ.
*/
{
	printf("\n------------------task 16_2------------------\n");
	const char strFrom[20] = "abcdefghij";
	char strTo[20] = "klmnopr";
	string_strncopy_terminated(strTo, strFrom, 5);
	puts(strTo);
	printf("------------------\n");
	const char strFrom1[20] = "abcdefghij";
	char strTo1[20] = "klmnopr";
	string_strncopy(strTo1, strFrom1, 5);
	puts(strTo1);
	printf("------------------\n");
	const char strFrom2[20] = "abcdefghij";
	char strTo2[20] = "klmnopr";
	strncpy(strTo2, strFrom2, 5);
	puts(strTo2);
}
void hw_16_3_my_strCat(void)
/*
Напишете собствена версия на стандартната функция strcat от string.h със
същия интерфейс и функционалност.
char *strcat( char *dest, const char *src );
Слепва два низа и връща поинтер към първия елемент от първия низ.
*/
{
	printf("\n------------------task 16_3-------------------\n");
	char strCopyrTo1[256] = "HI, ";
	const char strCopyFrom1[256] = "HI, world!";
	const char* chP1 = 0;
	printf("\nstrCopyrTo: %s", strCopyrTo1);
	printf("\nstrCopyFrom: %s\n", strCopyFrom1);
	chP1 = string_strcat(strCopyrTo1, strCopyFrom1);
	printf("\nstrCopyrTo: %s", strCopyrTo1);
	printf("\nchP = %s", chP1);
	printf("\n------------------");
	char strCopyrTo2[256] = "HI, ";
	const char strCopyFrom2[256] = "HI, world!";
	const char* chP2 = 0;
	chP2 = strcat(strCopyrTo2, strCopyFrom2);
	printf("\nstrCopyrTo: %s", strCopyrTo2);
	printf("\nchP = %s", chP2);
}
void hw_16_4_my_strnCat(void)
/*
Напишете собствена версия на стандартната функция strncat от string.h със
същия интерфейс и функционалност.
char *strncat( char *dest, const char *src, size_t count );
Залепва n символа от низ в края на дриг низ, връща поинтер към началото на слепения низ.
*/
{
	printf("\n------------------task 16_4------------------\n");
	char strTo1[256] = "HI, world!";
	const char strFrom1[256] = "HI, world!";
	const char* chP1 = 0;
	printf("\nstrTo: %s", strTo1);
	printf("\nstrFrom: %s", strFrom1);
	chP1 = string_strncat(strTo1, strFrom1, 2);
	printf("\nstrTo: %s", strTo1);
	printf("\nchP1 = %p", chP1);
	printf("\nchP1 = %s", chP1);
	printf("\n------------------");
	char strTo2[256] = "HI, world!";
	const char strFrom2[256] = "HI, world!";
	const char* chP2 = 0;
	printf("\nstrTo: %s", strTo2);
	printf("\nstrFrom: %s", strFrom2);
	chP2 = strncat(strTo2, strFrom2, 2);
	printf("\nstrTo: %s", strTo2);
	printf("\nchP2 = %p", chP2);
	printf("\nchP2 = %s", chP2);
}
void hw_16_5_my_strnCmp(void)
/*
Напишете собствена версия на стандартната функция strncmp от string.h със
същия интерфейс и функционалност.
int strncmp( const char *lhs, const char *rhs, size_t count );
Сравнява определен брой символи от два низа, връща 0, ако са еднакви, >0 - ако първия е по-голям и <0 - ако втория е по-голям.
*/
{
	printf("\n------------------task 16_5------------------\n");
	const char str11[256] = "HI, m";
	const char str12[256] = "HI, morning!";
	printf("\nstr1: %s", str11);
	printf("\nstr2: %s", str12);
	printf("\nCompare to position %d - %d", 4, string_strncmp(str11, str12, 4));
	printf("\nCompare to position %d - %d", 5, string_strncmp(str11, str12, 5));
	printf("\nCompare to position %d - %d", 6, string_strncmp(str11, str12, 6));
	printf("\n------------------");
	const char str31[256] = "HI, m";
	const char str32[256] = "HI, morning!";
	printf("\nstr1: %s", str31);
	printf("\nstr2: %s", str32);
	printf("\nCompare to position %d - %d", 4, string_strncmp_includeNULL(str31, str32, 4));
	printf("\nCompare to position %d - %d", 5, string_strncmp_includeNULL(str31, str32, 5));
	printf("\nCompare to position %d - %d", 6, string_strncmp_includeNULL(str31, str32, 6));
	printf("\n------------------");
	const char str21[256] = "HI, m";
	const char str22[256] = "HI, morning!";
	printf("\nstr1: %s", str21);
	printf("\nstr2: %s", str22);
	printf("\nCompare to position %d - %d", 4, strncmp(str21, str22, 4));
	printf("\nCompare to position %d - %d", 5, strncmp(str21, str22, 5));
	printf("\nCompare to position %d - %d", 6, strncmp(str21, str22, 6));
}
void hw_16_6_my_StrStr(void)
/*
Напишете собствена версия на стандартната функция strstr от string.h със
същия интерфейс и функционалност.
char *strstr( const char* str, const char* substr );
Връща адреса на първия символ в глсвния стринг, ако е намерил подсстринга или връща 0, ако не го е намерил.
*/
{
	printf("\n------------------task 16_6-------------------\n");
	const char str11[256] = "HI, world!";
	const char str12[256] = "rl";
	printf("\nstrSearchIn: %s", str11);
	printf("\nstrFind: %s", str12);
	printf("\n%d", string_searchStrInStr(str11, str12));
	printf("\nAdress of position - %p", string_strstr(str11, str12));
	printf("\nAdress of index 6 - %p", &str11[6]);
	printf("\n------------------");
	const char str21[256] = "HI, world!";
	const char str22[256] = "rl";
	printf("\nstrSearchIn: %s", str21);
	printf("\nstrFind: %s", str22);
	printf("\n%d", string_searchStrInStr(str21, str22));
	printf("\nAdress of position - %p", strstr(str21, str22));
	printf("\nAdress of index 6 - %p", &str21[6]);
}
void hw_16_7_searchCharArrInCharMatrix(void)
/*
Напишете функция, която връща общия брой на срещанията на всички стрингове
от подаден масив от стрингове в двуизмерен масив от char, по редове и колони.
Пример:
● { “cat”, “bat”, “hat”, “bit” }
● c a t h b a t
  x r a t i j k
  f s q y t k u
● Резултат: 3
*/
{
	printf("\n------------------task 16_7------------------\n");
	const char matrix[3][7] = {
						{'c','a','t','h','b','a','t'},
						{'a','r','a','t','i','j','k'},
						{'t','s','q','y','t','k','u'},
	};
	int rows = 3;
	int cols = 7;
	const char* arr[4] = { "cat", "bat", "hat", "bit" };
	int count[4] = { 0 };
	int arrSize = 4;
	io_matrixCharPrint(*matrix, rows, cols);
	int* pCount = count;
	for (int i = 0; i < arrSize; ++i, ++pCount)
	{
		*pCount = martix_searchCharArrInCharMatrix(*matrix, rows, cols, arr[i]);
		printf("\n%s - %d", arr[i], count[i]);
	}
}
void hw_16_8_extract_substr(void)
/*
Напишете функция, която връща подстринг от стринг по подадени индекси за начало
и край
char* extract_substr(const char* str, size_t idx_from, size_t idx_to, char result[])
Копира стринг в стринг от определени начална и крайна позиция.
*/
{
	printf("\n------------------task 16_8------------------\n");
	const char strFrom[20] = "Hello, world!";
	char strTo[20] = { 0 };
	int iFrom = 2;
	int iTo = 5;
	puts(strFrom);
	printf("\nbegin pos: %d", iFrom);
	printf("\nend pos: %d", iTo);
	puts("\n");
	puts(string_extractSubstr(strFrom, iFrom, iTo, strTo));
}
void hw_16_9_isSortedLexically_str(void)
/*
Напишете функция, която проверява дали един масив от стрингове е сортиран
лексикографски.
*/
{
	printf("\n------------------task 16_9------------------\n");
	const char* str[5] = { "aaaa", "fbbbbb", "cccccc", "ddd", "eeeeee" };
	int size = 5;
	for (int i = 0; i < size; i++)
	{
		puts(str[i]);
	}
	if (string_isSortedLexically(str, size))
	{
		printf("String is sorded lexically!");
	}
	else
	{
		printf("String is not sorded lexically!");
	}
}
void hw_16_10_printSubstring(void)
/*
Напишете функция, която принтира на отделни редове всички подстрингове в подаден стринг,
разделени от символите, подадени във втори стринг.
void print_str_tokens(const char* str, const char * delimiters);
Пример:
print_str_tokens(“hello,hi, bye byee_12-3”, “”);
Резултат:
hello
hi
bye
byee
12-3
*/
{
	printf("\n------------------task 16_10------------------\n");
	const char str[] = ",,,hello, hi, bye byee_12-3";
	const char delimiters[] = "_ ,";
	const char* p = str;
	print_str_tokens(p, delimiters);
}
