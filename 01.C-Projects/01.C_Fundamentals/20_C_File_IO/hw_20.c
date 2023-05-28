#include "hw_20.h"
#include "..\Project Vehicle\vehicleList.h"
#include "..\Project Vehicle\userInfo.h"
#include "..\Project Vehicle\brandDetails.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ARR_SIZE 2

void hw_20_1_userInfoChangeFile(void)
/*
Дефинирайте структура UserInfo със следните данни за всеки потребител:
● Категория на шофьорска книжка ( ползвайте enum за различните категории )
● Три имена
● ЕГН ( PIN )
Дефинирайте функции за сериализация(писане) и десериализация(четене) на обект от тип UserInfo.
Тествайте с текстов файл с данни за потребител и програма, която прочита файла, променя нещо и
го записва във същия файл.
*/
{
	printf("\n-----------------task 20_1-----------------------\n");
	UserInfo user;

	FILE* in = NULL;
	FILE* out = NULL;
	char filename[20]; //userInfo.txt
	printf("\nEnter input file name:");
	io_strEnter(filename, 20);

	in = file_open(in, filename, "r");
	userInfoObject_Deserilization(in, &user);
	file_close(in);

	userInfoObject_Print(&user);

	out = file_open(out, filename, "w");
	printf("Change drive category!\n");
	user.driveCategory = user.driveCategory + 1;
	userInfoObject_Serilization(out, &user);
	file_close(out);

	in = file_open(in, filename, "r");
	userInfoObject_Deserilization(in, &user);
	userInfoObject_Print(&user);
	file_close(in);
}
void hw_20_2_userInfoArrChangeFile(void)
/*
Дефинирайте функция за сериализация на масив от обекти от тип UserInfo.
Тествайте с прочитане на файл с множество данни за потребители, променяне на данните и
записване на новата информация в същия файл.
*/
{
	printf("\n-----------------task 20_2-----------------------\n");
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
}
void hw_20_4_brandSerilization(void)
/*
За програмата с отдаване на МПС под наем, направете следната функционалност:
Дефинирайте функции за сериализация и десериализация на типовете, които ползвате за съхранение
на информация за марка и за информация за модел (Meeting17_structures - Задача 8 (2/2))
Дефинирайте функции за сериализиране и десериализиране на обектите от тези типове, които се
съхраняват в модула, който е предназначен за съхранението на общата информация за марки и
модели на МПС.
Извикайте функцията за прочитане на данните от файл при стартиране на приложението.
*/
{
	printf("\n-----------------task 20_4-----------------------\n");
	listBrand* pfirst = NULL;
	pfirst = brandList_deserilization(pfirst);
	brandList_print(pfirst);

	brandList_serilization(pfirst);
	pfirst = brandList_empty(pfirst);
	brandList_print(pfirst);
}
void hw_20_5_brandPushBack(void)
/*
Добавете подменю в MainMenu, в което да позволява въвеждане на информация за нова марка и
модел, след което записва нововъведената информация във файла, който съдържа всички данни за
марки и модели МПС.
*/
{
	printf("\n-----------------task 20_5-----------------------\n");
	listBrand* pfirst = NULL;
	pfirst = brandList_deserilization(pfirst);
//	brandList_print(pfirst);

	BrandDetails brandObject;
	brandObject_Initializatoin(&brandObject);

	brandList_pushBack(pfirst, &brandObject);

	brandList_print(pfirst);
	brandList_serilization(pfirst);
	pfirst = brandList_empty(pfirst);
	brandList_print(pfirst);
}
void hw_20_7_vehicleSerilization(void)
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
{
	printf("\n-----------------task 20_7-----------------------\n");
	listVehicle* pfirst = NULL;
	pfirst = vehicleList_deserilization(pfirst);
	vehicleList_print(pfirst);

	vehicleList_serilization(pfirst);
	pfirst = vehicleList_empty(pfirst);
	vehicleList_print(pfirst);
}
void hw_20_8_vehiclePushBack(void)
/*
Направете меню за добавяне на новозакупен автомобил, който може да бъде даван под наем, както и за
премахване от автомобил от списъка с автомобили, с които разполага компанията.
Запазвайте промените във файл(файл с фирмени ПС)
*/
{
	printf("\n-----------------task 20_8-----------------------\n");
	listVehicle* pfirst = NULL;
	pfirst = vehicleList_deserilization(pfirst);
//	vehicleList_print(pfirst);

	vehicleList_insert(pfirst, 1);
	vehicleList_print(pfirst);
	vehicleList_delete(pfirst, 1);

	VehicleInfo vehicleObject;
	vehicleObject_Initializatoin(&vehicleObject);
	vehicleList_pushBack(pfirst, &vehicleObject);

	vehicleList_serilization(pfirst);
	pfirst = vehicleList_empty(pfirst);
	vehicleList_print(pfirst);
}