/*
Напишете програма, която принтира сумата на всеки ред и на всяка колона
на една матрица.
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

#define ROWS_3 3
#define COLS_4 4

int main(void)
{
	double arr[ROWS_3][COLS_4] = { 0 };
	double sum = 0;

	io_matrixDoubleEnter(*arr, ROWS_3, COLS_4);
	io_matrixDoublePrint(*arr, ROWS_3, COLS_4);

	for (int i = 0; i < ROWS_3; ++i)
	{
		sum = 0;
		for (int j = 0; j < COLS_4; ++j)
		{
			sum += arr[i][j];
		}
		printf("\nSum of row %d = %.2lf", i, sum);
	}
	for (int i = 0; i < COLS_4; ++i)
	{
		sum = 0;
		for (int j = 0; j < ROWS_3; ++j)
		{
			sum += arr[j][i];
		}
		printf("\nSum of column %d = %.2lf", i, sum);
	}
	return 0;
}

