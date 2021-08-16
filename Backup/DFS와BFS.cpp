#include <stdio.h>
#include <string.h>

int num, M, start;
int arr[1001][1001];
int queue[10001];
int front, rear;
int check[2000];

void init(void)
{
	int i, input1, input2;

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &input1, &input2);
		
		arr[input1][input2] = 1;
		arr[input2][input1] = 1;
	}
}

void dfs(int start)
{
	int i;
	printf("%d ", start);

	check[start] = 1;
	
	for (i = 1; i <= num; i++)
	{
		if ((arr[start][i] == 1) && (check[i] == 0))
		{
			dfs(i);
		}
	}
}

void bfs(int start)
{
	int temp, i;

	queue[rear++] = start;
	check[start] = 1;

	while (front < rear)
	{
		temp = queue[front++];
		printf("%d ", temp);
		for (i = 1; i <= num; i++)
		{
			if (arr[temp][i] == 1 && check[i] == 0)
			{
				queue[rear++] = i;
				check[i] = 1;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &num, &M, &start);
	
	init();

	dfs(start);
	memset(check, 0, sizeof(int)* 2000);
	printf("\n");
	bfs(start);
	printf("\n");

	return 0;
}