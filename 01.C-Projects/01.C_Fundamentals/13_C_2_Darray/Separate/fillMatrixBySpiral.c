#include <stdio.h>

#define N 3

void fillArr(const int n, int* arr)
{
	static int i = 1;
	static int it = 0;

	if (it == n - it - 1)
	{
		int row = it;
		int col = it;
		arr[row * n + col] = i;
		return;
	}
	for (int col = it; col != n - it - 1; col++)
	{
		int row = it;
		arr[row * n + col] = i;
		i++;
	}
	for (int row = it; row != n - it - 1; row++)
	{
		int col = n - it - 1;
		arr[row * n + col] = i;
		i++;
	}
	for (int col = n - it-1; it + 1 <= col; col--)
	{
		int row = n - it - 1;
		arr[row * n + col] = i;
		i++;
	}
	for (int row = n - it - 1; it + 1 <= row; row--)
	{
		int col = it;
		arr[row * n + col] = i;
		i++;
	}
	it++;
}

int main(void)
{
	int arr[N][N] = { 0 };
	int iter = 0;
	iter = (N % 2 == 0) ? (N / 2) : (N / 2 + 1);
	for (int i = 0; i < iter; i++)
	{
		fillArr(N, *arr);
	}
	for (int i = 0; i != N; i++)
	{
		for (int j = 0; j != N; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}