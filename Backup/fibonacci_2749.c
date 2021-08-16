/* https://www.acmicpc.net/problem/2749 */
#include <stdio.h>

long long memo[1000000];

long long fibonacci(long long n)
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
			memo[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1000000;
			return memo[n];
		}

	}

}

int main(void)
{
	long long num;

	scanf("%lld", &num);
	printf("%lld", fibonacci(num));

	return 0;
}