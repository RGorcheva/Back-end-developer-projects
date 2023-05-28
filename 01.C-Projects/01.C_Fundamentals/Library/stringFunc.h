#ifndef STRINGFUNC_H
#define STRINGFUNC_H

#include <stdlib.h>
#include <stdio.h>

char		string_replaceCharToChar(char* arr, char oldCh, char newCh);						//replace every old char with other new char in string.
void		string_callmify(char* str);															//replace every r'.' with '!' in string.	

size_t		string_strlen(const char* str);														//return number of symbols in str without terminated null.
void		string_shortenFirstWhitespace(char* str);											//shorten str to first whitespase.
void		string_shortenN(char* str, unsigned short n);										//shorten sttr to index n.

void		string_copyStrToStr(const char* sFrom, char* sTo);
void		string_copyBackwards(const char* str, char* rStr);
void		string_reverse(char* arr);
char*		string_strcopy(char* destination, const char* source);
char*		string_strncopy(char* destination, const char* source, size_t n);
char*		string_strCopySubstrInStr(const char* source, char* destinationStart);				//copy sourse in str with pointer to begin position in str
char*		string_strncopy_terminated(char* destination, const char* source, size_t n);
char*		string_strcat(char* strCopyrTo, const char* strCopyFrom);									//concatenate two strings
char*		string_strncat(char* strCopyrIn, const char* strCopy, size_t count);						//concatenate first string woth count symbols of second string.
char*		string_extractSubstr(const char* str, size_t idx_from, size_t idx_to, char* result);
char*		string_extractSubstrPtr(const char* from, const char* to, char* result);

int			string_countSymbols(const char* str, char c);
int			string_countPunct(const char* str);
int			string_countSubstrings(const char* strSearchIn, const char* strFind);
int			string_countRows(const char* str);
int			string_countWords(const char* str);
void		string_countWordsAppear(char* str);

const char* string_strstr(const char* strSearchIn, const char* strFind);
int			string_searchStrInStr(const char* strSearchIn, const char* strFind);
char*		string_findFirstAppear(const char* str, const char* sub);
char*		string_find_word_start(char* str);
char*		string_find_word_end(char* str);
const char* string_searchLongestWord(const char* str);
char*		string_find_number_start(char* str);
char*		string_find_number_end(char* str);

int			string_isCharUniqueInStr(const char* str, char ch);
int			string_strcmp(const char* str1, const char* str2);
int			string_strncmp(const char* str1, const char* str2, size_t count);
int			string_strncmp_includeNULL(const char* str1, const char* str2, size_t count);

char*		string_strchrFindFirstChar(const char* str, char c);
int			string_findFirstCharIndex(const char* str, char c);
char*		string_strrchrFindLastChar(const char* str, char c);
const char* string_findSubstringStart(const char* str, const char* delimiters);
const char* string_findSubstringEnd(const char* str, const char* delimiters);

void		string_matrixFillChar(char* arr, int row, int col, char c);
int			string_isMail(const char* mail);
int			string_isPalindrome(const char* str);
int			string_isSortedLexically(const char* str[], int size);

char* string_multipleNumbersBy2(char* str);


#endif