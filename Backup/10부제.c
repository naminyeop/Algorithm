/* https://www.acmicpc.net/problem/10797 */
#include <stdio.h>


int main(void)
{
	int num,i, input,cnt=0;

	scanf("%d", &num);

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &input);
		if (input == num)	cnt++;
	}
	printf("%d", cnt);

	return 0;
}
