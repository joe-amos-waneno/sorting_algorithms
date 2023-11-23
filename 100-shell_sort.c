#include "sort.h"
/**
 * shell_sort - Entry point
 * @array: input
 * @size: size of array
 * Return: 0 always
 */

void shell_sort(int *array, size_t size)
{
	size_t q = 1;

	while (q < size)
		q = (q * 3) + 1;

	while ((q = (q - 1) / 3) > 0)
		sortShell(array, size, q);
}

/**
 * sortShell - Next point
 * @a: input
 * @sz: lenght
 * @m: interval
 * Return: 0 always
 */

void sortShell(int *a, int sz, int m)
{
	int i, qw, j;

	for (i = 0; (i + m) < sz; i++)
	{
		for (j = i + m; (j - m) >= 0; j = j - m)
		{
			if (a[j] < a[j - m])
			{
				qw = a[j];
				a[j] = a[j - m];
				a[j - m] = qw;
			}
		}
	}
	print_array(a, sz);
}
