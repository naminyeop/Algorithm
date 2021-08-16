#include <stdio.h>

int M, N;
int arr[1001][1001];
int init_cnt;
int queue[2][1002001];
int front, rear; 

int init(void)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
			{
				queue[0][rear] = i;
				queue[1][rear] = j;
				rear++;
				init_cnt++;
			}
		}
	}

	return init_cnt;
}

void bfs(void)
{
	int nx, ny;

	while (front < rear)
	{
		nx = queue[0][front];
		ny = queue[1][front];
		front++;
		
		// µ¿ 
		if ((ny + 1 < M) && (arr[nx][ny + 1] == 0))
		{
			arr[nx][ny + 1] = arr[nx][ny] + 1;
			queue[0][rear] = nx;
			queue[1][rear] = ny + 1;
			rear++;
		}

		// ¼­
		if ((ny - 1 >= 0) && (arr[nx][ny - 1] == 0))
		{
			arr[nx][ny - 1] = arr[nx][ny] + 1;
			queue[0][rear] = nx;
			queue[1][rear] = ny - 1;
			rear++;
		}


		// ³²
		if ((nx + 1 < N) && (arr[nx+1][ny] == 0))
		{
			arr[nx+1][ny] = arr[nx][ny] + 1;
			queue[0][rear] = nx + 1;
			queue[1][rear] = ny;
			rear++;
		}


		// ºÏ
		if ((nx - 1 >= 0) && (arr[nx-1][ny] == 0))
		{
			arr[nx - 1][ny] = arr[nx][ny] + 1;
			queue[0][rear] = nx - 1;
			queue[1][rear] = ny;
			rear++;
		}
	}
}

void output(int flag)
{
	int i, j;
	int break_flag = 0;
	int max = 0;

	if (flag == 1)
	{
		printf("0\n");
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (arr[i][j] == 0)
				{
					break_flag = 1;
					break;
				}
				else
				{
					if (arr[i][j] > max)
					{
						max = arr[i][j];
					}
				}
			}
			if (break_flag == 1)
				break;
		}

		if (break_flag == 1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", max - 1);
		}
	}
}

int main(void)
{
	int flag = 0;
	int i, j;

	scanf("%d %d", &M, &N);

	if (init() == M * N)
	{
		flag = 1;
	}
	else
	{
		bfs();
	}

	output(flag);

	return 0;
}