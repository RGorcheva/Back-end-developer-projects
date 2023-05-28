#ifndef FUNC_DATAANDFILENAMEVALIDATION_H
#define FUNC_DATAANDFILENAMEVALIDATION_H
#include "configMacro.h"
#include <stdio.h>

typedef struct SRow
{
	char strName[MAX_SIZE_NAME];
	char strInvoiceNumber[MAX_SIZE_INVOICE];
	char strDate[MAX_SIZE_STRDATE];
	char strCurrency[MAX_SIZE_CURRENCY];
	double dTotalSumInvoices;
}SRow;

//The function validates the date from the contents of file with /%2d%2d%4d/ pattern
_Bool isDateValid(const char* strDate);
//The function does full file name validation (string plus date and time)
_Bool isFileNameValid(const wchar_t* wstrFileName);
//The function checks whether the supplied string (name in file data) contains only letters
_Bool isNameValid(const char* strName);
//The function checks if the supplied string (invoice number in file data)starts with FN and is followed by only digits
_Bool isInvoiceValid(const char* strInvoice);
//Function check if the supplied string (currency in file data) is equal to any element of apstrCurrency[] - array of all valid currencies
_Bool isCurrencyValid(char* currency);
//The function checks if the supplied double number is positive
_Bool isDoublePositive(const double dNumber);
//The function validates the last line of a text file, which must be equal to the sum of all invoice amounts in it
_Bool isEqualTotalInvoiceToSumOfRowInvoices(const double dTotalSum, SRow* pstructSRow, const unsigned uiCountRows);
//The function is used to lexicographically compare the invoice names in the file
int compareInvoiceNumbers(const void* a, const void* b);

#endif