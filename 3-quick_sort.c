#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1);
}

/**
 * quicksort - recursive function to perform Quick sort
 * @array: the array to sort
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high);
        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: the array to sort
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: the index of the pivot
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
                swap(&array[i], &array[j]);
        }
    }
    if (array[i + 1] != array[high])
        swap(&array[i + 1], &array[high]);

    print_array(array + low, high - low + 1);

    return (i + 1);
}

/**
 * swap - swaps two integer values
 * @a: pointer to the first value
 * @b: pointer to the second value
 *
 * Return: void
 */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
