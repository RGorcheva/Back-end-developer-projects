#define _CRT_SECURE_NO_WARNINGS
#include "func_OpenCloseFile.h"
#include "func_errorHandling.h"

//Opens file or prints error otherwise.
//Function takes pointer to file name and pointer to the file access mode.
//Function returns pointer to the openned file at success, and NULL at failure.
FILE* fileOpen(const char* strFileName, char* mode)
{
	FILE* pFile = NULL;
	if ((pFile = fopen(strFileName, mode)) == NULL)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_8);
	}
	return pFile;
}

//Close file or prints error otherwise.
//Function takes pointer to file.
void fileClose(FILE* pFile)
{
	if (fclose(pFile) != 0)
	{
		ERROR_PRINT(errno, ERROR_FORMAT_9);
	}
}