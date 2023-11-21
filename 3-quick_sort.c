#include "sort.h"
/**
 * aux_swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void aux_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lom_partition - Lomuto partition scheme for Quick Sort.
 * @array: The array to be partitioned.
 * @low: The lowest index of the partition.
 * @high: The highest index of the partition.
 * @size: The size of the array.
 *
 * Return: The final position of the pivot element.
 */
size_t lom_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			aux_swap(&array[i + 1], &array[high]);
			print_array(array, size);
		}
	}
	if (i + 1 != high)
	{
		aux_swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_recursive - Recursive function to perform Quick Sort.
 * @array: The array to be sorted.
 * @low: The lowest index of the partition.
 * @high: The highest index of the partition.
 * @size: The size of the array.
 */
void quick_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t piv_pos = lom_partition(array, low, high, size);

		quick_recursive(array, low, piv_pos - 1, size);
		quick_recursive(array, piv_pos + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursive(array, 0, size - 1, size);
}
