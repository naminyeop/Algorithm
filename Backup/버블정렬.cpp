#include <stdio.h>

void bubble(int arr[], int size)
{
	int i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void print(int arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr[10] = { 5, 7, 1, 9, 8, 3, 2, 4, 6, 0 };
	int size;

	size = sizeof(arr) / sizeof(int);
	
	print(arr, size);

	bubble(arr, size);

	print(arr, size);


	return 0;
}