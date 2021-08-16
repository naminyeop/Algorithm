#pragma warning(disable:4996)

#include <stdio.h>

#define ARR_MAX	30

int arr[ARR_MAX][ARR_MAX];

int visit[ARR_MAX];
int queue[ARR_MAX];
int front, rear;

int num, start;

void bfs(int start)
{
	visit[start] = 1;
	printf("%d ", start);

	queue[rear++] = start;

	while (front < rear)
	{
		start = queue[front++];
		for (int i = 1; i <= num; i++)
		{
			if (arr[start][i] == 1 && visit[i] == 0)
			{
				visit[i] = 1;
				printf("%d ", i);
				queue[rear++] = i;
			}
		}
	}
}

int main(void)
{
	int testcase;
	int T;
	int val1, val2;

	scanf("%d", &T);

	for (testcase = 1; testcase <= T; testcase++)
	{
		for (int i = 0; i < ARR_MAX; i++)
		{
			for (int j = 0; j < ARR_MAX; j++)
			{
				arr[i][j] = 0;
			}
			queue[i] = 0;
			visit[i] = 0;
		}
		front = rear = 0;

		scanf("%d %d", &num, &start);

		while (1)
		{
			scanf("%d %d", &val1, &val2);
			if (val1 == -1 && val2 == -1)
			{
				break;
			}
			arr[val1][val2] = arr[val2][val1] = 1;
		}

		printf("#%d# ", testcase);
		bfs(start);
	}

	return 0;
}