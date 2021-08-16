/* https://www.acmicpc.net/problem/2747 */
#include <stdio.h>

long long memo[90];

int fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else{
		if (memo[n] > 0) return memo[n];
		else
		{
			memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
			return memo[n];
		}
		
	}

}

int main(void)
{
	int num;
	
	scanf("%d", &num);
	printf("%lld", fibonacci(num));

	return 0;
}