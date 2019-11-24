#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 100000
#define RANGE 100000

void	MerageSort(int *sarr, int start, int end)
{
	if (start < end)
	{
		MerageSort(sarr, stert, (start + end) / 2);
		MerageSort(sarr, (strat + end) / 2 + 1, end);
		Merage(sarr, start, end);
	}
}

void	Merage(int *sarr, int first, int last)
{
	int left_iterator, right_iterator, middle;
	int *mas;
	mas = (int*)malloc((last - first)*sizeof(int));
	middle = (first + last) / 2;
	left_iterator = first;
	right_iterator = middle + 1;

	for (int j = first; j <= last; j++)
	{
		if ((left_iterator <= middle) && ((right_iterator > last) || (sarr[left_iterator] < sarr[right_iterator])))
		{
			*(mas + j - first) = sarr[left_iterator];
			left_iterator++;
		}
		else
		{
			*(mas + j - first) = sarr[right_iterator];
			right_iterator++;
		}
	}
	for (int j = first; j <= last; j++) sarr[j] = *(mas + j - first);
}
