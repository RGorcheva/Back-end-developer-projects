#ifndef ARRAYFUNC_H
#define ARRAYFUNC_H

#define COLS_4 4

//ARRAYS

void	array_RandomFill(char* arrName, int* arr, int sizeArr);
void	array_randomFillBetweenMinMax(int* arr, int size, int min, int max);
void	array_fillFromConsoleBetweenMinMax(int* arr, int size, int min, int max);

int		array_countElements(int* arr, int sizeArr, int iNumber);
int		array_maxElement(int* arr, int sizeArr);
int		array_minElement(int* arr, int sizeArr);
double	array_averageElements(const int* arr, int sizeArr);
int		array_sumElements(const int* arr, int sizeArr);
void	array_oddElements(int* arr, int sizeArr, int* oddArr, int sizeOddArr);
void	array_evenElements(int* arr, int sizeArr, int* evenArr, int sizeEvenArr);

int		array_multipleElements(const int* arr, int sizeArr);
int		array_multipleElementsBetweenMinMax(const int min, const int max);
void	array_nullNegativeElements(int* arr, int sizeArr);
void	array_copyArrToArr(const int* fromArr, int sizeFrom, int* toArr);
void	array_exchangeTwoArraies(int* arr1, int sizeArr1, int* arr2);

//MATRIXES

int		martix_isIdentity(const double* arr, int rows, int cols);

void	martix_sumMatrixPlusMatrix(double(*arrA)[COLS_4], double(*arrB)[COLS_4], double(*arrSum)[COLS_4], int rows);
void	martix_multipleMatrixWithNumber(double* arr, double* arrMult, int rows, int cols, double num);
void	martix_multipleMatrixWithVector(double* arr, double* arrMult, double* vector, int rows);
void	martix_multipleMatrixWithMatrix(double* arr1, double* arr2, double* arrMult, int rows);

void	martix_exchangeRows(int* arr, int rows, int cols, int rowM, int rowN);
void	martix_exchangeCols(int* arr, int rows, int cols, int colM, int colN);

int		martix_areEquals(const double* arrA, const double* arrB, int rows, int cols);
int		martix_searchArrInMatrix(const int* matrix, int rows, int cols, const int* arr, int arrSize);
int		martix_searchMatrixInMatrix(const int* matrixSearchIn, int Rows, int Cols, const int* matrixFind, int rows, int cols);
int		martix_searchCharArrInCharMatrix(const char* matrix, int rows, int cols, const char* arr);

int		martix_countUniqueCols(const int* matrix, int rows, int cols);
void	martix_copyMatrixToArr(const int* matrix, int* arr, int size);
void	martix_copyMatrixToArrBackwards(const int* matrix, int* arr, int size);





#endif