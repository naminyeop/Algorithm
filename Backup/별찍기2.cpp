#include <stdio.h>

int main(void)
{
	int num, i, j, k;

	scanf("%d", &num);

	for (i = num; i >0; i--)
	{
		/* ���� */
		for (j = i - 1; j>0; j--)
		{
			printf(" ");
		}
		/* �� */
		for (k = 0; k < num - i + 1; k++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}