#include <stdio.h>

#define MAX_ARR	51

int N, M;
int r_y, c_x, dir;
int arr[MAX_ARR][MAX_ARR];
int clean_cnt; 

/* 북(0), 동(1), 남(2), 서(3) */
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void init(void)
{
	int i, j;

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r_y, &c_x, &dir);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

}

void print(void)
{
	int i, j;

	printf("==========================\n");

	for (i = 0; i < r_y; i++)
	{
		for (j = 0; j < c_x; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void clean(int y, int x)
{
	if (arr[y][x] == 0)
	{
		arr[y][x] = 2;
		clean_cnt++;
	}
}
void dfs(int y, int x, int dir)
{
	int i;
	int temp_y, temp_x, temp_dir;

	if (arr[y][x] == 1)	return;

	/* process1. 현재위치 청소 */
	clean(y, x);

	/* process2. 왼쪽부터 탐색 */
	/* 북(0), 동(1), 남(2), 서(3) */
	for (i = 0; i < 4; i++)
	{
		temp_dir = (dir + 3) % 4;	/* 왼쪽으로 방향 전환 */
		
		temp_y = y + dy[temp_dir];	/* 왼쪽에 있는 좌표 */
		temp_x = x + dx[temp_dir];
	
		if (arr[temp_y][temp_x] == 0)	/* 청소 가능 공간*/
		{
			dfs(temp_y, temp_x, temp_dir);
			return; 
		}
		else
		{
			dir = temp_dir;
		}
	}

	/* 4 방향 모두 청소가 되있거나 벽인 경우 */

	/* 바라보는 방향을 유지한채 한칸 후진 */
	if (dir == 0)	y++;
	else if (dir == 1)	x--; 
	else if (dir == 2)	y--;
	else if (dir == 3)	x++;
	else;
		
	/* process2.를 수행한다 */
	dfs(y, x, dir);

}

int main(void)
{
	init();

	dfs(r_y, c_x, dir);

	printf("%d\n", clean_cnt);

	return 0;
}