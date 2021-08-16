#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <queue>

int N;
int arr[26][26];
int queue[2][626];
int front, rear;
int dan_cnt = 1;
int dan[1000];

void init(void)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
}

int compare(const void *first, const void *second) 
{ 
	if (*(int*)first > *(int*)second) 
		return 1; 
	else if (*(int*)first < *(int*)second) 
		return -1; 
	else return 0; 
}



void output(void)
{
	int i, j;
#if 0
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
#endif
	printf("%d\n", dan_cnt - 1);

	qsort(dan, dan_cnt+1, sizeof(int), compare);
	
	for (i = 2; i < dan_cnt + 1; i++)
	{
		printf("%d\n", dan[i]);
	}

}


void bfs(int x, int y)
{
	int nx, ny;
	
	dan_cnt++;
	queue[0][rear] = x;
	queue[1][rear++] = y; 
	arr[x][y] = dan_cnt;
	dan[dan_cnt]++;

	while (front < rear)
	{
		nx = queue[0][front];
		ny = queue[1][front++];

		// µ¿
		if ((ny + 1 < N) && (arr[nx][ny + 1] == 1))
		{
			arr[nx][ny + 1] = dan_cnt;
			queue[0][rear] = nx;
			queue[1][rear++] = ny + 1;
			dan[dan_cnt]++;
		}

		// ¼­
		if ((ny - 1 >= 0) && (arr[nx][ny - 1] == 1))
		{
			arr[nx][ny - 1] = dan_cnt;
			queue[0][rear] = nx;
			queue[1][rear++] = ny - 1;
			dan[dan_cnt]++;
		}


		// ³²
		if ((nx + 1 < N) && (arr[nx + 1][ny] == 1))
		{
			arr[nx + 1][ny] = dan_cnt;
			queue[0][rear] = nx + 1;
			queue[1][rear++] = ny;
			dan[dan_cnt]++;
		}


		// ºÏ
		if ((nx - 1 >= 0) && (arr[nx - 1][ny] == 1))
		{
			arr[nx - 1][ny] = dan_cnt;
			queue[0][rear] = nx - 1;
			queue[1][rear++] = ny;
			dan[dan_cnt]++;
		}
	}
}

void prog(void)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] == 1)
			{
				front = rear = 0;

				bfs(i, j);
			}
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	init();

	prog();
	
	output();

	return 0;
}