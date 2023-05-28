#ifndef FUNCTION_ARRAY_H
#define FUNCTION_ARRAY_H

void	enterArr(char* arrName, int* arr, int sizeArr);
void	randomFillArr(int* arr, int sizeArr);
void	printArr(char* arrName, int* arr, int sizeArr);
void	printBackwardsArr(char* arrName, int* arr, int sizeArr);
int		maxArr(int* arr, int sizeArr);
int		minArr(int* arr, int sizeArr);
int		countNumber(int* arr, int sizeArr, int iNumber);
void	oddArray(int* arr, int sizeArr, int* oddArr, int sizeOddArr);
void	evenArray(int* arr, int sizeArr, int* evenArr, int sizeEvenArr);

#endif