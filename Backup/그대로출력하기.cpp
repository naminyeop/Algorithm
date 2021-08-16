#include <stdio.h>

char str[101];

int main(void)
{
	int i=0;

	while (scanf("%[^\n]\n", str) != EOF)
	{
		printf("%s\n", str);
	}
	
	return 0;
}