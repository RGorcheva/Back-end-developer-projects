#include "hw_13.h"
#include "../Library/inputOutputFunc.h"
#include "../Library/arrayFunc.h"
#include <stdio.h>

#define ROWS_3 3
#define COLS_3 3
#define ROWS_4 4
#define COLS_4 4

void hw_13_0_1_PrintMatrix(void)
/*
Дефинирайте двумерен масив от int и го инициализирайте
Напишете вложен цикъл, който да го принтира в таблична форма.
*/
{
	printf("\n----------------task 13_0_1------------------\n");
	int arr[2][3] = {
					{0,1,2},
					{3,4,5}
	};
	int rows = 2;
	int cols = 3;

	io_matrixIntPrint(*arr, rows, cols);
}
void hw_13_0_2_enterPrintMatrix(void)
/*
Напишете функция, която приема двумерен масив от int с фиксиран
размер 3x4 и иска от потребителя да въведе стойностите на всички
елементи подред, един по един.
*/
{
	printf("\n----------------task 13_0_2------------------\n");
	int arr[3][4] = { 0 };

	io_matrixIntEnter(*arr, ROWS_3, COLS_4);
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);
}
void hw_13_0_3_enterPrintMatrixOnlyColumn(void)
/*
Напишете функция, която приема двумерен масив от int с вариращ
брой редове, но с фиксиран брой колони - 4. Функцията трябва да
принтира масива в табличен вид.
Ползвайте ‘\t’ за подравняване на изхода по колони.
*/
{
	printf("\n----------------task 13_0_3------------------\n");
	int arr[3][4] = { 0 };

	io_matrixIntEnterFixCols(arr, ROWS_3);
	io_matrixIntPrintFixCols(arr, ROWS_3);
}
void hw_13_1_sumMatrixs(void)
/*
Напишете програма, която събира две 4х4 матрици от float и записва резултата в
трета такава със същия размер. Събирането на матриците става като намерим
сумата на съответстващите елементи в тях. Данните за изходните матрици трябва
да бъдат въведени от потребителя. Разпечатайте трите матрици в конзолата.
*/
{
	printf("\n----------------task 13_1------------------\n");
	double arrA[ROWS_4][COLS_4] = { 0 };
	double arrB[ROWS_4][COLS_4] = { 0 };
	double arrSum[ROWS_4][COLS_4] = { 0 };

	io_matrixDoubleEnter(*arrA, ROWS_4, COLS_4);
	io_matrixDoubleEnter(*arrB, ROWS_4, COLS_4);
	martix_sumMatrixPlusMatrix(&*arrA, &*arrB, &*arrSum, ROWS_4);
	io_matrixDoublePrint(*arrA, ROWS_4, COLS_4);
	io_matrixDoublePrint(*arrB, ROWS_4, COLS_4);
	io_matrixDoublePrint(*arrSum, ROWS_4, COLS_4);
}
void hw_13_2_IsEqualsMatrix(void)
/*
Напишете програма, която проверява дали две дадени матрици от float са еднакви,
сравнявайки съответните елементи в тях. Разпечатайте в конзолата двете изходни
матрици и резултата от сравнението.
*/
{
	printf("\n----------------task 13_2------------------\n");
	double arrA[ROWS_4][COLS_4] = { 0 };
	double arrB[ROWS_4][COLS_4] = { 0 };

	io_matrixDoubleEnter(*arrA, ROWS_4, COLS_4);
	io_matrixDoubleEnter(*arrB, ROWS_4, COLS_4);

	io_matrixDoublePrint(*arrA, ROWS_4, COLS_4);
	io_matrixDoublePrint(*arrB, ROWS_4, COLS_4);

	(martix_areEquals(*arrA, *arrB, ROWS_4, COLS_4)) ? printf("\nEquals!\n") : printf("\nNot Equals!\n");
}
void hw_13_3_isIdentityMatrix(void)
/*
Напишете функция, която проверява дали дадена float матрица е identity matrix -
матрица с размер (N x N), където само елементите в главния диагонал са единици, а
всички останали елементи са нули.
*/
{
	printf("\n----------------task 13_3------------------\n");
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
}
void hw_13_4_exchangeRowsInMatrix(void)
/*
Напишете функция, която размерня два реда на матрица, по подадени аргументи за
индекси на редовете, които да се разменят.
*/
{
	printf("\n----------------task 13_4------------------\n");
	int arr[ROWS_3][COLS_4];
	int rowM = 0;
	int rowN = 0;

	rowM = io_intEnter("row M between 0 and 2");
	rowN = io_intEnter("row N between 0 and 2");
	io_matrixIntEnter(*arr, ROWS_3, COLS_4);
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);
	martix_exchangeRows(*arr, ROWS_3, COLS_4, rowM, rowN);
	printf("\n");
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);
}
void hw_13_5_exchangeColssInMatrix(void)
/*
Напишете функция, която разменя две колони на матрица, по подадени аргументи за
индекси на колоните, които да се разменят.
*/
{
	printf("\n----------------task 13_5------------------\n");
	int arr[ROWS_3][COLS_4];
	int colM = 0;
	int colN = 0;

	colM = io_intEnter("col M between 0 and 3");
	colN = io_intEnter("col N between o and 3");

	io_matrixIntEnter(*arr, ROWS_3, COLS_4);
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);
	martix_exchangeCols(*arr, ROWS_3, COLS_4, colM, colN);
	printf("\n");
	io_matrixIntPrint(*arr, ROWS_3, COLS_4);
}
void hw_13_6_multipleMatrixWithNumber(void)
/*
Напишете функция, която умножава всеки елемент на 3x3 float матрица с float
число.
*/
{
	printf("\n----------------task 13_6------------------\n");
	double arr[ROWS_3][COLS_3] = { 0 };
	double multipleArr[ROWS_3][COLS_3] = { 0 };
	double dNumber = 0.0;

	dNumber = io_intEnter("number");
	io_matrixDoubleEnter(*arr, ROWS_3, COLS_3);
	martix_multipleMatrixWithNumber(*arr, *multipleArr, ROWS_3, COLS_3, dNumber);
	io_matrixDoublePrint(*arr, ROWS_3, COLS_3);
	io_matrixDoublePrint(*multipleArr, ROWS_3, COLS_3);
}
void hw_13_7_multipleMatrixWithVector(void)
/*
Напишете функция, която умножава 3-мерен float вектор(едномерен масив с три
float елемента) по 3x3 float матрицa
*/

