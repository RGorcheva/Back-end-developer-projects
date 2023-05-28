#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H
#include "../Library/datetimeFunc.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct Orders {
	int orderID;
	int	userID;
	int vehicleID;
	int daysRented;
	dateTime startDate;
	float invoice;
}Orders;

typedef struct listOrder {
	Orders order;
	struct listOrder* next;
}listOrder;

listOrder* pfirstOrder;

FILE*		orderObject_Deserilization(FILE* in, Orders* pOrderObject);
void		orderObject_Print(Orders* pOrderObject);
void		orderObject_Initializatoin(Orders* pOrderObject);
void		orderObject_Serilization(FILE* out, Orders* pOrderObject);

bool		 orderList_isEmpty(listOrder* list);
void		 orderList_init(listOrder* list);
int			 orderList_countElements(listOrder* list);
void		 orderList_print(listOrder* list);
listOrder*   orderList_findIndexN(listOrder* list, int indx);
listOrder*	 orderList_findLast(listOrder* list);
void		 orderList_copyStruct(listOrder* list, Orders* pOrderObject);
listOrder*	 orderList_pushBack(listOrder* list, Orders* pOrderObject);
listOrder*	 orderList_empty(listOrder* list);
listOrder*	 orderList_delete(listOrder* list, int indx);
listOrder*	 orderList_deserilization(listOrder* list);
void		 orderList_serilization(listOrder* list);


#endif