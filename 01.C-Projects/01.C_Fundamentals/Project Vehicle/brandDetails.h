#ifndef BRANDDETAILS_H
#define BRANDDETAILS_H

#include <stdio.h>
#include <stdbool.h>

typedef struct BrandDetails
{
	char brand[10];
	char brandDetails[1000];
	char model[10];
	char modelDetails[1000];
	float pricePerDay;
	unsigned isRentedCount;
} BrandDetails;

typedef struct listBrand
{
	BrandDetails brands;
	struct listBrand* next;
}listBrand;

listBrand* pfirstBrand;

FILE*		brandObject_Deserilization(FILE* in, BrandDetails* pBrandDetail);
void		brandObject_Print(BrandDetails* pBrandDetail);
void		brandObject_Initializatoin(BrandDetails* pBrandDetail);
void		brandObject_Serilization(FILE* out, BrandDetails* pBrandDetail);

bool		brandList_isEmpty(listBrand* list);
void		brandList_init(listBrand* list);
int			brandList_countElements(listBrand* list);
void		brandList_print(listBrand* list);
listBrand*	brandList_findIndexN(listBrand* list, int indx);
listBrand*	brandList_findLast(listBrand* list);
void		brandList_copyStruct(listBrand* list, BrandDetails* pBrandObject);
listBrand*  brandList_pushBack(listBrand* list, BrandDetails* pBrandObject);
void		brandList_insert(listBrand* list, int indx);
listBrand*	brandList_empty(listBrand* list);
listBrand*	brandList_delete(listBrand* list, int indx);
listBrand*	brandList_deserilization(listBrand* list);
void		brandList_serilization(listBrand* list);


#endif