/*
Напишете програма, която проверява дали две дадени матрици от float са еднакви,
сравнявайки съответните елементи в тях. Разпечатайте в конзолата двете изходни
матрици и резултата от сравнението.
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"

#define ROWS_4 4

int main(void)

{
	double arrA[ROWS_4][COLS_4] = { 0 };
	double arrB[ROWS_4][COLS_4] = { 0 };

	io_matrixDoubleEnter(*arrA, ROWS_4, COLS_4);
	io_matrixDoubleEnter(*arrB, ROWS_4, COLS_4);

	io_matrixDoublePrint(*arrA, ROWS_4, COLS_4);
	io_matrixDoublePrint(*arrB, ROWS_4, COLS_4);

	(martix_areEquals(*arrA, *arrB, ROWS_4, COLS_4)) ? printf("\nEquals!\n") : printf("\nNot Equals!\n");

	return 0;
}

