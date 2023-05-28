/* Направете генератор на случайни числа по следния алгоритъм (xorshift):
 int A = 1, акумулатор с начална стойност
 При всяко вземане на число от генератора се прави следното:
 (i) A ^= A << 13;
 (ii) A ^= A >> 17;
 (iii) A ^= A << 5;
При всяка итерация изведете числото на екрана.
(Направете вариация с акумулатор long long int)
*/

#include <stdio.h>
#include <stdlib.h>

unsigned randNum(unsigned A)
{
	A ^= A << 13;
	printf("\nA = %d", A);
	A ^= A >> 17;
	printf("\nA = %d", A);
	A ^= A << 5;
	printf("\nA = %d", A);
	return A;
}

int main()
{
	unsigned B = 1;
	B = randNum(B);
	printf("\nB = %d\n", B);
	B = randNum(B);
	printf("\nB = %d\n", B);
	B = randNum(B);
	printf("\nB = %d", B);

	return 0;
}