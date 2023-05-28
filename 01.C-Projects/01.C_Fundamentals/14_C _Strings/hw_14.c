#include "hw_14.h"
#include "../Library/inputOutputFunc.h"
#include "../Library/arrayFunc.h"
#include "../Library/stringFunc.h"
#include "../library/mathFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hw_14_0_1_myStrlen(void)
/*
Напишете собствена версия на стандартната функция strlen от string.h
my_strlen
която връща стойност от тип size_t - дължината подадения й стринг, без да
брои терминиращия символ.
Тествайте с литерала и с null-терминиран масив от char
*/
{
	printf("\n----------------task 14_0_1------------------\n");
	size_t sizeArr = 0;
	size_t sizeStr = 0;
	const char arr[] = "Hallo!";
	sizeArr = string_strlen(arr);
	sizeStr = string_strlen("Hallo!");

	printf("\nMy Arrsize = %d", (int)sizeArr);
	printf("\nMy Strsize = %d", (int)sizeStr);
	printf("\nArrsize = %d", (int)strlen(arr));
	printf("\nStrsize = %d", (int)strlen("Hallo!"));
}
void hw_14_0_3_myStrChr(void)
/*
Напишете собствена версия на стандартната функция strchr от string.h,
my_strchr
която приема стринг и char и връща адреса на първия елемент на стринга,
който е равен на символът, подаден като аргумент. Ако символът не е
намерен, функцията връща нулев указател. Функцията трябва да може да
работи и с ‘\0’ като втори аргумент.
*/
{
	printf("\n----------------task 14_0_3------------------\n");
	const char str[20] = "HI, world!";
	char ch = 'w';
	const char* chP = 0;
	chP = string_strchrFindFirstChar(str, ch);
	printf("\n%s", str);
	printf("\nch= %c", ch);
	printf("\nstr[4] = %p", &str[4]);
	printf("\nchP = %p", chP);
	printf("\n----------------\n");
	chP = strchr(str, ch);
	printf("\nchP = %p", chP);

}
void hw_14_1_reverseString(void)
/*
Напишете функция, която обръща c string наобратно, използвайки само
адресна аритметика. Принтирайте оригиналния и обърнатия стринг един под
друг.
*/
{
	printf("\n----------------task 14_1------------------\n");
	const char str[] = "That's what!";
	char rStr[] = "That's what!";
	string_copyBackwards(str, rStr);
	printf("\nstr: %s", str);
	printf("\nReversed str: %s", rStr);
}
void hw_14_2_isPalindrome(void)
/*
Напишете функция, която проверява дали подаденият й стринг е палиндром
(редът на буквите от ляво надясно е същият като от дясно на ляво)
*/
{
	printf("\n----------------task 14_2------------------\n");
	char str[] = "rotator";
	printf("\n%s", str);
	if (string_isPalindrome(str))
	{
		printf("\n%s is palindrome!", str);
	}
	else
	{
		printf("\n%s is NOT palindrome!", str);
	}
}
void hw_14_3_replaceLowLetters(void)
/*
Напишете функция calmify_str, която заменя всички малки букви с главни и
всички точки с удивителни в подадения й стринг.
*/
{
	printf("\n----------------task 14_3------------------\n");
	char str[] = "Hello. 123.";
	printf("\n%s", str);
	string_callmify(str);
	printf("\n%s", str);
}
void hw_14_4_shortenStr(void)
/*
Напишете функция, която скъсява подадения й стринг до първия whitespace.
*/
{
	printf("\n----------------task 14_4------------------\n");
	char str[] = "Hello. 123.";
	printf("\n%s", str);
	string_shortenFirstWhitespace(str);
	printf("\n%s", str);
}
void hw_14_5_countChar(void)
/*
Напишете функция, която приема стринг и char символ и връща броя на
срещанията на символа в стринга.
*/
{
	printf("\n----------------task 14_5------------------\n");
	const char str[] = "Hello. World! 123.";
	char ch = 'l';
	int countChar = -1;

	printf("\n%s", str);
	countChar = string_countSymbols(str, ch);
	printf("\nSymbol %c exist %d times in string.", ch, countChar);
}
void hw_14_6_searchStrInStr(void)
/*
Напишете функция, която приема два стринга и претърсва за втория в
първия. Ако го намери - връща индекса на символа, от който започва
подстринга в стринга. Ако не го намери, връща: -1
*/
{
	printf("\n----------------task 14_6------------------\n");
	const char strSearchIn[] = "a.Hello. 123.";
	const char strFind[] = "123";
	printf("\n%s", strSearchIn);
	printf("\n%s", strFind);
	printf("\n%d", string_searchStrInStr(strSearchIn, strFind));
}
void hw_14_7_strInStrCounter(void)
/*
Напишете функция, която приема два стринга и връща число - колко пъти се
среща втория стринг в първия
*/
{
	printf("\n----------------task 14_7------------------\n");
	const char strSearchIn[] = "a123.Hello. 123.chdffj123cncgmmh123 h";
	const char strFind[] = "123";
	printf("\n%s", strSearchIn);
	printf("\n%s", strFind);
	printf("\n%d", string_countSubstrings(strSearchIn, strFind));
}
void hw_14_8_isMail(void)
/*
Напишете функция, която връща дали даден стринг е валиден email адрес.
*/
{
	printf("\n----------------task 14_8------------------\n");
	char mail[50] = { 0 };
	printf("Enter email!\n");
	scanf_s("%s", mail, 50);
	printf("\n%d", string_isMail(mail));
}
void hw_14_9_countRows(void)
/*
Напишете функция, която брои броя на редовете в един multi-line стринг
(стринг, който е на няколко реда)
*/
{
	printf("\n----------------task 14_9------------------\n");
	char str[] = "Hello. World! 123.\ntsbdbhs jfsdu sdjffis dsij.\nhdfubwu nchdu dhu.\n";
	int countRows = -1;

	printf("\n%s", str);
	countRows = string_countRows(str);
	printf("\nThere are %d lines in the string.", countRows);
}
void hw_14_10_myStrcmp(void)
/*напишете собствена версия на стандартната функция strcmp от string.h
my_strcmp
която сравнява два стринга и връща:
● 0 ако са еднакви
● стойност, по - голяма от 0 ако първият стринг е “по - голям”(ако първата
различна буква има по - голяма целочислена стойност).
● стойност, по - малка от 0 ако вторият стринг е “по - голям”.
*/
{
	printf("\n----------------task 14_10------------------\n");
	const char str1[] = "123abcderahf";
	const char str2[] = "123abcde";
	int areEquals = 0;

	printf("\n%s", str1);
	printf("\n%s", str2);
	areEquals = string_strcmp(str1, str2);
	printf("\n%d", areEquals);
}
void hw_14_11_countWordsInStr(void)
/*
Напишете фунцкия, която приема стринг и принтира броя на срещанията на всяка дума
от стринга.
*/
{
	printf("\n----------------task 14_11------------------\n");
	char str[] = "How are you today, how were you yesterday?";
	printf("\n%s", str);
	string_countWordsAppear(str);
}
void hw_14_12_searchLongestWord(void)
/*
Напишете фунцкия, която приема стринг и връща указател към началото на
най-дългата дума, която намери в стринга
*/
{
	printf("\n----------------task 14_12------------------\n");
	const char str[] = "The longest word, I ever know!";
	const char* theLongestWord = '\0';
	printf("\n%s", str);
	theLongestWord = string_searchLongestWord(str);
	printf("\nThe longest word is \t%s", theLongestWord);
	printf("\nThe longest word pointer is %p", theLongestWord);
}
