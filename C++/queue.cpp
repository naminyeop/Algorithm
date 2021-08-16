#pragma warning(disable:4996)

#include <stdio.h>

#define ARR_MAX	100

int front, rear;
int arr[ARR_MAX];

void QueueInit(void)
{
	front = rear = 0;
}

int QueueFull(void)
{
	int ret = 0;

	if ((rear + 1) % ARR_MAX == front)
	{
		ret = 1;
	}
	
	return ret;
}

int QueueEmpty(void)
{
	int ret = 0;

	if (front == rear)
	{
		ret = 1;
	}
	
	return ret;
}


int QueueEnqueue(int val)
{
	int err = 0;

	if (QueueFull() != 1)
	{
		arr[rear] = val;
		rear++;
		if (rear == ARR_MAX)
		{
			rear = 0;
		}
	}
	else
	{
		err = -1;
	}
	
	return err;
}

int QueueDequeue(int *val)
{
	int err = 0;

	if (QueueEmpty() != 1)
	{
		*val = arr[front];
		front++;
		if (front == ARR_MAX)
		{
			front = 0;
		}
	}
	else
	{
		err = -1;
	}

	return err;
}

int main(void)
{
	int T;
	int N;

	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d", &N);

		QueueInit();

		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			if(QueueEnqueue(value) != 0)
			{
				printf("Enqueue Error! \n");
			}
		}
	
		printf("#%d# ", testcase);

		while (!QueueEmpty())
		{
			int value;
			if (QueueDequeue(&value) == 0)
			{
				printf("%d ", value);
			}
			else
			{
				printf("Dequeue Error! \n");
			}
		}
		printf("\n");
	}
	
	return 0;
}