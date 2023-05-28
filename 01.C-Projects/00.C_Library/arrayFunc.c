#include "arrayFunc.h"
#include "mathFunc.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//ARRAYS

void	array_RandomFill(char* arrName, int* arr, int sizeArr)
{
	//fill array with random values from 1 to 100
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		*i = rand() %100;
	}
}
void	array_randomFillBetweenMinMax(int* arr, int size, int min, int max)
{
	//random fill array from min to max
	for (int* i = arr; i <= arr + size; ++i)
	{
		*i = math_randRange(min, max);
	}
}
void	array_fillFromConsoleBetweenMinMax(int* arr, int size, int min, int max)
{
	//fill array from console in interval (min, Max)
	printf("\nEnter values from %d to %d\n", min, max);
	for (int* i = arr; i < arr + size; ++i)
	{
		printf("[%lld]=", i - arr);
		scanf_s("\n%d", i);
		if (*i < min)
		{
			*i = min;
		}
		else if (*i > max)
		{
			*i = max;
		}
	}
	printf("\n");
}

int		array_countElements(int* arr, int sizeArr, int iNumber)
{
	int iCount = 0;
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		if (*i == iNumber)
		{
			++iCount;
		}
	}
	return iCount;
}
int		array_maxElement(int* arr, int sizeArr)
{
	int* i = arr;
	int max = *i;
	for (i = arr; i < arr + sizeArr; ++i)
	{
		if (*i >= max)
		{
			max = *i;
		}
	}
	return max;
}
int		array_minElement(int* arr, int sizeArr)
{
	int* i = arr;
	int min = *i;
	for (i = arr; i < arr + sizeArr; ++i)
	{
		if (*i <= min)
		{
			min = *i;
		}
	}
	return min;
}
double	array_averageElements(const int* arr, int sizeArr)
{
	double average = 0.0;
	average = (double)array_sumElements(arr, sizeArr) / (double)sizeArr;
	return average;
}
int		array_sumElements(const int* arr, int sizeArr)
{
	const int* i = arr;
	int sum = 0;
	for (i = arr; i < arr + sizeArr; ++i)
	{
		sum += *i;
	}
	return sum;
}

void	array_evenElements(int* arr, int sizeArr, int* evenArr, int sizeEvenArr)
{
	int* j = evenArr;
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		if (*i % 2 == 0)
		{
			*j = *i;
			++j;
		}
	}
}

void	array_oddElements(int* arr, int sizeArr, int* oddArr, int sizeOddArr)
{
	int* j = oddArr;
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		if (*i % 2 == 1)
		{
			*j = *i;
			++j;
		}
	}
}

int		array_multipleElements(const int* arr, int sizeArr)
{
	const int* i = arr;
	int product = 1;
	for (i = arr; i < arr + sizeArr; ++i)
	{
			product *= *i;
	}
	return product;
}

int		array_multipleElementsBetweenMinMax(const int min, const int max)
{
	int product = 1;
	for (int i = min; i <= max; ++i)
	{
		product *= i;
	}
	return product;
}

void	array_nullNegativeElements(int* arr, int sizeArr)
{
	int* i = arr;
	for (i = arr; i < arr + sizeArr; ++i)
	{
		if (*i < 0)
		{
			*i = 0;
		}
	}
}

void	array_copyArrToArr(const int* fromArr, int sizeFrom, int* toArr)
{
	const int *i = fromArr;
	int *j = toArr;
	for (i = fromArr; i < fromArr + sizeFrom; ++i)
	{
		*j = *i;
		++j;
	}
}

void	array_exchangeTwoArraies(int* arr1, int sizeArr1, int* arr2)
{
	int* i = arr1;
	int* j = arr2;
	int c = 0;
	for (i = arr1; i < arr1 + sizeArr1; ++i)
	{
		c = *j;
		*j = *i;
		*i = c;
		++j;
	}
}

//MATRIXES

int		martix_isIdentity(const double* arr, int rows, int cols)
{
	int count = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if ((i == j) && (math_dequals(arr[i * cols + j], 1.0)))
			{
				++count;
			}
			if ((i != j) && (math_dequals(arr[i * cols + j], 0.0)))
			{
				++count;
			}
		}
	}
	if (count == rows * cols)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void	martix_sumMatrixPlusMatrix(double (*arrA)[COLS_4], double (*arrB)[COLS_4], double (*arrSum)[COLS_4], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < COLS_4; ++j)
		{
			arrSum[i][j] = arrA[i][j] + arrB[i][j];
		}
	}
}

void	martix_multipleMatrixWithNumber(double* arr, double* arrMult, int rows, int cols, double num)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			arrMult[i*cols + j] = arr[i*cols + j] * num;
		}
	}
}

