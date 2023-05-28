/*
Напишете функция, която приема двумерен масив от int с вариращ
брой редове, но с фиксиран брой колони - 4. Функцията трябва да
принтира масива в табличен вид.
Ползвайте ‘\t’ за подравняване на изхода по колони.
*/

#include "../Library/myInputOutput.h"

#define ROWS 3
#define COLS 4

int main(void)
{
	int arr[3][4] = {0};

	io_matrixIntEnterFixCols(arr, ROWS);
	io_matrixIntPrintFixCols(arr, ROWS);

	return 0;
}
