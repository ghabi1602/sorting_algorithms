#include "sort.h"

/**
 * bubble_sort - sorts the array with the bubble sort mecanism
 * @array: the array to sort
 * @size: size of the array
 * Return: none
 */
void bubble_sort(int *array, size_t size)
{
	bool swap = true;
	size_t i, n = size;
	int aux;

	while (swap)
	{
		swap = false;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
				swap = true;
			}
		}
		n -= 1;
	}
	print_array(array, size);
}
