/* 6:
Напишете функция, която запълва масив от цели числа с въведени от потребителя
стойности
● Ползвайте функциите от горните три задачи за тестване с примерни стойности в
тестовите функции
*/

#include "functions_array.h"

int main(void)
{
	int iArr[8] = { 0 };
	int size = (int)sizeof(iArr) / sizeof(int);
	io_arrEnter("iArr", iArr, size);
	io_arrPrintSquareScopes("iArr", iArr, size);

	return 0;
}