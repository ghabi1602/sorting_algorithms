#include "sort.h"

/**
* shell_sort - sorts an array of integers using
* the shell sort algorithm with Knuth sequence
* @array: the array of integers
* @size: size of the array
*
* Return: none
*/

void shell_sort(int *array, size_t size)
{
	size_t intv = 0, j, i;
	int tmp;

	if (size < 2)
		return;

	while ((intv = intv * 3 + 1) < size)
		;

	intv = (intv - 1) / 3;

	for (; intv > 0; intv = (intv - 1) / 3)
	{
		for (i = intv; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= intv && tmp <= array[j - intv]; j -= intv)
				array[j] = array[j - intv];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
