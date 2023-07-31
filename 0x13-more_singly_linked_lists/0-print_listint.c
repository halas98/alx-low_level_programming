#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Print elements of a singly linked list.
 * @h: Pointer to a list.
 * Return: Integer.
 **/

size_t print_listint(const listint_t *h)
{
	const listint_t *tp;
	unsigned int cntr = 0;

	tp = h;
	while (tp != NULL)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
		cntr++;
	}

	return (cntr);
}

