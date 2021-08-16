/* https://www.acmicpc.net/problem/11726 */
#include "stdio.h"

int memo[10000];

int taling(int num)
{
	if (num <= 1)   return 1;
	else
	{
		if (memo[num] > 0) return memo[num];
		else
		{
			memo[num] = (taling(num - 1) + taling(num - 2)) % 10007;
			return memo[num];
		}

	}
}

int main(void)
{
	int num = 0;
	int result = 0;

	scanf("%d", &num);

	result = taling(num);

	printf("%d\n", result);

	return 0;
}