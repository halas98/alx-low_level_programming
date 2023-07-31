#include <stdio.h>
#include "lists.h"

/**
 * print_listint - singly linked list node structure
 * @h: integer
 * return: the number of the nodes
 */

size_t print_listint(const listint_t *h)
{
	const listint_t *current = h;
	size_t count = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		count++;
	}

	return (count);
}

