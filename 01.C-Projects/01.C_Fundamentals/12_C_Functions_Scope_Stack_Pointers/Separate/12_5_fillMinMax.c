/* 5:
Напишете функция, която запълва елементите на масив от цели числа с произволни
числа от подаден интервал [min, max]
*/

#include "../functions_array.h"
#include "../Library/myMath.h"
#include <time.h>
#include <stdlib.h>

int main(void)
{
	srand((int)time(NULL));

	int iArr[10] = {0};
	int size = (int)sizeof(iArr) / sizeof(int);
	int min = -1;
	int max = -1;
	min = io_intEnter("min");
	max = io_intEnter("max");
	randomFillIntervalArr(iArr, size, min, max);

	io_arrPrintSquareScopes("iArr", iArr, size);
	return 0;
}