{
	printf("\n----------------task 13_7------------------\n");
	double arr[ROWS_3][ROWS_3] = { 0 };
	double multipleVector[ROWS_3] = { 0 };
	double vector[ROWS_3] = { 0 };

	io_matrixDoubleEnter(vector, ROWS_3, 1);
	io_matrixDoubleEnter(*arr, ROWS_3, ROWS_3);

	martix_multipleMatrixWithVector(*arr, multipleVector, vector, ROWS_3);
	io_matrixDoublePrint(*arr, ROWS_3, ROWS_3);
	io_matrixDoublePrint(vector, ROWS_3, 1);
	io_matrixDoublePrint(multipleVector, ROWS_3, 1);
}
void hw_13_8_multipleMatrixWithMatrix(void)
/*
Напишете функция, която умножава две 3x3 float матрици
*/
{
	printf("\n----------------task 13_8------------------\n");
	double arr1[ROWS_3][COLS_3] = { 0 };
	double arr2[ROWS_3][COLS_3] = { 0 };
	double multipleArr[ROWS_3][COLS_3] = { 0 };

	io_matrixDoubleEnter(*arr1, ROWS_3, COLS_3);
	io_matrixDoubleEnter(*arr2, ROWS_3, COLS_3);

	martix_multipleMatrixWithMatrix(*arr1, *arr2, *multipleArr, ROWS_3);
	io_matrixDoublePrint(*arr1, ROWS_3, COLS_3);
	io_matrixDoublePrint(*arr2, ROWS_3, COLS_3);
	io_matrixDoublePrint(*multipleArr, ROWS_3, COLS_3);
}
void hw_13_9_countUniqueColsInMatrix(void)
/*
Напишете програма, която печата броя на уникалните колони в бинарна
матрица, съставена само от единици и нули.
*/
{
	printf("\n----------------task 13_9------------------\n");
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
	printf("%d unique columns.", countUniqueCols);
}
void hw_13_10_sumRowsSumCols(void)
/*
Напишете програма, която принтира сумата на всеки ред и на всяка колона
на една матрица.
*/
{
	printf("\n----------------task 13_10------------------\n");
	double arr[ROWS_3][COLS_4] = { 0 };
	double sum = 0;

	io_matrixDoubleEnter(*arr, ROWS_3, COLS_4);
	io_matrixDoublePrint(*arr, ROWS_3, COLS_4);

	for (int i = 0; i < ROWS_3; ++i)
	{
		sum = 0;
		for (int j = 0; j < COLS_4; ++j)
		{
			sum += arr[i][j];
		}
		printf("\nSum of row %d = %.2lf", i, sum);
	}
	for (int i = 0; i < COLS_4; ++i)
	{
		sum = 0;
		for (int j = 0; j < ROWS_3; ++j)
		{
			sum += arr[j][i];
		}
		printf("\nSum of column %d = %.2lf", i, sum);
	}
}
void hw_13_11_searchArrInMatrix(void)
/*
Напишете функция, която претърсва за последователност от стойности (подадени
в едномерен масив) в редовете и колоните на двумерен масив. Функцията връща 1
ако е открила последователността, в някой ред или колона и 0 ако не е.
*/
{
	printf("\n----------------task 13_11------------------\n");
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
}
void hw_13_12_searchMatrixInMatrix(void)
/*
Напишете функция, която търси за под-матрица в матрица (подобно на миналата
задача, но търсим за двумерен масив)
*/
{
	printf("\n----------------task 13_12------------------\n");
	const int matrixSearchIn[6][5] = {
					{0,1,0,1,1},
					{1,1,1,1,0},
					{1,0,0,1,0},
					{1,1,1,1,0},
					{1,1,1,1,1},
					{0,1,0,1,0}
	};
	int Rows = 6;
	int Cols = 5;
	const int matrixFind[4][4] = {
					{1,1,1,1},
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
}