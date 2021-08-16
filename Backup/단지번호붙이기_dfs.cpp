#include <stdio.h>
#include <algorithm>

#define MAX_ARR	(26)

int n;
int arr[MAX_ARR][MAX_ARR];
int check[MAX_ARR][MAX_ARR];
int djcnt;
int output[MAX_ARR * MAX_ARR];


void init(void)
{
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
}

void print(void)
{
	int i, j;

	printf("========================\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void output_print(void)
{
	int j;

	printf("========================\n");
	
	for (j = 0; j <= djcnt; j++)
	{
		printf("%d ", output[j]);
	}
	printf("========================\n");

}

void dfs(int i, int j)
{
	check[i][j] = djcnt;
	arr[i][j] = 0;
	output[djcnt]++;

	/* µ¿ */
	if (j + 1 < n && arr[i][j + 1] == 1)
	{
		dfs(i, j + 1);
	}
	/* ¼­ */
	if (j - 1 >= 0 && arr[i][j - 1] == 1)
	{
		dfs(i, j - 1);
	}
	/* ³² */
	if (i + 1 < n && arr[i + 1][j] == 1)
	{
		dfs(i + 1, j);
	}

	/* ºÏ */
	if (i - 1 >= 0 && arr[i - 1][j] == 1)
	{
		dfs(i - 1, j);
	}

}

void prog(void)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && check[i][j] == 0)
			{
				djcnt++;
				dfs(i, j);
			}
		}
	}
}

void result(void)
{
	int i;

	printf("%d\n", djcnt);
	for (i = 1; i <= djcnt; i++)
	{
		printf("%d\n", output[i]);
	}
}

void sort(void)
{
	int i, j;
	int temp;

	for (i = 0; i <= djcnt; i++)
	{
		for (j = i+1; j <= djcnt; j++)
		{
			if (output[i] > output[j])
			{
				temp = output[i];
				output[i] = output[j];
				output[j] = temp;
			}
		}
	}
}

int main(void)
{
	init();

	prog();

	//std::sort(output + 1, output + 1 + djcnt);
	//output_print();
	sort(); 
	//output_print();

	result();
	
	return 0;
}