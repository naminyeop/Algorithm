#include <stdio.h>
#include <string.h>

int N, M;
char arr[51][51];
int check[51][51];
int queue[2][2501];
int front, rear;

void init(void)
{
	int i, j;
	
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}
}

int bfs(int x, int y, int cnt)
{
	int nx, ny;
	int temp_max = 0;
	int i, j;

	front = rear = 0;
	for (i = 0; i < N; i++)
	{
		memset(check[i], 0x0, sizeof(int)* (M));
	}

	queue[0][rear] = x;
	queue[1][rear++] = y;
	check[x][y] = cnt;

	while (front < rear)
	{
		if (front + 1 >= 2500) front = 0;
		nx = queue[0][front];
		ny = queue[1][front++];
		//printf("nx : %d ny : %d , check : %d \n", nx, ny, check[nx][ny]);

		// µ¿
		if ((ny + 1 < M) && (arr[nx][ny + 1] == 'L') && check[nx][ny + 1] == 0)
		{
			if (rear + 1 >= 2500) rear = 0;
			queue[0][rear] = nx;
			queue[1][rear++] = ny + 1;		
			check[nx][ny + 1] = check[nx][ny] + 1;
			if (temp_max < check[nx][ny + 1]) temp_max = check[nx][ny + 1];
		}

		// ¼­
		if ((ny - 1 >= 0) && (arr[nx][ny - 1] == 'L') && check[nx][ny - 1] == 0)
		{
			if (rear + 1 >= 2500) rear = 0;
			queue[0][rear] = nx;
			queue[1][rear++] = ny - 1;
			check[nx][ny - 1] = check[nx][ny] + 1;
			if (temp_max < check[nx][ny - 1]) temp_max = check[nx][ny - 1];
		}


		// ³²
		if ((nx + 1 < N) && (arr[nx + 1][ny] == 'L') && check[nx + 1][ny] == 0)
		{
			if (rear + 1 >= 2500) rear = 0;
			queue[0][rear] = nx + 1;
			queue[1][rear++] = ny;
			check[nx + 1][ny] = check[nx][ny] + 1;
			if (temp_max < check[nx + 1][ny]) temp_max = check[nx + 1][ny];
		}

		// ºÏ
		if ((nx - 1 >= 0) && (arr[nx - 1][ny] == 'L') && check[nx - 1][ny] == 0)
		{
			if (rear + 1 >= 2500) rear = 0;
			queue[0][rear] = nx - 1;
			queue[1][rear++] = ny;
			check[nx - 1][ny] = check[nx][ny] + 1;
			if (temp_max < check[nx - 1][ny]) temp_max = check[nx - 1][ny];
		}
	
	}
	//printf("temp_max : %d \n", temp_max);
	return temp_max;
}

void prog(void)
{
	int i, j;
	int max = 0, temp = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (arr[i][j] == 'L')
			{
				//printf("%d %d \n", i, j);
				temp = bfs(i, j, 1);
				if (max < temp) max = temp;
			}
		}
	}

	printf("%d\n", max-1);
}

int main(void)
{
	init();
	prog();


	return 0;
}