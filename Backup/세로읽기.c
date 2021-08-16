/* https://www.acmicpc.net/problem/10798 */
#include <stdio.h>
#include <string.h>

char arr[5][16];

int main(void)
{
	int i,j;
	
	memset(arr,'@',sizeof(char)*5*16);

	for (i = 0; i < 5; i++)
	{
		scanf("%s", &arr[i]);
	}
	
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (arr[j][i] != '@' && arr[j][i] != '\0')
			{
				printf("%c", arr[j][i]);
			}
		}
		
	}

	return 0;
}
