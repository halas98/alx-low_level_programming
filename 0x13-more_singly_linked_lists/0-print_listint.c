#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Print elements of a singly linked list.
 * @h: Pointer to a list.
 * Return: Integer.
 **/

size_t print_listint(const listint_t *h)
{
	const listint_t *current = h;
	size_t cntr = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		cntr++;
	}

	return (cntr);
}
