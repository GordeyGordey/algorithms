/*Бисерная сортировка https://habr.com/ru/post/198962/*/
#include <stdio.h>
#include <stdlib.h>

#	define BEAD(i, j) beads[i * max + j]

/*Отображает массив*/
void display(int arr[], int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

/*Здесь происходит сортировка массива
a ---Массив для сортировки
len -Размер массива*/
void bead_sort(int *a, int len)
{
	int i, j, max, sum;
	unsigned char *beads;

	for (i = 1, max = a[0]; i < len; i++)
		if (a[i] > max)
			max = a[i];
	beads = calloc(1, max * len);
	for (i = 0; i < len; i++)
		for (j = 0; j < a[i]; j++)
			BEAD(i, j) = 1;
 
	for (j = 0; j < max; j++) {
		/* посчитайте сколько бус на каждом посте */
		for (sum = i = 0; i < len; i++)
		{
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		/* отметьте нижнюю сумму бус */
		for (i = len - sum; i < len; i++)
			BEAD(i, j) = 1;
	}
 
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
	}
	free(beads);
}

int main(int argc, const char * argv[])
{
	int n;
	printf("Enter size of array:\n");
	scanf("%d", &n); // E.g. 8 1 2 3

	printf("Enter the elements of the array\n");
	int i;
	int arr[n];
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Original array: ");
	display(arr, n);
	bead_sort(arr, n);
	printf("Sorted array: ");
	display(arr, n);
	return 0;
}
