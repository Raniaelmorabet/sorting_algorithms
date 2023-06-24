#include "sort.h"

/**
 * swap - swaps 2 int values
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - partitions the array
 * @array: the integer array to sort
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: the index of the pivot
 */
int lomuto_partition(int *array, int low, int high)
{
    int i, j, pivot = array[high];

    for (i = j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[i], &array[high]);

    return i;
}

/**
 * quicksort - quicksorts via Lomuto partitioning scheme
 * @array: the integer array to sort
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int p = lomuto_partition(array, low, high);

        quicksort(array, low, p - 1);
        quicksort(array, p + 1, high);
    }
}

/**
 * quick_sort - calls quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    quicksort(array, 0, size - 1);
}
