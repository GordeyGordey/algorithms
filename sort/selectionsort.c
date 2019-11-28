#include <stdio.h>

//функция сортировки прямым выбором
void	selectionsort(int *num, int size)
{
	int min;
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i; //запоминаем индекс текущего элемента 
		//ищем минимальный элемент чтобы поместить на место i-ого
		for (int j = i + 1; j < size; i++)// для остальных элементов после i-ого
		{
	  		if (num[j] < num[min])
				min = j;
		}
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;
	}
}

int	main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	selectionsort(a, 10);
	for (int i = 0; i < 10; i++)
		printf("%d", a[i]);
	getchar(); getchar();
	return (0);
}
