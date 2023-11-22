#include "sort.h"

/**
 * heapify - Ensure the heap property is maintained
 * @array: The array to be heapified
 * @size: The size of the array
 * @i: Index to start heapifying from
 * @total_size: Original size of the array for printing purposes
 */
void heapify(int *array, size_t size, size_t i, size_t total_size)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        /* Swap elements and print array */
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        print_array(array, total_size);
        
        /* Recursively heapify the affected subtree */
        heapify(array, size, largest, total_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    /* Build max heap */
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    /* Extract elements one by one from the heap */
    for (int i = size - 1; i > 0; i--)
    {
        /* Swap root with the current last node and print array */
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);

        /* Heapify the reduced heap */
        heapify(array, i, 0, size);
    }
}
