#include <stdio.h>

#define MAX_ARR	(101)

int n, m;
int arr[MAX_ARR][MAX_ARR];
int check_arr[MAX_ARR][MAX_ARR];

int front, rear;
int queue[2][MAX_ARR*MAX_ARR];
int max;

void init(void)
{
	int i, j;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
}

void print(void)
{
	int i, j;

	printf("==============================\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void check(void)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (check_arr[i][j] > max)	max = check_arr[i][j];
		}
	}

	printf("%d", max);
}

void bfs(void)
{
	int nx, ny;

	queue[0][rear] = 0;
	queue[1][rear++] = 0;

	check_arr[0][0] = 1;

	while (front < rear)
	{
		nx = queue[0][front];
		ny = queue[1][front++];

		/* µ¿ */
		if ((ny + 1 < m) && arr[nx][ny + 1] == 1 && check_arr[nx][ny + 1] == 0)
		{
			queue[0][rear] = nx;
			queue[1][rear++] = ny + 1;
			check_arr[nx][ny + 1] = check_arr[nx][ny] + 1;
		}

		/* ¼­ */
		if ((ny - 1 >= 0) && arr[nx][ny - 1] == 1 && check_arr[nx][ny - 1] == 0)
		{
			queue[0][rear] = nx;
			queue[1][rear++] = ny - 1;
			check_arr[nx][ny - 1] = check_arr[nx][ny] + 1;
		}

		/* ³² */
		if ((nx + 1 < n) && arr[nx+1][ny] == 1 && check_arr[nx+1][ny] == 0)
		{
			queue[0][rear] = nx + 1;
			queue[1][rear++] = ny;
			check_arr[nx + 1][ny] = check_arr[nx][ny] + 1;
		}


		/* ºÏ */
		if ((nx - 1 >= 0) && arr[nx - 1][ny] == 1 && check_arr[nx-1][ny] == 0)
		{
			queue[0][rear] = nx - 1;
			queue[1][rear++] = ny;
			check_arr[nx-1][ny] = check_arr[nx][ny] + 1;
		}
	}

	printf("%d\n", check_arr[n - 1][m - 1]);
}

int main(void)
{
	init();

	//print();
	bfs();
//	check();
	

	return 0;
}