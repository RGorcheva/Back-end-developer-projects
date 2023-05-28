/*
Напишете програма, която си принтира аргументите, подадени от командния ред, всеки на нов ред.
Използвайте следния прототип за main функцията:
int main(int argc, char* argv[])
Тествайте програмата си от командния ред.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		printf("%s\t", argv[i]);
	}
	return 0;
}
