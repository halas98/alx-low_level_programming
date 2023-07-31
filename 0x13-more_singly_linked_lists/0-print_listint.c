#include <stdio.h>
#include "lists.h"

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */

size_t print_listint(const listint_t *h)
{
    const listint_t *current = h;
    size_t count = 0;

    while (current != NULL)
    {
        printf("%d ", current->n);
        current = current->next;
        count++;
    }

    printf("\n");
    return count;
}


