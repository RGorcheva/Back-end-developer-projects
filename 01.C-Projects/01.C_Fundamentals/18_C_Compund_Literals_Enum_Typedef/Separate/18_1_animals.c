/*
Дефинирайте структура Animal с два member-а: име на вида на животното и това
дали е тревопасно, хищник или всеядно ( Herbivore, Carnivore, Omnivore
съответно ). Използвайте enum за класификацията на видовете животни според
вида на храната им.
● Използвайте typedef при дефиницията на структурата и enum-a за да не се
налага да пишем struct или enum всеки път когато декларираме променлива от
тези типове.
● Използвайте typedef за да дадете алтернативно име на тип : указател към Animal
● Напишете функция, която приема масив от Animal и принтира информацията за
всеки елемент от масива. За целта ползвайте “новия тип” от предходната точка.
Дефинирайте и инициализирайте масив от животни, тествайте функцията с
масива
*/

#include <stdio.h>


typedef enum { Cat, Dog, Pig, Horse, Lion, Dove, Human} animalType;
typedef enum { Herbivore, Carnivore, Omnivore } foodType;

typedef struct {
	animalType type;
	foodType eat;
} Animal;

typedef Animal* PtrAnimal;

void print_animals(PtrAnimal ptrAnimal);

int main(void)
{
	Animal animals[7] = {
		{
			.type = Cat,
			.eat = Carnivore
		},
		{
			.type = Dog,
			.eat = Carnivore
		},
				{
			.type = Pig,
			.eat = Omnivore
		},
		{
			.type = Horse,
			.eat = Herbivore
		},
				{
			.type = Lion,
			.eat = Carnivore
		},
		{
			.type = Dove,
			.eat = Herbivore
		},
		{
			.type = Human,
			.eat = Omnivore
		}
	};

	PtrAnimal ptrAnimal = animals;
	print_animals(ptrAnimal);
	return 0;
}


void print_animals(PtrAnimal ptrAnimal)
{
	PtrAnimal pt = ptrAnimal;
	for (; pt < ptrAnimal + 7; pt++)
	{
		switch (pt->type)
		{
			case Cat: printf("\nCat"); break;
			case Dog: printf("\nDog"); break;
			case Pig: printf("\nPig"); break;
			case Horse: printf("\nHorse"); break;
			case Lion: printf("\nLion"); break;
			case Dove: printf("\nDove"); break;
			case Human: printf("\nHuman"); break;
			default: break;
		};
		switch (pt->eat)
		{
			case Herbivore: printf("\nHerbivore"); break;
			case Carnivore: printf("\nCarnivore"); break;
			case Omnivore: printf("\nOmnivore"); break;
			default: break;
		};
		printf("\n");
	}
}