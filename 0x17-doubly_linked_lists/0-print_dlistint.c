#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Prints all elements of a doubly linked list of integers.
 * @h: Pointer to the head of the doubly linked list.
 * Return: The number of nodes in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *ptr = h;
	size_t n = 0;

	while (ptr && ptr->prev)
		ptr = ptr->prev;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		n++;
		ptr = ptr->next;
	}
	return (n);
}
