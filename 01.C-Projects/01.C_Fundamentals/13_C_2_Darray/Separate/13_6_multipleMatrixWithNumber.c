/*
Напишете функция, която умножава всеки елемент на 3x3 float матрица с float
число. 
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

#define ROWS_3 3
#define COLS_3 3

int main(void)
{
	double arr[ROWS_3][COLS_3] = { 0 };
	double multipleArr[ROWS_3][COLS_3] = { 0 };
	double dNumber = 0.0;

	dNumber = io_intEnter("number");
	io_matrixDoubleEnter(*arr, ROWS_3, COLS_3);
	martix_multipleMatrixWithNumber(*arr, multipleArr, ROWS_3, COLS_3, dNumber);
	io_matrixDoublePrint(*arr, ROWS_3, COLS_3);
	io_matrixDoublePrint(*multipleArr, ROWS_3, COLS_3);

	return 0;
}