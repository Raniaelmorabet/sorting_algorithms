#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare function for qsort to compare deck nodes
 * @a: Pointer to the first deck node
 * @b: Pointer to the second deck node
 *
 * Return: Negative if 'a' is less than 'b', positive if 'a' is greater than 'b',
 *         0 if 'a' is equal to 'b'
 */
int compare_cards(const void *a, const void *b)
{
    const deck_node_t *node1 = *(const deck_node_t **)a;
    const deck_node_t *node2 = *(const deck_node_t **)b;

    int value_cmp = strcmp(node1->card->value, node2->card->value);
    if (value_cmp != 0)
        return value_cmp;

    return node1->card->kind - node2->card->kind;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current, *next;
    card_t *temp_card;

    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    current = *deck;

    while (current != NULL)
    {
        next = current->next;
        while (next != NULL)
        {
            if (compare_cards(current->card, next->card) > 0)
            {
                temp_card = current->card;
                current->card = next->card;
                next->card = temp_card;
            }
            next = next->next;
        }
        current = current->next;
    }
}
