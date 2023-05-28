/*
Напишете функция, която умножава две 3x3 float матрици
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

#define ROWS_3 3

int main(void)
{
	double arr1[ROWS_3][ROWS_3] = { 0 };
	double arr2[ROWS_3][ROWS_3] = { 0 };
	double multipleArr[ROWS_3][ROWS_3] = { 0 };

	io_matrixDoubleEnter(*arr1, ROWS_3, ROWS_3);
	io_matrixDoubleEnter(*arr2, ROWS_3, ROWS_3);

	martix_multipleMatrixWithMatrix(*arr1, *arr2, *multipleArr, ROWS_3);
	io_matrixDoublePrint(*arr1, ROWS_3, ROWS_3);
	io_matrixDoublePrint(*arr2, ROWS_3, ROWS_3);
	io_matrixDoublePrint(*multipleArr, ROWS_3, ROWS_3);

	return 0;
}
