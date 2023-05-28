/*
Дефинирайте двумерен масив от int и го инициализирайте
Напишете вложен цикъл, който да го принтира в таблична форма.
*/

#include "../Library/myInputOutput.h"

int main(void)
{
	int arr[2][3] = {
						{0,1,2},
						{3,4,5}
					};
	int rows = 2;
	int cols = 3;

	io_matrixIntPrint(*arr, rows, cols);

	return 0;
}