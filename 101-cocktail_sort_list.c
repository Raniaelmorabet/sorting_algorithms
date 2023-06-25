#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    if (node2->prev == NULL)
        *list = node2;

    print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;
    
    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (current = current->prev; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
            }
        }
    } while (swapped);
}
