#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * swap_nodes - Swaps two deck nodes
 * @deck: Double pointer to the head of the deck
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    if (node1->next == node2)
    {
        node1->next = node2->next;
        node2->prev = node1->prev;
        node1->prev = node2;
        node2->next = node1;
    }
    else
    {
        deck_node_t *node1_next = node1->next;
        deck_node_t *node1_prev = node1->prev;
        deck_node_t *node2_next = node2->next;
        deck_node_t *node2_prev = node2->prev;

        node1->next = node2_next;
        node1->prev = node2_prev;
        node2->next = node1_next;
        node2->prev = node1_prev;
    }

    if (node1->prev == NULL)
        *deck = node1;
    else if (node2->prev == NULL)
        *deck = node2;
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
                swap_nodes(deck, current, next);

                temp_card = (card_t *)current->card;
                current->card = next->card;
                next->card = (const card_t *)temp_card;
            }
            next = next->next;
        }
        current = current->next;
    }
}
