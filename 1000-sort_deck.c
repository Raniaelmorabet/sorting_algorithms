#include "deck.h"
#include <stdlib.h>

/**
 * compare_cards - Compare function for qsort to compare deck nodes
 * @a: Pointer to the first deck node
 * @b: Pointer to the second deck node
 *
 * Return: Negative if a < b, 0 if a == b, Positive if a > b
 */
int compare_cards(const void *a, const void *b)
{
    const deck_node_t *node1 = *(const deck_node_t **)a;
    const deck_node_t *node2 = *(const deck_node_t **)b;

    int value_cmp = strcmp(node1->card->value, node2->card->value);
    if (value_cmp != 0)
        return value_cmp;

    return (int)(node1->card->kind) - (int)(node2->card->kind);
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t size = 52;
    deck_node_t *nodes[52];

    deck_node_t *current = *deck;
    size_t i = 0;
    while (current != NULL)
    {
        nodes[i++] = current;
        current = current->next;
    }

    qsort(nodes, size, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < size - 1; i++)
    {
        nodes[i]->next = nodes[i + 1];
        nodes[i + 1]->prev = nodes[i];
    }
    nodes[size - 1]->next = NULL;

    *deck = nodes[0];
}
