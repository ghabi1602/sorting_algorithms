#include "sort.h"

/**
 * radix_sort - sorts an array using the lsd Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 *
 * Return: None
 */

void radix_sort(int *array, size_t size)
{
	int max_int;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	max_int = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max_int)
			max_int = array[i];

	for (lsd = 1; max_int / lsd > 0; lsd *= 10)
	{
		count_sort_lsd(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * count_sort_lsd - count sort with LSD
 * @array: array of integers
 * @size: size of the array
 * @lsd: least significant digit
 *
 * Return: None
 */
void count_sort_lsd(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0}, *out_arr, i, m;
	size_t j, n;

	out_arr = malloc(sizeof(int) * size);

	for (j = 0; j < size; j++)
		count_arr[(array[j] / lsd) % 10]++;
	for (i = 1; i < 10; i++)
		count_arr[i] += count_arr[i - 1];

	for (m = size - 1; m >= 0; m--)
	{
		out_arr[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
		count_arr[(array[m] / lsd) % 10]--;
	}

	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	free(out_arr);
}
