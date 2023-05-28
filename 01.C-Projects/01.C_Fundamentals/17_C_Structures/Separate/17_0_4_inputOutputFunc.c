/*
Напишете функция за принтиране на данните на VehicleShopInfo обект.
Напишете функция за въвеждането на данните за VehicleShopInfo от потребителя.
Напишете програма, която ползва функциите.
*/
#include "../Library/stringFunctions.h"
#include <stdio.h>
#include <string.h>

void enter_vehicleInfo(struct VehicleShopInfo* pVehicle);
void print_vehicleInfo(struct VehicleShopInfo* pVehicle);

const char* brand[] = { "FIAT", "MAZDA", "FORD", "TOYOTA" };
const char* model[] = { "Punto", "2", "Fiesta", "Yaris" };

struct VehicleShopInfo
{
	unsigned yearOfМanufacture;
	const char* brand;
	const char* model;
	char VIN[20];
	float pricePerDay;
	bool isRented;
};

int main(void)
{
	struct VehicleShopInfo vehicle_1;
	struct VehicleShopInfo* pVehicle = &vehicle_1;
	enter_vehicleInfo(pVehicle);
	print_vehicleInfo(pVehicle);
	return 0;
}

	void print_vehicleInfo(struct VehicleShopInfo* pVehicle)
	{
		printf("\nVehicle_1:\nyearOfManufacture - %u", pVehicle->yearOfМanufacture);
		printf("\nbrand - %s", pVehicle->brand);
		printf("\nmodel - %s", pVehicle->model);
		printf("\nVIN - %s", pVehicle->VIN);
		printf("\npricePerDay - %.2f BGN", pVehicle->pricePerDay);
	}

	void enter_vehicleInfo(struct VehicleShopInfo* pVehicle)
	{
		int chooseBrand = 0;
		printf("\nyearOfManufacture: ");
		scanf_s("%u", &pVehicle->yearOfМanufacture);
		printf("\nChoose vehicle between: FIAT Punto-1, MAZDA 2-2, FORD Fiesta-3, TOYOTA Yaris-4");
		scanf_s("%d", &chooseBrand);
		if (chooseBrand == 1)
		{
			pVehicle->brand = brand[0];
			pVehicle->model = model[0];
		} else if (chooseBrand == 2)
		{
			pVehicle->brand = brand[1];
			pVehicle->model = model[1];
		}
		else if (chooseBrand == 3)
		{
			pVehicle->brand = brand[2];
			pVehicle->model = model[2];
		}
		else if (chooseBrand == 4)
		{
			pVehicle->brand = brand[3];
			pVehicle->model = model[3];
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
	}
