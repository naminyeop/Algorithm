#include <stdio.h>

int num, L;
int cnt_arr[1001];
char dir_arr[1001] = {'R',};
int front = 1;
int count;
int flag = 0;

int check(int x, int y)
{
	int ret = 1;






	return ret;
}


// dir : (µ¿:0) (ºÏ:1) (¼­:2) (³²:3)
void prog(int cur_x, int cur_y)
{
	int i;
	int nx, ny;
	int len;
	char dir = 'R';
	char prev_dir, temp_dir;

	do
	{
		len = cnt_arr[front];
		
		printf("len : %d , dir : %c\n", len, dir);

		for (i = 0; i < len; i++)
		{
			if (dir == 'R')
			{
				cur_x = cur_x + 1;
			}
			else if (dir == 'L')
			{
				cur_x = cur_x - 1;
			}
			else if (dir == 'U')
			{
				cur_y = cur_y + 1;
			}
			else if (dir == 'D')
			{
				cur_y = cur_y - 1;
			}
			else;

			flag = check(cur_x, cur_y);
			if (flag == 1)
			{
				break;
			}
			printf("cur_x : %d / cur_y : %d\n", cur_x, cur_y);
		}

		if (flag == 1)
		{
			break;
		}

		prev_dir = dir;
		temp_dir = dir_arr[front++];

		if (prev_dir == 'R' && temp_dir == 'L')	dir = 'U';
		else if (prev_dir == 'R' && temp_dir == 'R')	dir = 'D';
		else if (prev_dir == 'U' && temp_dir == 'L')	dir = 'L';
		else if (prev_dir == 'U' && temp_dir == 'R')	dir = 'R';
		else if (prev_dir == 'L' && temp_dir == 'L')	dir = 'D';
		else if (prev_dir == 'L' && temp_dir == 'R')	dir = 'U';
		else if (prev_dir == 'D' && temp_dir == 'L')	dir = 'R';
		else if (prev_dir == 'D' && temp_dir == 'R')	dir = 'L';
		else;

	} while (1);



}

void init(void)
{
	int i;

	scanf("%d", &L);
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d %c", &cnt_arr[i], &dir_arr[i]);
	}
#if 0
	for (i = 0; i <= num; i++)
	{
		printf("%d %c \n", cnt_arr[i], dir_arr[i]);
	}
#endif

}

int main(void)
{
	init();

	prog(0,0);

	return 0;
}
