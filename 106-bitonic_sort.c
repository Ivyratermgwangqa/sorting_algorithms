#include "sort.h"
#include <stdio.h>

/**
 * bitonic_merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @low: Starting index of the first subarray
 * @count: Size of the subarray to be sorted
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive function for Bitonic Sort
 * @array: The array to be sorted
 * @low: Starting index of the array
 * @count: Size of the array to be sorted
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, count, dir ? "UP" : "DOWN");
        print_array(array + low, count);

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);
        bitonic_merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (size > 1)
    {
        bitonic_sort_recursive(array, 0, size, 1);
    }
}
