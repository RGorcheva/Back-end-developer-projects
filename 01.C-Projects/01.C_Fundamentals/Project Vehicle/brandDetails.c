#include "brandDetails.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static const char* FORMAT_BRANDDETAILS_DESERILIZATOIN = "(%[^|]| %[^|]| %[^|]| %[^|]| %f, %u)\n";
static const char* FORMAT_BRANDDETAILS_SERILIZATION = "(%s| %s| %s| %s| %f, %u)\n";
static const char* FORMAT_BRANDDETAILS_PRINT = "\nBrand: %s\nBrand Details: %s\nModel: %s\nModel details: %s\n"
"PricePerDay: %.2f BGN\nNumber of available vehicles: %u\n";

FILE*		brandObject_Deserilization(FILE* in, BrandDetails* pBrandDetail)
{
	int ifscan = fscanf(in, FORMAT_BRANDDETAILS_DESERILIZATOIN, &pBrandDetail->brand, &pBrandDetail->brandDetails, &pBrandDetail->model, &pBrandDetail->modelDetails, &pBrandDetail->pricePerDay, &pBrandDetail->isRentedCount);
	return in;
}
void		brandObject_Print(BrandDetails* pBrandDetail)
{
	printf("\n--------------------------------------\n");
	fprintf(stdout, FORMAT_BRANDDETAILS_PRINT, pBrandDetail->brand, pBrandDetail->brandDetails, pBrandDetail->model, pBrandDetail->modelDetails, pBrandDetail->pricePerDay, pBrandDetail->isRentedCount);
}
void		brandObject_Initializatoin(BrandDetails* pBrandDetail)
{
	printf("\nEnter brand name:");
	io_strEnter(pBrandDetail->brand, 10);
	setbuf(stdin, NULL);
	printf("\nEnter brand details:");
	io_strEnter(pBrandDetail->brandDetails, 500);
	setbuf(stdin, NULL);
	printf("\nEnter model name:");
	io_strEnter(pBrandDetail->model, 10);
	setbuf(stdin, NULL);
	printf("\nEnter model details:");
	io_strEnter(pBrandDetail->modelDetails, 500);
	setbuf(stdin, NULL);
	printf("\nEnter price per day:");
	scanf_s("%f", &pBrandDetail->pricePerDay);
	pBrandDetail->isRentedCount = 0u;
}
void		brandObject_Serilization(FILE* out, BrandDetails* pBrandDetail)
{
	fprintf(out, FORMAT_BRANDDETAILS_SERILIZATION, pBrandDetail->brand, pBrandDetail->brandDetails, pBrandDetail->model, pBrandDetail->modelDetails, pBrandDetail->pricePerDay, pBrandDetail->isRentedCount);
}

bool		brandList_isEmpty(listBrand* list)
{
	return list == NULL;
}
void		brandList_init(listBrand* list)
{
	list = NULL;
}
int			brandList_countElements(listBrand* list)
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
void		brandList_print(listBrand* list)
{
	if (list == NULL)
		return;
	while (list != NULL)
	{
		brandObject_Print(&list->brands);
		list = list->next;
	}
	printf("\n------------------------------------\n");
}
listBrand*	brandList_findIndexN(listBrand* list, int indx)
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
listBrand*	brandList_findLast(listBrand* list)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	return list;
}
void		brandList_copyStruct(listBrand* list, BrandDetails* pBrandObject)
{
	strcpy(list->brands.brand, pBrandObject->brand);
	strcpy(list->brands.brandDetails, pBrandObject->brandDetails);
	strcpy(list->brands.model, pBrandObject->model);
	strcpy(list->brands.modelDetails, pBrandObject->modelDetails);
	list->brands.pricePerDay = pBrandObject->pricePerDay;
	list->brands.isRentedCount = pBrandObject->isRentedCount;
}
listBrand*	brandList_pushBack(listBrand* list, BrandDetails* pBrandObject)
{
	listBrand* pNew = (listBrand*)malloc(sizeof(listBrand));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return NULL;
	}
	brandList_copyStruct(pNew, pBrandObject);
	pNew->next = NULL;

	if (list == NULL)
	{
		list = pNew;
	}
	else
	{
		listBrand* plast = brandList_findLast(list);
		plast->next = pNew;
	}
	return list;
}
void		brandList_insert(listBrand* list, int indx)
{
	BrandDetails brandObject;
	brandObject_Initializatoin(&brandObject);

	listBrand* pNew = (listBrand*)malloc(sizeof(listBrand));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	brandList_copyStruct(pNew, &brandObject);
	listBrand* prev = brandList_findIndexN(list, indx - 1);
	pNew->next = prev->next;
	prev->next = pNew;
}
listBrand*	brandList_empty(listBrand* list)
{
	if (list == NULL)
	{
		printf("\nlist is NULL pointer!!!");
		return NULL;
	}
	while (list != NULL)
	{
		listBrand* temp = list->next;
		free(list);
		list = temp;
	}
	return NULL;
}
listBrand*	brandList_delete(listBrand* list, int indx)
{
	if (list == NULL)
		return NULL;
	if (indx == 0)
	{
		listBrand* first = list->next;
		free(list);
		return first;
	}
	listBrand* first = list;
	int count = 0;
	while (count != indx - 1)
	{
		++count;
		list = list->next;
	}
	listBrand* prev = list;
	list = list->next;
	prev->next = list->next;
	free(list);
	return first;
}
listBrand*	brandList_deserilization(listBrand* list)
{
	FILE* in = NULL;
	//char filename[20] = { 0 };
	//printf("\nEnter input file name:");
	//io_strEnter(filename, 20);
	in = file_open(in, "brandList.txt", "r");

	int countElements = 0;
	in = int_deserilization(in, &countElements);

	listBrand* pfirst = NULL;
	for (int i = 0; i < countElements; i++)
	{
		BrandDetails brandObject;
		in = brandObject_Deserilization(in, &brandObject);
		pfirst = brandList_pushBack(pfirst, &brandObject);
	}
	return pfirst;
}
void		brandList_serilization(listBrand* list)
{
	FILE* out = NULL;
	out = file_open(out, "brandList.txt", "w");

	int countElem = brandList_countElements(list);
	out = int_serilization(out, &countElem);

	while (list != NULL)
	{
		brandObject_Serilization(out, &list->brands);
		list = list->next;
	}
	file_close(out);
}
