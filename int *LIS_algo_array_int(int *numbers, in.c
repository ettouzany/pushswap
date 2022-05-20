int *LIS_algo_array_int(int *numbers, int *size)
{
	//find the largest increasing subsequence in numbers array of size size and return an array of that subsequence
	int *subsequence;
	int *lenght;
	subsequence = (int *)malloc(sizeof(int) * *size);
	lenght = (int *)malloc(sizeof(int) * *size);
	int max_size = 0;
	int i;
	int j;
	i = 0;
	j = 0;

	while (i < *size)
	{
		length[i] = 1;
		i++;
	}

	i = 0;
	while (i < *size)
	{
		j = 0;
		while (j < i)
		{
			if (numbers[i] > numbers[j] && lenght[i] < lenght[j] + 1)
			{
				lenght[i] = lenght[j] + 1;
				subsequence[i] = j;
			}
			j++;
		}
		if (lenght[i] > max_size)
			max_size = lenght[i];
		i++;
	}
	i = 0;
	while (i < *size)
	{
		if (lenght[i] == max_size)
			break ;
		i++;
	}
	int *result;
	result = (int *)malloc(sizeof(int) * max_size);
	int k = 0;
	while (k < max_size)
	{
		result[k] = numbers[i];
		i = subsequence[i];
		k++;
	}
	free(subsequence);
	free(lenght);
	*size = max_size;
	return (result);
}
