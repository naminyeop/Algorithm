#include <stdio.h>
#include <string.h>
#define	MAX_ARR	8

int N, M;
int arr[MAX_ARR][MAX_ARR];
int copy[MAX_ARR][MAX_ARR];

int queue[2][MAX_ARR*MAX_ARR];
int front, rear;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
unsigned int max = 0;
unsigned int safety_cnt = 0;

void init(void)
{
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2)	/* 바이러스이면 queue에 삽입 */
			{
				queue[0][rear] = i;
				queue[1][rear] = j;
				rear++;
			}
		}
	}
}

void print(void)
{
	int i, j;

	printf("=======================\n");

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int bfs(void)
{
	int v_y, v_x;
	int i,j;
	int temp_y, temp_x;
	int ret;

	while (front < rear)
	{
		v_y = queue[0][front];
		v_x = queue[1][front++];

		//printf("y : %d, x : %d \r\n", v_y, v_x);

		for (i = 0; i < 4; i++)
		{
			temp_y = v_y + dy[i];
			temp_x = v_x + dx[i];

			if (temp_y < 0 || temp_x < 0 || temp_y >= N || temp_x >= M)	continue;

			if (arr[temp_y][temp_x] == 0)
			{
				arr[temp_y][temp_x] = 2;

				queue[0][rear] = temp_y;
				queue[1][rear] = temp_x;
				rear++;
			}
		}
	}

	safety_cnt = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)	/* 안전 영역 */
			{
				safety_cnt++;
			}
		}
	}

	ret = safety_cnt;

	return ret;
}

void dfs(int y, int x, int depth)
{
	int i, j;
	int dummy;
	int ret = 0;

	arr[y][x] = 3;
	if (depth == 1)
	{
		/* 저장 */
		memset(copy, 0x0, sizeof(int)*MAX_ARR*MAX_ARR);
		memcpy(copy, arr, sizeof(int)*MAX_ARR*MAX_ARR);

//		printf("SAVE !! \n");
//		print();

		/* bfs를 돌려야 하고 */
		ret = bfs();
		if (ret > max)	max = ret;

//		print();
//		scanf("%d", &dummy);

		/*복원*/
		memcpy(arr, copy, sizeof(int)*MAX_ARR*MAX_ARR);
		memset(queue, 0x0, sizeof(int)*2*MAX_ARR*MAX_ARR);
		arr[y][x] = 0;
		front = rear = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (arr[i][j] == 2)	/* 바이러스이면 queue에 삽입 */
				{
					queue[0][rear] = i;
					queue[1][rear] = j;
					rear++;
				}
			}
		}

		return;
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)	/* 벽을 놓을 수 있는 빈 공간 */
			{
				dfs(i, j, depth-1);
			}
		}
	}
	arr[y][x] = 0;
}

void prog(void)
{
	int i, j; 

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)	/* 벽을 놓을 수 있는 빈 공간 */
			{
				dfs(i, j, 3);
			}
		}
	}

	printf("%d\n", max);

}

int main(void)
{
	init();

	prog();

	return 0;
}