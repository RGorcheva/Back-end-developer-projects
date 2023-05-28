#include "..\Project Vehicle\OrderDetails.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


int main(void)
{
	Orders order1 = {
		.orderID = 1u,
		.userID = 1u,
		.vehicleID = 3u,
		.daysRented = 3,
		.startDate.day = 05,
		.startDate.month = 01,
		.startDate.year = 2023,
		.invoice = 180.00f
	};
	Orders order2 = {
		.orderID = 2u,
		.userID = 2u,
		.vehicleID = 1u,
		.daysRented = 3,
		.startDate.day = 10,
		.startDate.month = 01,
		.startDate.year = 2023,
		.invoice = 150.00f
	};
	//FILE* out = NULL;
	//out = file_open(out, "orderList.txt", "w");
	//int count = 2;
	//int* pCountElements = &count;
	//out = int_serilization(out, pCountElements);
	//Orders* porderObject = &order1;
	//orderObject_Serilization(out, porderObject);
	//porderObject = &order2;
	//orderObject_Serilization(out, porderObject);
	//file_close(out);

	listOrder* pfirst = NULL;
	pfirst = orderList_deserilization(pfirst);
	orderList_print(pfirst);

	orderList_pushBack(pfirst, &order1);
	orderList_print(pfirst);
	orderList_delete(pfirst, 2);
	int iCountElements = orderList_countElements(pfirst);
	orderList_serilization(pfirst, &iCountElements);
	pfirst = orderList_empty(pfirst);
	orderList_print(pfirst);
	return 0;
}