#include "stringFunc.h"
#include "mathFunc.h"
#include <string.h>
#include <ctype.h>


char		string_replaceCharToChar(char *arr, char oldCh, char newCh)
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
void		string_callmify(char* str)
{
	for (char* p = str; *p != '\0'; ++p)
	{
		*p = toupper(*p);
		if (*p == '.')
		{
			*p = '!';
		}
	}
}

size_t		string_strlen(const char* str)
{
	size_t count = 0;
	for (const char* c = str; *c != '\0'; ++c)
	{
		++count;
	}
	return count;
}
void		string_shortenFirstWhitespace(char* str)
{
	for (char* p = str; *p != '\0'; ++p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			break;
		}
	}
}
void		string_shortenN(char* str, unsigned short n)
{
	if (strlen(str) <= n)
	{
		return;
	}
	*(str + n) = '\0';
}

void		string_copyStrToStr(const char* sFrom, char* sTo)
{
	for (; *sFrom != '\0'; ++sFrom, ++sTo)
	{
		*sTo = *sFrom;
	}
}
void		string_copyBackwards(const char* str, char* rStr)
{
	int lenght = (int)string_strlen(str);
	char* rp = rStr;
	for (const char* p = str + lenght - 1; p >= str; --p, ++rp)
	{
		*rp = *p;
	}
	*rp = '\0';
}
void		string_reverse(char* str)
{
	int lenght = (int)string_strlen(str);
	char c = 0;
	for (char* p = str, *rp = str + lenght - 1; p < rp; ++p, --rp)
	{
		c = *p;
		*p = *rp;
		*rp = c;
	}
}
char*		string_strcopy(char* destination, const char* source)
{
	int lenSource = (int)strlen(source);
	const char* pFrom = source;
	char* pTo = destination;
	for (; (pFrom <= source + lenSource) && (pFrom != NULL); pTo++, pFrom++)
	{
		*pTo = *pFrom;
	}
	*pTo = '\0';
	return destination;
}
char*		string_strncopy(char* destination, const char* source, size_t n)
{
	int lenSource = (int)strlen(source);
	const char* pFrom = source;
	char* pTo = destination;
	for (; (pFrom <= source + n - 1) && (pFrom != 0); pTo++, pFrom++)
	{
		*pTo = *pFrom;
	}
	return destination;
}
char*		string_strCopySubstrInStr(const char* source, char* destinationStart)
{
	int sourceLen = (int)strlen(source);
	char* pFrom = destinationStart;
	const char* pSource = source;
	for (; pFrom < destinationStart + sourceLen; pFrom++, pSource++)
	{
		*pFrom = *pSource;
	}
	return destinationStart;
}
char*		string_strncopy_terminated(char* destination, const char* source, size_t n)
{
	int lenSource = (int)strlen(source);
	const char* pFrom = source;
	char* pTo = destination;
	for (; (pFrom <= source + n - 1) && (pFrom != 0); pTo++, pFrom++)
	{
		*pTo = *pFrom;
	}
	*pTo = '\0';
	return destination;
}
char*		string_strcat(char* strCopyrIn, const char* strCopy)
{
	char* pNull = string_strchrFindFirstChar(strCopyrIn, '\0');
	const char* pStrCopy = strCopy;
	for (; *pStrCopy != '\0'; ++pStrCopy, ++pNull)
	{
		*(pNull) = *(pStrCopy);
	}
	return strCopyrIn;
}
char*		string_strncat(char* strCopyrIn, const char* strCopy, size_t count)
{
	char* pNull = string_strchrFindFirstChar(strCopyrIn, '\0');
	const char* pStrCopy = strCopy;
	for (; (pStrCopy < strCopy + count) && (strCopy != 0); ++pStrCopy, ++pNull)
	{
		*(pNull) = *(pStrCopy);
	}
	*(pNull) = '\0';
	return strCopyrIn;
}

char*		string_extractSubstr(const char* str, size_t from, size_t to, char* result)
{
	int iter = 0;
	for (; from + iter < to; ++iter)
	{
		result[iter] = str[from + iter];
	}
	result[from + iter] = '\0';
	return result;
}
//extract substring from index to index in first string
char*		string_extractSubstrPtr(const char* from, const char* to, char* result)
{
	int iter = 0;
	for (; from + iter < to; ++iter)
	{
		*(result + iter) = *(from + iter);
	}
	*(result + iter) = '\0';
	return result;
}
//extract substring from pointer to pointer in first string

