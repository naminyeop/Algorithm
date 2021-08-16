#include <stdio.h>

#define MAX_ARR	100

int n;
int arr[MAX_ARR][MAX_ARR];
int dp[MAX_ARR][MAX_ARR];

void init(void)
{
	int i, j;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
}

int min(int a, int b)
{
	if (a > b) return b;
	else		return a;
}

int prog(int y, int x)
{
	if (dp[y][x] > 0) return dp[y][x];

	if (y == 1 && x == 1)
	{
		dp[y][x] = arr[y][x];
	}
	else if (y == 1)
	{
		dp[y][x] =  prog(1, x - 1) + arr[y][x];
	}
	else if (x == 1)
	{
		dp[y][x] = prog(y - 1, x) + arr[y][x];
	}
	else
	{
		dp[y][x] = arr[y][x] + min(prog(y-1,x),prog(y,x-1));
	}

	return dp[y][x];
}

int main(void)
{
	init();

	printf("%d", prog(n,n));	

	return 0;
}