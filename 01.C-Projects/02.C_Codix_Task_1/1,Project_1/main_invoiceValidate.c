#define _CRT_SECURE_NO_WARNINGS
#include "func_vecFileNames.h"
#include "func_FileNameEdit.h"
#include "func_OpenCloseFile.h"
#include "func_ReadWriteInFile.h"
#include "func_DataAndFilenameValidation.h"
#include "func_ErrorHandling.h"
#include <stdlib.h>
#include <string.h>

int main(void) //(int argc, char* argv[])
{
	//For test and debug we enter arguments manually.
	int argc = 2;
	const char* argv[2] = { "filename.exe", "C:\\test_dir" };

	const char* strDirectory = argv[1];
	char strFilePath[MAX_SIZE_FILEPATH] = { '\0' };

	//Creates full path to the Error Log File and Opuput Log file.
	errorFileInit(strDirectory);
	outputFileInit(strDirectory);

	//Checks if number of argument is at least 2.
	if (argc < 2)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_1);
		exit(EXIT_FAILURE);
	}

	//Initializes a vector that will hold the names of all files, matching the pattern.
	vecFileNames vect;
	vecFileNames_init(&vect);

	//Checks if the directory exists.
	if (!isDirectoryExist(strDirectory))
	{
		ERROR_PRINT(errno, ERROR_FORMAT_2);
		exit(EXIT_FAILURE);
	}

	//Searches the directory for files with the specified pattern.
	if (!isFillsNamesOfValidFiles(strDirectory, &vect))
	{
		ERROR_PRINT(errno, ERROR_FORMAT_3);
		exit(EXIT_FAILURE);
	}

	//Opens file for output log.
	FILE* outputFile = NULL;
	outputFile = fileOpen(strOutputFilePath, "a");

	//Loop that iterates through each file found.
	for (int iIter = 0; iIter < vect.size; iIter++)
	{
		//Creates full path to the data file.
		concatFullPathToFile(strDirectory, vect.paFileName[iIter], strFilePath);

		//Deserialization of information from the file - in structure type SRow.
		SRow* pstructSRow = NULL;
		unsigned uiCountRows = 0;
		double dTotalSumInvoice = 0.0;

		STR_OPEN_FILE(vect.paFileName[iIter]);

		_Bool isValidFileContent = fileReadAndValidateData(strFilePath, &uiCountRows, &pstructSRow, &dTotalSumInvoice, outputFile);
		if (!isValidFileContent)
		{
			//Renames an invalid file to .KO;
			char strNewFilePath[MAX_SIZE_FILEPATH] = { '\0' };
			renameFile(strDirectory, vect.paFileName[iIter], strNewFilePath, isValidFileContent);
			STR_INCORRECT_FILE(vect.paFileName[iIter]);
			continue;
		}

		STR_CORRECT_FILE(vect.paFileName[iIter]);

		//Sorts SRow structures lexically
		if (pstructSRow == NULL)
		{
			ERROR_PRINT(errno, ERROR_FORMAT_4);
		}
		else
		{
			SRow* pstrIterator = pstructSRow;
			qsort(pstrIterator, (size_t)(uiCountRows - MIN_FILE_ROWS), sizeof(SRow), compareInvoiceNumbers);
		}

		//Creates new file for serilization file content.
		char strNewFilePath[MAX_SIZE_FILEPATH] = { '\0' };
		renameFileToINVOICES_ORDERED(strDirectory, vect.paFileName[iIter], strNewFilePath);

		//Serilization of file content
		allSerilization(strNewFilePath, uiCountRows, pstructSRow, dTotalSumInvoice);

		//Frees memory for structures SRow.
		free(pstructSRow);

		//Renames original file to .OK
		renameFile(strDirectory, vect.paFileName[iIter], strNewFilePath, isValidFileContent);
	}

	//Close file for output log.
	fileClose(outputFile);

	//Frees vector vecFileNames.
	vecFileNames_free(&vect);
	printf("Done! :)\n");
	return 0;
}