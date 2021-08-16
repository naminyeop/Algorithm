#include <stdio.h>

int n, k;
int check[100001]; /* 0 <= n,k <= 100,000 */
int front, rear;
int queue[100001]; /* 0 <= n,k <= 100,000 */

int bfs(void)
{
	queue[rear++] = n;
	check[n] = 1;

	while (front < rear)
	{
		int temp = queue[front++];

		if (temp == k)
		{
			return check[temp] - 1;
		}

		if (temp - 1 >= 0 && check[temp - 1] == 0)
		{
			check[temp - 1] = check[temp] + 1;
			queue[rear++] =  temp - 1;
		}
		
		if (temp + 1 <= 100000 && check[temp + 1] == 0)
		{
			check[temp + 1] = check[temp] + 1;
			queue[rear++] = temp + 1;
		}
	
		if (temp * 2 <= 100000 && check[temp * 2] == 0)
		{
			check[temp*2] = check[temp];
			queue[rear++] = temp*2;
		}
	}
}

int main(void)
{
	int result;

	scanf("%d %d", &n, &k); /* n : ¼öºó, k : µ¿»ý */

	printf("%d", bfs());

	return 0;
}