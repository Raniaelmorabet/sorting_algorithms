#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *count, *output, max, i, exp;

	if (array == NULL || size < 2)
		return;

	count = malloc(sizeof(int) * 10);
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;

		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = output[i];

		print_array(array, size);
	}

	free(count);
	free(output);
}
