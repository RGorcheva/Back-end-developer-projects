#define _CRT_SECURE_NO_WARNINGS
#include "func_vecFileNames.h"
#include "func_DataAndFilenameValidation.h"
#include "func_FileNameEdit.h"
#include <Windows.h>
#include "func_ErrorHandling.h"
#include "configMacro.h"


//Initialize the vector vecFileNames. 
//Function takes a pointer to the vector vecFileNames.
void vecFileNames_init(vecFileNames* vec)
{
	if (vec == NULL)
	{
		ERROR_PRINT((int)errno, ERROR_FORMAT_5);
		return;
	}
	vec->paFileName = NULL;
	vec->size = 0;
	vec->capacity = VEC_CAPACITY;
	vec->paFileName = (vectData*)malloc(sizeof(vectData) * vec->capacity);
	if (vec->paFileName == NULL)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_6);
		return;
	}
}

//Free dynamic memory for the vector vecFileNames.
//Function takes a pointer to the vector vecFileNames.
void vecFileNames_free(vecFileNames* vec)
{
	if (vec == NULL)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_5);
		return;
	}
	vec->size = 0;
	vec->capacity = 0;
	free(vec->paFileName);
	vec->paFileName = NULL;
}

//Double the capacity of vector vecFileNames.
//Function takes pointer to vector vecFileNames.
static void vecFileNames_doubleCapacity(vecFileNames* vec)
{
	if (vec == NULL)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_5);
		return;
	}
	if (vec->capacity <= 0)
	{
		vec->capacity = VEC_CAPACITY;
	}
	size_t newCapacity = vec->capacity * 2;
	vectData* newData = (vectData*)malloc(sizeof(vectData) * newCapacity);
	if (newData == NULL)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_6);
		return;
	}
	for (size_t i = 0; i < vec->size; i++)
	{
		strcpy(newData[i], vec->paFileName[i]);
	}

	free(vec->paFileName);
	vec->paFileName = newData;
	vec->capacity = newCapacity;
}

//Push back filename in vector.
//Function takes pointer to vector vecFileNames and pointer to file name wchat_t string.
static void vecFileNames_pushBack(vecFileNames* vec, wchar_t* wStr)
{
	if (vec == NULL)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_5);
		return;
	}
	if (vec->size + 1 > vec->capacity)
	{
		vecFileNames_doubleCapacity(vec);
	}
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, vec->paFileName[vec->size++], MAX_SIZE_FILENAME, wStr, wcslen(wStr) + 1);
}

//Checks if the directory exists.
//Function takes as an argument a pointer to a string with a directory name.
//Function returns TRUE if the directory exist or FALSE otherwise.
_Bool isDirectoryExist(const char* strDirectory)
{
	if (strDirectory == NULL)
	{
		return FALSE;
	}
	//Cast to wchar_t.
	wchar_t wstrDirectory[MAX_SIZE_FILEPATH];
	mbstowcs(wstrDirectory, strDirectory, strlen(strDirectory) + 1);

	DWORD attributes = GetFileAttributes(wstrDirectory);
	if (attributes == INVALID_FILE_ATTRIBUTES || !(attributes & FILE_ATTRIBUTE_DIRECTORY))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

//Search in the directory for files with the specified template, validate filename and push back in vector vecFileNames.
//Function takes pointer to the directory name and pointer to vector vecFileNames.
//Function returns TRUE if the directory consist valid files and FALSE otherwise.
_Bool isFillsNamesOfValidFiles(const char* strDirectory, vecFileNames* vec)
{
	if (strDirectory == NULL)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_5);
		return FALSE;
	}
	//Cast to wchar_t.
	wchar_t wstrDirectory[MAX_SIZE_FILEPATH];
	mbstowcs(wstrDirectory, strDirectory, strlen(strDirectory) + 1);

	wchar_t wstrSearchPattern[MAX_SIZE_FILEPATH];
	wconcatFullPathToFile(wstrDirectory, WSTR_FULL_FILENAME_PATTERN, wstrSearchPattern);

	WIN32_FIND_DATA findData;
	HANDLE findHandle = FindFirstFile(wstrSearchPattern, &findData);
	if (findHandle != INVALID_HANDLE_VALUE)
	{
		do
		{
			//Check if is valid filename and push back in vector vFileNames
			if (isFileNameValid(findData.cFileName))
			{
				vecFileNames_pushBack(vec, findData.cFileName);
			}
		} while (FindNextFile(findHandle, &findData));
		if (FindClose(findHandle) == 0)
		{
			ERROR_PRINT(errno, ERROR_FORMAT_12);
		}
	}
	else
	{
		return FALSE;
	}
	if(vec->size == 0)
	{
		return FALSE;
	}
	return TRUE;
}