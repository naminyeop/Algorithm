#include <stdio.h>
#include <string.h>

char str[1000001];

int main(void)
{
	char *temp = NULL;
	int cnt = 0;
	int flag = 0;
	scanf("%[^\n]", &str);

	temp = strtok(str, " ");
	
	if (temp != NULL)
	{
		flag = 1;
	}
	
	while (strtok(NULL, " "))
	{
		cnt++;
	}

	if (flag == 1)
	{
		printf("%d\n", cnt + 1);
	}
	else
	{
		printf("0");
	}
	return 0;
}