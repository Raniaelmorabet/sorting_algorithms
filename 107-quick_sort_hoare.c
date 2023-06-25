#include "sort.h"

void quick_sort_helper(int *array, int left, int right, size_t size);
int partition(int *array, int left, int right, size_t size);
void swap(int *a, int *b);

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @left: left index
 * @right: right index
 * @size: size of the array
 * Return: void
 */
void quick_sort_helper(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);

		quick_sort_helper(array, left, pivot - 1, size);
		quick_sort_helper(array, pivot, right, size);
	}
}

/**
 * partition - partitions an array
 * @array: array of integers
 * @left: left index
 * @right: right index
 * @size: size of the array
 * Return: index of the pivot
 */
int partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1, j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}


/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
