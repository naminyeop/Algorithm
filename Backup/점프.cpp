#include <stdio.h>
#define MAX_ARR	101

#define bottom_up

int n;

int arr[MAX_ARR][MAX_ARR];
long long dp[MAX_ARR][MAX_ARR];

void init(void)
{
	int i, j;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
}

#ifdef bottom_up
void prog(void)
{
	int i, j;

	dp[1][1] = 1; 

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == n && j == n) break;
			dp[i + arr[i][j]][j] += dp[i][j];
			dp[i][j + arr[i][j]] += dp[i][j];
		}
	}
}
#else

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

/* top down */
long long prog(int y, int x)
{
	int i, j;
	long long ret;

	if (y == n && x == n) return 1;

	if (dp[y][x] > -1) {
		ret = dp[y][x];
		return ret;
	} 

	ret = 0;

	for (i = 0; i < 2; i++)
	{
		int nx = x + dx[i] * arr[y][x];
		int ny = y + dy[i] * arr[y][x];
		if (nx > n || ny > n) continue;

		ret += prog(nx, ny);
	}
	return ret;
}
#endif


int main(void)
{
	int i, j;
	init();
#ifdef bottom_up
	prog();
	
	printf("%lld\n", dp[n][n]);
#else
	printf("%lld", prog(1, 1));

	for (i = 1; i <= n; i++)
	{fff
		for (j = 1; j <= n; j++)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
#endif


	return 0;

}