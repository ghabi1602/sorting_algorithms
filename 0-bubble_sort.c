#include "sort.h"

/**
 * bubble_sort - sorts the array with the bubble sort mecanism
 * @array: the array to sort
 * @size: size of the array
 * Return: none
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	int aux, swap = 1;

	while (swap)
	{
		swap = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
				swap = 1;
			}
		}
		n -= 1;
	}
	print_array(array, size);
}
