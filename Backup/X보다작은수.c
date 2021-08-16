#include <stdio.h>

int main(void)
{
	int n,x;
	int i, num;

	scanf("%d %d", &n, &x);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if(num < x)	printf("%d ", num);
	}


	return 0;
}