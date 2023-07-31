#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Pointer to a pointer that points to the head of the list.
 *
 * Return: Data (n) stored in the head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    int data = 0;
    listint_t *temp;

    if (head == NULL || *head == NULL)
        return 0;

    temp = *head;
    data = temp->n;
    *head = (*head)->next;
    free(temp);

    return data;
}

