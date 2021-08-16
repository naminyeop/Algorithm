/* https://www.acmicpc.net/problem/1003 */
#include <stdio.h>

int cnt_0;
int cnt_1; 

int fibonacci(int n)
{
	if (n == 0)
	{
		cnt_0++;
		return 0;
	}
	else if (n == 1)
	{
		cnt_1++;
		return 1;
	}
	else{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

}

int main(void)
{
	int num,T;
	int i;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &num);
		cnt_0 = cnt_1 = 0; 
		fibonacci(num);

		printf("%d %d\n", cnt_0, cnt_1);
	}
	

	return 0; 
}