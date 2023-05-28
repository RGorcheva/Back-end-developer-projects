/*
Рефакторирайте структурата, която съдържа информация за превозно средство, с което компанията
разполага да съдържа следната информация:
● Марка
● Модел
● Необходима категория за шофьорска книжка (използвайте enum-а от Задача 1)
● VIM (Уникален идентификационен номер)
● Година на производство
Дефинирайте функции за сериализиране и десериализиране на обектите от тези типове, които се
съхраняват в модула, който е предназначен за съхранението и обработката на общата информация за
превозните средства, с които разполага компанията.
Извикайте функцията за прочитане на данните от файл(файл с фирмени ПС) при стартиране на
приложението
*/

#include "..\Project Vehicle\vehicleList.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"


int main(void)
{
	listVehicle* pfirst = NULL;
	pfirst = vehicleList_deserilization(pfirst);
	vehicleList_print(pfirst);

	vehicleList_serilization(pfirst);
	pfirst = vehicleList_empty(pfirst);
	vehicleList_print(pfirst);
	return 0;
}

