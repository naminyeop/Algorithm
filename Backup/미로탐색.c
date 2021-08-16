#include <stdio.h>

int main(void)
{
	char c = 0xff;

	if(c == (char)0xff)	printf("111\n");
	else				printf("222\n");

	return 0;
}