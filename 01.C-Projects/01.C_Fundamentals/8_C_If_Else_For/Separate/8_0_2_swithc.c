/*
ренапишете предишното упражнение като вместо if - else - if конструкцията
използвайте switch - case.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int iChoice = -1;

	printf("\nPress 1 to see a \“Hello, World\” message");
	printf("\nPress 2 to see a poem.");
	printf("\nPress 3 to get a random dice roll.");
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
		default:
		{
			printf("\nWrong choice!");
			break;
		}
	}
	return 0;
}
	