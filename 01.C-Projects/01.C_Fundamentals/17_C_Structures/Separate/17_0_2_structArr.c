/*
Дефинирайте масив от VehicleShopInfo обекти и го инициализирайте.
Обходете масива и принтирайте информацията за всяко превозно средство от
масива.
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
	struct VehicleShopInfo vehicles[2] = {
	{
		.yearOfМanufacture = 2017u,
		.brand = brand[3],
		.model = model[3],
		.VIN = "67LU280957863CH56",
		.pricePerDay = 120.0f
	},
	{
		.yearOfМanufacture = 2010u,
		.brand = brand[1],
		.model = model[1],
		.VIN = "8363GKY0387864RD3",
		.pricePerDay = 100.0f
	}
	};

	printf("\nVehicle[0]:\t%u,\t%s,\t%s,\t%s,\t%.2f", vehicles[0].yearOfМanufacture, vehicles[0].brand, vehicles[0].model, vehicles[0].VIN, vehicles[0].pricePerDay);
	printf("\nVehicle[1]:\t%u,\t%s,\t%s,\t%s,\t%.2f", vehicles[1].yearOfМanufacture, vehicles[1].brand, vehicles[1].model, vehicles[1].VIN, vehicles[1].pricePerDay);

	return 0;
}