#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @left: Pointer to the first node
 * @right: Pointer to the second node
 **/
void swap_nodes(listint_t **list, listint_t **left, listint_t **right)
{
	listint_t *temp_left = *left;
	listint_t *temp_right = *right;

	if (*left == NULL || *right == NULL)
		return;

	if (temp_left->prev == NULL)
	{
		temp_left->next = temp_right->next;
		if (temp_right->next != NULL)
			temp_right->next->prev = temp_left;
		temp_left->prev = temp_right;
		temp_right->next = temp_left;
		temp_right->prev = NULL;
		*list = temp_right;
	}
	else
	{
		temp_left->next = temp_right->next;
		if (temp_right->next != NULL)
			temp_right->next->prev = temp_left;
		temp_right->next = temp_left;
		temp_right->prev = temp_left->prev;
		temp_left->prev->next = temp_right;
		temp_left->prev = temp_right;
	}

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to the doubly linked list
 **/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
	}
}
