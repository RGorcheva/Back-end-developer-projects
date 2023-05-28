/*
Да се създаде Union с елементи float, char, int и double.
Да се създаде масив и да се мапълни с елементи от горния union с произволни стойности. 
*/

1#include <stdio.h>
#include <stdlib.h>
#include <time.h>

union base_type
{
	float f;
	char c;
	int i;
	double d;
} a;

struct base_val
{
	enum { val_type_f, val_type_c, val_type_i, val_type_d } value_type;
	union base_type value;
} base_val[10];

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		if (i % 4 == 0)
		{
			base_val[i].value.f = (float)(rand() % 10);
			base_val[i].value_type = val_type_f;
		}
		if (i % 4 == 1)
		{
			base_val[i].value.c = (char)(rand() % 10) + 'c';
			base_val[i].value_type = val_type_c;
		}
		if (i % 4 == 2)
		{
			base_val[i].value.i = (int)(rand() % 10);
			base_val[i].value_type = val_type_i;
		}
		if (i % 4 == 3)
		{
			base_val[i].value.d = (double)(rand() % 10);
			base_val[i].value_type = val_type_d;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (base_val[i].value_type == val_type_f)
		{
			printf("\n%0.4ff", base_val[i].value.f);
		}
		else if (base_val[i].value_type == val_type_c)
		{
			printf("\n%c", base_val[i].value.c);
		}
		else if (base_val[i].value_type == val_type_i)
		{
			printf("\n%d", base_val[i].value.i);
		}
		else
		{
			printf("\n%0.6lf", base_val[i].value.d);
		}
	}
	return 0;
}