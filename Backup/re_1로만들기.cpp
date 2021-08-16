#include <stdio.h>

int d[1000001];

int prog(long long num)
{
	if (num == 1)	return 0;
	if (d[num] > 0)	return d[num];

	d[num] = prog(num - 1) + 1;

	if (num % 2 == 0)
	{
		int temp = prog(num / 2) + 1;
		if (d[num] > temp) d[num] = temp;
	}

	if (num % 3 == 0)
	{
		int temp = prog(num / 3) + 1;
		if (d[num] > temp) d[num] = temp;
	}
	return d[num];
}

int main(void)
{
	long long num;

	scanf("%lld", &num);

	printf("%d",prog(num));

	return 0;
}