#include <stdio.h>

double *combsort(double a[], int nElements)
{
	int i, j, gap, swapped = 1;
	double temp;

	gap = nElements;
	while (gap > 1 || swapped == 1)
	{
		gap = gap * 10 / 13;
		if (gap == 9 || gap == 10) gap = 11;
		if (gap < 1) gap = 1;
		swapped = 0;
		for (i = 0, j = gap; j < nElements; i++, j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				swapped = 1;
			}
		}
	}
	return (a);
}

int main(void)
{
	int u;
	int i;
	
	printf("Enter size of array:\n");
	scanf("%d", &u);
	double a[u];
	printf("Enter the elements of the array\n");
	for(i = 0; i < u; i++)
		scanf("%Lf", &a[i]);
	combsort(a, u);
	for (i = 0; i < u; ++i)
		printf("%Lf ", a[i]);
	return 0;
}
