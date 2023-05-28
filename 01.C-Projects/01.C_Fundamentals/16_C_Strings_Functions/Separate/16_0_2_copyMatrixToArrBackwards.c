/*
Да се напише функция, която копира двумерен масив в едномерен със същия брой елементи, но в обратен ред.
*/

#define SIZE 6
#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

int main(void)
{
	const int matrix[2][3] = { 0 };
	int arr[SIZE] = { 0 };

	io_matrixIntEnter(*matrix, 2, 3);
	martix_copyMatrixToArrBackwards(*matrix, arr, SIZE);
	io_matrixIntPrint(*matrix, 2, 3);
	printf("\n");
	io_matrixIntPrint(arr, 1, SIZE);

	return 0;
}
