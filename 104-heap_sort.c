#include "sort.h"

void heapify(int *array, size_t size, int i, size_t size_orig);

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - heapifies a subtree
 * @array: array of integers
 * @size: size of the array
 * @i: index
 * @size_orig: original size of the array
 * Return: void
 */
void heapify(int *array, size_t size, int i, size_t size_orig)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int tmp;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		print_array(array, size_orig);
		heapify(array, size, largest, size_orig);
	}
}
