#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * create_dnode - creates a new node
 * @n: data of the node
 * @prev: link to the previous node
 * @next: link to the next node
 * Return: pointer to the new node
 */
dlistint_t *create_dnode(int n, dlistint_t *prev, dlistint_t *next)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = prev;
	new->next = next;
	return (new);
}

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: head of the doubly-linked list
 * @idx: index for the insertion of the new node
 * @n: data for the new node
 * Return: address of the new node or NULL if an error occurs
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr = *h, *localPrev = NULL;
	unsigned int count = 0;

	if (!h)
		return (NULL);
	if (idx == 0) /* insert at the beginning of the list */
	{
		if (!*h)
			*h = create_dnode(n, NULL, NULL); /* first node */
		else
		{
			(*h)->prev = create_dnode(n, NULL, *h);
			*h = (*h)->prev;
		}
		return (*h);
	}
	for (curr = *h; curr && (count < idx); curr = curr->next, count++)
	{
		localPrev = curr;
	}
	if ((count == idx) && (curr == NULL)) /* insert at the end of the list */
	{
		localPrev->next = create_dnode(n, localPrev, NULL);
		return (localPrev->next);
	}
	if ((count < idx) && (curr == NULL)) /* idx too high */
		return (NULL);
	if (localPrev != NULL)
	{ /* insert in the middle of the list */
		localPrev->next = create_dnode(n, localPrev, curr);
		curr->prev = localPrev->next;
		return (localPrev->next);
	}
	return (NULL); /* should never run */
}
