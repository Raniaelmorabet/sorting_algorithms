#include "sort.h"

void bitonic_sort_helper(int *array, int start, int size, int total_size,
			 int dir);
void bitonic_merge(int *array, int start, int size, int dir);

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_helper(array, 0, size, size, 1);
}

/**
 * bitonic_sort_helper - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array of integers
 * @start: start index
 * @size: size of the array
 * @dir: direction
 * @total_size: total size of the array
 * Return: void
 */
void bitonic_sort_helper(int *array, int start, int size, int total_size,
			 int dir)
{
	int middle;

	if (size > 1)
	{
		middle = size / 2;
		printf("Merging [%d/%d] (%s):\n", size, total_size,
		       dir == 1 ? "UP" : "DOWN");
		print_array(array + start, size);
		bitonic_sort_helper(array, start, middle, total_size, 1);
		bitonic_sort_helper(array, start + middle, middle, total_size, 0);
		bitonic_merge(array, start, size, dir);
		printf("Result [%d/%d] (%s):\n", size, total_size,
		       dir == 1 ? "UP" : "DOWN");
		print_array(array + start, size);
	}
}

/**
 * bitonic_merge - merges two arrays
 * @array: array of integers
 * @start: start index
 * @size: size of the array
 * @dir: direction
 * Return: void
 */
void bitonic_merge(int *array, int start, int size, int dir)
{
	int i, middle, tmp;

	if (size > 1)
	{
		middle = size / 2;
		for (i = start; i < start + middle; i++)
		{
			if (dir == (array[i] > array[i + middle]))
			{
				tmp = array[i];
				array[i] = array[i + middle];
				array[i + middle] = tmp;
			}
		}
		bitonic_merge(array, start, middle, dir);
		bitonic_merge(array, start + middle, middle, dir);
	}
}