int			string_countSymbols(const char* str, char c)
{
	int countCh = 0;
	for (const char* p = str; *p != '\0'; ++p)
	{
		if (*p == c)
		{
			++countCh;
		}
	}
	return countCh;
}
int			string_countPunct(const char* str)
{
	int countPunct = 0;
	for (const char* p = str; *p != '\0'; ++p)
	{
		if (ispunct(*p))
		{
			++countPunct;
		}
	}
	return countPunct;
}
int			string_countSubstrings(const char* strSearchIn, const char* strFind)
{
	int countExist = 0;
	for (int i = 0; strSearchIn[i]; ++i)
	{
		int j = 0;
		for (; strFind[j]; ++j)
		{
			if (tolower(strFind[j]) != tolower(strSearchIn[i + j]))
			{
				break;
			}
		}
		if (!strFind[j])
		{
			++countExist;
		}
	}
	return countExist;
}
int			string_countRows(const char* str)
{
	int i = 0;
	int countN = 0;
	for (; str[i] != '\0'; ++i)
	{
		if (str[i] == '\n')
		{
			++countN;
		}
	}
	if (str[0] == '\n')
	{
		--countN;
	}
	if (str[i - 1] == '\n')
	{
		return countN;
	}
	else
	{
		return countN + 1;
	}
}
int			string_countWords(const char* str)
{
	int numLettersInWord = 0;
	int numWords = 0;
	for (const char* p = str; *p != '\0'; ++p)
	{
		if (isalpha(*p))
		{
			if (numLettersInWord == 0)
			{
				++numWords;
			}
			++numLettersInWord;
		}
		else
		{
			numLettersInWord = 0;
		}
	}
	return numWords;
}
void		string_countWordsAppear(char* str)
{
	char word[10] = { 0 };
	char* pStr = str;
	char* startWord = NULL;
	char* endWord = NULL;

	for (; *pStr != '\0'; ++pStr)
	{
		*pStr = tolower(*pStr);
	}
	pStr = str;
	for (; *pStr != '\0';)
	{
		pStr = string_find_word_start(pStr);
		startWord = pStr;
		if (startWord == NULL) break;
		if (*pStr != '\0')
		{
			pStr = string_find_word_end(pStr);
			endWord = pStr;
			string_extractSubstrPtr(startWord, endWord, word);
			int countWordsAppear = string_countSubstrings(str, word);
			char* firstAppear = string_findFirstAppear(str, word);
			if (startWord == firstAppear)
			{
				printf("\n%s - %d", word, countWordsAppear);
			}
		}
	}
}

const char* string_strstr(const char* strSearchIn, const char* strFind)
{
	const char* pSearchIn = strSearchIn;
	const char* pFind = strFind;
	for (; *pSearchIn != '\0'; ++pSearchIn)
	{
		const char* pIn = pSearchIn;
		for (; *pFind != '\0'; ++pFind, ++pIn)
		{
			if (*pFind != *pIn)
			{
				break;
			}
		}
		if (*pFind == '\0')
		{
			return pSearchIn;
		}
	}
	return 0;
}
//finds pointer to the first appearance of substring  in string
char* string_findFirstAppear(const char* str, const char* sub)
{
	for (int i = 0; *(str + i) != '\0'; ++i)
	{
		int j = 0;
		for (; *(sub + j) != '\0'; ++j)
		{
			if (*(sub + j) != *(str + i + j))
			{
				break;
			}
		}
		if (*(sub + j) == '\0')
		{
			return (char*)str + i;
		}
	}
	return NULL;
}
//finds pointer to the first appearance of substring  in string
int			string_searchStrInStr(const char* strSearchIn, const char* strFind)
{
	for (int i = 0; strSearchIn[i] != '\0'; ++i)
	{
		int j = 0;
		for (; strFind[j] != '\0'; ++j)
		{
			if (strFind[j] != strSearchIn[i + j])
			{
				break;
			}
		}
		if (!strFind[j])
		{
			return i;
		}
	}
	return -1;
}
//finds index to the first appearance of substring  in string
char*		string_find_word_start(char* str)//търсим начало на дума
{
	for (char* st = str; *st != '\0'; st++)
	{
		if (isalpha(*st))
		{
			return st;
		}
	}
	return NULL;
}
char*		string_find_word_end(char* str)//търсим края на дума, връща поинтер към първи символ различен от буква
{
	char* st = str;
	for (; *st != '\0'; st++)
	{
		if (!isalpha(*st))
		{
			return st;
		}
	}
	return st;
}
const char* string_searchLongestWord(const char* str)
{
	int saveMaxLetters = 0;
	const char* maxLeterP = 0;
	int countLetters = 0;
	const char* p = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (isalpha(str[i]))
		{
			if (!countLetters)
			{
				p = &str[i];
			}
			++countLetters;
		}
		else if (isspace(str[i]) || ispunct(str[i]))
		{
			if (saveMaxLetters < countLetters)
			{
				saveMaxLetters = countLetters;
				maxLeterP = p;
			}
			countLetters = 0;
		}
	}
	return maxLeterP;
}
char*		string_find_number_start(char* str)//търсим начало на дума
{
	for (char* st = str; *st != '\0'; st++)
	{
		if (isdigit(*st))
		{
			return st;
		}
	}
	return 0;
}
char*		string_find_number_end(char* str)//търсим края на число, връща поинтер към първи символ различен от цифра
{
	char* st = str;
	for (; *st != '\0'; st++)
	{
		if (!isdigit(*st))
		{
			return st;
		}
	}
	return st;
}

