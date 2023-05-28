#include "functionsMenu.h"
#include "vehicleList.h"
#include "brandDetails.h"
#include "../Library/stringFunc.h"
#include <stdio.h>
#include <string.h>

extern struct VehicleShopInfo VehicleShop[10];
extern struct VehicleShopInfo* pVehicle = VehicleShop;
extern struct BrandDetails BrandDetail[4];
extern struct BrandDetails* pBrandDetail = BrandDetail;
static int chooseVehicle;
char* cBrand;
float iFinalPrice;

void enter_vehicleInfo(struct VehicleShopInfo* pVehicle)
{
	printf("\nyearOfManufacture: ");
	scanf_s("%u", &pVehicle->yearOfМanufacture);
	int chooseBrand = 0;
	printf("\nChoose vehicle between:\n 1 >> FIAT Punto\n, 2 >> MAZDA 2\n, 3 >> FORD Fiesta\n, 4 >> TOYOTA Yaris\n");
	scanf_s("%d", &chooseBrand);
	if (chooseBrand == 1)
	{
		pVehicle->brand = "FIAT";
		pVehicle->model = "Punto";
	}
	else if (chooseBrand == 2)
	{
		pVehicle->brand = "MAZDA";
		pVehicle->model = "2";
	}
	else if (chooseBrand == 3)
	{
		pVehicle->brand = "FORD";
		pVehicle->model = "Fiesta";
	}
	else if (chooseBrand == 4)
	{
		pVehicle->brand = "TOYOTA";
		pVehicle->model = "Yaris";
	}
	printf("\nVIN:");
	setbuf(stdin, NULL);
	fgets(pVehicle->VIN, 19, stdin);
	char* p = 0;
	p = string_strchrFindFirstChar(pVehicle->VIN, '\n');
	*p = '\0';
	setbuf(stdin, NULL);
	printf("\npricePerDay:");
	scanf_s("%f", &pVehicle->pricePerDay);
	printf("\nEnter if vehicle is rented: \n0 - No, 1 - Yes!");
	scanf_s("%d", &pVehicle->isRented);
}
void print_vehicleInfo(struct VehicleShopInfo* pVehicle)
{
	//printf("\nyearOfManufacture - %u", pVehicle->yearOfМanufacture);
	//printf("\nbrand - %s", pVehicle->brand);
	//printf("\nmodel - %s", pVehicle->model);
	//printf("\nVIN - %s", pVehicle->VIN);
	//printf("\npricePerDay - %.2f BGN", pVehicle->pricePerDay);
	//printf("\nrented - %d.", pVehicle->isRented);
	printf("\n%s %s,\t%u,\tVIN:%s,\tpricePerDay - %.2f BGN", pVehicle->brand, pVehicle->model, pVehicle->yearOfМanufacture, pVehicle->VIN, pVehicle->pricePerDay);
}
void print_brandDetails(struct VehicleShopInfo* pVehicle, struct BrandDetails* pBrandDetail)
{
	for (int br = 0; br < 4; br++, pBrandDetail++)
	{
		if (pBrandDetail->brand == cBrand)
		{
			printf("\nBrand - %s", pBrandDetail->brand);
			printf("\nBrand Details: %s", pBrandDetail->brandDetails);
			printf("\nmodel - %s", pBrandDetail->model);
			printf("\nmodel Details: %s", pBrandDetail->modelDetails);
			printf("\npricePerDay - %.2f BGN", pBrandDetail->pricePerDay);
			pVehicle = VehicleShop;
			for (int veh = 0; veh < 10; veh++, pVehicle++)
			{
				if (pVehicle->brand == cBrand && pVehicle->isRented == 0u)
				{
					++(pBrandDetail->isRentedCount);
				}
			}
			printf("\nNumber of available vehicles - %d.", pBrandDetail->isRentedCount);
		}
	}
}
enum Function f_main_menu(void)
{
	char menuChoice = -1;
	printf("\n---------------------------------------");
	printf("\nMAIN MENU:");
	do
	{
		printf("\n---------------------------------------");
		printf("\nPress 1 to choose VEHICLE LIST");
		printf("\nPress 2 to choose VEHICLE BRAND LIST");
		printf("\nPress q to QUIT");
		printf("\n---------------------------------------\n");
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
			return e_quit;
		}
		else
		{
			printf("\nYour choice is not correct! Try again!");
		}
	} while (menuChoice != '1' && menuChoice != '2' && menuChoice != 'q');
}
enum Function f_vehicleBrandList(void)
{
	printf("\n---------------------------------------");
	printf("\nVEHICLE BRAND LIST");
	printf("\n---------------------------------------");

