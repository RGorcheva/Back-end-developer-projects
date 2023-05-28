#define _CRT_SECURE_NO_WARNINGS
#include "func_FileNameEdit.h"
#include "func_ErrorHandling.h"
#include <stdio.h>
#include "configMacro.h"
#include <Windows.h>


//The function checks and converts all letters of a given string to uppercase.
//The function takes a char pointer as a parameter.
//The function return char pointer to converted string.
char* toUpperFileName(char* strFileName)
{
	if (strFileName == NULL)
	{
		return NULL;
	}
	for (char* it = strFileName; *it != '.'; it++)
	{
		if (isalpha(*it))
		{
			*it = toupper(*it);
		}
	}
	return strFileName;
}

//The function rename a given file.
//The function accept const char* to old filename and char* to new filename.
static void changeFileName(const char* strOldFilePath, char* strNewFilePath)
{
	if ((strOldFilePath == NULL) || (strNewFilePath == NULL))
	{
		return;
	}
	wchar_t wstrOldFilePath[MAX_SIZE_FILEPATH];
	mbstowcs(wstrOldFilePath, strOldFilePath, strlen(strOldFilePath) + 1);
	wchar_t wstrNewFilePath[MAX_SIZE_FILEPATH];
	mbstowcs(wstrNewFilePath, strNewFilePath, strlen(strNewFilePath) + 1);

	if (!MoveFileW(wstrOldFilePath, wstrNewFilePath))
	{
		ERROR_PRINT(errno, ERROR_FORMAT_10);
	}
}

//The function renames the supplied file name, with the appropriate extension 'OK' or 'KO', according to its validity.
//The function takes as arguments a const char pointer to the filename, a second char pointer to the new filename, 
// and a boolean variable for the file's validity.
//The function returns a char pointer to the new file name on success ор a null char pointer on failure.
static char* createFileName(const char* strOldFileName, char* strNewFileName, _Bool isValidFile)
{
	if ((strOldFileName == NULL) || (strNewFileName == NULL))
	{
		return NULL;
	}
	size_t oldLen = strlen(strOldFileName);
	strcpy(strNewFileName, strOldFileName);
	char* add = NULL;
	for (char* it = strNewFileName; it < strNewFileName + oldLen; it++)
	{
		if (*it == '.')
		{
			add = it;
			for (it = it + 1; it < strNewFileName + oldLen; it++)
			{
				*it = '\0';
			}
			strcpy(add + 1, (isValidFile) ? "OK" : "KO" );
		}
	}
	return strNewFileName;
}

//Creates a new filename that matches the pattern "INVOICES_ORDERED_YYYYMMDD_HHMMSS.txt".
//The function takes as arguments a const char pointer to the filename, a second char pointer to the new filename.
//The function returns a char pointer to the new file name on successnull ор а char pointer on failure.
static char* createFileNameINVOICES_ORDERED(const char* strOldFileName, char* strNewFileName)
{
	if ((strOldFileName == NULL) || (strNewFileName == NULL))
	{
		return NULL;
	}
	size_t oldLen = strlen(strOldFileName);
	strcpy(strNewFileName, "INVOICES_ORDERED_");
	const char* add = NULL;
	for (const char* it = strOldFileName; it < strOldFileName + oldLen; it++)
	{
		if ((*it > '0') && (*it < '9'))
		{
			add = it;
			strcat(strNewFileName, add);
			break;
		}
	}
	return strNewFileName;
}

//Creates a full path to the file - concat the directory name to the file name in wchar_t type.
//The function takes as arguments a const wchar_t pointer to a directory path, a const wchar_t pointerto a filename, 
//and a wchar_t pointer to the result of the concatenation
void wconcatFullPathToFile(const wchar_t* wstrDirectory, const wchar_t* wstrFilename, wchar_t* wstrResult)
{
	if ((wstrDirectory == NULL) || (wstrFilename == NULL))
	{
		return;
	}
	size_t szDirectoryLength = wcslen(wstrDirectory);
	size_t szFileNameLength = wcslen(wstrFilename);
	if ((szDirectoryLength + szFileNameLength + 1) > MAX_SIZE_FILEPATH)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_14);
	}
	wcscpy(wstrResult, wstrDirectory);
	if (wstrResult[szDirectoryLength - 1] != L'\\')
	{
		wstrResult[szDirectoryLength] = L'\\';
		++szDirectoryLength;
	}
	wcscpy(wstrResult + szDirectoryLength, wstrFilename);
}

//Creates a full path to the file - concat the directory name to the file name in char type.
//The function takes as arguments a const char pointer to a directory path, a const char pointer to a original filename,
//and a char pointer to the result of the concatenation
void concatFullPathToFile(const char* strDirectory, const char* strFilename, char* strResult)
{
	if ((strDirectory == NULL) || (strFilename == NULL))
	{
		return;
	}
	size_t szDirectoryLength = strlen(strDirectory);
	size_t szFileNameLength = strlen(strFilename);
	if ((szDirectoryLength + szFileNameLength + 1) > MAX_SIZE_FILEPATH)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_14);
	}
	strcpy(strResult, strDirectory);
	if (strResult[szDirectoryLength - 1] != '\\')
	{
		strResult[szDirectoryLength] = '\\';
		++szDirectoryLength;
	}
	strcpy(strResult + szDirectoryLength, strFilename);
	size_t szFullPathLength = szDirectoryLength + strlen(strFilename);
	strResult[szFullPathLength] = '\0';
}

//The function is used to specify the path to a valid file with the extension '.OK' or 'KO'
//The function takes as arguments a const char pointer to a directory path, a const char pointer to a original filename,
// and a char pointer to a new filename.
//The function returns char pointer to new file name.
char* renameFile(const char* strDirectory,const char* strFileName, char* strNewFilePath, _Bool isValidFileContent)
{
	char strNewFileName[MAX_SIZE_FILENAME] = { '\0' };
	char strFilePath[MAX_SIZE_FILEPATH] = { '\0' };
	createFileName(strFileName, strNewFileName, isValidFileContent);
	concatFullPathToFile(strDirectory, strFileName, strFilePath);
	concatFullPathToFile(strDirectory, strNewFileName, strNewFilePath);
	changeFileName(strFilePath, strNewFilePath);
	return strNewFilePath;
}

//Creates new filename for serilization file content.
//The function takes as arguments const char pointer to a directory path,const char pointer to a filename and char pointer 
// for returnning full path to new file 
//The function returns char pointer to new full path of file
char* renameFileToINVOICES_ORDERED(const char* strDirectory,const char* strFileName, char* strNewFilePath)
{
	char strNewFileName[MAX_SIZE_FILENAME] = { '\0' };
	strcpy(createFileNameINVOICES_ORDERED(strFileName, strNewFileName), strNewFileName);
	concatFullPathToFile(strDirectory, strNewFileName, strNewFilePath);
	return strNewFilePath;
}