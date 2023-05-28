#ifndef FUNCTIONSMENU_H
#define FUNCTIONSMENU_H

//extern int chooseVehicle;

enum Function 
{ 
	e_main_menu, 
	e_quit, 
	e_back, 
	e_vehicleBrandList, 
	e_allVehicleList, 
	e_brandDetails, 
	e_rentVehicle
};

void			enter_vehicleInfo(struct VehicleShopInfo* pVehicle);
void			print_vehicleInfo(struct VehicleShopInfo* pVehicle);
void			print_brandDetails(struct VehicleShopInfo* pVehicle, struct BrandDetails* pBrandInfo);
enum Function	f_main_menu(void);
enum Function	f_vehicleBrandList(void);
enum Function	f_allVehicleList(void);
enum Function	f_brandDetails(void);
enum Function	f_rentVehicle(void);

#endif
