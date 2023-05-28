/*
Да се напише функция, която напълва двумерен масив с определен символ.
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char matrix[3][4] = { 0 };
	char ch = 'f';
	int row = 3;
	int col = 4;
	string_matrixFillChar(*matrix, row, col, ch);
	return 0;
}
