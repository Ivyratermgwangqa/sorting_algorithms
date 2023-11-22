#include "deck.h"
#include <stdio.h>
/**
 * compare_cards - Compare two cards for qsort
 * @a: Pointer to the first card node
 * @b: Pointer to the second card node
 *
 * Return: Negative value if a < b, positive if a > b, 0 if equal
 */
int compare_cards(const void *a, const void *b)
{
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;

    if (node_a->card->kind != node_b->card->kind)
        return (node_a->card->kind - node_b->card->kind);
    return (node_a->card->value[0] - node_b->card->value[0]);
}

/**
 * sort_deck - Sort a deck of cards in ascending order
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t i;
    deck_node_t *node = *deck;
    deck_node_t *nodes[52];

    /* Store deck nodes in an array */
    for (i = 0; i < 52; i++)
    {
        nodes[i] = node;
        node = node->next;
    }

    /* Use qsort to sort the array of nodes based on card values and kinds */
    qsort(nodes, 52, sizeof(deck_node_t *), compare_cards);

    /* Reconnect the doubly linked list based on the sorted array */
    for (i = 0; i < 51; i++)
    {
        nodes[i]->next = nodes[i + 1];
        nodes[i + 1]->prev = nodes[i];
    }

    /* Update pointers for the first and last nodes in the sorted list */
    nodes[0]->prev = NULL;
    nodes[51]->next = NULL;
    *deck = nodes[0];
}
