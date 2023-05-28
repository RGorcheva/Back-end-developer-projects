/*
Напишете функция, която търси за под-матрица в матрица (подобно на миналата
задача, но търсим за двумерен масив)
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

int main(void)
{
	const int matrixSearchIn[6][5] = {
						{0,1,0,1,1},
						{1,1,1,1,0},
						{1,1,0,1,0},
						{1,1,1,1,0},
						{1,1,1,1,1},
						{0,1,0,1,0}
	};
	int Rows = 6;
	int Cols = 5;
	const int matrixFind[4][4] = {
					{2,1,1,1},
					{1,0,0,1},
					{1,1,1,1},
					{1,1,1,1}
	};
	int rows = 4;
	int cols = 4;

	io_matrixIntPrint(*matrixSearchIn, Rows, Cols);
	printf("\n");
	io_matrixIntPrint(*matrixFind, rows, cols);

	if (martix_searchMatrixInMatrix(*matrixSearchIn, Rows, Cols, *matrixFind, rows, cols))
	{
		printf("The matrix is found in the big matrix!");
	}
	else
	{
		printf("The matrix is NOT found in the big matrix!");
	}
	return 0;
}