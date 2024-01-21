#include "sort.h"

/**
 * swap - swaps 2 elements of an array
 * @x: the first element
 * @y: the second element
 * Return: void
 */
void swap(int *x, int *y)
{
	int aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

/**
 * partition - sets the pivot in the proper place
 * @array: the array to be sorted
 * @low: lowest index in the array partition
 * @high: highest index in the array partition
 * @size: size of array
 * Return: index of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}

/**
 * lomuto_qsort - sorts an array recursively
 * @array: the array to be sorted
 * @low: the lowest index of array
 * @high: the highest index of array
 * @size: size of the array
 * Return: void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_qsort(array, low, i - 1, size);
		lomuto_qsort(array, i + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array with the quicksort mecanism
 * @array: the array to be sorted
 * @size: the size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