void	martix_multipleMatrixWithVector(double* arr, double* vecMult, double* vector, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			vecMult[i] += arr[i * rows + j] * vector[j];
		}
	}
}

void	martix_multipleMatrixWithMatrix(double* arr1, double* arr2, double* arrMult, int size)
{
	for (int row = 0; row < size; ++row)
	{
		for (int col = 0; col < size; ++col)
		{
			for (int it = 0; it < size; ++it)
			{
				arrMult[row * size + col] += arr1[row * size + it] * arr2[it * size + col];
			}
		}
	}
}

void	martix_exchangeRows(int* arr, int rows, int cols, int rowM, int rowN)
{
	int temp = 0;
	for (int j = 0; j < cols; ++j)
	{
		temp = arr[rowM * cols + j];
		arr[rowM * cols + j] = arr[rowN * cols + j];
		arr[rowN * cols + j] = temp;
	}
}

void	martix_exchangeCols(int* arr, int rows, int cols, int colM, int colN)
{
	int temp = 0;
	for (int i = 0; i < rows; ++i)
	{
		temp = arr[i * cols + colM];
		arr[i * cols + colM] = arr[i * cols + colN];
		arr[i * cols + colN] = temp;
	}
}

int		martix_areEquals(const double* arrA, const double* arrB, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (!math_dequals(arrA[i * cols + j], arrB[i * cols + j]))
			{
				return 0;
			}
		}
	}
	return 1;
}

int		martix_searchArrInMatrix(const int* matrix, int rows, int cols, const int* arr, int arrSize)
{
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - arrSize + 1; j++)
		{
			for (int s = 0; s < arrSize; s++)
			{
				if (*(arr + s) == *(matrix + i * cols + j + s))
				{
					++count;
				}

			}
			if (count == arrSize)
				{
					return 1;
					break;
				}
			count = 0;
		}

	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows - arrSize + 1; j++)
		{
			for (int s = 0; s < arrSize; s++)
			{
				if (*(arr + s) == *(matrix + (j + s) * rows + i))
				{
					++count;
				}
				if (count == arrSize)
				{
					return 1;
					break;
				}
			}
			count = 0;
		}

	}
	return 0;
}

int		martix_searchMatrixInMatrix(const int* matrixSearchIn, int Rows, int Cols, const int* matrixFind, int rows, int cols)
{
	int count = 0;
	for (int i = 0; i < Rows - rows + 1; i++)
	{
		for (int j = 0; j < Cols - cols + 1; j++)
		{
			count = 0;
			for (int m = 0; m < rows; m++)
			{
				for (int n = 0; n < cols; n++)
				{
					if (matrixFind[m * cols + n] == matrixSearchIn[(i + m) * Cols + (j + n)])
					{
						++count;
					}
					if (count == rows * cols)
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;	
}

int		martix_searchCharArrInCharMatrix(const char* matrix, int ROW, int COL, const char* arr)
{
	int countAppear = 0;
	int arrSize = (int)strlen(arr);
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL - arrSize + 1; col++)
		{
			int symbol = 0;
			for (; symbol < arrSize; symbol++)
			{
				if (*(arr + symbol) != *(matrix + row * COL + col + symbol))
				{
					break;
				}
			}
			if (symbol == arrSize)
			{
				++countAppear;
			}
		}
	}
	for (int col = 0; col < COL; col++)
	{
		for (int row = 0; row < ROW - arrSize + 1; row++)
		{
			int symbol = 0;
			for (; symbol < arrSize; symbol++)
			{
				if (*(arr + symbol) != *(matrix + (row + symbol) * COL + col))
				{
					break;
				}
			}
			if (symbol == arrSize)
			{
				++countAppear;
			}
		}
	}
	return countAppear;
}

int		martix_countUniqueCols(const int* matrix, int rows, int cols)
{
	int countEqualsElementsInColumn = 0;
	int countUniqueColsInLoop = 0;
	int UniqueColInMatrix = 0;
	for (int m = 0; m < cols; m++)
	{
		countUniqueColsInLoop = 0;
		for (int j = 0; j < cols; j++)
		{
			if (m == j) { continue; }
			countEqualsElementsInColumn = 0;
			for (int i = 0; i < rows; i++)
			{
				if (*(matrix + i * cols + m) == *(matrix + i * cols + j))
				{
					++countEqualsElementsInColumn;
				}
			}
			if (countEqualsElementsInColumn < rows)
			{
				++countUniqueColsInLoop;
			}
		}
		if (countUniqueColsInLoop == cols - 1)
		{
			++UniqueColInMatrix;
		}
	}
	return UniqueColInMatrix;
}

void	martix_copyMatrixToArr(const int* matrix, int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = matrix[i];
	}
}

void	martix_copyMatrixToArrBackwards(const int* matrix, int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = matrix[size - i - 1];
	}
}




