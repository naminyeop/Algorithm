#include <stdio.h>
#include <string.h>

#define MAX_ARR	51

int T;
int M, N;	// M : 가로 , N : 세로
int K;

int arr[MAX_ARR][MAX_ARR];
int check[MAX_ARR][MAX_ARR];
int djcnt;

void init(void)
{
	int i;
	int temp_x, temp_y;

	memset(arr, 0x0, sizeof(int) * MAX_ARR * MAX_ARR);
	memset(check, 0x0, sizeof(int) * MAX_ARR * MAX_ARR);
	djcnt = 0;

	scanf("%d %d %d", &M, &N, &K);

	for (i = 0; i < K; i++)
	{
		scanf("%d %d", &temp_x, &temp_y);
		arr[temp_y][temp_x] = 1;
	}
}

void dfs(int y, int x)
{
	if (check[y][x] == 1)	return;

	check[y][x] = 1;

	/* 동 */
	if (arr[y][x + 1] == 1 && x + 1 < M ) dfs(y, x + 1);
	/* 서 */
	if (arr[y][x - 1] == 1 && x - 1 >= 0) dfs(y, x - 1);
	/* 남 */
	if (arr[y + 1][x] == 1 && y + 1 < N) dfs(y + 1, x);
	/* 북 */
	if (arr[y - 1][x] == 1 && y - 1 >= 0) dfs(y - 1, x);

}

void prog(void)
{
	int i, j;

	for (i = 0; i < N; i++) // y
	{
		for (j = 0; j < M; j++) // x
		{
			if (arr[i][j] == 1 && check[i][j] == 0)
			{
				djcnt++;
				dfs(i,j);
			}
		}
	}
}

void print(void)
{
	int i, j;

	printf("================================\n");
	for (i = 0; i < N; i++) // y
	{
		for (j = 0; j < M; j++) // x
		{
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int i;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{	
		init();

		prog();
		//print();

		printf("%d\n", djcnt);
	}
	
	return 0;
}