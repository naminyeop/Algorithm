#include <stdio.h>

long long d[91];

long long prog(long long num)
{
	if (num == 1)
	{
		return 1;
	}
	else if (num == 2)
	{
		return 1;
	}
	else
	{
		if (d[num] > 0)
		{
			return d[num];
		}
		else
		{
			d[num] = prog(num - 1) + prog(num - 2);
			return d[num];
		
		}
	}
}

int main(void)
{
	int num;

	scanf("%d", &num);

	printf("%lld", prog(num));

	return 0;
}