/*
Дефинирайте функция за сериализация на масив от обекти от тип UserInfo.
Тествайте с прочитане на файл с множество данни за потребители, променяне на данните и
записване на новата информация в същия файл.
*/

#include "..\Project Vehicle\userInfo.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ARR_SIZE 2

int main(void)
{
	UserInfo userArr[ARR_SIZE];

	FILE* in = NULL;
	FILE* out = NULL;
	char filename[20] = { 0 };     ///userInfoArr.txt
	printf("\nEnter input file name:");
	io_strEnter(filename, 20);

	in = file_open(in, filename, "r");
	userInfoArr_Deserilization(in, userArr, ARR_SIZE);
	file_close(in);

	userInfoArr_Print(userArr, ARR_SIZE);

	out = file_open(out, filename, "w");
	printf("Change drive category!\n");
	for (int i = 0; i < ARR_SIZE; i++)
	{
		userArr[i].driveCategory = userArr[i].driveCategory + 1;
	}
	userInfoArr_Serilization(out, userArr, ARR_SIZE);
	file_close(out);

	in = file_open(in, filename, "r");
	userInfoArr_Deserilization(in, userArr, ARR_SIZE);
	userInfoArr_Print(userArr, ARR_SIZE);
	file_close(in);
	return 0;
}