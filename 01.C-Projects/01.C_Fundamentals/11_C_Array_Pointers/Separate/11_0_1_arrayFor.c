﻿/*
Дефинирайте масив от 8 елемента и инициализирайте елементите му на 0.
Обходете масива и променете стойността на всеки втори елемент на 1
00000000 -> 01010101
*/

#include <stdio.h>

int main()
{
	int arr[8] = {0,0,0,0,0,0,0,0};
	int i = 0;

	for (i = 1; i < 8; i+= 2)
	{
			arr[i] = 1;
	}
	for (i = 0; i < 8; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}
