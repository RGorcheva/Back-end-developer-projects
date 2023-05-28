#ifndef FUNC_ERRORHANDLING_H
#define FUNC_ERRORHANDLING_H
#include "func_OpenCloseFile.h"
#include "func_FileNameEdit.h"
#include "configMacro.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define STR_FILE_OUTPUT_LOG "progamOutputLog.txt"
#define STR_FILE_ERROR_LOG "errorLog.txt"

//List with system errors:
#define ERROR_FORMAT_1 "Too few arguments!"
#define ERROR_FORMAT_2 "The directory does not exist!"
#define ERROR_FORMAT_3 "There is no file with this pattern in the directory!"
#define ERROR_FORMAT_4 "Pointer to structs is lost!"
#define ERROR_FORMAT_5 "NULL pointer!"
#define ERROR_FORMAT_6 "Cannot alocate memory!"
#define ERROR_FORMAT_7 "Cannot convert from wchar_t* to char*!"
#define ERROR_FORMAT_8 "Error in openning file!"
#define ERROR_FORMAT_9 "Error in clossing file!"
#define ERROR_FORMAT_10 "Error in renaming file!"
#define ERROR_FORMAT_11 "Invalid reposition of file pointer!"
#define ERROR_FORMAT_12 "Error with seeking in directory!"
#define ERROR_FORMAT_13 "Error in openning error log file!"
#define ERROR_FORMAT_14 "File path array size overflow!"

char strErrorFilePath[MAX_SIZE_FILEPATH];
char strOutputFilePath[MAX_SIZE_FILEPATH];

//Concatenates full path to error log lile in the given directory
//The function takes pointer to the string with name of directory
void errorFileInit(const char* strDirectory);

//Concatenates full path to output log lile in the given directory
//The function takes pointer to the string with name of directory
void outputFileInit(const char* strDirectory);

//Prints system errors in error log file in the given directory.
//Takes X - errno from last error and ERROR_FORMAT - string from list with system errors.
#define ERROR_PRINT(X, ERROR_FORMAT) {	FILE* errFile;\
										if ((errFile = fopen(strErrorFilePath, "a")) == NULL)\
										{fprintf(stderr, "%s\n", ERROR_FORMAT_13);}\
										else\
										{\
											fprintf(errFile, "%s, %s\n", __DATE__, __TIME__);\
											fprintf(errFile, "Error in line %d in file \n%s.\n", __LINE__, __FILE__);\
											fprintf(errFile, "(Error code %d - %s)\n", X, strerror(X));\
											fprintf(errFile, "%s\n\n", ERROR_FORMAT);\
										}\
										fileClose(errFile);\
									 }

//Prints errors from file content in output lod file in the given directory.
//Takes X - errno from last error and PFILE - pointer to beginning of the wrong row.
#define ERROR_LINE_IN_FILE_PRINT(X,PFILE) {\
											fprintf(outputFile, "Error in line %d: ", X);\
											char ch = '\0';\
											while ((ch = getc(PFILE)) != '\n'){fprintf(outputFile, "%c", ch);}\
											fprintf(outputFile, "%c", '\n');\
										  }

//Prints info for openning file in output lod file in the given directory.
//Takes X - string with name of openned file.
#define STR_OPEN_FILE(X)  { fprintf(outputFile, "%s - open\n", X); }

//Prints info that openned file is correct in output lod file in the given directory.
//Takes X - string with name of openned file.
#define STR_CORRECT_FILE(X)  { fprintf(outputFile, "%s - correct\n\n", X); }

//Prints info that openned file is INcorrect in output lod file in the given directory.
//Takes X - string with name of openned file.
#define STR_INCORRECT_FILE(X)  { fprintf(outputFile, "%s - incorrect\n\n", X); }

#endif