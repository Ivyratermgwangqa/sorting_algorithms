#include "sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 * @list: A pointer to a pointer to the head of the list.
 */
void swap_nodes(listint_t *node1, listint_t **node2, listint_t **list)
{
        if (node1->prev != NULL)
                node1->prev->next = *node2;
        else
                *list = *node2;

        if ((*node2)->next != NULL)
                (*node2)->next->prev = node1;

        node1->next = (*node2)->next;
        (*node2)->prev = node1;
        (*node2)->next = node1;
        node1->prev = *node2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(temp, &(temp->next), list);
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		swapped = 0;
		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(temp->prev, &temp, list);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
