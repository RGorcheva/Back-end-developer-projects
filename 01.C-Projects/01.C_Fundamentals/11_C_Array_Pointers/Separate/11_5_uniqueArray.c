/*
Напишете програма, която принтира уникалните елементи от масив с цели
числа, въведени от клавиатурата.
*/

#include "functions_array.h"

int main(void)
{
	int iArr[10];
	int iCount = 0;
	int size = (int)sizeof(iArr) / sizeof(int);

	enterArr("iArr", iArr, size);

	int i = 0;
	int j = 0;
	for (i = 0; i < size; ++i)
	{
		iCount = 0;
		for (j = 0; j < size; ++j)
		{
			if (i == j)
			{
				continue;
			}
			if (iArr[i] == iArr[j])
			{
				++iCount;
			}	
		}
		if (iCount == 0)
		{
			printf("\nUnique value: iArr[%d]=%d", i, iArr[i]);
		}
	}
	return 0;
}