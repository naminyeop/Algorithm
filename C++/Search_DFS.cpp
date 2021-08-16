#pragma warning(disable:4996)

#include <stdio.h>

#define ARR_MAX	30
int arr[ARR_MAX][ARR_MAX];
int visit[ARR_MAX];

int N;
int start;

void init(void)
{
	for (int i = 0; i < ARR_MAX; i++)
	{
		for (int j = 0; j < ARR_MAX; j++)
		{
			arr[i][j] = 0;
		}
		visit[i] = 0;
	}
}

void input(void)
{
	int val1, val2;

	scanf("%d %d",&N, &start);

	while (1)
	{
		scanf("%d %d", &val1, &val2);
		if (val1 == -1 && val2 == -1)
		{
			break;
		}
		else
		{
			arr[val1][val2] = arr[val2][val1] = 1;
		}
	}
}

void DepthFisrtSearch(int start)
{
	int i;

	visit[start] = 1;

	for (i = 1; i <= N; i++)
	{
		if (visit[i] == 0 && arr[start][i] == 1)
		{
			printf("%d ", i);
			DepthFisrtSearch(i);
		}
	}
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++)
	{
		init();

		input();
		
		printf("#%d# ", testcase);
		printf("%d ", start);

		DepthFisrtSearch(start);	
		
		printf("\n");
	}

	return 0;
}