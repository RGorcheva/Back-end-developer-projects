/*
Пренапишете предишното упражнение като вмъкнете
конструкцията switch-case в един цикъл while, така че питането
да се повтаря, докато потребителят не въведе числото 4, което е
поставено в питането за изход от програмата.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int iChoice = -1;

	do
	{
		printf("\nHello!");
		printf("\nPress 1 to see a \“Hello, World\” message");
		printf("\nPress 2 to see a poem.");
		printf("\nPress 3 to get a random dice roll.");
		printf("\nPress 4 to exit.");
		scanf("%d", &iChoice);

		switch (iChoice)
		{
			case 1:
			{
				printf("\nHello, World!");
				break;
			}
			case 2:
			{
				printf("\nTwo lovely eyes - Peyo Yavorov");
				printf("\nTwo lovely eyes. The spirit of a child.\nTwo lovely eyes. Sunrays and music.");
				printf("\nThey don't want anything and they don't vow. \nMy soul is praying,");
				printf("Child! \nMy soul is praying.");
				break;
			}
			case 3:
			{
				printf("\n%d", rand() % 6);
				break;
			}
			case 4:
			{
				printf("\nThank you for your choice! Good bye!");
				break;
			}
			default:
			{
				printf("\nWrong choice!");
				break;
			}
		}
	} while (iChoice != 4);

	return 0;
}