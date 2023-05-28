#ifndef VEHICLELIST_H
#define VEHICLELIST_H

struct VehicleShopInfo
{
	unsigned yearOfМanufacture;
	const char* brand;
	const char* model;
	char VIN[20];
	float pricePerDay;
	unsigned isRented;
} VehicleShop[10], *ptrVehicleShop;

#endif