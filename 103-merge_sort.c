#include "sort.h"

/**
 * merge_sub - Merge two subarrays in ascending order.
 * @subarray: The main array containing two subarrays to be merged.
 * @buffer: A temporary buffer to store the merged subarrays.
 * @lo: The starting index of the first subarray.
 * @mid: The ending index of the first subarray and the starting index of the second subarray.
 * @hi: The ending index of the second subarray.
 */
void merge_sub(int *subarray, int *buffer, size_t lo, size_t mid, size_t hi)
{
  size_t low;
  size_t midi;
	size_t a = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + lo, mid - lo);

	printf("[Right]: ");
	print_array(subarray + mid, hi - mid);

	for (low = lo, midi = mid; low < mid && midi < hi; a++)
  {
    if (subarray[low] < subarray[midi])
    {
			buffer[a] = subarray[low++];
		}
		else
		{
			buffer[a] = subarray[midi++];
		}
	}
	for (; low < mid; low++)
	{
		buffer[a++] = subarray[low];
	}
	for (; midi < hi; midi++)
	{
		buffer[a++] = subarray[midi];
	}
	for (low = lo, a = 0; low < hi; low++)
	{
		subarray[low] = buffer[a++];
	}
	printf("[Done]: ");
	print_array(subarray + lo, hi - lo);
}

/**
 * merge_sort_call - Recursively sorts subarrays using the merge sort algorithm.
 * @subarray: The array to be sorted.
 * @buffer: A temporary buffer for the merging process.
 * @lo: The starting index of the subarray to be sorted.
 * @hi: The ending index of the subarray to be sorted.
 */
void merge_sort_call(int *subarray, int *buffer, size_t lo, size_t hi)
{
	size_t mid;

	if (hi - lo > 1)
	{
		mid = lo + (hi - lo) / 2;
		merge_sort_call(subarray, buffer, lo, mid);
		merge_sort_call(subarray, buffer, mid, hi);
		merge_sub(subarray, buffer, lo, mid, hi);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_call(array, buffer, 0, size);

	free(buffer);
}
