/*
Добавете подменю в MainMenu, в което да позволява въвеждане на информация за нова марка и
модел, след което записва нововъведената информация във файла, който съдържа всички данни за
марки и модели МПС.
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

	BrandDetails brandObject;
	brandObject_Initializatoin(&brandObject);

	brandList_pushBack(pfirst, &brandObject);

	brandList_print(pfirst);
	brandList_serilization(pfirst);
	pfirst = brandList_empty(pfirst);
	brandList_print(pfirst);
	return 0;
}
