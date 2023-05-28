/*
Напишете програма, която събира две 4х4 матрици от float и записва резултата в
трета такава със същия размер. Събирането на матриците става като намерим
сумата на съответстващите елементи в тях. Данните за изходните матрици трябва
да бъдат въведени от потребителя. Разпечатайте трите матрици в конзолата.
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

#define ROWS_4 4
#define COLS_4 4

int main(void)
{
	double arrA[ROWS_4][COLS_4] = {0};
	double arrB[ROWS_4][COLS_4] = {0};
	double arrSum[ROWS_4][COLS_4] = {0};

	io_matrixDoubleEnter(*arrA, ROWS_4, COLS_4);
	io_matrixDoubleEnter(*arrB, ROWS_4, COLS_4);
	martix_sumMatrixPlusMatrix(*arrA, *arrB, *arrSum, ROWS_4);
	io_matrixDoublePrint(*arrA, ROWS_4, COLS_4);
	io_matrixDoublePrint(*arrB, ROWS_4, COLS_4);
	io_matrixDoublePrint(*arrSum, ROWS_4, COLS_4);

	return 0;
}