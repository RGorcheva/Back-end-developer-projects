/*напишете собствена версия на стандартната функция strcmp от string.h
my_strcmp
която сравнява два стринга и връща:
● 0 ако са еднакви
● стойност, по - голяма от 0 ако първият стринг е “по - голям”(ако първата
различна буква има по - голяма целочислена стойност).
● стойност, по - малка от 0 ако вторият стринг е “по - голям”.
*/

#include "../library/stringfunctions.h"
#include "../library/myMath.h"

int main(void)
{
	const char str1[] = "123abcderahf";
	const char str2[] = "123abcde";
	int areEquals = 0;

	printf("\n%s", str1);
	printf("\n%s", str2);
	areEquals = string_strcmp(str1, str2);
	printf("\n%d", areEquals);
	return 0;
}

