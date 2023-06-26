#include <stdlib.h>
#include "deck.h"

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *node_array[52];
	deck_node_t *current = *deck;
	size_t i = 0;

	while (current != NULL)
	{
		node_array[i] = current;
		current = current->next;
		i++;
	}

	qsort(node_array, 52, sizeof(deck_node_t *), card_compare);

	*deck = node_array[0];
	current = *deck;
	current->prev = NULL;

	for (i = 1; i < 52; i++)
	{
		current->next = node_array[i];
		node_array[i]->prev = current;
		current = current->next;
	}

	current->next = NULL;
}
