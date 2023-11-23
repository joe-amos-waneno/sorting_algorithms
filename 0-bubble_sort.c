#include "sort.h"

/**
 * bubble_sort - Entry point
 * @array: inpup
 * @size: size of the array
 * Return: 0 always
 */
void bubble_sort(int *array, size_t size)
{
	int sp, tp;
	size_t j, q;

	for (q = size, sp = 1; q > 0 && sp; q--)
	{
		sp = 0;
		for (j = 0; (j + 1) < q; j++)
		{
			if (array[j] > array[j + 1])
			{
				tp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tp;
				print_array(array, size);
				sp = 1;
			}
		}
	}
}
