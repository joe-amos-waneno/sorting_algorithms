#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list -func that sort a dll
 * @list: db linked ls
 * Return: void
 * amine mohamed & salma abzou
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pt, *qw;

	if (!list)
		return;

	pt = *list;

	while (pt)
	{
		while (pt->next && (pt->n > pt->next->n))
		{
			qw = pt->next;
			pt->next = qw->next;
			qw->prev = pt->prev;

			if (pt->prev)
				pt->prev->next = qw;

			if (qw->next)
				qw->next->prev = pt;

			pt->prev = qw;
			qw->next = pt;

			if (qw->prev)
				pt = qw->prev;
			else
				*list = qw;

			print_list(*list);
		}
		pt = pt->next;
	}
}
