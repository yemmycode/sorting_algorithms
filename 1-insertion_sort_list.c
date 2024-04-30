#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order.
 * @list: Pointer to a pointer to the head of the list.
 *
 * Description: Swaps nodes to sort the list and prints it after each swap.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        prev = current->prev;
        next = current->next;

        while (prev != NULL && prev->n > current->n)
        {
            /* Swap nodes */
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;
            current->prev = prev->prev;
            prev->prev = current;
            prev->next = next;
            if (next != NULL)
                next->prev = prev;

            /* Print the list after swap */
            print_list(*list);

            prev = current->prev;
        }

        current = next;
    }
}
