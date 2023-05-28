#include "functionsMenu.h"

//да се преработи на лист

int main(void)
{
	int menuChoice = 0;
	mainMenu: menuChoice = f_main_menu();
	if (menuChoice == e_allVehicleList)
	{
		allVehicleList: menuChoice = f_allVehicleList();
		if (menuChoice == e_rentVehicle)
		{
			menuChoice = f_rentVehicle();
			if (menuChoice == e_main_menu)
			{
				goto mainMenu;
			}
		}
		else if (menuChoice == e_brandDetails)
		{
			menuChoice = f_brandDetails();
			goto allVehicleList;
		} 
		else goto mainMenu;
	}
	else if (menuChoice == e_vehicleBrandList)
	{
		vehicleBrandList: menuChoice = f_vehicleBrandList();
		if (menuChoice == e_rentVehicle)
		{	
			menuChoice = f_rentVehicle();
			if (menuChoice == e_main_menu)
			{
				goto mainMenu;
			}
		}
		else if (menuChoice == e_brandDetails)
		{
			menuChoice = f_brandDetails();
			goto vehicleBrandList;
		}
		else goto mainMenu; 
	}
	else if (menuChoice == e_quit)
	{
		return 0;
	}
	return 0;
}