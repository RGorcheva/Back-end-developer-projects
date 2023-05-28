/*
● Дефинирайте нов тип VehicleShopInfo, който можем да ползваме за да държим
информация, свързана с отдаването на превозни средства под наем.
● Дефинирайте members за следната информация:
○ Година на производство
○ Име на марката
○ Име на модела
○ Уникален идентификатор на превозното средство (VIN)
○ Цена на ден
● Дефинирайте две променливи от тип VehicleShopInfo и ги инициализирайте.
● Принтирайте информацията за двете превозни средства.
*/

#include <stdio.h>
#include <string.h>

const char* brand[] = {"FIAT", "MAZDA", "FORD", "TOYOTA"};
const char* model[] = {"Punto", "2", "Fiesta", "Yaris"};

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

	struct VehicleShopInfo vehicle_2 = {
		.yearOfМanufacture = 2010u,
		.brand = brand[1],
		.model =model[1],
		.VIN = "8363GKY0387864RD3",
		.pricePerDay = 100.0f
	};

	printf("\nVehicle_1:\t%u,\t%s,\t%s,\t%s,\t%.2f", vehicle_1.yearOfМanufacture, vehicle_1.brand, vehicle_1.model, vehicle_1.VIN, vehicle_1.pricePerDay);
	printf("\nVehicle_2:\t%u,\t%s,\t%s,\t%s,\t%.2f", vehicle_2.yearOfМanufacture, vehicle_2.brand, vehicle_2.model, vehicle_2.VIN, vehicle_2.pricePerDay);

	return 0;
}