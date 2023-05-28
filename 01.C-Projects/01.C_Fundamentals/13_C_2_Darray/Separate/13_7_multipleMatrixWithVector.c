/*
Напишете функция, която умножава 3-мерен float вектор(едномерен масив с три
float елемента) по 3x3 float матрицa 
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

#define ROWS_3 3

int main(void)
{
	double arr[ROWS_3][ROWS_3] = { 0 };
	double multipleArr[ROWS_3][ROWS_3] = { 0 };
	double vector[ROWS_3] = { 0 };

	io_matrixDoubleEnter(vector, ROWS_3, 1);
	io_matrixDoubleEnter(*arr, ROWS_3, ROWS_3);

	martix_multipleMatrixWithVector(*arr, *multipleArr, vector, ROWS_3);
	io_matrixDoublePrint(*arr, ROWS_3, ROWS_3);
	io_matrixDoublePrint(vector, ROWS_3, 1);
	io_matrixDoublePrint(*multipleArr, ROWS_3, ROWS_3);

	return 0;
}
