#include "vehicleList.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum DrivingLicense { A1, A2, A, B, B1, C, D, BE, CE, DE, T };

static const char* FORMAT_VEHICLEINFO_DESERILIZATOIN = "(%u, %[^,], %[^,], %[^,], %u, %d, %f, %u)\n";
static const char* FORMAT_VEHICLEINFO_SERILIZATION = "(%u, %s, %s, %s, %u, %d, %f, %u)\n";
static const char* FORMAT_VEHICLEINFO_PRINT = "\nVehicle ID: %u\n--------------\n%s\t%s\nVIN: %s\nYear of manufacture: %u\n"
"Driving licence category needed: %s\nPricePerDay: %.2f BGN\nAvailable for rent: %s\n";

FILE*		 vehicleObject_Deserilization(FILE* in, VehicleInfo* pVehicleObject)
{
	int ifscan = fscanf(in, FORMAT_VEHICLEINFO_DESERILIZATOIN, &pVehicleObject->vehicleID, &pVehicleObject->brand, &pVehicleObject->model, &pVehicleObject->VIN, &pVehicleObject->yearOfМanufacture, &pVehicleObject->driveCatNeeded, &pVehicleObject->pricePerDay, &pVehicleObject->isRented);
	return in;
}
void		 vehicleObject_Print(VehicleInfo* pVehicleObject)
{
	char* driveCat = NULL;
	switch (pVehicleObject->driveCatNeeded)
	{
	case A1: driveCat = "A1"; break;
	case A2: driveCat = "A2"; break;
	case A: driveCat = "A"; break;
	case B: driveCat = "B"; break;
	case B1: driveCat = "B1"; break;
	case C: driveCat = "C"; break;
	case D: driveCat = "D"; break;
	case BE: driveCat = "BE"; break;
	case CE: driveCat = "CE"; break;
	case DE: driveCat = "DE"; break;
	case T: driveCat = "T"; break;
	default: driveCat = "NA";
	}
	char* rent = NULL;
	switch (pVehicleObject->isRented)
	{
	case 0: rent = "Yes"; break;
	case 1: rent = "No"; break;
	default: rent = "NA"; break;
	}
	fprintf(stdout, FORMAT_VEHICLEINFO_PRINT, pVehicleObject->vehicleID, pVehicleObject->brand, pVehicleObject->model, pVehicleObject->VIN, pVehicleObject->yearOfМanufacture, driveCat, pVehicleObject->pricePerDay, rent);
}
void	     vehicleObject_Initializatoin(VehicleInfo* pVehicleObject)
{
	printf("\nEnter vehicle ID:");
	scanf_s("%u", &pVehicleObject->vehicleID);
	printf("\nEnter brand name:");
	io_strEnter(pVehicleObject->brand, 10);
	setbuf(stdin, NULL);
	printf("\nEnter model name:");
	io_strEnter(pVehicleObject->model, 10);
	setbuf(stdin, NULL);
	printf("\nEnter VIN:");
	io_strEnter(pVehicleObject->VIN, 20);
	setbuf(stdin, NULL);
	printf("\nEnter driving category: \nA1\t0\nA2\t1\nA\t2\nB\t3\nB1\t4\nC\t5\nD\t6\nBE\t7\nCE\t8\nDE\t9\nT\t10\n");
	scanf_s("%d", &pVehicleObject->driveCatNeeded);
	printf("\nEnter price per day:");
	scanf_s("%f", &pVehicleObject->pricePerDay);
	pVehicleObject->isRented = 0u;
}
void		 vehicleObject_Serilization(FILE* out, VehicleInfo* pVehicleObject)
{
	fprintf(out, FORMAT_VEHICLEINFO_SERILIZATION, pVehicleObject->vehicleID, pVehicleObject->brand, pVehicleObject->model, pVehicleObject->VIN, pVehicleObject->yearOfМanufacture, pVehicleObject->driveCatNeeded, pVehicleObject->pricePerDay, pVehicleObject->isRented);
}

bool		 vehicleList_isEmpty(listVehicle* list)
{
	return list == NULL;
}
void		 vehicleList_init(listVehicle* list)
{
	list = NULL;
}
int			 vehicleList_countElements(listVehicle* list)
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
void		 vehicleList_print(listVehicle* list)
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
listVehicle* vehicleList_findIndexN(listVehicle* list, int indx)
{
	listVehicle* it = list;
	int countIndex = 0;
	while (it != NULL)
	{
		if (countIndex == indx)
			return it;
		countIndex++;
		it = it->next;
	}
	return NULL;
}
listVehicle* vehicleList_findLast(listVehicle* list)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	return list;
}
void		 vehicleList_copyStruct(listVehicle* list, VehicleInfo* pVehicleObject)
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
listVehicle* vehicleList_pushBack(listVehicle* list, VehicleInfo* pVehicleObject)
{
	listVehicle* pNew = (listVehicle*)malloc(sizeof(listVehicle));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return NULL;
	}
	vehicleList_copyStruct(pNew, pVehicleObject);
	pNew->next = NULL;

	if (list == NULL)
	{
		list = pNew;
	}
	else
	{
		listVehicle* plast = vehicleList_findLast(list);
		plast->next = pNew;
	}
	return list;
}
listVehicle* vehicleList_insert(listVehicle* list, int indx)
{
	listVehicle* pfirst = list;
	listVehicle* pNew = (listVehicle*)malloc(sizeof(listVehicle));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return NULL;
	}
	if (list == NULL)
	{
		return vehicleList_pushBack(list, &pNew->vehicle);
	}
	VehicleInfo vehicle;
	vehicleObject_Initializatoin(&vehicle);
	vehicleList_copyStruct(pNew, &vehicle);
	if (indx == 0)
	{
		pNew->next = pfirst;
		return pNew;
	}
	else
	{
		listVehicle* prev = vehicleList_findIndexN(list, indx - 1);
		pNew->next = prev->next;
		prev->next = pNew;
		return pfirst;
	}
}
listVehicle* vehicleList_empty(listVehicle* list)
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
listVehicle* vehicleList_delete(listVehicle* list, int indx)
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
listVehicle* vehicleList_deserilization(listVehicle* list)
{
	FILE* in = NULL;
	//char filename[20] = { 0 };
	//printf("\nEnter input file name:");
	//io_strEnter(filename, 20);
	in = file_open(in, "vehicleList.txt", "r");

	int countElements = 0;
	int* pCount = &countElements;
	in = int_deserilization(in, pCount);

	listVehicle* pfirst = NULL;
	for (int i = 0; i < countElements; i++)
	{
		VehicleInfo vehicleObject;
		VehicleInfo* pVehicleObject = &vehicleObject;
		in = vehicleObject_Deserilization(in, pVehicleObject);
		pfirst = vehicleList_pushBack(pfirst, pVehicleObject);
	}
	return pfirst;
}
void		 vehicleList_serilization(listVehicle* list)
{
	FILE* out = NULL;
	//char filename[20] = { 0 };
	//printf("\nEnter input file name:");
	//io_strEnter(filename, 20);
	out = file_open(out, "vehicleList.txt", "w");
	int countElem = vehicleList_countElements(list);
	out = int_serilization(out, &countElem);

	while (list != NULL)
	{
		vehicleObject_Serilization(out, &list->vehicle);
		list = list->next;
	}
	file_close(out);
}