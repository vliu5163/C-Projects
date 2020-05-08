#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void bubbleSort(int size, int arr[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void bubbleSortDown(int size, int arr[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void printArray(int size, int arr[])
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int main(int argc, char **argv)
{
	int num = 0;
	scanf("%d", &num);
	int *a1 = (int*) malloc(num * sizeof(int));
	int *a2 = (int*) malloc(num * sizeof(int));
	int *a3 = (int*) malloc(num * sizeof(int));

    if (a1 == NULL || a2 == NULL || a3 == NULL)
    {
       perror("malloc returned NULL");
       exit(1);
    }

	srand(time(NULL));   // should only be called once

    for (int i = 0; i < num; i++)
    {
		a1[i] = rand();
    }

    for (int i = 0; i < num; i++)
    {
		a2[i] = a1[i];
    }

    for (int i = 0; i < num; i++)
    {
		a3[i] = a1[i];
    }

    for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < (num - i - 1); j++)
		{
			if (a2[j] > a2[j + 1])
			{
				int temp = a2[j];
				a2[j] = a2[j + 1];
				a2[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < (num - i - 1); j++)
		{
			if (a3[j] < a3[j + 1])
			{
				int temp = a3[j];
				a3[j] = a3[j + 1];
				a3[j + 1] = temp;
			}
		}
	}

    printf("Original array\n");
    printArray(num, a1);
    printf("Low to high array\n");
    printArray(num, a2);
    printf("High to low array\n");
    printArray(num, a3);
    free(a1);
	free(a2);
	free(a3);
}

