/*
Използвайте конструкцията if-else, направете програма, която
прави едно от три различни неща(каквито си изберете), в
зависимост от избора на потребителя:
Press 1 to see a “Hello, World” message.
Press 2 to see a poem.
Press 3 to get a random dice roll. (може да ползвате функцията int rand() от stdlib.h)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int iChoice = -1;

	printf("\nPress 1 to see a \"Hello, World\" message");
	printf("\nPress 2 to see a poem.");
	printf("\nPress 3 to get a random dice roll.");
	scanf("%d", &iChoice);
	time_t t = 0;

	srand((unsigned)time(&t));

	if (iChoice == 1)
	{
		printf("\nHello, World!");
	}
	else if (iChoice == 2)
	{
		printf("\nTwo lovely eyes - Peyo Yavorov");
		printf("\nTwo lovely eyes. The spirit of a child.\nTwo lovely eyes. Sunrays and music.");
		printf("\nThey don't want anything and they don't vow. \nMy soul is praying,");
		printf("Child! \nMy soul is praying.");
	}
	else if (iChoice == 3)
		{
			printf("\nThe dice shows %d", rand()%6);
		}
	return 0;
}