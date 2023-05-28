/*
Напишете функция, която проверява дали дадена float матрица е identity matrix -
матрица с размер (N x N), където само елементите в главния диагонал са единици, а
всички останали елементи са нули.
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

int main(void)
{
	int rows = 4;
	int cols = 4;
	double arr[4][4] = { 0 };

	io_matrixDoubleEnter(*arr, rows, cols);
	io_matrixDoublePrint(*arr, rows, cols);

	if (martix_isIdentity(*arr, rows, cols))
	{
		printf("\nIdentity matrix!");
	}
	else
	{
		printf("\nNOT Identity matrix!");
	}
	return 0;
}
