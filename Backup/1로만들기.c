#include <stdio.h>

int d[1000001]; 

int program(long long n)
{
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];

	d[n] = program(n-1) + 1;

	if (n % 2 == 0)
	{
		int temp;
		temp = program(n / 2) + 1;
		if (temp < d[n]) d[n] = temp;
	}

	if (n % 3 == 0)
	{
		int temp;
		temp = program(n / 3) + 1;
		if (temp < d[n]) d[n] = temp;
	}
	
	return d[n];
}

int main(void)
{
	long long num;

	scanf("%lld", &num);

	printf("%d\n", program(num));

	return 0;
}
