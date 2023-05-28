#ifndef INPUTOUTPUTFUNC_H
#define INPUTOUTPUTFUNC_H

#define COLS_4  4

void	io_arrEnter(char* arrName, int* arr, int sizeArr);
void	io_arrPrintName(char* arrName, int* arr, int sizeArr);
void	io_arrPrint(int* arr, int sizeArr);
void	io_arrPrintSquareScopes(char* arrName, int* arr, int sizeArr);
void	io_arrPrintBackwards(char* arrName, int* arr, int sizeArr);

int		io_intEnter(char* str);
void	io_intPrint(char* str, int i);

char*	io_strEnter(char* str, int strMaxSize);
void	io_strEnterMultilineEOF(char* string);
void	io_strPrintInCol(char* s);
void	io_strPrintInRow(char* s);
void	io_strPrintBackwords(const char* str);
void	io_strPrintRowsBackwards(const char* str);
void	io_strPrintBackwardsEveryRow(const char* str);

void	io_matrixIntEnter(const int* arr, int rows, int cols);
void	io_matrixIntPrint(const int* arr, int rows, int cols);
void	io_matrixIntEnterFixCols(int(*arr)[COLS_4], int rows);
void	io_matrixIntPrintFixCols(const int(*arr)[COLS_4], int rows);

void	io_matrixDoubleEnter(double* arr, int rows, int cols);
void	io_matrixDoublePrint(const double* arr, int rows, int columns);
void	io_matrixDoubleEnterFixCols(double(*arr)[COLS_4], int rows);
void	io_matrixDoublePrintFixCols(const double(*arr)[COLS_4], int rows);

void	io_matrixCharEnter(char* arr, int rows, int cols);
void	io_matrixCharPrint(const char* arr, int rows, int cols);



#endif