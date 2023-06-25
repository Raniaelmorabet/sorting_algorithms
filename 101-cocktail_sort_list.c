#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current;

    if (list == NULL || *list == NULL)
        return;

    while (swapped) {
        swapped = 0;

        /* Forward pass */
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n) {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        /* Backward pass */
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n) {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
            }
        }
    }
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *prev, *next;

    prev = node1->prev;
    next = node2->next;

    if (prev != NULL)
        prev->next = node2;
    else
        *list = node2;

    if (next != NULL)
        next->prev = node1;

    node1->prev = node2;
    node2->next = node1;
    node1->next = next;
    node2->prev = prev;
}