int			string_isCharUniqueInStr(const char* str, char ch)
{
	const char* chFirst = string_strchrFindFirstChar(str, ch);
	const char* chLast = string_strrchrFindLastChar(str, ch);
	if ((chFirst == chLast) && (chFirst))
	{
		return 1;
	}
	return 0;
}
int			string_strcmp(const char* str1, const char* str2)
{
	const char* pStr1 = str1;
	const char* pStr2 = str2;
	int isEqual = 0;
	int maxSize = math_maxInt((int)strlen(str1), (int)strlen(str2));
	for (int i = 0; i < maxSize; ++i)
	{
		if (!(isEqual = str1[i] - str2[i]))
		{
			continue;
		}
		else
		{
			return isEqual;
		}
	}
	return 0;
}
//compare two strings. Return 0 if strings are equal, >0 if the first is 'bigger' and < if the first is 'smaller.ASCI table
int			string_strncmp(const char* str1, const char* str2, size_t count)
{
	int isEqual = 0;
	for (const char* pStr1 = str1, *pStr2 = str2; pStr1 < str1 + count; pStr1++, pStr2++)
	{
		if (isEqual = *pStr1 - *pStr2)
		{
			return isEqual;
		}
	}
	return 0;
}
//compare two strings to symbol n.
int			string_strncmp_includeNULL(const char* str1, const char* str2, size_t count)
{
	int isEqual = 0;
	for (const char* pStr1 = str1, *pStr2 = str2; pStr1 <= str1 + count; pStr1++, pStr2++)
	{
		if (isEqual = *pStr1 - *pStr2)
		{
			return isEqual;
		}
	}
	return 0;
}

char*		string_strchrFindFirstChar(const char* str, char c)
{
	int lenght = (int)strlen(str);

	for (const char* p = str; p <= str + lenght; ++p)
	{
		if (*p == c)
		{
			return (char*)p;
		}
	}
	return NULL;
}
//finds pointer to the first appearance of symbol in string
int			string_findFirstCharIndex(const char* str, char c)
{
	int lenght = (int)strlen(str);

	for (const char* p = str; p <= str + lenght - 1; ++p)
	{
		if (*p == c)
		{
			return 1;
		}
	}
	return 0;
}
//finds index to the first appearance of symbol in string
char*		string_strrchrFindLastChar(const char* str, char c)
{
	int lenght = (int)strlen(str);
	for (const char* p = str + lenght; p >= str; --p)
	{
		if (*p == c)
		{
			return (char*)p;
		}
	}
	return 0;
}
const char* string_findSubstringStart(const char* str, const char* delimiters)
///търсим начало на подстринг
{
	for (const char* st = str; *st != '\0'; st++)
	{
		for (const char* del = delimiters; *del != '\0'; del++)
		{
			if (!string_findFirstCharIndex(delimiters, *st))

			{
				return st;
			}
		}
	}
	return 0;
}
//finds pointer to the first symbol of substring in string, separated by delimiters
const char* string_findSubstringEnd(const char* str, const char* delimiters)
////търсим края на подстринг, връща поинтер към първи разделящ символ
{
	const char* st = str;
	for (; *st != '\0'; st++)
	{
		for (const char* del = delimiters; *del != '\0'; del++)
		{
			if (*st == *del)
			{
				return st;
			}
		}
	}
	return st;
}
//finds pointer to the last symbol of substring in string, separated by delimiters. Return first delimiter after the substring.

