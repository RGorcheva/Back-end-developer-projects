/*
Напишете функция, която приема двумерен масив от int с фиксиран
размер 3x4 и иска от потребителя да въведе стойностите на всички
елементи подред, един по един.
*/

#include "../Library/myInputOutput.h"

#define ROWS 3
#define COLS 4

int main(void)
{
	int arr[3][4] = { 0 };

	io_matrixIntEnter(*arr, ROWS, COLS);
	io_matrixIntPrint(*arr, ROWS, COLS);

	return 0;
}

