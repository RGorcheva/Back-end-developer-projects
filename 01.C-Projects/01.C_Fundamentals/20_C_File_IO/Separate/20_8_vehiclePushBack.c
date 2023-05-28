/*
Направете меню за добавяне на новозакупен автомобил, който може да бъде даван под наем, както и за
премахване от автомобил от списъка с автомобили, с които разполага компанията.
Запазвайте промените във файл(файл с фирмени ПС)
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

	vehicleList_insert(pfirst, 1);
	vehicleList_print(pfirst);
	vehicleList_delete(pfirst, 1);

	VehicleInfo vehicleObject;
	vehicleObject_Initializatoin(&vehicleObject);
	vehicleList_pushBack(pfirst, &vehicleObject);

	vehicleList_serilization(pfirst);
	pfirst = vehicleList_empty(pfirst);
	vehicleList_print(pfirst);
	return 0;
}


