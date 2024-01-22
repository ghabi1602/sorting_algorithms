#include "sort.h"

/**
 * counting_sort - sorts an array using the Counting sort algorithm
 * @array: pointer to unsorted array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *out_arr, max_int, num, j, l;
	size_t i, k, m, n;

	if (size < 2)
		return;

	max_int = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max_int)
			max_int = array[i];

	count_arr = malloc(sizeof(size_t) * (max_int + 1));
	out_arr = malloc(sizeof(int) * size);

	for (j = 0; j <= max_int; j++)
		count_arr[j] = 0;
	for (k = 0; k < size; k++)
	{
		num = array[k];
		count_arr[num] += 1;
	}
	for (l = 1; l <= max_int; l++)
		count_arr[l] += count_arr[l - 1];
	print_array(count_arr, max_int + 1);
	for (m = 0; m < size; m++)
	{
		out_arr[count_arr[array[m]] - 1] = array[m];
		count_arr[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	free(count_arr);
	free(out_arr);
}
