/*
Напишете функция, която претърсва за последователност от стойности (подадени
в едномерен масив) в редовете и колоните на двумерен масив. Функцията връща 1
ако е открила последователността, в някой ред или колона и 0 ако не е.
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

int main(void)
{
	const int matrix[4][5] = { 
						{1,1,0,1,1},
						{2,1,1,1,0},
						{1,1,2,3,4},
						{4,0,1,0,0}
						};
	int rows = 4;
	int cols = 5;
	const int arr[4] = { 1,2,3,4 };
	int arrSize = 4;

	io_matrixIntPrint(arr, 1, arrSize);
	printf("\n");
	io_matrixIntPrint(*matrix, rows, cols);

	if (martix_searchArrInMatrix(*matrix, rows, cols, arr, arrSize))
	{
		printf("The array is found in the matrix!");
	}
	else
	{
		printf("The array is NOT found in the matrix!");
	}
	return 0;
}