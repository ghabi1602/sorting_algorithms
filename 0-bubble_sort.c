#include "sort.h"

/**
 * bubble_sort - sorts the array with the bubble sort mecanism
 * @array: the array to sort
 * @size: size of the array
 * Return: none
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, a;
	int aux;

	if (!array || !size)
		return;
	a = 0;
	while (a < size)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
			}
		}
		a++;
	}
}