void		string_matrixFillChar(char* arr, int row, int col, char c)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%c\t", c);
		}
		printf("\n");
	}
}
int			string_isMail(const char* mail)
{
	const char* posAt = 0;
	const char* posDot = 0;
	int countAt = 0;
	int countSymbols = 0;

	for (const char* p = mail; *p != '\0'; ++p) // Търсим ппоследната позиция, на която има "@".
	{
		if (*p == '@')
		{
			posAt = p;
			++countAt;
		}
		if (*p == '.')
		{
			posDot = p;
		}
	}
	if ((countAt != 1) || (posDot - posAt < 0)) // Търсим само едно "@" и да има "." след него. 
	{
		return 0;
	}
	if (!(isalpha(*mail)))  // Да започва с буква
	{
		return 0;
	}
	for (const char* p = mail; p < posAt; ++p) // Да съдържа малки латиски букви, цифри и символите '.', '_','-'.
	{
		if (isalpha(*p) || isdigit(*p) || *p == '.' || *p == '-' || *p == '_')
		{
			++countSymbols;
		}
		else
		{
			return 0;
		}
	}
	if (!(3 <= countSymbols && countSymbols <= 30)) // Да съдържа между 3 и 30 символа преди домейна
	{
		return 0;
	}
	countSymbols = 0;
	for (const char* p = posAt + 1; p < posDot; ++p) // Домейна да съдържа малки латински букви, цифри или '-' преди '.'
	{
		if (isalpha(*p) || isdigit(*p) || *p == '-')
		{
			++countSymbols;
		}
		else
		{
			return 0;
		}
	}
	if (countSymbols < 3) // Да съдържа минимум 3 символа преди '.'
	{
		return 0;
	}
	countSymbols = 0;
	for (const char* p = posDot + 1; *p != '\0'; ++p) // Разширението да съдържа малки латински букви, цифри
	{
		if (isalpha(*p) || isdigit(*p))
		{
			++countSymbols;
		}
		else
		{
			return 0;
		}
	}
	if (countSymbols < 2) // Да съдържа минимум 2 символа след '.'
	{
		return 0;
	}
	return 1;
}
int			string_isPalindrome(const char* str)
{
	int countEquals = 0;
	int lenght = (int)string_strlen(str);
	for (const char* p = str, *rp = str + lenght - 1; p < str + lenght / 2; ++p, --rp)
	{
		if (*p != *rp)
		{
			return 0;
		}
	}
	return 1;
}
int			string_isSortedLexically(const char* str[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (*(str[i]) > *(str[i + 1]))
		{
			return 0;
		}
	}
	return 1;
}

char* string_multipleNumbersBy2(char* str)
{
	//char str[256] = "Here you can 100 find activities to practise your reading skills.\n"
	//	"Reading will help you to improve your 555 understanding of the\n"
	//	"language and 500 build your vocabulary.\n";

	//printf("\n%s", str);

	char* pStr = str;
	char chNumber[10] = { 0 };
	char chResult[10] = { 0 };
	char* pStart = NULL;
	char* pEnd = NULL;
	for (; *pStr != '\0';)
	{
		pStr = string_find_number_start(pStr);
		if (pStr == NULL) break;
		pStart = pStr;
		if (*pStr != '\0')
		{
			pStr = string_find_number_end(pStr);
			pEnd = pStr;
			string_extractSubstrPtr(pStart, pEnd, chNumber);
			int iNumber = atoi(chNumber);
			int iResult = 2 * iNumber;
			_itoa(iResult, chResult, 10);
			int translation = (int)strlen(chResult) - (int)strlen(chNumber);
			if (translation > 0)
			{
				int strLen = (int)strlen(pEnd);
				char* it = pEnd + strLen - translation;
				for (; it >= pEnd; it--)
				{
					*(it + translation) = *it;

				}
				pStr++;
			}
			string_strCopySubstrInStr(chResult, pStart);
		}
	}
	//printf("\n%s", str);
	return str;
}





