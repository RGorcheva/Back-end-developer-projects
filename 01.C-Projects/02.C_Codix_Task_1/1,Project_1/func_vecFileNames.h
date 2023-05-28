#ifndef FUNC_VFILENAMES_H
#define FUNC_VFILENAMES_H
#include <stdio.h>
#include "configMacro.h"

typedef char vectData[MAX_SIZE_FILENAME];
typedef struct vecFileNames
{
	vectData* paFileName;
	size_t size;
	size_t capacity;
} vecFileNames;

//Initialize the vector
void vecFileNames_init(vecFileNames* vec);
//Free dynamic memory for the vector
void vecFileNames_free(vecFileNames* vec);

//Checking if the directory exists.
_Bool isDirectoryExist(const char* strDirectory);
//Search in the directory for files with the specified template and push back in vector valid files
_Bool isFillsNamesOfValidFiles(const char* strDirectory, vecFileNames* vec);

#endif