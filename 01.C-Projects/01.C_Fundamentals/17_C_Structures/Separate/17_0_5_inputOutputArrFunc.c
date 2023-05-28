/*
● Напишете функция за принтиране на масив от VehicleShopInfo обекти
● Напишете функция за въвеждането на масив от VehicleShopInfo обекти от 
потребителя
● Напишете програма, която извиква функциите.
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>
#include <string.h>

void enter_vehicleInfoArr(struct VehicleShopInfo* pVehicle, int countElements);
void print_vehicleInfoArr(struct VehicleShopInfo* pVehicle, int countElements);

const char* brand[] = { "FIAT", "MAZDA", "FORD", "TOYOTA" };
const char* model[] = { "Punto", "2", "Fiesta", "Yaris" };

struct VehicleShopInfo
{
	unsigned yearOfМanufacture;
	const char* brand;
	const char* model;
	char VIN[20];
	float pricePerDay;
};

int main(void)
{
	struct VehicleShopInfo vehicles[2];
	int countElements = 2;
	enter_vehicleInfoArr(vehicles, countElements);
	print_vehicleInfoArr(vehicles, countElements);
	return 0;
}

void print_vehicleInfoArr(struct VehicleShopInfo* pVehicle, int countElements)
{
	int i = 0;
	for (struct VehicleShopInfo* p = pVehicle; p < pVehicle + countElements; p++, i++)
	{
		printf("\nVehicle[%d]:\nyearOfManufacture - %u",i, p->yearOfМanufacture);
		printf("\nbrand - %s", p->brand);
		printf("\nmodel - %s", p->model);
		printf("\nVIN - %s", p->VIN);
		printf("\npricePerDay - %.2f BGN", p->pricePerDay);
		printf("\n");
	}
}

void enter_vehicleInfoArr(struct VehicleShopInfo* pVehicle, int countElements)
{
	int i = 0;
	for (struct VehicleShopInfo* ptr = pVehicle; ptr < pVehicle + countElements; ptr++, i++)
	{
		printf("\nEnter Info for vehicle %d:", i);
		printf("\nyearOfManufacture: ");
		scanf_s("%u", &ptr->yearOfМanufacture);
		int chooseBrand = 0;
		printf("\nChoose vehicle between: FIAT Punto-1, MAZDA 2-2, FORD Fiesta-3, TOYOTA Yaris-4");
		scanf_s("%d", &chooseBrand);
		if (chooseBrand == 1)
		{
			ptr->brand = brand[0];
			ptr->model = model[0];
		}
		else if (chooseBrand == 2)
		{
			ptr->brand = brand[1];
			ptr->model = model[1];
		}
		else if (chooseBrand == 3)
		{
			ptr->brand = brand[2];
			ptr->model = model[2];
		}
		else if (chooseBrand == 4)
		{
			ptr->brand = brand[3];
			ptr->model = model[3];
		}
		printf("\nVIN:");
		setbuf(stdin, NULL);
		fgets(ptr->VIN, 19, stdin);
		char* p = 0;
		p = string_strchrFindFirstChar(ptr->VIN, '\n');
		*p = '\0';
		setbuf(stdin, NULL);
		printf("\npricePerDay:");
		scanf_s("%f", &ptr->pricePerDay);
	}
}