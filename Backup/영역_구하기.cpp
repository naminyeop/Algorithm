#include <stdio.h>

#define __DFS__	1

#define MAX_ARR	101

int M, N, K;
int arr[MAX_ARR][MAX_ARR];
int djcnt;

void init(void)
{
	int k;
	int x1, y1, x2, y2;
	int i, j;

	scanf("%d %d %d", &M, &N, &K);

	for (k = 0; k < K; k++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (i = y1; i < y2; i++)
		{
			for (j = x1; j < x2; j++)
			{
				arr[i][j] = 1;
			}
		}
	}
}

void print(void)
{
	int i, j;

	printf("=======print==========\n");

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}

#if __DFS__

void dfs(int y, int x, int cnt)
{
	//if (arr[y][x] != 0)	return;
	//else
	{
		/* µ¿ */
		if (x + 1 <= N && arr[y][x + 1] == 0)
		{
			arr[y][x + 1] = cnt;
			dfs(y, x + 1, cnt);
		}

		/* ¼­ */
		if (x - 1 >= 0 && arr[y][x - 1] == 0)
		{
			arr[y][x - 1] = cnt;
			dfs(y, x - 1, cnt);
		}

		/* ³² */
		if (y + 1 <= M && arr[y + 1][x] == 0)
		{
			arr[y + 1][x] = cnt;
			dfs(y + 1, x, cnt);
		}

		/* ºÏ */
		if (y - 1 <= M && arr[y - 1][x] == 0)
		{
			arr[y - 1][x] = cnt;
			dfs(y - 1, x, cnt);
		}
	}

}

void prog(void)
{
	int i, j;

	djcnt = 2;

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
			{
				dfs(i, j, djcnt);
				djcnt++;
			}
		}
	}
}

#else


void prog(void)
{
	int i, j;

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
			{

			}
		}
	}
}

#endif

int main(void)
{
	init();

	print();

	prog();

	print();

	return 0;
}