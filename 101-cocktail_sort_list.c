#include "sort.h"

/**
 * ls_Wap - Entry point
 * @pt_one: pointer
 * @pt_tow: pointer
 * @n: zero or one
 * Return: 0 always
 */
void ls_Wap(listint_t **pt_one, listint_t **pt_tow, int n)
{
	listint_t *my_ax, *my_tp;

	my_ax = *pt_one;
	my_tp = *pt_tow;

	my_ax->next = my_tp->next;
	my_tp->prev = my_ax->prev;

	if (my_tp->next)
		my_tp->next->prev = my_ax;

	if (my_ax->prev)
		my_ax->prev->next = my_tp;

	my_ax->prev = my_tp;
	my_tp->next = my_ax;

	if (n == 0)
		*pt_one = my_tp;
	else
		*pt_tow = my_ax;
}

/**
 * cocktail_sort_list - Entry
 * @list: linked list
 * Return: 0 always
 */
void cocktail_sort_list(listint_t **list)
{
        listint_t *lmt1, *pt, *lmt2;

        if (list == NULL)
                return;

        if (*list == NULL)
                return;

        lmt1 = lmt2 = NULL;
        pt = *list;

        do {
                srInc_rease(&pt, &lmt1, list);
                srDec_rease(&pt, &lmt2, list);
        } while (lmt1 != lmt2);
}

/**
 * srInc_rease - Entry point
 * @pt: pointer
 * @lmt: limit
 * @ls: int list
 * Return: void
 */
void srInc_rease(listint_t **pt, listint_t **lmt, listint_t **ls)
{
	listint_t *my_ax;

	my_ax = *pt;

	while (my_ax != *lmt && my_ax->next != *lmt)
	{
		if (my_ax->n > my_ax->next->n)
		{
			ls_Wap(&my_ax, &(my_ax->next), 0);
			if (my_ax->prev == NULL)
				*ls = my_ax;
			print_list(*ls);
		}
		my_ax = my_ax->next;
	}

	*lmt = my_ax;
	*pt = my_ax;
}

/**
 * srDec_rease - Entry
 * @pt: pointer
 * @lmt: limit
 * @ls: int list
 * Return: void
 */
void srDec_rease(listint_t **pt, listint_t **lmt, listint_t **ls)
{
	listint_t *my_ax;

	my_ax = *pt;

	while (my_ax != *lmt && my_ax->prev != *lmt)
	{
		if (my_ax->n < my_ax->prev->n)
		{
			ls_Wap(&(my_ax->prev), &my_ax, 1);
			if (my_ax->prev->prev == NULL)
				*ls = my_ax->prev;
			print_list(*ls);
		}
		my_ax = my_ax->prev;
	}

	*lmt = my_ax;
	*pt = my_ax;
}
