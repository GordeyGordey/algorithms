/*Сорт шейкер является улучшением Bubble Sort.Улучшение в основном в том, что значения «пузырились» в обоих направлениях через массив, потому 
что на каждой итерации пузырек коктельной сортировки сортирует один раз вперед и один раз назад*/
#include <stdio.h>

void swap(int *x, int *y)
{
	if(x == y)
		return;
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void cocktailsort(int *a, size_t n)
{
	while(1)
	{
		char flag;
		size_t start[2] = {1, n - 1},
				end[2] = {n, 0},
				inc[2] = {1, -1};
		for(int it = 0; it < 2; ++it)
		{
			flag = 1;
			for(int i = start[it]; i != end[it]; i += inc[it])
				if(a[i - 1] > a[i])
				{
					swap(a + i - 1, a + i);
					flag = 0;
				}
			if(flag)
				return;
		}
	}
}

int main(void)
{
	int u;
	int i;
	
	printf("Enter size of array:\n");
	scanf("%d", &u);
	int a[u];
	printf("Enter the elements of the array\n");
	for(i = 0; i < u; i++)
		scanf("%d", &a[i]);
	size_t n = sizeof(a)/sizeof(a[0]);
	cocktailsort(a, n);
	for (size_t i = 0; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}
