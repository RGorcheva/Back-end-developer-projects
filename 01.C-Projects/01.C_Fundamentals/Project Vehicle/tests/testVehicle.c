#include "..\Project Vehicle\vehicleList.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

enum DrivingLicense { A1, A2, A, B, B1, C, D, BE, CE, DE, T };

//typedef struct listVehicle
//{
//	VehicleInfo vehicle;
//	struct listVehicle* next;
//} listVehicle;


bool list_isEmpty(listVehicle* list)
{
	return list == NULL;
}
void list_init(listVehicle* list)
{
	list = NULL;
}
int list_countElements(listVehicle* list)
{
	if (list == NULL)
		return 0;
	int count = 0;
	while (list != NULL)
	{
		++count;
		list = list->next;
	}
	return count;
}
void list_print(listVehicle* list)
{
	if (list == NULL)
		return;
	while (list != NULL)
	{
		vehicleObject_Print(&list->vehicle);
		list = list->next;
	}
	printf("\n------------------------------------\n");
}
listVehicle* list_findIndexN(listVehicle* list, int indx)
{
	int countIndex = 0;
	while (list != NULL)
	{
		if (countIndex == indx)
			return list;
		countIndex++;
		list = list->next;
	}
	return NULL;
}
listVehicle* list_findLast(listVehicle* list)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	return list;
}
void list_copyStruct(listVehicle* list, VehicleInfo* pVehicleObject)
{
	list->vehicle.vehicleID = pVehicleObject->vehicleID;
	strcpy(list->vehicle.brand, pVehicleObject->brand);
	strcpy(list->vehicle.model, pVehicleObject->model);
	strcpy(list->vehicle.VIN, pVehicleObject->VIN);
	list->vehicle.yearOfМanufacture = pVehicleObject->yearOfМanufacture;
	list->vehicle.driveCatNeeded = pVehicleObject->driveCatNeeded;
	list->vehicle.pricePerDay = pVehicleObject->pricePerDay;
	list->vehicle.isRented = pVehicleObject->isRented;
}
listVehicle* list_pushBack(listVehicle* list, VehicleInfo* pVehicleObject)
{
	listVehicle* pNew = (listVehicle*)malloc(sizeof(listVehicle));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return NULL;
	}
	list_copyStruct(pNew, pVehicleObject);
	pNew->next = NULL;

	if (list == NULL)
	{
		list = pNew;
	}
	else
	{
		listVehicle* plast = list_findLast(list);
		plast->next = pNew;
	}
	return list;
}
void list_insert(listVehicle* list, int indx)
{
	VehicleInfo vehicle;
	VehicleInfo* pVehicleObject = &vehicle;
	vehicleObject_Initializatoin(pVehicleObject);

	listVehicle* pNew = (listVehicle*)malloc(sizeof(listVehicle));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	list_copyStruct(pNew, pVehicleObject);
	listVehicle* prev = list_findIndexN(list, indx - 1);
	pNew->next = prev->next;
	prev->next = pNew;
}
listVehicle* list_empty(listVehicle* list)
{
	if (list == NULL)
	{
		printf("\nlist is NULL pointer!!!");
		return NULL;
	}
	while (list != NULL)
	{
		listVehicle* temp = list->next;
		free(list);
		list = temp;
	}
	return NULL;
}
listVehicle* list_delete(listVehicle* list, int indx)
{
	if (list == NULL)
		return NULL;
	if (indx == 0)
	{
		listVehicle* first = list->next;
		free(list);
		return first;
	}
	listVehicle* first = list;
	int count = 0;
	while (count != indx - 1)
	{
		++count;
		list = list->next;
	}
	listVehicle* prev = list;
	list = list->next;
	prev->next = list->next;
	free(list);
	return first;
}
FILE* int_deserilization(FILE* in, int* pCount)
{
	int ifscan = fscanf(in, "(%d)\n", pCount);
	return in;
}
FILE* int_serilization(FILE* out, int* pCount)
{
	fprintf(out, "(%d)\n", *pCount);
	return out;
}
listVehicle* list_deserilization(listVehicle* list)
{
	FILE* in = NULL;
	char filename[20] = { 0 };
	printf("\nEnter input file name:");
	io_strEnter(filename, 20);
	in = file_open(in, filename, "r");

	int countElements = 0;
	int* pCount = &countElements;
	in = int_deserilization(in, pCount);
	printf("\nCount elem = %d", countElements);

	listVehicle* pfirst = NULL;
	for (int i = 0; i < countElements; i++)
	{
		VehicleInfo vehicleObject;
		VehicleInfo* pVehicleObject = &vehicleObject;
		in = vehicleObject_Deserilization(in, pVehicleObject);
		pfirst = list_pushBack(pfirst, pVehicleObject);
	}
	return pfirst;
}
void list_serilization(listVehicle* list, int* pCountElements)
{
	FILE* out = NULL;
	char filename[20] = { 0 };
	printf("\nEnter input file name:");// ..\Data\vehicleList.txt
	io_strEnter(filename, 20);
	out = file_open(out, filename, "w");

	out = int_serilization(out, pCountElements);

	while (list != NULL)
	{
		vehicleObject_Serilization(out, &list->vehicle);
		list = list->next;
	}
	file_close(out);
}

int main(void)
{
	listVehicle* pfirst = NULL;
	pfirst = vehiclelist_deserilization(pfirst);
	vehiclelist_print(pfirst);

	vehiclelist_insert(pfirst, 2);
	vehiclelist_print(pfirst);
	pfirst = list_delete(pfirst, 2);
	list_print(pfirst);
	int iCountElements = vehiclelist_countElements(pfirst);
	printf("\nNumber of elements: %d\n", iCountElements);
	vehiclelist_serilization(pfirst, &iCountElements);
	pfirst = vehiclelist_empty(pfirst);
	vehiclelist_print(pfirst);
	return 0;
}