#include <stdio.h>

int arr[10];
int check[10];

int main(void)
{
	unsigned long long num1;
	unsigned long long num2;
	unsigned long long num3;
	unsigned long long result;

	int i, zero_cnt=0,index = 0; 

	scanf("%lld %lld %lld", &num1, &num2, &num3);

	result = num1 * num2 * num3;

	for (i = 0; i < 10; i++)
	{
		arr[i] = result % 10;
		result = result / 10;
		//printf("%d / result : %d\n", arr[i], result);
		if (result == 0)
		{
			index = i;
			break;
		}
		
	}
	
	for (i = 0; i <= index; i++)
	{
		check[arr[i]]++;
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", check[i]);
	}

	




	return 0;
}