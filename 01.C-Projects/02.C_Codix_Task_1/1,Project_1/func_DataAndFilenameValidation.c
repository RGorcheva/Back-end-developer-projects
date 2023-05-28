#define _CRT_SECURE_NO_WARNINGS
#include "func_DataAndFilenameValidation.h"
#include "func_FileNameEdit.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "configMacro.h"

char* apstrCurrency[] = { "BGN", "USD", "EUR", "RSD", "TND" };

//Checks if a given year is a leap year.
//Input parameters of the function is unsigned int choosen year.
//The function returns TRUE if the year is a leap year.
static _Bool isLeapYear(const unsigned uiYear)
{
	if (((uiYear % 4 == 0) && (uiYear % 100 != 0)) || (uiYear % 400 == 0))
		return TRUE;
	else
		return FALSE;
}

//The function checks that the date and time in the file name are valid.
//The function accepts as a parameter a constant pointer to the file name.
//The function returns TRUE if it successfully validates the date and time from the filename
static _Bool isDateInStringValid(const char* pcFileName) 
{
	unsigned uiYear;
	unsigned uiMonth;
	unsigned uiDay;
	unsigned uiHour;
	unsigned uiMinute;
	unsigned uiSecond;
	const unsigned uiMin_Year = 1900;
	const unsigned uiMax_Year = 2200;
	const unsigned uiMax_Hour = 23;
	const unsigned uiMax_Minute_Sec = 59;
	const unsigned uiMin_Month_Day = 1;
	const unsigned uiMax_Month = 12;
	unsigned uiMax_Day = 31;

	if (pcFileName == NULL)
	{
		return FALSE;
	}
	if (sscanf(pcFileName, STR_FULL_FILENAME_PATTERN, &uiYear, &uiMonth, &uiDay, &uiHour, &uiMinute, &uiSecond) != 6)
	{
		return FALSE;
	}
	if (uiMonth == 2)
	{
		_Bool bResult = isLeapYear(uiYear);
		if (bResult)
		{
			uiMax_Day = 29;
		}
		else
		{
			uiMax_Day = 28;
		}
	}
	if (uiYear < uiMin_Year || uiYear > uiMax_Year)
	{
		return FALSE;
	}
	if (uiMonth < uiMin_Month_Day || uiMonth > uiMax_Month)
	{
		return FALSE;
	}
	if (uiDay < uiMin_Month_Day || uiDay > uiMax_Day)
	{
		return FALSE;
	}
	if (uiHour > uiMax_Hour)
	{
		return FALSE;
	}
	if (uiMinute > uiMax_Minute_Sec)
	{
		return FALSE;
	}
	if (uiSecond > uiMax_Minute_Sec)
	{
		return FALSE;
	}
	return TRUE;
}

//The function validates the date from the contents of file with /%2d%2d%4d/ pattern
//The function accepts a string pointer
// The function returns TRUE if it successfully validates the date from the contents of file
_Bool isDateValid(const char* strDate)
{
	unsigned uiYear;
	unsigned uiMonth;
	unsigned uiDay;
	const unsigned uiMinYear = 1900;
	const unsigned uiMaxYear = 2200;
	const unsigned uiMinMonthDay = 1;
	const unsigned uiMaxMonth = 12;
	unsigned uiMaxDay = 31;
	if (strDate == NULL)
	{
		return FALSE;
	}
	if (sscanf(strDate, STR_FILEDATA_PATTERN_DATE, &uiDay, &uiMonth, &uiYear) != 3)
	{
		return FALSE;
	}
	if (uiMonth == 2)
	{
		_Bool bResult = isLeapYear(uiYear);
		if (bResult)
		{
			uiMaxDay = 29;
		}
		else
		{
			uiMaxDay = 28;
		}
	}
	if (uiYear < uiMinYear || uiYear > uiMaxYear)
	{
		return FALSE;
	}
	if (uiMonth < uiMinMonthDay || uiMonth > uiMaxMonth)
	{
		return FALSE;
	}
	if (uiDay < uiMinMonthDay || uiDay > uiMaxDay)
	{
		return FALSE;
	}
	return TRUE;
}

//The function checks if a file name starts with this pattern "IMPORT_INVOICES_????????_??????.txt".
//The function takes as a parameter a pointer to the name of a file, which name is converted to uppercase letters
//The function returns TRUE if it succeeded in matching the beginning of the filename with the supplied pattern
static _Bool isFileNameFitsToPattern( const char* strUpperFileName)
{
	const unsigned cuValidDigitsForDate = 8;
	const unsigned cuValidDigitsForTime = 6;

	if (strUpperFileName == NULL)
	{
		return FALSE;
	}
	char* strPattern = STR_FILENAME_PATTERN_BEGIN;
	size_t len = strlen(strPattern);
	char* strPatternIt = strPattern;
	unsigned uCounterDigits = 0;
	const char* it = strUpperFileName;
	for (; it < strUpperFileName + len; it++, strPatternIt++)
	{
		if (*it != *strPatternIt)
		{
			return FALSE;
		}
	}
	for (; *it != '_'; it++)
	{
		if (isdigit(*it))
		{
			uCounterDigits++;
		}
		else
		{
			return FALSE;
		}
	}
	if (uCounterDigits != cuValidDigitsForDate)
	{
		return FALSE;
	}
	uCounterDigits = 0;
	it++;
	for (; *it != '.'; it++)
	{
		if (isdigit(*it))
		{
			uCounterDigits++;
		}
		else
		{
			return FALSE;
		}
	}
	if (uCounterDigits != cuValidDigitsForTime)
	{
		return FALSE;
	}
	return TRUE;
}

