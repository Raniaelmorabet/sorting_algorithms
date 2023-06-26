#include<stdlib.h>
#include<string.h>
#include"deck.h"

/**
 * compare_cards - Compare two card pointers for sorting.
 * @card1: Pointer to the first card.
 * @card2: Pointer to the second card.
 * Return: Negative value if card1 should come before card2
 */
int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;

	int value_cmp = strcmp(c1->value, c2->value);

	if (value_cmp != 0)
		return (value_cmp);

	return (c1->kind - c2->kind);
}

/**
 * sort_deck - Sort a deck of cards in-place.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	size_t i, count = 0;
	deck_node_t *node = *deck;
	card_t *cards[52];

	while (node != NULL)
	{
		cards[count++] = (card_t *)node->card;
		node = node->next;
	}

	qsort(cards, count, sizeof(card_t *), compare_cards);

	node = *deck;
	for (i = 0; i < count; i++)
	{
		node->card = cards[i];
		node = node->next;
	}
}
