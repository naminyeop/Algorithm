#include <stdio.h>
#include <string.h>

char str[100];

int main(void)
{
	int num,i,sum=0;
	

	scanf("%d", &num);

	scanf("%s", str);
	//printf("%s", str);

	for (i = 0; i < strlen(str); i++)
	{
		//printf("str[%d] : %d\n",i, str[i]-'0');
		sum += str[i]-'0';
	}
	printf("%d", sum);

	return 0;
}