#ifndef DECK_H
#define DECK_H

#include <stddef.h>

typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int compare_cards(const void *card1, const void *card2);
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2);

#endif /* DECK_H */