	int chooseBrand = 0;
	do
	{
		printf("\nChoose vehicle brand between:\n1 >> FIAT\n2 >> MAZDA\n3 >> FORD\n4 >> TOYOTA\n");
		scanf_s("%d", &chooseBrand);
		switch (chooseBrand) {
		case 1: cBrand = "FIAT"; break;
		case 2: cBrand = "MAZDA"; break;
		case 3: cBrand = "FORD"; break;
		case 4: cBrand = "TOYOTA"; break;
		default: printf("\nWrong choice!Try again!"); break;
		} 
	}while (chooseBrand != 1 && chooseBrand != 2 && chooseBrand != 3 && chooseBrand != 4);
	printf("\n---------------------------------------");
	printf("\nBrand: %s", cBrand);
	printf("\n---------------------------------------");
	for (int i = 0; i < 10; i++)
	{
		if (VehicleShop[i].brand == cBrand)
		{
			printf("\nVehicle %d:", i);
			print_vehicleInfo(&(VehicleShop[i]));
			printf("\n");
		}
	}
	char menuChoice = 0;
	do
	{	
		printf("\n---------------------------------------");
		printf("\nPress 1 to see BRAND DETAILS");
		printf("\nPress 2 to RENT A VEHICLE");
		printf("\nPress b to go back to MAIN MENU");
		printf("\n---------------------------------------\n");
		scanf_s(" %c", &menuChoice, 1);
		if (menuChoice == '1')
		{
			return e_brandDetails;
		} else 	if (menuChoice == '2')
		{
			printf("\nChoose a vehicle number:");
			scanf_s("%d", &chooseVehicle);
			return e_rentVehicle;
		}
		else if (menuChoice == 'b')
		{
			return e_back;
		}
		else
		{
			printf("\nWrong choice! Try again!");
		}
	} while (menuChoice != '1' && menuChoice != '2' && menuChoice != 'q');
}
enum Function f_allVehicleList(void)
{
	printf("\n---------------------------------------");
	printf("\nVEHICLE LIST:");
	printf("\n---------------------------------------");
	for (int i = 0; i < 10; i++)
	{
		if (VehicleShop[i].isRented == 0)
		{
			printf("\nVehicle %d:", i);
			print_vehicleInfo(&(VehicleShop[i]));
			printf("\n");
		}
	}
	char menuChoice = 0;
	do
	{
		printf("\n---------------------------------------");
		printf("\nPress 1 to see BRAND DETAILS");
		printf("\nPress 2 to RENT A VEHICLE");
		printf("\nPress b to go back to MAIN MENU");
		printf("\n---------------------------------------\n");
		scanf_s(" %c", &menuChoice, 1);
		if (menuChoice == '1')
		{

			return e_brandDetails;
		}
		else 	if (menuChoice == '2')
		{
			printf("\nChoose a vehicle number:");
			scanf_s("%d", &chooseVehicle);
			return e_rentVehicle;
		}
		else if (menuChoice == 'b')
		{
			return e_back;
		}
		else
		{
			printf("\nWrong choice! Try again!");
		}
	} while (menuChoice != '1' && menuChoice != '2' && menuChoice != 'q');
}
enum Function f_brandDetails(void)
{
	printf("\n---------------------------------------");
	printf("\nBRAND DETAILS:");
	printf("\n---------------------------------------");
	int chooseBrand = 0;
	do
	{
		printf("\nChoose vehicle brand between:\n1 >> FIAT\n2 >> MAZDA\n3 >> FORD\n4 >> TOYOTA\n");
		scanf_s("%d", &chooseBrand);
		switch (chooseBrand) {
		case 1: cBrand = "FIAT"; break;
		case 2: cBrand = "MAZDA"; break;
		case 3: cBrand = "FORD"; break;
		case 4: cBrand = "TOYOTA"; break;
		default: printf("\nWrong choice!Try again!"); break;
		}
	} while (chooseBrand != 1 && chooseBrand != 2 && chooseBrand != 3 && chooseBrand != 4);

	pBrandDetail = BrandDetail;
	print_brandDetails(pVehicle, pBrandDetail);
	char menuChoice = 0;
	do
	{
		printf("\n---------------------------------------");
		printf("\nPress b to go back to VEHICLE LISTS");
		printf("\n---------------------------------------\n");
		scanf_s(" %c", &menuChoice, 1);
		if (menuChoice == 'b')
		{
			return e_back;
		}
		else
		{
			printf("\nWrong choice! Try again!");
		}
	} while (menuChoice != 'b');
}
enum Function f_rentVehicle(void)
{
	printf("\n---------------------------------------");
	printf("\nRENT A VEHICLE:");
	printf("\n---------------------------------------");
	printf("\nYou choose vehicle %d:\n", chooseVehicle);
	pVehicle = &VehicleShop[chooseVehicle];
	print_vehicleInfo(pVehicle);
	float iCurrentPrice = 0;
	int countDays = 0;
	printf("\n\nFor how many days will you rent the vehicle?\n");
	scanf_s("%d", &countDays);
	iCurrentPrice = countDays * pVehicle->pricePerDay;
	iFinalPrice += iCurrentPrice;
	printf("\n---------------------------------------");
	printf("\nYour current account is %.2f", iCurrentPrice);
	printf("\nYour Final account is %.2f", iFinalPrice);
	pVehicle->isRented = 1;

	char menuChoice = -1;
	do
	{
		printf("\n---------------------------------------");
		printf("\nPress 1 to MAIN MENU");
		printf("\nPress q to QUIT");
		printf("\n---------------------------------------\n");
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
			printf("\nYour choice is not correct! Try again!");
		}
	} while (menuChoice != '1' && menuChoice != 'q');
}