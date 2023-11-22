#include "sort.h"
/**
 * quick_sort_recursive_hoare - Recursive function for Quick Sort (Hoare partition scheme)
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 */
void quick_sort_recursive_hoare(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        ssize_t p = hoare_partition(array, low, high, size);

        printf("Pivot element: %d\n", array[p]);
        print_array(array, size);

        quick_sort_recursive_hoare(array, low, p, size);
        quick_sort_recursive_hoare(array, p + 1, high, size);
    }
}

/**
 * hoare_partition - Hoare partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
ssize_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        /* Swap array[i] and array[j] */
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        print_array(array, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive_hoare(array, 0, size - 1, size);
}
