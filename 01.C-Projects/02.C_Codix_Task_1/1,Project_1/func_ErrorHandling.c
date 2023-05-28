#define _CRT_SECURE_NO_WARNINGS
#include "func_ErrorHandling.h"
#include "configMacro.h"

//Concatenates full path to error log lile in given directory
//The function takes pointer to the string with name of directory
void errorFileInit(const char* strDirectory)
{
	const char* strErrorLogFile = STR_FILE_ERROR_LOG;
	concatFullPathToFile(strDirectory, strErrorLogFile, strErrorFilePath);
}

//Concatenates full path to output log lile in given directory
//The function takes pointer to the string with name of directory
void outputFileInit(const char* strDirectory)
{
	const char* strExitLogFile = STR_FILE_OUTPUT_LOG;
	concatFullPathToFile(strDirectory, strExitLogFile, strOutputFilePath);
}

