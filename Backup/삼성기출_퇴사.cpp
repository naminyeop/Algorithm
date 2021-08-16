#include <stdio.h>
#include <string.h>

#define MAX_ARR	16

int N;
int arr[2][MAX_ARR];

void init(void)
{
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &arr[0][i], &arr[1][i]);
	}
}



int main(void)
{
	init();


	return 0;
}