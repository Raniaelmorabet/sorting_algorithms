#include "sort.h"

void merge_sort_helper(int *array, int left, int right);
void merge(int *array, int p, int q, int r);


/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_helper(array, 0, size - 1);
}

/**
 * merge_sort_helper - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers
 * @left: left index
 * @right: right index
 */
void merge_sort_helper(int *array, int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = (left + right) / 2;

		merge_sort_helper(array, left, middle);
		merge_sort_helper(array, middle + 1, right);

		printf("Merging...\n");

		merge(array, left, middle, right);
	}
}


/**
 * merge - merges two arrays
 * @array: array of integers
 * @p: left index
 * @q: middle index
 * @r: right index
 * Return: void
 */
void merge(int *array, int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *left, *right;

	left = malloc(sizeof(int) * n1);
	if (!left)
		return;
	right = malloc(sizeof(int) * n2);
	if (!right)
		return;

	printf("[left]: ");
	for (i = 0; i < n1; i++)
		left[i] = array[p + i];
	print_array(left, n1);

	printf("[right]: ");
	for (j = 0; j < n2; j++)
		right[j] = array[q + 1 + j];
	print_array(right, n2);

	i = 0;
	j = 0;
	k = p;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}

		k++;
	}

	while (i < n1)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array + p, r - p + 1);

	free(left);
	free(right);
}
