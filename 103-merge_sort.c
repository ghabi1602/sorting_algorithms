#include "sort.h"

/**
 * length - returns the length of an array
 * @arr: the array to calculate the length
 * Return: size_t
 */

size_t length(int *arr)
{
	return (sizeof(arr) / sizeof(arr[0]));
}

/**
 * merge - function that merges 2 arrays into the original array
 * @left_array: the left array partition from array
 * @right_array: the right array partition from array
 * @array: the original array
 * Return: void
 */

void merge(int *left_array, int *right_array, int *array)
{
	size_t left_size = length(left_array), right_size = length(right_array);
	size_t i = 0, l = 0, r = 0;

	while (l < left_size && r < right_size)
	{
		if (left_array[l] < right_array[r])
		{
			array[i] = left_array[l];
			i++;
			l++;
		}
		else
		{
			array[i] = right_array[r];
			i++;
			r++;
		}
	}
	while (l < left_size)
	{
		array[i] = left_array[l];
		i++;
		l++;
	}
	while (r < right_size)
	{
		array[i] = right_array[r];
		i++;
		r++;
	}
}

/**
 * merge_sort - sorts an array using the merge sort mecanism
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int left_array[size / 2], right_array[size - (size / 2)];
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		if (i < size / 2)
			left_array[i] = array[i];
		else
		{
			right_array[j] = array[i];
			j++;
		}
	}
	merge_sort(left_array, size / 2);
	merge_sort(right_array, size - (size / 2));
	merge(left_array, right_array, array);
}
