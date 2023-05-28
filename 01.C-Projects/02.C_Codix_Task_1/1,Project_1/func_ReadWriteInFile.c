#define _CRT_SECURE_NO_WARNINGS
#include "func_ReadWriteInFile.h"
#include "func_DataAndFilenameValidation.h"
#include "func_OpenCloseFile.h"
#include "func_ErrorHandling.h"
#include <Windows.h>

//Check if the string contains valid double number.
//Function takes pointer to the string.
//Function returns TRIE if the string contains valid double number or FALSE otherwise.
static _Bool isDouble(char* paDoubleNumber)
{
	unsigned countDot = 0;
	for (char* it = paDoubleNumber; *it != '\0'; it++)
	{
		if (*it == '.')
		{
			countDot++;
		}
	}
	if (countDot > 1)
	{
		return FALSE;
	}
	unsigned uLen = (unsigned)strlen(paDoubleNumber);
	if ((!isdigit(*paDoubleNumber)) && (!isdigit(*(paDoubleNumber+uLen - 1))))
	{
		return FALSE;
	}
	for (char* it = paDoubleNumber + 1; *it != '\0'; it++)
	{
		if ((*it != '.') && (!isdigit(*it)))
		{
			return FALSE;
		}
	}
	return TRUE;
}

//Counts all rows in file.
//Function takes fle pointer to openned file.
//Function returns number of all rows in file.
static unsigned countAllRowsInFile(FILE* pFile)
{
	if (pFile == NULL)
	{
		return 0;
	}
	long lCurrentPosition = ftell(pFile);
	fseek(pFile, 0L, SEEK_SET);
	int countRows = 1;
	char ch = '\0';
	while ((ch = getc(pFile)) != EOF)
	{
		if (ch == '\n')
		{
			++countRows;
		}
	}
	fseek(pFile, lCurrentPosition, SEEK_SET);
	return countRows;
}

//Counts all empty rows in file.
//Function takes fle pointer to openned file.
//Function returns number of all empty rows in file.
static unsigned countEmptyRowsInFile(FILE* pFile)
{
	if (pFile == NULL)
	{
		return FALSE;
	}
	long lCurrentPosition = ftell(pFile);
	fseek(pFile, 0L, SEEK_SET);
	int countEmptyRows = 1;
	char ch = '\0';
	while ((ch = getc(pFile)) != EOF)
	{
		if (ch == '\n')
		{
			while ((ch = getc(pFile)) == '\n')
			{
				countEmptyRows++;
			}
		}
	}
	fseek(pFile, lCurrentPosition, SEEK_SET);
	return countEmptyRows;
}

//Iterates new line symbols until finding of row with data.
//takes FILE* to current position.
//return FILE* previous position of new data row.
static FILE* findNextDataRow(FILE* pFile)
{
	char ch = '\0';
	while ((ch = getc(pFile)) == '\n')
	{
		;
	}
	fseek(pFile, -1L, SEEK_CUR);
	return pFile;
}

//Calculates number of current row in file.
//Function takes file pointer to currenr position in file.
//Function returns number of current line in file.
static unsigned findCurrentRowNumber(FILE* pFile)
{
	unsigned iCurrentRow = 1;
	long lCurrentPosition = ftell(pFile);
	char ch = '\0';
	fseek(pFile, 0L, SEEK_SET);
	while ((ch = getc(pFile)) != EOF)
	{
		if (ftell(pFile) > lCurrentPosition)
		{
			break;
		}
		if (ch == '\n')
		{
			iCurrentRow++;
		}
	}
	fseek(pFile, lCurrentPosition, SEEK_SET);
	return iCurrentRow;
}

//Reads a integer number from a text file
//Takes a pointer to the text file and a pointer to the variable where the integer number is stored.
//Returns TRUE if the int is reads successfully, otherwise it returns FALSE.
static _Bool isReаdNumberOfRows(FILE* pFile, int* piValue)
{
	if (fscanf(pFile, "%d", piValue) != 1)
	{
		return FALSE;
	}
	return TRUE;
}

//Writes a number of rows to a text file
//Function takes a pointer to the text file and a pointer to the variable 
//that contains the number that needs to be written to the file.
static void numberOfRowsSerelization(FILE* pFile, int* piValue)
{
	fprintf(pFile, "%d\n", *piValue);
}

//Reads a double number from a text file
//Takes a pointer to the text file and a pointer to the variable where the double number is stored.
//Returns TRUE if the double is reads successfully, otherwise it returns FALSE.
static _Bool isReаdTotalSumInvoice(FILE* pFile, double* pdValue)
{
	if (fscanf(pFile, "%lf", pdValue) != 1)
	{
		return FALSE;
	}
	return TRUE;
}

//Writes a total sum of invoices in the text file 
//Function takes pointer to a file and a pointer to the variable where the value is stored.
static void totalSumInvoiceSerilization(FILE* pFile, double* pdValue)
{
	fprintf(pFile, "%.2lf\n", *pdValue);
}

