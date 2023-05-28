/*
Напишете функция, която връща общия брой на срещанията на всички стрингове
от подаден масив от стрингове в двуизмерен масив от char, по редове и колони.
Пример:
● { “cat”, “bat”, “hat”, “bit” }
● c a t h b a t
  x r a t i j k
  f s q y t k u
● Резултат: 3
*/

#include "../Library/myInputOutput.h"
#include "../Library/functionsArray.h"
#include <stdio.h>

int main(void)
{
	const char matrix[3][7] = {
						{'c','a','t','h','b','a','t'},
						{'a','r','a','t','i','j','k'},
						{'t','s','q','y','t','k','u'},
	};
	int rows = 3;
	int cols = 7;
	const char* arr[4] = { "cat", "bat", "hat", "bit" };
	int count[4] = { 0 };
	int arrSize = 4;
	io_matrixCharPrint(*matrix, rows, cols);
	int* pCount = count;
	for (int i = 0; i < arrSize; ++i, ++pCount)
	{
		*pCount = martix_searchCharArrInCharMatrix(*matrix, rows, cols, arr[i]);
		printf("\n%s - %d", arr[i], count[i]);
	}

	return 0;
}