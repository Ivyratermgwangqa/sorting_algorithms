#include "sort.h"
/**
 * getMax - Get the maximum value in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum value
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * countingSort - Perform counting sort on an array based on significant place
 * @array: The array
 * @size: The size of the array
 * @exp: The current significant place (1, 10, 100, ...)
 */
void countingSort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};

    if (output == NULL)
        return;

    /* Count occurrences in count[] */
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Change count[i] so that count[i] contains the actual
       position of this digit in output[] */
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array to array[], so that array[] now
       contains sorted numbers according to current digit */
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    /* Print array after each pass */
    print_array(array, size);

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max = getMax(array, size);

    /* Perform counting sort for every digit place */
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(array, size, exp);
}
