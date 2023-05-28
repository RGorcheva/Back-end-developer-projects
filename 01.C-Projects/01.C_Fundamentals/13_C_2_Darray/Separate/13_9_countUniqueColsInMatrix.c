/*
Напишете програма, която печата броя на уникалните колони в бинарна
матрица, съставена само от единици и нули.
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

int main(void)
{
	const int matrix[6][5] = {
						{0,1,1,1,1},
						{1,1,1,1,0},
						{1,1,1,1,0},
						{1,1,1,1,0},
						{1,1,1,1,1},
						{0,1,1,1,0}
	};
	int rows = 6;
	int cols = 5;
	int countUniqueCols = 0;
	io_matrixIntPrint(*matrix, rows, cols);
	countUniqueCols = martix_countUniqueCols(*matrix, rows, cols);
	printf("%d different columns.", countUniqueCols);
	return 0;
}