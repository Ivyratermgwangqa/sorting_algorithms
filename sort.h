#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
}listint_t;
/**
 * @brief Boolean values represented as an enum.
 *
 * This enum defines boolean values to represent true and false.
 */
typedef enum bool
{
	false = 0,
	true
}bool;

/* auxiliary functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void aux_swap(int *a, int *b);
void quick_recursive(int *array, ssize_t low, ssize_t high, size_t size);
size_t lom_partition(int *array, ssize_t low, ssize_t high, size_t size);

/* function that sorts an array */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
