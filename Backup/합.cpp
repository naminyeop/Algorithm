#include <stdio.h>

int prog(int num)
{
	int i, ret = 0;

	for (i = 1; i <= num; i++)
	{
		ret += i;
	}

	return ret;
}

int main(void)
{
	int num;

	scanf("%d", &num);

	printf("%d", prog(num));


	return 0;
}