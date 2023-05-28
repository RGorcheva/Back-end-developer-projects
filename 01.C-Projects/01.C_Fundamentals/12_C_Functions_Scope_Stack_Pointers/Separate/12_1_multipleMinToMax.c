/* 1:
Напишете функция, която изчислява произведението на всички 
цели числа в даден интервал [min, max].
*/

#include "functions_array.h"

int main()
{
	int iMin = 0;
	int iMax = 0;
	int iProduct = 0;

	iMin = io_intEnter("Min");
	iMax = io_intEnter("Max");

	iProduct = multipleMinMax(iMin, iMax);

	printf("\nProduct of numbers from %d to %d is  %d", iMin, iMax, iProduct);
	return 0;
}