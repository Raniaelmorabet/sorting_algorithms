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
    const char *values[] = {"Jack", "4", "3", "Queen", "5", "10", "6", "9", "7", "King", "8", "2", "Ace"};
    
    int index1 = -1, index2 = -1;
    for (int i = 0; i < 13; i++) {
        if (strcmp(c1->value, values[i]) == 0) {
            index1 = i;
            break;
        }
    }
    for (int i = 0; i < 13; i++) {
        if (strcmp(c2->value, values[i]) == 0) {
            index2 = i;
            break;
        }
    }

    if (index1 != index2)
        return index1 - index2;

    return c1->kind - c2->kind;
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
