#include <stdio.h>

int arr[21][21];
int N, M;
int s_x, s_y;
int num;
int dir[1001];
int front, rear;

typedef struct{
	int up;
	int down;
	int left;
	int right;
	int fron;
	int rer;
}dice;

dice d;

void init(void)
{
	int i, j;
	int k;

	scanf("%d %d %d %d %d", &N, &M, &s_x, &s_y, &num);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (k = 0; k < num; k++)
	{
		scanf("%d", &dir[k]);
		rear++;
	}
}

void print(void)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void trans(int x, int y)
{
	if (arr[x][y] == 0) // 이동한 곳의 좌표가 0이면 
	{
		arr[x][y] = d.down;
	}
	else
	{
		d.down = arr[x][y];
		arr[x][y] = 0;
	}
}

void dice_trans(int dir)
{
	int temp_up, temp_down, temp_left, temp_right, temp_front, temp_rear;

	switch (dir)
	{
	case 1: // 동
		temp_up = d.up;
		temp_down = d.down;
		temp_left = d.left;
		temp_right = d.right;

		d.up = temp_left;
		d.down = temp_right;
		d.left = temp_down;
		d.right = temp_up;
		break;

	case 2: // 서
		temp_up = d.up;
		temp_down = d.down;
		temp_left = d.left;
		temp_right = d.right;

		d.up = temp_right;
		d.down = temp_left;
		d.left = temp_up;
		d.right = temp_down;
		break;

	case 3: // 남
		temp_up = d.up;
		temp_down = d.down;
		temp_front = d.fron;
		temp_rear = d.rer;

		d.up = temp_rear;
		d.down = temp_front;
		d.fron = temp_up;
		d.rer = temp_down;
		break;

	case 4: // 북
		temp_up = d.up;
		temp_down = d.down;
		temp_front = d.fron;
		temp_rear = d.rer;

		d.up = temp_front;
		d.down = temp_rear;
		d.fron = temp_down;
		d.rer = temp_up;
		break;

	default:
		break;
	}


}

void prog(void)
{
	int temp_dir;
	int temp_x, temp_y;

	temp_x = s_x;
	temp_y = s_y;

	while (front < rear)
	{
		temp_dir = dir[front++];
		
		//printf("x : %d y : %d\n", temp_x, temp_y);
		switch (temp_dir)
		{
			case 1: // 동
				if (temp_y + 1 < M)
				{
					//printf("move 동 ");
					dice_trans(1);
					temp_y = temp_y + 1;
					trans(temp_x, temp_y);
					printf("%d\n", d.up);
				}				
				break;

			case 2: // 서
				if (temp_y - 1 >= 0)
				{
					//printf("move 서 ");
					dice_trans(2);
					temp_y = temp_y - 1;
					trans(temp_x, temp_y);
					printf("%d\n", d.up);
				}
				break;

			case 3: // 북
				if (temp_x - 1 >= 0)
				{
					//printf("move 북 ");
					dice_trans(3);
					temp_x = temp_x - 1;
					trans(temp_x, temp_y);
					printf("%d\n", d.up);
				}
				break;

			case 4: // 남
				if (temp_x + 1 < N)
				{
					//printf("move 남 ");
					dice_trans(4);
					temp_x = temp_x + 1;
					trans(temp_x, temp_y);
					printf("%d\n", d.up);
				}
				break;

			default:
				break;
		}
	
	}

}

int main(void)
{
	init();
	//print();
	prog();

	return 0;
}


