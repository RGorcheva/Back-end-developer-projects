#ifndef FUNC_READWRITEINFILE_H
#define FUNC_READWRITEINFILE_H

#include <stdio.h>

//Writes to a text file all valid data from original file, sorted lexicographically.
void allSerilization(char* filePath, unsigned uiCountRows, struct SRow* pSRow, double totalSum);

//Read of all data from file and check validation.
_Bool fileReadAndValidateData(char* strFilePath, unsigned* puiCountRows, struct SRow** pstructSRow, double* pdTotalSumInvoice, FILE* outputFile);

#endif