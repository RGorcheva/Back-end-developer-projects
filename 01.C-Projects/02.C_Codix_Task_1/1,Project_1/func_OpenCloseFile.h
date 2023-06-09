#ifndef FUNC_OPENCLOSEFILE_H
#define FUNC_OPENCLOSEFILE_H
#include <stdio.h>

//Opens file or prints error otherwise.
FILE* fileOpen(const char* strFileName, char* mode);

//Close file or prints error otherwise.
void fileClose(FILE* pFile);

#endif