//The function does full file name validation (string plus date and time)
//The function takes as a parameter wchar_t pointer to the filename
//The function returns TRUE if it was successful in validating the file name against a given pattern checked by nested functions
_Bool isFileNameValid(const wchar_t* wstrFileName)
{
	if (wstrFileName == NULL)
	{
		return FALSE;
	}
	char strFileName[MAX_SIZE_FILENAME];
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, strFileName, MAX_SIZE_FILENAME, wstrFileName, wcslen(wstrFileName) + 1);
	const char* strUpperFileName = toUpperFileName(strFileName);
	if (!isFileNameFitsToPattern(strUpperFileName))
	{
		return FALSE;
	}
	if (!isDateInStringValid(strUpperFileName))
	{
		return FALSE;
	}
	return TRUE;
}

//The function converts the supplied string to uppercase
//The function takes a pointer to a string as a parameter
//The function returns a pointer to the converted string
static char* toUpperString(char* strString)
{
	if (strString == NULL)
	{
		return NULL;
	}
	for (char* it = strString; *it != '\0'; it++)
	{
		if (isalpha(*it))
		{
			*it = toupper(*it);
		}
	}
	return strString;
}

//The function checks whether the supplied string (name in file data) contains only letters
//The function takes a pointer to a string as a parameter
//The function returns TRUE if it has read only letters in the string
_Bool isNameValid(const char* strName)
{
	if (strName == NULL)
	{
		return FALSE;
	}
	int i = 0;
	while (strName[i] != '\0')
	{
		if (!isalpha(strName[i]))
			return FALSE;
		i++;
	}
	return TRUE;
}

//The function checks if the supplied string (invoice number in file data)starts with FN and is followed by only digits
//The function takes a pointer to a string as a parameter
//The function returns TRUE if it has read FN as the first two characters and then only digits from the supplied string
_Bool isInvoiceValid(const char* strInvoice)
{
	if (strInvoice == NULL)
	{
		return FALSE;
	}
	if ((strInvoice[0] != 'f' && strInvoice[0] != 'F'))
	{
		return FALSE;
	}
	if ((strInvoice[1] != 'n' && strInvoice[1] != 'N'))
	{
		return FALSE;
	}
	int i = 2;
	while (strInvoice[i] != '\0')
	{
		if (!isdigit(strInvoice[i]))
		{
			return FALSE;
		}
		i++;
	}
	return TRUE;
}

//Function check if the supplied string (currency in file data) is equal to any element of apstrCurrency[] - array of all valid currencies
//The function takes a pointer to a string as a parameter
//The function returns TRUE if it succeeded in comparing the supplied string with any of the elements of the array of all valid currencies
_Bool isCurrencyValid(char* strCurrency)
{
	size_t szSize = sizeof(apstrCurrency) / sizeof(char*);
	if (strCurrency == NULL)
	{
		return FALSE;
	}
	strCurrency = toUpperString(strCurrency);
	for (int i = 0; i < szSize; i++)
	{
		if (strcmp(strCurrency, apstrCurrency[i]) == 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//The function checks if the supplied double number is positive
//The function takes a double variable as a parameter
//The function return TRUE if a double variable is positive
_Bool isDoublePositive(const double dNumber)
{
	if (dNumber < 0)
	{
		return FALSE;
	}
	return TRUE;
}

//The function compares two double numbers.It is static because we only use it in this header
//The function accepts two variables of type double as parameters
//The function returns TRUE if the two variables are equal using an epsilon constant
static _Bool isDoubleEquals(const double a, const double b)
{
	const double epsilon = 0.0001;
	double minus = a - b;
	return (epsilon > fabs(minus)) ? TRUE : FALSE;
}

//The function validates the last line of a text file, which must be equal to the sum of all invoice amounts in it
//The function accepts as parameters a double variable (deserialized as the sum of the invoices), a pointer to a structure 
//(for deserializing data from a file) and an unsigned int (number of lines read in the file)
//The function returns true if it successfully compares the sum of the invoices in the file with a deserialized sum from it
_Bool isEqualTotalInvoiceToSumOfRowInvoices(const double dTotalSum, SRow* pstructSRow,const unsigned uiCountRows)
{
	if (pstructSRow == NULL)
	{
		return FALSE;
	}
	double dSum = 0;
	for (SRow* pstrIterator = pstructSRow; pstrIterator < pstructSRow + uiCountRows - MIN_FILE_ROWS; pstrIterator++)
	{
		dSum = dSum + pstrIterator->dTotalSumInvoices;
	}
	return (isDoubleEquals(dSum, dTotalSum)) ? TRUE : FALSE;
}

//The function is used for predicate in qsort-function for lexicographically compare the invoice names in the file
//The function accepts two constant void pointers as parameters
//The function returns: - Negative value if *a appears before *b in lexicographical order.
//						- Zero if *a and *b compare equal.
//						- Positive value if *a appears after *b in lexicographical order.
int compareInvoiceNumbers(const void* a, const void* b)
{
	SRow structA = *(SRow*)a;
	SRow structB = *(SRow*)b;
	return  (strcmp(structA.strInvoiceNumber, structB.strInvoiceNumber));
}
