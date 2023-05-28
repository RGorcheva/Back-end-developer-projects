#include "OrderDetails.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static const char* FORMAT_ORDERS_DESERILIZATOIN = "(%u, %u, %u, %d, %u/%u/%u, %f)\n";
static const char* FORMAT_ORDERS_SERILIZATION = "(%u, %u, %u, %d, %u/%u/%u, %f)\n";
static const char* FORMAT_ORDERS_PRINT = "\nOrder ID: %u\n--------------\nUser ID: %u\nVehicle ID: %u\nDays rendet: %d\nStart date: %d/%d/%d\nInvoice: %.2f\n";

FILE*		orderObject_Deserilization(FILE* in, Orders* pOrderObject)
{
	unsigned day = 0;
	unsigned month = 0;
	unsigned year = 0;
	int ifscan = fscanf(in, FORMAT_ORDERS_DESERILIZATOIN, &pOrderObject->orderID, &pOrderObject->userID, &pOrderObject->vehicleID, &pOrderObject->daysRented, &day, &month, &year, &pOrderObject->invoice);
	pOrderObject->startDate.day = day;
	pOrderObject->startDate.month = month;
	pOrderObject->startDate.year = year;
	return in;
}
void		orderObject_Print(Orders* pOrderObject)
{
	fprintf(stdout, FORMAT_ORDERS_PRINT, pOrderObject->orderID, pOrderObject->userID, pOrderObject->vehicleID, pOrderObject->daysRented, pOrderObject->startDate.day, pOrderObject->startDate.month, pOrderObject->startDate.year, pOrderObject->invoice);
}
void		orderObject_Initializatoin(Orders* pOrderObject)
{
	//printf("\nEnter vehicle ID:");
	//scanf_s("%u", &pVehicleObject->vehicleID);
	//printf("\nEnter brand name:");
	//io_strEnter(pVehicleObject->brand, 10);
	//setbuf(stdin, NULL);
	//printf("\nEnter model name:");
	//io_strEnter(pVehicleObject->model, 10);
	//setbuf(stdin, NULL);
	//printf("\nEnter VIN:");
	//io_strEnter(pVehicleObject->VIN, 20);
	//setbuf(stdin, NULL);
	//printf("\nEnter driving category: \nA1\t0\nA2\t1\nA\t2\nB\t3\nB1\t4\nC\t5\nD\t6\nBE\t7\nCE\t8\nDE\t9\nT\t10\n");
	//scanf_s("%d", &pVehicleObject->driveCatNeeded);
	//printf("\nEnter price per day:");
	//scanf_s("%f", &pVehicleObject->pricePerDay);
	//pVehicleObject->isRented = 0u;
}
void		orderObject_Serilization(FILE* out, Orders* pOrderObject)
{
	fprintf(out, FORMAT_ORDERS_SERILIZATION, pOrderObject->orderID, pOrderObject->userID, pOrderObject->vehicleID, pOrderObject->daysRented, pOrderObject->startDate.day, pOrderObject->startDate.month, pOrderObject->startDate.year, pOrderObject->invoice);
}

bool		orderList_isEmpty(listOrder* list)
{
	return list == NULL;
}
void		orderList_init(listOrder* list)
{
	list = NULL;
}
int			orderList_countElements(listOrder* list)
{
	listOrder* it = list;
	if (it == NULL)
		return 0;
	int count = 0;
	while (it != NULL)
	{
		++count;
		it = it->next;
	}
	return count;
}
void		orderList_print(listOrder* list)
{
	if (list == NULL)
		return;
	while (list != NULL)
	{
		orderObject_Print(&list->order);
		list = list->next;
	}
	printf("\n------------------------------------\n");
}
listOrder*	orderList_findIndexN(listOrder* list, int indx)
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
listOrder*	orderList_findLast(listOrder* list)
{
	listOrder* it = list;
	while (it->next != NULL)
	{
		it = it->next;
	}
	return it;
}
void		orderList_copyStruct(listOrder* list, Orders* pOrderObject)
{
	list->order.orderID = pOrderObject->orderID;
	list->order.userID = pOrderObject->userID;
	list->order.vehicleID = pOrderObject->vehicleID;
	list->order.daysRented = pOrderObject->daysRented;
	list->order.startDate = pOrderObject->startDate;
	list->order.invoice = pOrderObject->invoice;
}
listOrder*	orderList_pushBack(listOrder* list, Orders* pOrderObject)
{
	listOrder* pNew = (listOrder*)malloc(sizeof(listOrder));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return NULL;
	}
	orderList_copyStruct(pNew, pOrderObject);
	pNew->next = NULL;

	if (list == NULL)
	{
		list = pNew;
	}
	else
	{
		listOrder* plast = orderList_findLast(list);
		plast->next = pNew;
	}
	return list;
}
listOrder*	orderList_empty(listOrder* list)
{
	if (list == NULL)
	{
		printf("\nlist is NULL pointer!!!");
		return NULL;
	}
	while (list != NULL)
	{
		listOrder* temp = list->next;
		free(list);
		list = temp;
	}
	return NULL;
}
listOrder*  orderList_delete(listOrder* list, int indx)
{
	if (list == NULL)
		return NULL;
	if (indx == 0)
	{
		listOrder* first = list->next;
		free(list);
		return first;
	}
	listOrder* first = list;
	int count = 0;
	while (count != indx - 1)
	{
		++count;
		list = list->next;
	}
	listOrder* prev = list;
	list = list->next;
	prev->next = list->next;
	free(list);
	return first;
}
listOrder*	orderList_deserilization(listOrder* list)
{
	FILE* in = NULL;
	in = file_open(in, "orderList.txt", "r");
	int countElements = 0;
	in = int_deserilization(in, &countElements);
//	listOrder* pfirst = NULL;
//	FILE* in1 = in;
	for (int i = 0; i < countElements; i++)
	{
		Orders orderObject;
		in = orderObject_Deserilization(in, &orderObject);
		list = orderList_pushBack(list, &orderObject);
	}
	file_close(in);
	return list;
}
void		orderList_serilization(listOrder* list)
{
	listOrder* it = list;
	FILE* out = NULL;
	out = file_open(out, "orderList.txt", "w");

	int countElem = orderList_countElements(it);
	out = int_serilization(out, &countElem);

	while (it != NULL)
	{
		orderObject_Serilization(&out, &it->order);
		it = it->next;
	}
	file_close(out);
}