#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <stdio.h>
#include <stdbool.h>

 enum DrivingLicense;

typedef struct VehicleShopInfo
{
	unsigned vehicleID;
	char brand[10];
	char model[10];
	char VIN[20];
	unsigned yearOfМanufacture;
	enum DrivingLicense driveCatNeeded;
	float pricePerDay;
	unsigned isRented;
} VehicleInfo;

typedef struct listVehicle
{
	VehicleInfo vehicle;
	struct listVehicle* next;
} listVehicle;

listVehicle* pfirstVehicle;

FILE*		vehicleObject_Deserilization(FILE* in, VehicleInfo* pVehicleObject);
void		vehicleObject_Print(VehicleInfo* pVehicleObject);
void		vehicleObject_Initializatoin(VehicleInfo* pVehicleObject);
void		vehicleObject_Serilization(FILE* out, VehicleInfo* pVehicleObject);

bool		 vehicleList_isEmpty(listVehicle* list);
void		 vehicleList_init(listVehicle* list);
int			 vehicleList_countElements(listVehicle* list);
void		 vehicleList_print(listVehicle* list);
listVehicle* vehicleList_findIndexN(listVehicle* list, int indx);
listVehicle* vehicleList_findLast(listVehicle* list);
void		 vehicleList_copyStruct(listVehicle* list, VehicleInfo* pVehicleObject);
listVehicle* vehicleList_pushBack(listVehicle* list, VehicleInfo* pVehicleObject);
listVehicle* vehicleList_insert(listVehicle* list, int indx);
listVehicle* vehicleList_empty(listVehicle* list);
listVehicle* vehicleList_delete(listVehicle* list, int indx);
listVehicle* vehicleList_deserilization(listVehicle* list);
void		 vehicleList_serilization(listVehicle* list);

#endif