#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integer values
 * @a: Pointer to the first value
 * @b: Pointer to the second value
 *
 * Description: Swaps the values pointed to by @a and @b
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for QuickSort
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 *
 * Description: Picks a pivot element and partitions the array around it
 * using the Lomuto partition scheme.
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array + low, high - low + 1);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array + low, high - low + 1);

	return (i + 1);
}

/**
 * quicksort - Recursive function to perform QuickSort
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 *
 * Description: Implements the QuickSort algorithm using the Lomuto partition
 * scheme recursively.
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
 * quick_sort - Sorts an array of integers in ascending order using QuickSort
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Description: Sorts the elements in @array in ascending order using the
 * QuickSort algorithm.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1);
}
