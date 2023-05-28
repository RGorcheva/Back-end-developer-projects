/*
Дефинирайте структура UserInfo със следните данни за всеки потребител:
● Категория на шофьорска книжка ( ползвайте enum за различните категории )
● Три имена
● ЕГН ( PIN )
Дефинирайте функции за сериализация(писане) и десериализация(четене) на обект от тип UserInfo.
Тествайте с текстов файл с данни за потребител и програма, която прочита файла, променя нещо и
го записва във същия файл.
*/

#include "..\Project Vehicle\userInfo.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	UserInfo user;
	//userInfoObject_Initializatoin(&user);

	FILE* in = NULL;	
	FILE* out = NULL;
	char filename[20]; //userInfo.txt
	printf("\nEnter input file name:");
	io_strEnter(filename, 20);

	in = file_open(in, filename, "r");
	userInfoObject_Deserilization(in, &user);
	file_close(in);

	userInfoObject_Print(&user);

	out = file_open(out, filename, "w");
	printf("Change drive category!\n");
	user.driveCategory = user.driveCategory + 1;
	userInfoObject_Serilization(out, &user);
	file_close(out);

	in = file_open(in, filename, "r");
	userInfoObject_Deserilization(in, &user);
	userInfoObject_Print(&user);
	file_close(in);

	return 0;
}