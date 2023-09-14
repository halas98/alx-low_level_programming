#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes node at given index
 * @head: double pointer to list's head
 * @index: index of node to delete (starts at 0)
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur, *temp;
	unsigned int i = 0;

	if (!*head)
		return (-1);

	cur = *head;

	if (index == 0)
	{
		*head = cur->next;
		if (cur->next)
			cur->next->prev = NULL;
		free(cur);
		return (1);
	}

	while (i < index - 1)
	{
		if (!cur->next)
			return (-1);
		cur = cur->next;
		i++;
	}

	if (!cur->next)
		return (-1);

	temp = cur->next;
	cur->next = temp->next;
	if (temp->next)
		temp->next->prev = cur;
	free(temp);

	return (1);
}
