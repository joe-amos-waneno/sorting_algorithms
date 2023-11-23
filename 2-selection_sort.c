#include "sort.h"

/**
 * selection_sort - entry point
 * @array: array of int
 * @size: size of the array
 * Return: 0 always
 */
void selection_sort(int *array, size_t size)
{
	int qw;
	size_t q, k, g;

	for (q = 0; q < size; q++)
	{
		g = q;
		for (k = q + 1; k < size; k++)
		{
			if (array[g] > array[k])
				g = k;
		}

		if (q != g)
		{
			qw = array[q];
			array[q] = array[g];
			array[g] = qw;
			print_array(array, size);
		}
	}
}
