#include <stdio.h>
#include<assert.h>

int main()
{

	int array[10], c, d, swap;

	printf("Enter 10 integers\n");

	for (c = 0; c < 10; c++)
		scanf("%d", &array[c]);

	sortAsc(array);
	sortDsc(array);

	return 0;
}

int sortAsc(int array[])
{
	int c, d, swap;

	for (c = 0 ; c < 9; c++)
	{
		for (d = 0 ; d < 9 - c; d++)
		{
			if (array[d] > array[d+1])
			{
				swap       = array[d];
				array[d]   = array[d+1];
				array[d+1] = swap;
			}
		}
	}

	printf("Sorted list in ascending order:\n");

	for ( c = 0 ; c < 10 ; c++ )
		printf("%d\n", array[c]);

	return 0;
}

int sortDsc(int array[], int n)
{
	int c, d, swap;

	for (c = 0 ; c < 9; c++)
	{
		for (d = 0 ; d < 9 - c ; d++)
		{
			if (array[d] > array[d+1])
			{
				swap       = array[d];
				array[d]   = array[d+1];
				array[d+1] = swap;
			}
		}
	}

	printf("Sorted list in descending order:\n");

	for ( c = 9 ; c >= 0; c-- )
		printf("%d\n", array[c]);

	return 0;
}


