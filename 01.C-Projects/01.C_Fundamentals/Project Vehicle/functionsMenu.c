#include "functionsMenu.h"
#include "vehicleList.h"
#include "brandDetails.h"
#include "OrderDetails.h"
#include <string.h>
#include "macroStrings.h"

static int chooseVehicle;
static float iFinalPrice;

static void all_deserilizatoin(void)
{
	pfirstVehicle = vehicleList_deserilization(pfirstVehicle);
	pfirstBrand = brandList_deserilization(pfirstBrand);
	orderList_deserilization(pfirstOrder);
	//Да се сравни крайна дата на поръчки дали е по-стара от днешната.
	//Ако ДА, то да се промени isRented на listVehicle обектите.
}
static void all_serilizatoin_free(void)
{
	vehicleList_serilization(pfirstVehicle);
	vehicleList_empty(pfirstVehicle);
	brandList_serilization(pfirstBrand);
	brandList_empty(pfirstBrand);
}

enum Function f_main_menu(void)
{
	all_deserilizatoin();
	char menuChoice = -1;
	printf(MAIN_MENU_MENU);

	//Да добавя меню за редакция на поръчки
	do
	{
		printf(MAIN_MENU_CHOICE);
		scanf_s(" %c", &menuChoice, 1);
		if (menuChoice == '1')
		{
			return e_allVehicleList;
		}
		else if (menuChoice == '2')
		{
			return e_vehicleBrandList;
		}
		else if (menuChoice == 'q')
		{
			all_serilizatoin_free();
			return e_quit;
		}
		else
		{
			printf(WRONG_CHOICE);
		}
	} while (menuChoice != '1' && menuChoice != '2' && menuChoice != 'q');
}
enum Function f_vehicleBrandList(void)
{
	printf(VEHICLE_BRAND_LIST);
	printf(VEHICLE_BRAND_LIST_CHOICE_BRAND);
	listBrand* pBrand = pfirstBrand;
	int i = 0;
	while (pBrand != NULL)
	{
		printf("%d >> %s\n", ++i, pBrand->brands.brand);
		pBrand = pBrand->next;
	}
	int chooseBrand = 0;
	do
	{
		scanf_s("%d", &chooseBrand);
		pBrand = brandList_findIndexN(pfirstBrand, chooseBrand - 1);
		if (pBrand == NULL)
		{
			printf(WRONG_CHOICE);
		}
	} while (pBrand == NULL);

	VEHICLE_BRAND_LIST_BRAND(pBrand->brands.brand);

	listVehicle* pVehicle = pfirstVehicle;
	while (pVehicle != NULL)
	{
		if (!strcmp(pVehicle->vehicle.brand, pBrand->brands.brand))
		{
			vehicleObject_Print(&pVehicle->vehicle);
			printf("\n");
		}
		pVehicle = pVehicle->next;
	}
	char menuChoice = 0;
	do
	{	
		printf(VEHICLE_BRAND_LIST_CHOICE);
		scanf_s(" %c", &menuChoice, 1);
		if (menuChoice == '1')
		{
			return e_brandDetails;
		} else 	if (menuChoice == '2')
		{
			printf(VEHICLE_BRAND_LIST_CHOICE_VEHICLE);
			scanf_s("%d", &chooseVehicle);
			return e_rentVehicle;
		}
		else if (menuChoice == 'b')
		{
			return e_back;
		}
		else
		{
			printf(WRONG_CHOICE);
		}
	} while (menuChoice != '1' && menuChoice != '2' && menuChoice != 'q');
}
enum Function f_allVehicleList(void)
{
	printf(VEHICLE_LIST_MENU);
	listVehicle* pVehicle = pfirstVehicle;
	while (pVehicle != NULL)
	{
		if (pVehicle->vehicle.isRented == 0)
		{
			vehicleObject_Print(&pVehicle->vehicle);
			printf("\n");
		}
		pVehicle = pVehicle->next;
	}
	char menuChoice = 0;
	do
	{
		printf(VEHICLE_LIST_MENU_CHOICE);
		scanf_s(" %c", &menuChoice, 1);
		if (menuChoice == '1')
		{
			return e_brandDetails;
		}
		else 	if (menuChoice == '2')
		{
			printf(VEHICLE_BRAND_LIST_CHOICE_VEHICLE);
			scanf_s("%d", &chooseVehicle);
			return e_rentVehicle;
		}
		else if (menuChoice == 'b')
		{
			return e_back;
		}
		else
		{
			printf(WRONG_CHOICE);
		}
	} while (menuChoice != '1' && menuChoice != '2' && menuChoice != 'q');
}
enum Function f_brandDetails(void)
{
	printf(BRAND_DETAILS_MENU);
	printf(BRAND_DETAILS_MENU_CHOICE_BRAND);
	listBrand* pBrand = pfirstBrand;
	int i = 0;
	while (pBrand != NULL)
	{
		printf("%d >> %s\n", ++i, pBrand->brands.brand);
		pBrand = pBrand->next;
	}
	int chooseBrand = 0;
	do
	{
		scanf_s("%d", &chooseBrand);
		pBrand = brandList_findIndexN(pfirstBrand, chooseBrand - 1);
		if (pBrand == NULL)
		{
			printf(WRONG_CHOICE);
		}
	} while (pBrand == NULL);
	brandObject_Print(&pBrand->brands);
	char menuChoice = 0;
	do
	{
		printf(BRAND_DETAILS_MENU_CHOICE);
		scanf_s(" %c", &menuChoice, 1);
		if (menuChoice == 'b')
		{
			return e_back;
		}
		else
		{
			printf(WRONG_CHOICE);
		}
	} while (menuChoice != 'b');
}
enum Function f_rentVehicle(void)
{
	printf(RENT_A_VEHICLE_MENU);

	Orders orderObject;
	orderObject.orderID = orderList_countElements(pfirstOrder) + 1;
	unsigned publicUserID = 1; // Ще се взима от UserID в лист Users при LogIn.
	orderObject.userID = publicUserID;
	listVehicle* pVehicle = vehicleList_findIndexN(pfirstVehicle, chooseVehicle);
	vehicleObject_Print(&pVehicle->vehicle);
	orderObject.vehicleID = chooseVehicle;
	printf(RENT_A_VEHICLE_DAYS);
	scanf_s("%d", &orderObject.daysRented);
	datetime_enterDate(&orderObject.startDate);
	pVehicle->vehicle.isRented = 1;

	float iCurrentPrice = 0;
	iCurrentPrice = orderObject.daysRented * pVehicle->vehicle.pricePerDay;
	orderObject.invoice = iCurrentPrice;
	iFinalPrice += iCurrentPrice;
	ACCOUNT(iCurrentPrice, iFinalPrice);

	
	orderList_pushBack(pfirstOrder, &orderObject);
	orderList_serilization(pfirstOrder);
	orderList_empty(pfirstOrder);

	char menuChoice = -1;
	do
	{
		printf(RENT_A_VEHICLE_MENU_CHOICE);
		scanf_s(" %c", &menuChoice, 1);
		if (menuChoice == '1')
		{
			return e_main_menu;
		}
		else if (menuChoice == 'q')
		{
			return e_quit;
		}
		else
		{
			printf(WRONG_CHOICE);
		}
	} while (menuChoice != '1' && menuChoice != 'q');
}