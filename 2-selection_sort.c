#include "sort.h"


/**
 * selection_sort - sorts an array of list using
 * the selection sort algorithm
 * @array: pointer to unsorted array
 * @size: size of the array
 *
 * Return: None
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (array[i] > array[j])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
}
