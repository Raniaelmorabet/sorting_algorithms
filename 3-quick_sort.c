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
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, int lo, int hi)
{
	if (lo < hi)
	{
		int p = lomuto_partition(array, lo, hi);
		quicksort(array, lo, p - 1);
		quicksort(array, p + 1, hi);
	}
}

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: the array to sort
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: the index of the pivot
 */
int lomuto_partition(int *array, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j, temp;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, hi + 1);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, hi + 1);
	}

	return (i + 1);
}
