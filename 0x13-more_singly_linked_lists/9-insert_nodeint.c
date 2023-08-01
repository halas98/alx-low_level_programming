#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Pointer to the head of the linked list
 * @idx: Index where the new node should be added (starting from 0)
 * @n: Value to be set in the new node
 *
 * Return: The address of the new node, or NULL if it failed
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *current;
    unsigned int i;

    if (head == NULL)
        return (NULL);

    /* Create the new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;

    /* If idx is 0, insert at the beginning */
    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* Find the previous node to the insertion point */
    current = *head;
    for (i = 0; i < idx - 1; i++)
    {
        if (current == NULL)
        {
            free(new_node);
            return (NULL); /* Index out of range */
        }
        current = current->next;
    }

    /* If current is NULL, it means idx is greater than the current size */
    if (current == NULL)
    {
        free(new_node);
        return (NULL); /* Index out of range */
    }

    /* Insert the new node */
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
