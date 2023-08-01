#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - The node at index of a listint_t linked list
 * @head: Pointer to the head of the linked list
 * @index: Index of the node to be deleted (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1); /* Empty list */

	current = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	for (i = 0; i < index - 1; i++)
	{
		if (current->next == NULL)
			return (-1); /* Index out of range */
		current = current->next;
	}

	if (current->next == NULL)
		return (-1); /* Index out of range */

	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}

