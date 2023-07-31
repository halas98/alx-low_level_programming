#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head of the listint_t list.
 *
 * Return: the number of nodes.
 */
size_t print_listint(const listint_t *h)
{
    size_t num = 0;

    while (h)
    {
        num++;
	printf("%d\n", h->n);
        h = h->next;
    }

    return (num);
}

