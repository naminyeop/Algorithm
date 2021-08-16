#include <stdio.h>

int arr[101][101];
int result_arr[101][101];
int check[101];
int front, rear;
int queue[10201];
int num;

void bfs(int k)
{
	int ny,i;

	queue[rear++] = k;

	while (front < rear)
	{
		ny = queue[front++];
		
		for (i = 0; i < num; i++)
		{
			if ((arr[ny][i] == 1) && (check[i] == 0))
			{
				queue[rear++] = i;
				check[i] = 1;
			}
		}
	}
}

void check_arr(int k)
{
	int i, j;

	for (i = 0; i < num; i++)
	{
		if (check[i] == 1)
		{
			result_arr[k][i] = 1;
			check[i] = 0;
		}
	}
}

int main(void)
{
	int i,j,k;
	int result = 0;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (k = 0; k < num; k++)
	{
		bfs(k);
		check_arr(k);
	}

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%d ", result_arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}