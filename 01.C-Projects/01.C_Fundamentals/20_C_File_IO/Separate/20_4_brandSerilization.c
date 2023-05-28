/*
За програмата с отдаване на МПС под наем, направете следната функционалност:
Дефинирайте функции за сериализация и десериализация на типовете, които ползвате за съхранение
на информация за марка и за информация за модел (Meeting17_structures - Задача 8 (2/2))
Дефинирайте функции за сериализиране и десериализиране на обектите от тези типове, които се
съхраняват в модула, който е предназначен за съхранението на общата информация за марки и
модели на МПС.
Извикайте функцията за прочитане на данните от файл при стартиране на приложението.
*/

#include "../Project Vehicle/brandDetails.h"
#include "../Library/stringFunc.h"
#include "../Library/inputOutputFunc.h"
#include "../Library/fileFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	listBrand* pfirst = NULL;
	pfirst = brandList_deserilization(pfirst);
	brandList_print(pfirst);

	brandList_serilization(pfirst);
	pfirst = brandList_empty(pfirst);
	brandList_print(pfirst);
	return 0;
}
