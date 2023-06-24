#include "sort.h"
#include <stdio.h>
/**
 * partition - array partition
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 * Return: int pivot index
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, high + 1);
            }
        }
    }

    if (array[i + 1] > array[high])
    {
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, high + 1);
    }

    return (i + 1);
}

/**
 * quick_sort_recursive - sorts an array of integers recursively
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);
        quick_sort_recursive(array, low, pivot - 1);
        quick_sort_recursive(array, pivot + 1, high);
    }
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}
