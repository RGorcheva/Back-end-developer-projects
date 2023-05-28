#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char line[20];
	while (fgets(line, 20, stdin) != 0 && line[0] != '\n')
	{
		fputs(line, stdout);

		char* pCh = 0;
		if (pCh = strchr(line, '\n'))
			*pCh = '\0';
	}
}