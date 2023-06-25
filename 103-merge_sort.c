#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_left_right - Prints the left and right partitions of an array.
 * @array: The array.
 * @size: The size of the array.
 * @first: The initial position.
 * @mid: The middle position.
 * Description: This function prints the left and right partitions of an array
 * during the merge sort process.
 */
void print_left_right(int *array, int size, int first, int mid)
{
	int k;

	printf("Merging...\n");
	printf("[left]: ");
	k = first;
	while (k < mid)
	{
		if (k != mid - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}

	printf("[right]: ");
	k = mid;
	while (k < size)
	{
		if (k < size - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}
}

/**
 * merge - Merges two partitions of an array.
 * @array: The array.
 * @size: The size of the array.
 * @cpy: A copy of the array.
 * @first: The initial position of the first partition.
 * @mid: The middle position that separates the two partitions.
 * Description: This function merges the left and right partitions of an array
 * during the merge sort process.
 */
void merge(int *array, int size, int *cpy, int first, int mid)
{
	int i, j, k;

	print_left_right(array, size, first, mid);

	i = first;
	j = mid;

	printf("[Done]: ");
	k = first;
	while (k < size)
	{
		if (i < mid && (j >= size || array[i] <= array[j]))
		{
			cpy[k] = array[i];
			i++;
		}
		else
		{
			cpy[k] = array[j];
			j++;
		}
		if (k < size - 1)
			printf("%d, ", cpy[k]);
		else
			printf("%d\n", cpy[k]);
		k++;
	}
}

/**
 * mergeSort - Sorts an array using the merge sort algorithm.
 * @cpy: A copy of the array.
 * @first: The initial position.
 * @size: The size of the array.
 * @array: The original array.
 * Description: This function recursively divides the array into smaller
 * partitions and merges them back in sorted order.
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int mid;

	if (size - first < 2)
		return;

	mid = (size + first) / 2;

	mergeSort(array, first, mid, cpy);
	mergeSort(array, mid, size, cpy);

	merge(cpy, size, array, first, mid);
}

/**
 * copy_array - Copies an array.
 * @arr: The source array.
 * @cpy: The destination array.
 * @size: The size of the array.
 * Description: This function copies the elements of one array to another.
 */
void copy_array(int *arr, int *cpy, int size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		cpy[i] = arr[i];
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Description: This function sorts an array of integers in ascending order
 * using the merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *cpy;

	if (array == NULL || size < 2)
		return;

	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;

	copy_array(array, cpy, size);
	mergeSort(cpy, 0, (int)size, array);

	free(cpy);
}
