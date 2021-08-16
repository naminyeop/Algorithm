#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARR	5001
#define MAX_NUM	3001

int T, N;
int arr[MAX_ARR][MAX_ARR];
int check[MAX_ARR][MAX_ARR];
int check2[MAX_ARR][MAX_ARR];
int pos[3][MAX_NUM]; // 0 : x , 1 : y , 2 : r

int front, rear;
int queue[2][MAX_ARR*MAX_ARR];
int djcnt;

void print(void)
{
	int i, j;

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}


void draw(int x, int y, int len)
{
	int temp_x, temp_y, temp_len = 1;

	check[y][x] = 1;

	while ((front < rear))
	{
		temp_x = queue[0][front];
		temp_y = queue[1][front++];
		
		if (arr[temp_y][temp_x] == len + 1) break;

		//printf("x : %d  y: %d len : %d \r\n", temp_x, temp_y, temp_len);

		/* µ¿ */
		if ((temp_x + 1 < MAX_ARR) && arr[temp_y][temp_x + 1] == 0)
		{
			queue[0][rear] = temp_x + 1;
			queue[1][rear++] = temp_y;
			arr[temp_y][temp_x + 1] = arr[temp_y][temp_x] + 1;
			check[temp_y][temp_x + 1] = arr[temp_y][temp_x] + 1;
		}
		/* ¼­ */
		if ((temp_x - 1 >= 0) && arr[temp_y][temp_x - 1] == 0)
		{
			queue[0][rear] = temp_x - 1;
			queue[1][rear++] = temp_y;
			arr[temp_y][temp_x - 1] = arr[temp_y][temp_x] + 1;
			check[temp_y][temp_x - 1] = arr[temp_y][temp_x] + 1;
		}

		/* ³² */
		if ((temp_y + 1 < MAX_ARR) && arr[temp_y + 1][temp_x] == 0)
		{
			queue[0][rear] = temp_x;
			queue[1][rear++] = temp_y + 1;
			arr[temp_y + 1][temp_x] = arr[temp_y][temp_x] + 1;
			check[temp_y + 1][temp_x] = arr[temp_y][temp_x] + 1;
		}

		/* ºÏ */
		if ((temp_y - 1 >= 0) && arr[temp_y - 1][temp_x] == 0)
		{
			queue[0][rear] = temp_x;
			queue[1][rear++] = temp_y - 1;
			arr[temp_y - 1][temp_x] = arr[temp_y - 1][temp_x] + 1;
			check[temp_y - 1][temp_x] = arr[temp_y][temp_x] + 1;
		}

	}
}

void dfs(int i, int j)
{
	check2[i][j] = djcnt;
	arr[i][j] = 0;

	/* µ¿ */
	if (j + 1 < MAX_ARR && arr[i][j + 1] != 0)
	{
		dfs(i, j + 1);
	}

	/* ¼­ */
	if (j - 1 >= 0  && arr[i][j - 1] != 0)
	{
		dfs(i, j - 1);
	}

	/* ³² */
	if (i + 1 < MAX_ARR && arr[i + 1][j] != 0)
	{
		dfs(i + 1, j);
	}


	/* ºÏ */
	if (i - 1 >= 0 && arr[i - 1][j] != 0)
	{
		dfs(i - 1, j);
	}

}

void prog(void)
{
	int i, j;

	for (i = 0; i < MAX_ARR; i++)
	{
		for (j = 0; j < MAX_ARR; j++)
		{
			if (arr[i][j] != 0 && check2[i][j] == 0)
			{
				djcnt++;
				dfs(i, j);
			}
		}
	}
	printf("%d", djcnt);

}

void init(void)
{
	int t, i,nx,ny,nr;
	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		scanf("%d", &N);
		memset(arr, 0x0, sizeof(int)*MAX_ARR*MAX_ARR);
		memset(check, 0x0, sizeof(int)*MAX_ARR*MAX_ARR);
		memset(check2, 0x0, sizeof(int)*MAX_ARR*MAX_ARR);
		djcnt = 0;

		for (i = 0; i < N; i++)
		{
			scanf("%d %d %d", &pos[0][i], &pos[1][i], &pos[2][i]);
			memset(queue, 0x0, sizeof(int) * 2 * MAX_ARR*MAX_ARR);
			front = rear = 0;

			nx = pos[0][i];
			ny = pos[1][i];
			nr = pos[2][i];
			arr[ny][nx] = 1;

			queue[0][rear] = nx;
			queue[1][rear++] = ny;

			draw(nx, ny, nr);
		}
		//print();
		prog();
	}
	
}

int main(void)
{
	init();


	return 0;
}