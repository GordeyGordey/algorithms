void	insertionsort(int *arr, int N)
{
	for (int i = 1; i < N; i++)
	{
		int k = i;
		while (k > 0 && arr[k -1] > arr[k])
		{
			int tmp = arr[k];
			arr[k] = arr[k - 1];
			arr[k -1] = tmp;
			k -= 1;
		}
	}
}