//Reads a structure SRow from a text file.
//Function takes  a pointer to the text file and  a pointer to the SRow structure where the data read from the file is stored.
//Function returns TRUE if the data from the structure is read and valid, otherwise it returns FALSE.
static _Bool isReаdStructSRow(FILE* pFile, SRow* pSRow)
{
	if ((fscanf(pFile, "%[^;\n];", pSRow->strName) != 1) || (!isNameValid(pSRow->strName)))
	{
		return FALSE;
	}
	if ((fscanf(pFile, "%[^;\n];", pSRow->strInvoiceNumber) != 1) || (!isInvoiceValid(pSRow->strInvoiceNumber)))
	{
		return FALSE;
	}
	if ((fscanf(pFile, "%[^;\n];", pSRow->strDate) != 1) || (!isDateValid(pSRow->strDate)))
	{
		return FALSE;
	}
	if ((fscanf(pFile, "%[^;\n];", pSRow->strCurrency) != 1) || (!isCurrencyValid(pSRow->strCurrency)))
	{
		return FALSE;
	}
	char caDoubleNumber[14] = { '\0' };
	if (fscanf(pFile, "%[^;\n]", caDoubleNumber) != 1)
	{
		return FALSE;
	}
	if (isDouble(caDoubleNumber))
	{
		char* ptr;
		pSRow->dTotalSumInvoices = strtod(caDoubleNumber, &ptr);
		if (!isDoublePositive(pSRow->dTotalSumInvoices))
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
	return TRUE;
}

//Writes a SRow structure to a text file.
//Function takes a pointer to the text file and a pointer to the "SRow" structure that needs to be written to the file.
static void structSRowSerilization(FILE* pFile, SRow* pSRow)
{
	fprintf(pFile, "%s;%s;%s;%s;%.2lf\n", pSRow->strName, pSRow->strInvoiceNumber, pSRow->strDate, pSRow->strCurrency, pSRow->dTotalSumInvoices);
}

//Writes to a text file all valid data from original file, sorted lexicographically.
//Function takes pointer to file path, variable that keeps number of rows, 
// pointer to structure SRow, where are stored all rows and double variable for total sum of invoices.
void allSerilization(char* filePath, unsigned uiCountRows, SRow* pSRow, double totalSum)
{
	FILE* pFile = NULL;
	pFile = fileOpen(filePath, "w");
	if (pFile == NULL)
	{
		return;
	}
	numberOfRowsSerelization(pFile, &uiCountRows);
	for (SRow* pstrIterator = pSRow; pstrIterator < pSRow + uiCountRows - 2; pstrIterator++)
	{
		structSRowSerilization(pFile, pstrIterator);
	}
	totalSumInvoiceSerilization(pFile, &totalSum);
	fileClose(pFile);
}

//Read of all data from file and check validation.
//Function takes pointer to the text file with data for reading, 
// a pointer to the number of rows in the file,a pointer to a dinamic memory used as array of SRow structures
// and a pointer to the total sum of invoices.
//Function returns TRUE if the data is valid and read successfully, 
//and FALSE if there is an error in opening the file or validating the data.
_Bool fileReadAndValidateData(char* strFilePath, unsigned* puiCountRows, SRow** pstructSRow, double* pdTotalSumInvoice, FILE* outputFile)
{
	//Open file.
	FILE* pFile = NULL;
	pFile = fileOpen(strFilePath, "r");
	if (pFile == NULL)
	{
		return FALSE;
	}

	//Deserialization of information from the file - in structure type SRow.
	_Bool isValidFileContent = TRUE;
	unsigned allRows = countAllRowsInFile(pFile);
	unsigned emptyRows = countEmptyRowsInFile(pFile);
	unsigned realNumberOfDataRows = allRows - emptyRows;
	pFile = findNextDataRow(pFile);
	long lBeginOfRowPosition = ftell(pFile);
	if ((!isReаdNumberOfRows(pFile, puiCountRows)) || (*puiCountRows != realNumberOfDataRows))
	{
		*puiCountRows = realNumberOfDataRows;
		int iCurrentRow = findCurrentRowNumber(pFile);
		fseek(pFile, lBeginOfRowPosition, SEEK_SET);
		ERROR_LINE_IN_FILE_PRINT(iCurrentRow, pFile);
		isValidFileContent = FALSE;
	}
	if (*puiCountRows <= MIN_FILE_ROWS)
	{
		ERROR_LINE_IN_FILE_PRINT(findCurrentRowNumber(pFile), pFile);
		isValidFileContent = FALSE;
	}
	else
	{
		unsigned numberOfStructs = *puiCountRows - MIN_FILE_ROWS;
		*pstructSRow = (SRow*)malloc(sizeof(SRow) * (size_t)numberOfStructs);
		if (*pstructSRow == NULL)
		{
			ERROR_PRINT(errno, ERROR_FORMAT_6);
			isValidFileContent = FALSE;
		}
		SRow* pstrIterator = *pstructSRow;
		for (; pstrIterator < *pstructSRow + numberOfStructs; pstrIterator++)
		{
			pFile = findNextDataRow(pFile);
			lBeginOfRowPosition = ftell(pFile);
			if (!isReаdStructSRow(pFile, pstrIterator))
			{
				int iCurrentRow = findCurrentRowNumber(pFile);
				fseek(pFile, lBeginOfRowPosition, SEEK_SET);
				ERROR_LINE_IN_FILE_PRINT(iCurrentRow, pFile);
				isValidFileContent = FALSE;
			}
		}
		pstrIterator = *pstructSRow;
		pFile = findNextDataRow(pFile);
		lBeginOfRowPosition = ftell(pFile);
		if ((!isReаdTotalSumInvoice(pFile, pdTotalSumInvoice)) || 
			(!isEqualTotalInvoiceToSumOfRowInvoices(*pdTotalSumInvoice, pstrIterator, *puiCountRows)))
		{
			int iCurrentRow = findCurrentRowNumber(pFile);
			fseek(pFile, lBeginOfRowPosition, SEEK_SET);
			ERROR_LINE_IN_FILE_PRINT(iCurrentRow, pFile);
			isValidFileContent = FALSE;
		}
	}
	fileClose(pFile);
	return isValidFileContent;
}