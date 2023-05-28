#ifndef FUNC_FILENAMEEDIT_H
#define FUNC_FILENAMEEDIT_H
#include <Windows.h>


//The function checks and converts all letters of a given string to uppercase.
char* toUpperFileName(char* strFileName);
//Creates a full path to the file - concat the directory name to the file name in wchar_t type.
void wconcatFullPathToFile(const wchar_t* wstrDirectory, const wchar_t* wstrFilename, wchar_t* wstrResult);
//Creates a full path to the file - concat the directory name to the file name in char type.
void concatFullPathToFile(const char* strDirectory, const char* strFilename, char* strResult);
//The function is used to specify the path to a valid file with the extension '.OK' or 'KO'
char* renameFile(const char* strDirectory, const char* strFileName, char* strNewFilePath, _Bool isValidFileContent);
//Creates new filename for serilization file content.
char* renameFileToINVOICES_ORDERED(const char* strDirectory,const char* strFileName, char* strNewFilePath);

#endif