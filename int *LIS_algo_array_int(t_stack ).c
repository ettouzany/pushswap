int *LIS_algo_array_int(t_stack **stack)
{
	//find the largest increasing subsequence in numbers array of size size and return an array of that subsequence
	int *lenght;
	lenght = (int *)malloc(sizeof(int) * *size);
	int max_size = 0;
	int i;
	int j;
	i = 0;
	j = 0;

	while (i < *size)
	{
		lenght[i] = 1;
		i++;
	}
	while (i < *size)
	{
		j = 0;
		while (j < i)
		{
			if (stack[i] > numbers[j] && lenght[i] < lenght[j] + 1)
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
