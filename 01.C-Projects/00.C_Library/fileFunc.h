#ifndef FILEFUNC_H
#define FILEFUNC_H

#include <stdio.h>

int				file_countRows(FILE *pFile);
unsigned long 	file_countSymbols(FILE* pFile);
int				file_countWords(FILE* pFile);

FILE*			file_open(FILE* out, const char* pFile, char* mode);
void			file_close(FILE* pFile);

FILE*			int_deserilization(FILE* in, int* pCount);
FILE*			int_serilization(FILE* out, int* pCount);


#endif