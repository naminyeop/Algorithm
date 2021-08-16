#pragma warning(disable:4996)

#include <stdio.h>

#define STACK_MAX	100

int top = 0;
int arr[STACK_MAX];

void StackInit(void);
int StackPush(int val);
int StackPop(int *val);
int StackIsEmpty(void);
int StackIsFull(void);

void StackInit(void)
{
	top = 0;
}

int StackPush(int val)
{
	int err = 0;

	if (StackIsFull() == 0)
	{
		arr[top] = val;
		top++;
	}
	else
	{
		err = -1;
		printf("stack is overflow!! \n");
	}

	return err;
}

int StackPop(int *val)
{
	int err = 0;

	if (StackIsEmpty() == 0)
	{
		top--;
		*val = arr[top];
	}
	else
	{
		err = -1;
	}
	
	return err;
}

int StackIsEmpty(void)
{
	int ret = 0;

	if (top == 0)
	{
		ret = 1;
	}
	
	return ret;
}

int StackIsFull(void)
{
	int ret = 0;

	if (top == STACK_MAX)
	{
		ret = 1;
	}

	return ret;
}


int main(void)
{
	int T, N;

	printf("stack test");

	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d", &N);

		StackInit();
		
		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			if (StackPush(value) != 0)
			{
				printf("StackPush Error! \n");
			}
		}

		printf("#%d ", testcase);
	
		while (StackIsEmpty() != 1)
		{
			int value;

			if (StackPop(&value) == 0)
			{
				printf("%d ", value);
			}
		}	
		printf("\n");
	}

	return 0;
}