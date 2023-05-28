#include "..\Project Vehicle\brandDetails.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

//typedef struct ListBrand
//{
//	BrandDetails brand;
//	struct ListBrand* brandNext;
//}listBrand;

bool brandList_isEmpty(listBrand* list)
{
	return list == NULL;
}
void brandList_init(listBrand* list)
{
	list = NULL;
}
int brandList_countElements(listBrand* list)
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
void brandList_print(listBrand* list)
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
listBrand* brandList_findIndexN(listBrand* list, int indx)
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
listBrand* brandList_findLast(listBrand* list)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	return list;
}
void brandList_copyStruct(listBrand* list, BrandDetails* pBrandObject)
{
	strcpy(list->brands.brand, pBrandObject->brand);
	strcpy(list->brands.brandDetails, pBrandObject->brandDetails);
	strcpy(list->brands.model, pBrandObject->model);
	strcpy(list->brands.modelDetails, pBrandObject->modelDetails);
	list->brands.pricePerDay = pBrandObject->pricePerDay;
	list->brands.isRentedCount = pBrandObject->isRentedCount;
}
listBrand* brandList_pushBack(listBrand* list, BrandDetails* pBrandObject)
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
void brandList_insert(listBrand* list, int indx)
{
	BrandDetails brand;
	BrandDetails* pBrandObject = &brand;
	brandObject_Initializatoin(pBrandObject);

	listBrand* pNew = (listBrand*)malloc(sizeof(listBrand));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	brandList_copyStruct(pNew, pBrandObject);
	listBrand* prev = brandList_findIndexN(list, indx - 1);
	pNew->next = prev->next;
	prev->next = pNew;
}
listBrand* brandList_empty(listBrand* list)
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
listBrand* brandList_delete(listBrand* list, int indx)
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
listBrand* brandList_deserilization(listBrand* list)
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

	listBrand* pfirst = NULL;
	for (int i = 0; i < countElements; i++)
	{
		BrandDetails brandObject;
		BrandDetails* pBrandObject = &brandObject;
		in = brandObject_Deserilization(in, pBrandObject);
		pfirst = brandList_pushBack(pfirst, pBrandObject);
	}
	return pfirst;
}
void brandList_serilization(listBrand* list, int* pCountElements)
{
	FILE* out = NULL;
	char filename[20] = { 0 };
	printf("\nEnter input file name:");// ..\Data\vehicleList.txt
	io_strEnter(filename, 20);
	out = file_open(out, filename, "w");

	out = int_serilization(out, pCountElements);

	while (list != NULL)
	{
		brandObject_Serilization(out, &list->brands);
		list = list->next;
	}
	file_close(out);
}

