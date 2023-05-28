#ifndef MACROSTRINGS_H
#define MACROSTRINGS_H

#define MAIN_MENU_MENU   "\n---------------------------------------\
						  \nMAIN MENU:"
#define MAIN_MENU_CHOICE "\n---------------------------------------\
						  \nPress 1 to choose VEHICLE LIST\
						  \nPress 2 to choose VEHICLE BRAND LIST\nPress q to QUIT\
						  \n---------------------------------------\n"
#define WRONG_CHOICE "\nYour choice is not correct! Try again!\n"
#define VEHICLE_LIST_MENU "\n---------------------------------------\
						   \nVEHICLE LIST:\
						   \n---------------------------------------"
#define VEHICLE_LIST_MENU_CHOICE "\n---------------------------------------\
								  \nPress 1 to see BRAND DETAILS\
								  \nPress 2 to RENT A VEHICLE\
								  \nPress b to go back to MAIN MENU\
								  \n---------------------------------------\n"
#define VEHICLE_BRAND_LIST "\n---------------------------------------\
							\nVEHICLE BRAND LIST\
							\n---------------------------------------"
#define VEHICLE_BRAND_LIST_CHOICE  "\n---------------------------------------\
									\nPress 1 to see BRAND DETAILS\
									\nPress 2 to RENT A VEHICLE\
									\nPress b to go back to MAIN MENU\
									\n---------------------------------------\n"
#define VEHICLE_BRAND_LIST_CHOICE_BRAND "\nChoose vehicle brand between:\n"
#define VEHICLE_BRAND_LIST_CHOICE_VEHICLE "\nChoose a vehicle number:"
#define VEHICLE_BRAND_LIST_BRAND(X) (printf("\n---------------------------------------\
											 \nBrand: %s\
											 \n---------------------------------------",X))
#define BRAND_DETAILS_MENU "\n---------------------------------------\
							\nBRAND DETAILS:\
							\n---------------------------------------"
#define BRAND_DETAILS_MENU_CHOICE  "\n--------------------------------------\
									\nPress b to go back to VEHICLE LISTS\
									\n---------------------------------------\n"
#define BRAND_DETAILS_MENU_CHOICE_BRAND "\nChoose vehicle brand between:\n"
#define RENT_A_VEHICLE_MENU	"\n---------------------------------------\
							 \nRENT A VEHICLE:\
							 \n---------------------------------------"
#define RENT_A_VEHICLE_MENU_CHOICE "\n---------------------------------------\
									\nPress 1 to MAIN MENU\
									\nPress q to QUIT\
									\n---------------------------------------\n"
#define RENT_A_VEHICLE_DAYS "\n\nFor how many days will you rent the vehicle?\n"

#define ACCOUNT(X,Y) (printf("\n---------------------------------------\
					  \nYour current account is %.2f\
					  \nYour Final account is %.2f", X, Y))

#endif