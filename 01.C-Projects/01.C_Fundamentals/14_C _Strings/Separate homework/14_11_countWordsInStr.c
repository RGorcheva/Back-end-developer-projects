
#include "../Library/inputOutputFunc.h"
#include "../Library/arrayFunc.h"
#include "../Library/stringFunc.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str[] = "How are you today, how were you yesterday?";
	printf("\n%s", str);
	string_countWordsAppear(str);
	return 0;
}