int main(void)
{
	//BrandDetails Brand1 = {
	//.brand = "FIAT",
	//.brandDetails = "\n\tFiat Automobiles S.p.A. is an Italian automobile manufacturer, formerly part of Fiat Chrysler Automobiles, and since 2021 a subsidiary of Stellantis through its Italian division Stellantis Italy. Fiat Automobiles was formed in January 2007 when Fiat S.p.A. reorganized its automobile business, and traces its history back to 1899 when the first Fiat automobile, the Fiat 4 HP, was produced.\n",
	//.model = "Punto",
	//.modelDetails = "\n\tThe Fiat Punto has 1 Diesel Engine and 1 Petrol Engine on offer. The Diesel engine is 1248 cc while the Petrol engine is 1172 cc . It is available with Manual transmission.Depending upon the variant and fuel type the Punto has a mileage of 14.6 to 20.3 kmpl & Ground clearance of Punto is 195mm. The Punto is a 5 seater 4 cylinder car and has length of 3987mm, width of 1687mm and a wheelbase of 2510mm.\n",
	//.pricePerDay = 50.0f,
	//.isRentedCount = 0u
	//};
	//BrandDetails Brand2 = {
	//	.brand = "MAZDA",
	//	.brandDetails = "\n\tMazda Motor Corporation, commonly referred to as simply Mazda, is a Japanese multinational automotive manufacturer headquartered in Fuchū, Hiroshima, Japan. In 2015, Mazda produced 1.5 million vehicles for global sales, the majority of which(nearly one million) were produced in the company's Japanese plants, with the remainder coming from a variety of other plants worldwide. During this time, Mazda was the 15th-largest automaker in terms of production globally.\n",
	//	.model = "2",
	//	.modelDetails = "\n\tThe Mazda 2 is offered Petrol engine in the Indonesia. The new Hatchback from Mazda comes in a total of 2 variants. If we talk about Mazda 2 engine specs then the Petrol engine displacement is 1496 cc. 2 is available with Automatic transmission. The 2 is a 5 Seater Hatchback and has a length of 4060 mm the width of 1695 mm, and a wheelbase of 2570 mm. along with a ground clearance of 152 mm.\n",
	//	.pricePerDay = 60.0f,
	//	.isRentedCount = 0u
	//};
	//BrandDetails Brand3 = {
	//	.brand = "FORD",
	//	.brandDetails = "\n\tFord Motor Company (commonly known as Ford) is an American multinational automobile manufacturer headquartered in Dearborn, Michigan, United States. It was founded by Henry Ford and incorporated on June 16, 1903. The company sells nautomobiles and commercial vehicles under the Ford brand, and luxury cars under its Lincoln luxury brand. Ford also owns Brazilian SUV manufacturer Troller, an 8% stake in Aston Martin of the United Kingdom and a 32% stake in China's Jiangling Motors. It also has joint ventures in China (Changan Ford), Taiwan (Ford Lio Ho), Thailand (AutoAlliance Thailand), Turkey (Ford Otosan), and Russia (Ford Sollers).\n",
	//	.model = "Fiesta",
	//	.modelDetails = "\n\tThe Ford Fiesta has 1 Diesel Engine and 1 Petrol Engine on offer. The Diesel engine is 1498 cc while the Petrol engine is 1499 cc . It is available with Manual transmission.Depending upon the variant and fuel type the Fiesta has a mileage of 17.0 to 25.01 kmpl & Ground clearance of Fiesta is 153mm. The Fiesta is a 5 seater 4 cylinder car and has length of 4320mm, width of 1764mm and a wheelbase of 2489mm.\n",
	//	.pricePerDay = 60.0f,
	//	.isRentedCount = 0u
	//};
	//BrandDetails Brand4 = {
	//	.brand = "TOYOTA",
	//	.brandDetails = "\n\tToyota Motor Corporation (commonly known as simply Toyota) is a Japanese multinational automotive manufacturer headquartered in Toyota City, Aichi, Japan. It was founded by Kiichiro Toyoda and incorporated on August 28, 1937. Toyota is one of the largest automobile manufacturers in the world, producing about 10 million vehicles per year. As of 2009, Toyota officially lists approximately 70 different models sold under its namesake brand, including sedans, coupes, vans, trucks, hybrids, and crossovers. Many of these models are produced as passenger sedans, which range from the subcompact Toyota Yaris, compact Corolla, to mid-size Camry and full-size Avalon. Minivans include the Innova, Alphard/Vellfire, Sienna, and others. Several small cars, such as the xB and tC, were sold under the Scion brand.\n",
	//	.model = "Yaris",
	//	.modelDetails = "\n\tThe Toyota Yaris has 1 Petrol Engine on offer. The Petrol engine is 1496 cc. It is available with Manual & Automatic transmission. Depending upon the variant and fuel type the Yaris has a mileage of 17.1 to 17.8 kmpl. The Yaris is a 5 seater 4 cylinder car and has length of 4425mm, width of 1730mm and a wheelbase of 2550mm.\n",
	//	.pricePerDay = 80.0f,
	//	.isRentedCount = 0u
	//};
	//FILE* out = NULL;
	//char filename[20] = { 0 };
	//printf("\nEnter input file name:");// brandList.txt
	//io_strEnter(filename, 20);
	//out = file_open(out, filename, "w");
	//int count = 4;
	//int* pCountElements = &count;
	//out = int_serilization(out, pCountElements);
	//BrandDetails* pBrandObject = &Brand1;
	//brandObject_Serilization(out, pBrandObject);
	//pBrandObject = &Brand2;
	//brandObject_Serilization(out, pBrandObject);
	//pBrandObject = &Brand3;
	//brandObject_Serilization(out, pBrandObject);
	//pBrandObject = &Brand4;
	//brandObject_Serilization(out, pBrandObject);
	//file_close(out);

	listBrand* pfirst = NULL;
	pfirst = brandList_deserilization(pfirst);
	brandList_print(pfirst);

	brandList_insert(pfirst, 2);
	brandList_print(pfirst);
	pfirst = brandList_delete(pfirst, 2);
	brandList_print(pfirst);
	int iCountElements = brandList_countElements(pfirst);
	brandList_serilization(pfirst, &iCountElements);
	pfirst = brandList_empty(pfirst);
	brandList_print(pfirst);
	return 0;
}