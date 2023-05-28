/*
● Дефинирайте и инициализирайте променлива от тип VehicleShopInfo и друга
променлива, от тип - указател към VehicleShopInfo.
● Използвайте scanf_s и указателя към VehicleShopInfo за да дадете възможност на
потребителя да промени годината на производство.
● Принтирайте информацията за превозното средство чрез указателя.
*/

#include <stdio.h>

const char* brand[] = { "FIAT", "MAZDA", "FORD", "TOYOTA" };
const char* model[] = { "Punto", "2", "Fiesta", "Yaris" };

struct VehicleShopInfo
{
	unsigned yearOfМanufacture;
	const char* brand;
	const char* model;
	char VIN[17];
	float pricePerDay;
};

int main(void)
{
	struct VehicleShopInfo vehicle_1 = {
	.yearOfМanufacture = 2017u,
	.brand = brand[3],
	.model = model[3],
	.VIN = "67LU280957863CH56",
	.pricePerDay = 120.0f
	};

	struct VehicleShopInfo *pVehicle = &vehicle_1;
	
	printf("\nVehicle_1:\t%u,\t%s,\t%s,\t%s,\t%.2f", pVehicle->yearOfМanufacture, pVehicle->brand, pVehicle->model, pVehicle->VIN, pVehicle->pricePerDay);
	printf("\nChange year of manufacture:");
	scanf_s("%u", &(pVehicle->yearOfМanufacture));
	printf("\nVehicle_1:\t%u,\t%s,\t%s,\t%s,\t%.2f", pVehicle->yearOfМanufacture, pVehicle->brand, pVehicle->model, pVehicle->VIN, pVehicle->pricePerDay);
	return 0;
}