/*
Напишете функция, която разменя две колони на матрица, по подадени аргументи за
индекси на колоните, които да се разменят.*/#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

#define ROWS_3 3
#define COLS_4 4

int main(void)
{
	int arr[ROWS_3][COLS_4];
	int colM = 0;
	int colN = 0;
	
	colM = io_intEnter("col M");
	colN = io_intEnter("col N");

	io_matrixIntEnter(*arr, ROWS_3, COLS_4);
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);
	martix_exchangeCols(*arr, ROWS_3, COLS_4, colM, colN);
	printf("\n");
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);

	return 0;
}


