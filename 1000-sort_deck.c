#include "deck.h"
#include <stdlib.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_nodes(deck_node_t *node1, deck_node_t *node2)
{
    deck_node_t *prev1 = node1->prev;
    deck_node_t *next1 = node1->next;
    deck_node_t *prev2 = node2->prev;
    deck_node_t *next2 = node2->next;

    if (prev1)
        prev1->next = node2;
    if (next1)
        next1->prev = node2;
    if (prev2)
        prev2->next = node1;
    if (next2)
        next2->prev = node1;

    node1->prev = prev2;
    node1->next = next2;
    node2->prev = prev1;
    node2->next = next1;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order.
 * @deck: Pointer to the deck of cards.
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current, *next;
    int swapped;

    if (deck == NULL || *deck == NULL)
        return;

    do
    {
        swapped = 0;
        current = *deck;

        while (current->next)
        {
            next = current->next;

            if (next->card->kind < current->card->kind ||
                (next->card->kind == current->card->kind &&
                 strcmp(next->card->value, current->card->value) < 0))
            {
                swap_nodes(current, next);
                if (*deck == current)
                    *deck = next;
                swapped = 1;
            }
            else
            {
                current = current->next;
            }
        }
    } while (swapped);
}
