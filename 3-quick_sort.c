#include "sort.h"

/**
 * quick_sort -Entry level
 * @array: input
 * @size: size
 */

void quick_sort(int *array, size_t size)
{
	srtQuick(array, 0, size - 1, size);
}

/**
 * srtQuick - Entry point
 * @a: input
 * @lw: first index
 * @higher: last index
 * @sz: length of the array
 * Return: 0 always
 */
void srtQuick(int *a, int lw, int higher, int sz)
{
	int qw;
	int i, y, b;

	if (lw < higher)
	{
		b = higher;
		y = lw;
		for (i = lw; i < higher; i++)
		{
			if (a[i] < a[b])
			{
				if (i != y)
				{
					qw = a[i];
					a[i] = a[y];
					a[y] = qw;
					print_array(a, sz);
				}
				y++;
			}
		}
		if (y != b && a[y] != a[b])
		{
			qw = a[y];
			a[y] = a[b];
			a[b] = qw;
			print_array(a, sz);
		}
		srtQuick(a, lw, y - 1, sz);
		srtQuick(a, y + 1, higher, sz);
	}
}
