#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int N;
	printf("Input N: ");
	scanf("%d", &N);
	int *mass;

	mass = (int *)malloc(N * sizeof(int));
	printf("Input the array elements:\n");
	int i;
	i = 0;
	while (i < N)
	{
		scanf("%d", &mass[i]);
		i++;
	}
	// сортировка пузырьком
	int tmp;
	_Bool noSwap;
	for (int i = N - 1; i >= 0; i--)
	{
		noSwap = 1;
		for (int j = 0; j < i; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
				noSwap = 0;
			}
		}
		if (noSwap == 1)
			break;
	}
	printf("Sorted array:\n");
	for (int i = 0; i < N; i++)
		printf("%d", mass[i]);
	printf("\n");
	free(mass);
	return (0);
}
