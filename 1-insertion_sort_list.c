#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		next = current->next;
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = current;
			prev->prev = current;
			prev = current->prev;
			if (!current->prev)
				*list = current;
			print_list(*list);
		}
		current = next;
	}
}
