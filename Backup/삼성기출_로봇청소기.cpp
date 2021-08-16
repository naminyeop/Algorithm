#include <stdio.h>
#define MAX_ARR	51

int N, M;
int r_y, c_x, dir; /* dir(0) : 북 / dir(1) : 동 / dir(2) : 남 / dir(3) : 서 */

int arr[MAX_ARR][MAX_ARR];
int dir_arr[MAX_ARR][MAX_ARR];
int cnt;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

void init(void)
{
	int i, j;
	
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r_y, &c_x, &dir);

	dir_arr[r_y][c_x] = dir;

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

	printf("=============================\n");

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
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
		cnt++;
	}
}

/* dir(0) : 북 / dir(1) : 동 / dir(2) : 남 / dir(3) : 서 */
void prog(int y, int x, int dir)
{
	int temp_dir, temp_y, temp_x;
	int i = 0;

	if (arr[y][x] == 1)	return;		// 벽이면 return

	clean(y, x);			// 1. 현재의 위치를 청소 한다.

	for (i = 0; i < 4; i++)
	{
		temp_dir = (dir + 3) % 4;
		temp_y = y + dy[temp_dir];
		temp_x = x + dx[temp_dir];

		if (arr[temp_y][temp_x] == 0)	// 왼쪽으로 돌았을때 청소할수 있는 공간이면
		{
			prog(temp_y, temp_x, temp_dir);
			return;
		}
		else
		{
			dir = temp_dir;
		}
	}

	if (dir == 0)			y++;
	else if (dir == 1)		x--;
	else if (dir == 2)		y--;
	else if (dir == 3)		x++;
	else;

	prog(y, x, dir);
}

int main(void)
{
	init();

//	print();

	prog(r_y , c_x, dir);

	printf("%d\n", cnt);

	return 0;
}