#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t i, middle;

	if (!array || size < 2)
		return;

	middle = size / 2;
	left = array;
	right = array + middle;

	merge_sort(left, middle);
	merge_sort(right, size - middle);

	printf("Merging...\n");

	printf("[left]: ");
	print_array(left, middle);

	printf("[right]: ");
	print_array(right, size - middle);

	for (i = 0; i < middle; i++)
	{
		while (*left > *right && right < array + size)
		{
			*left = *left ^ *right;
			*right = *left ^ *right;
			*left = *left ^ *right;
			left++;
			right++;
		}
	}

	printf("[Done]: ");
	print_array(array, size);
}
