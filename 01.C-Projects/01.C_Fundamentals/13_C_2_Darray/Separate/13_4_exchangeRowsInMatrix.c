/*
Напишете функция, която размерня два реда на матрица, по подадени аргументи за
индекси на редовете, които да се разменят.
*/
#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

#define ROWS_3 3
#define COLS_4 4

int main(void)
{
	int arr[ROWS_3][COLS_4];
	int rowM = 0;
	int rowN = 0;

	rowM = io_intEnter("row M");
	rowN = io_intEnter("row N");
	io_matrixIntEnter(*arr, ROWS_3, COLS_4);
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);
	martix_exchangeRows(*arr, ROWS_3, COLS_4, rowM, rowN);
	printf("\n");
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);
	
	return 0;
}



