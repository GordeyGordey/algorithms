/*Фановый алгоритм Bogosort просто перемешивает коллекцию случайным образом, пока она не отсортирована*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_sorted(int *a, int n)
{
	while (--n >= 1)
		if (a[n] < a[n-1])
			return (0);
	return (1);
}

void shuffle(int *a, int n)
{
	int i, t, r;
	for(i=0; i < n; i++)
	{
		t = a[i];
		r = rand() % n;
		a[i] = a[r];
		a[r] = t;
	}
}

void bogosort(int *a, int n)
{
	while (!is_sorted(a, n))
		shuffle(a, n);
}

int main()
{
	int n;
	printf("Enter size of array:\n");
	scanf("%d", &n);
	printf("Enter the elements of the array\n");
	int i;
	int arr[n];
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	bogosort(arr, n);
	for (i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
